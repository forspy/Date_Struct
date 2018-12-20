
//压缩技术
#ifndef COMPRESS
#define COMPRESS 

#include "huffmantree.h"
#include <fstream>
#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;


//压缩函数
void Compress()
{
	unsigned char ch;
	int i, j, k;
	int Charnum[256];//
	unsigned char Chars[256];    //与下面共同使用 ,记录字符
	int Charnums[256];    //记录对应字符的个数
	int CharKinds;        //字符种数
	char filenameorg[21];    //文件名不超过20个字符 源文件名
	char filenameaim[21];   //目标文件名
	int fileorgsize; //源文件大小
	int fileaimsize; //压缩文件大小

	HuffmanTree<unsigned char> ht;
	CharNameNode NameNode[256];            //存储字符对应的霍夫曼编码
	BinTreeNode<unsigned char> *btn = NULL;
	Code *first = NULL;
	Code *last = NULL;

	ifstream filein;
	ofstream fileout;

	cout << "\t\t\t\t请输入要压缩的数据文件名称：";
	cin >> filenameorg;
	filein.open(filenameorg, ios::_Nocreate | ios::binary);     //open:filenameorg

	if (!filein)
	{
		cout << filenameorg << "\t\t\t\t数据文件不存在!\n";
		filein.clear();
		return;
	}
	cout << "\t\t\t\t请输入要压缩数据文件的名称(*.rar)：";  //以后再用
	cin >> filenameaim;

	char filetype[5];
	int len;
	len = strlen(filenameaim);
	if (len <= 4)
	{
		cout << filenameaim << "\t\t\t\t压缩数据文件的扩展名必须为.rar\n";
		return;
	}
	for (i = len - 1, j = 3; i >= len - 4; i--, j--)//判断文件的扩展名为.HFM
		filetype[j] = filenameaim[i];
	filetype[4] = '\0';
	if (strcmp(filetype, ".rar") != 0)//判断文件的扩展名为.HFM
	{
		cout << filenameaim << "\t\t\t\t压缩数据文件的扩展名必须为.rar\n";
		return;
	}

	//          ******************************************************

	for (i = 0; i<256; i++)
	{
		Charnum[i] = 0;        //记录每一个字符的个数   
		Charnums[i] = 0;      //记录字符Char[i]的个数
	}
	filein.unsetf(ios::skipws);
	fileorgsize = 0;  //计算源文件大小
	filein >> ch;
	if (ch == EOF)
		cout << "\t\t\t\t数据文件为空";
	else
	{
		Charnum[unsigned int(ch)]++;
		fileorgsize++;
	}
	while (filein >> ch)
	{
		Charnum[unsigned int(ch)]++;      //统计每种字符的频数
		fileorgsize++;
	}
	filein.setf(ios::skipws);
	filein.close();                                       //close:filenameorg 
	//          ******************************************************

	j = 0;
	for (i = 0; i<256; i++)
	{
		if (Charnum[i])
		{
			Chars[j] = unsigned char(i);     //统计源文件中存在的字符的
			Charnums[j] = Charnum[i];
			j++;
		}
	}
	CharKinds = j;
	//          ******************************************************

	fileaimsize = 0; //计算压缩文件大小
	fileout.open(filenameaim, ios::binary);
	fileout << '0' << ' ';            //非法位数（之后修改）
	//fileout<<filenameorg<<' ';
	fileout << CharKinds << ' '; //存入字符种类
	fileaimsize += 7;
	for (i = 0; i<CharKinds; i++)
	{
		fileout << Chars[i] << ' ' << Charnums[i] << ' ';//将字符信息存入临时压缩文件
		fileaimsize += 10;
	}

	ht.Build(Charnums, Chars, CharKinds, ht);  //建立霍夫曼树
	i = 0;
	ht.Path(ht.GetRoot(), first, last, NameNode, i); //搜索霍夫曼树求得字符对应的霍夫曼编码
	//          ***********************************************************        
	


	filein.open(filenameorg, ios::_Nocreate | ios::binary);
	filein.unsetf(ios::skipws);
	k = 0;
	j = 0;
	while (filein >> ch)
	{
		i = 0;
		while (ch != NameNode[i].charname)  //找到ch
			i++;
		Code *p = NameNode[i].link;
		while (p != NULL)
		{
			j <<= 1;
			j += p->code;
			k++;
			if (k == 8)
			{
				fileout << unsigned char(j);
				fileaimsize++;   //计算压缩文件大小
				k = 0;
				j = 0;
			}
			p = p->link;
		}
	}
	filein.setf(ios::skipws);
	filein.close();
	if (k<8)
	{
		j <<= (8 - k);
		fileout << unsigned char(j);
		fileaimsize++;            //计算压缩文件大小
	}
	fileout.seekp(0, ios::beg);
	fileout << 8 - k;                //修改非法代码的位数
	fileout.close();
	for (i = 0; i<CharKinds; i++)
	{
		Code *q = NameNode[i].link;
		Code *s = NULL;
		while (q != NULL)
		{
			s = q;
			q = q->link;
			delete s;
		}
		NameNode[i].link = NULL;   //清除链表信息
	}
	ht.Destroy();
	cout << "\t\t\t\t数据文件压缩成功,压缩率为：" << (fileaimsize * 100) / fileorgsize << '%' << endl;

	return;
}
//解压缩函数
void Decompress()
{
	unsigned char ch;
	int i, j, k;
	unsigned char Chars[256];        //与下面共同使用 ,记录字符
	int Charnums[256];        //记录对应字符的个数
	int CharKinds;            //字符种数
	unsigned int total;  //记录字符转化后的数
	int fpend;                    //暂存文件指针的最后位置　　
	char filenameorg[21];         //文件名不超过20个字符 源文件名
	char filenameaim[21];        //目标文件名

	HuffmanTree<unsigned char> ht;
	CharNameNode NameNode[256];        //存储字符对应的霍夫曼编码
	BinTreeNode<unsigned char> *btn = NULL;
	Code *first = NULL;
	Code *last = NULL;

	ifstream filein;
	ofstream fileout;

	char filetype[5];
	int len;
	cout << "\t\t\t\t请输入要解压数据文件的名称：";
	cin >> filenameorg;

	len = strlen(filenameorg);
	if (len <= 4)
	{
		cout << filenameorg << "\t\t\t\t不是霍夫曼编码的程序，无法进行解压！\n";
		return;
	}
	for (i = len - 1, j = 3; i >= len - 4; i--, j--)
		filetype[j] = filenameorg[i];
	filetype[4] = '\0';
	if (strcmp(filetype, ".rar") != 0)
	{
		cout << filenameorg << "\t\t\t\t不是霍夫曼编码的程序，无法进行解压！\n";
		return;
	}
	filein.open(filenameorg, ios::_Nocreate | ios::binary);
	if (!filein)
	{
		cout << filenameorg << "\t\t\t\t不存在!\n";
		filein.clear();
		return;
	}
	filein.close();

	cout << "\t\t\t\t请输入解压后的数据文件名称：";
	cin >> filenameaim;

	filein.open(filenameorg, ios::_Nocreate | ios::binary);
	if (!filein)
	{
		cout << "\t\t\t\t解压数据文件失败,请重试!\n";
		filein.clear();
		return;
	}
	filein.seekg(0, ios::end);
	fpend = filein.tellg();                //记录文件尾的位置
	filein.seekg(0, ios::beg);      //恢复    
	filein.unsetf(ios::skipws);
	filein >> k >> ch;            //最后一个字符不合法的位数
	//filein>>filenameaim>>ch;

	filein >> CharKinds >> ch;
	for (i = 0; i<CharKinds; i++)
		filein >> Chars[i] >> ch >> Charnums[i] >> ch;  //载入字符信息

	ht.Build(Charnums, Chars, CharKinds, ht);  //建立霍夫曼树
	btn = ht.GetRoot();
	fileout.open(filenameaim, ios::binary);  //以文本文件打开
	if (!fileout)
	{
		cout << "\t\t\t\t目标数据文件创建失败,请重试!\n";
		fileout.clear();
		return;
	}
	while (filein >> ch)
	{
		total = (unsigned int)(ch);  //这里都是正确的
		j = 0;
		//if (filein.tellg() == fpend)           //到了文件尾         NONONONONONONONONO
		//	j = k;                        //留k位不输出
		for (i = 7; i >= j; i--)
		{
			if (total&(1 << i))   //这一位是1向右子树走
				btn = btn->GetRight();
			else
				btn = btn->GetLeft();
			//        if(btn->GetData()!=0)
			if (btn->GetLeft() == NULL&&btn->GetRight() == NULL)
			{
				fileout << btn->GetData();
				btn = ht.GetRoot();
			}
		}
	}
	fileout.close();
	filein.setf(ios::skipws);
	filein.close();
	ht.Destroy();
	cout << "\t\t\t\t数据文件解压成功!\n";
	cout << "\t\t\t\t保存在\"" << filenameaim << "\"中." << endl;

	return;
}

#endif
