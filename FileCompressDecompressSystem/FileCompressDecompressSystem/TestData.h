
#ifndef CESHI
#define CESHI

#include "compress.h"
#include <iostream>
#include <fstream>

using namespace std;


void Ceshi()
{
	unsigned char ch;
	int i, j, k;
	int Charnum[256];//
	unsigned char Chars[256];    //与下面共同使用 ,记录字符
	int Charnums[256];    //记录对应字符的个数
	int CharKinds;        //字符种数
	unsigned char string[301];
	unsigned char *acharp;   //字符指针
	int length; //报文长度

	HuffmanTree<unsigned char> ht;
	CharNameNode NameNode[256];            //存储字符对应的霍夫曼编码
	BinTreeNode<unsigned char> *btn = NULL;
	Code *first = NULL;
	Code *last = NULL;
	Code *pCode = NULL;  //临时使用
	unsigned int total;
	int fpend;
	ofstream fileout;
	ifstream filein;

	cout << "请输入要测试的字符串(长度不超过300)：";
	cin >> string;
	acharp = string;

	for (i = 0; i<256; i++)
	{
		Charnum[i] = 0;        //记录每一个字符的个数   
		Charnums[i] = 0;      //记录字符Char[i]的个数
	}
	while (*acharp != '\0')
	{
		Charnum[unsigned int(*acharp)]++;      //统计每种字符的频数
		acharp++;
	}

	//  ******************************************************

	j = 0;
	for (i = 0; i<256; i++)
	{
		if (Charnum[i])
		{
			Chars[j] = unsigned char(i);     //统计字符串中存在的字符的
			Charnums[j] = Charnum[i];
			j++;
		}
	}
	CharKinds = j;

	fileout.open("temp.txt", ios::binary);  //输出到临时文件中保存
	fileout << '0' << ' ';            //非法位数（之后修改）
	fileout << CharKinds << ' '; //存入字符种类
	for (i = 0; i<CharKinds; i++)
		fileout << Chars[i] << ' ' << Charnums[i] << ' ';//将字符信息存入临时文件

	ht.Build(Charnums, Chars, CharKinds, ht);  //建立霍夫曼树
	i = 0;
	ht.Path(ht.GetRoot(), first, last, NameNode, i); //搜索霍夫曼树求得字符对应的霍夫曼编码
	//          ***********************************************************    

	cout << "各字符的霍夫曼编码：\n";
	for (i = 0; i<CharKinds; i++)
	{
		cout << "\t" << NameNode[i].charname << ':';
		pCode = NameNode[i].link;
		while (pCode != NULL)
		{
			cout << pCode->code;
			pCode = pCode->link;
		}
		cout << endl;
	}
	k = 0;
	j = 0;
	length = 0;  //报文长度
	acharp = string;
	cout << "报文：";
	while (*acharp != '\0')
	{

		i = 0;
		while (*acharp != NameNode[i].charname)  //找到ch
			i++;
		pCode = NameNode[i].link;
		while (pCode != NULL)
		{
			length++;
			j <<= 1;
			j += pCode->code;
			cout << pCode->code;
			k++;
			if (k == 8)
			{
				fileout << unsigned char(j);
				k = 0;
				j = 0;
			}
			pCode = pCode->link;
		}
		acharp++;
	}
	cout << "\n长度：" << length << endl;
	if (k<8)
	{
		j <<= (8 - k);
		fileout << unsigned char(j);
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

	filein.open("temp.txt", ios::binary);  //从临时文件中取出Huffman码
	filein.seekg(0, ios::end);
	fpend = filein.tellg();                //记录文件尾的位置
	filein.seekg(0, ios::beg);      //恢复    
	filein.unsetf(ios::skipws);
	filein >> k >> ch;            //最后一个字符不合法的位数
	filein >> CharKinds >> ch;
	for (i = 0; i<CharKinds; i++)
		filein >> Chars[i] >> ch >> Charnums[i] >> ch;  //载入字符信息

	ht.Build(Charnums, Chars, CharKinds, ht);  //建立霍夫曼
	btn = ht.GetRoot();
	cout << "上述报文的解码：";

	while (filein >> ch)
	{
		total = (unsigned int)(ch);  //这里都是正确的
		j = 0;
		//if (filein.tellg()==fpend)           //到了文件尾         NONONONONONONONONO
		//	j = k;                        //留k位不输出
		for (i = 7; i >= j; i--)
		{
			if (total&(1 << i))   //这一位是1向右子树走
				btn = btn->GetRight();
			else
				btn = btn->GetLeft();
			if (btn->GetData() != 0)
			{
				cout << btn->GetData();
				btn = ht.GetRoot();
			}
		}
	}
	cout << endl;
	filein.setf(ios::skipws);
	filein.close();

	cout << "输入Huffman编码: ";
	cin >> string;
	acharp = string;
	cout << "输出解码：";
	while (*acharp != '\0')
	{
		if (*acharp == '1')    //这一位是1向右子树走
			btn = btn->GetRight();
		else
			btn = btn->GetLeft();
		if (btn->GetData() != 0)
		{
			cout << btn->GetData();
			btn = ht.GetRoot();
		}
		acharp++;
	}
	cout << endl;
	ht.Destroy();
	return;
}

#endif


