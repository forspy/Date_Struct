
//ѹ������
#ifndef COMPRESS
#define COMPRESS 

#include "huffmantree.h"
#include <fstream>
#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;


//ѹ������
void Compress()
{
	unsigned char ch;
	int i, j, k;
	int Charnum[256];//
	unsigned char Chars[256];    //�����湲ͬʹ�� ,��¼�ַ�
	int Charnums[256];    //��¼��Ӧ�ַ��ĸ���
	int CharKinds;        //�ַ�����
	char filenameorg[21];    //�ļ���������20���ַ� Դ�ļ���
	char filenameaim[21];   //Ŀ���ļ���
	int fileorgsize; //Դ�ļ���С
	int fileaimsize; //ѹ���ļ���С

	HuffmanTree<unsigned char> ht;
	CharNameNode NameNode[256];            //�洢�ַ���Ӧ�Ļ���������
	BinTreeNode<unsigned char> *btn = NULL;
	Code *first = NULL;
	Code *last = NULL;

	ifstream filein;
	ofstream fileout;

	cout << "\t\t\t\t������Ҫѹ���������ļ����ƣ�";
	cin >> filenameorg;
	filein.open(filenameorg, ios::_Nocreate | ios::binary);     //open:filenameorg

	if (!filein)
	{
		cout << filenameorg << "\t\t\t\t�����ļ�������!\n";
		filein.clear();
		return;
	}
	cout << "\t\t\t\t������Ҫѹ�������ļ�������(*.rar)��";  //�Ժ�����
	cin >> filenameaim;

	char filetype[5];
	int len;
	len = strlen(filenameaim);
	if (len <= 4)
	{
		cout << filenameaim << "\t\t\t\tѹ�������ļ�����չ������Ϊ.rar\n";
		return;
	}
	for (i = len - 1, j = 3; i >= len - 4; i--, j--)//�ж��ļ�����չ��Ϊ.HFM
		filetype[j] = filenameaim[i];
	filetype[4] = '\0';
	if (strcmp(filetype, ".rar") != 0)//�ж��ļ�����չ��Ϊ.HFM
	{
		cout << filenameaim << "\t\t\t\tѹ�������ļ�����չ������Ϊ.rar\n";
		return;
	}

	//          ******************************************************

	for (i = 0; i<256; i++)
	{
		Charnum[i] = 0;        //��¼ÿһ���ַ��ĸ���   
		Charnums[i] = 0;      //��¼�ַ�Char[i]�ĸ���
	}
	filein.unsetf(ios::skipws);
	fileorgsize = 0;  //����Դ�ļ���С
	filein >> ch;
	if (ch == EOF)
		cout << "\t\t\t\t�����ļ�Ϊ��";
	else
	{
		Charnum[unsigned int(ch)]++;
		fileorgsize++;
	}
	while (filein >> ch)
	{
		Charnum[unsigned int(ch)]++;      //ͳ��ÿ���ַ���Ƶ��
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
			Chars[j] = unsigned char(i);     //ͳ��Դ�ļ��д��ڵ��ַ���
			Charnums[j] = Charnum[i];
			j++;
		}
	}
	CharKinds = j;
	//          ******************************************************

	fileaimsize = 0; //����ѹ���ļ���С
	fileout.open(filenameaim, ios::binary);
	fileout << '0' << ' ';            //�Ƿ�λ����֮���޸ģ�
	//fileout<<filenameorg<<' ';
	fileout << CharKinds << ' '; //�����ַ�����
	fileaimsize += 7;
	for (i = 0; i<CharKinds; i++)
	{
		fileout << Chars[i] << ' ' << Charnums[i] << ' ';//���ַ���Ϣ������ʱѹ���ļ�
		fileaimsize += 10;
	}

	ht.Build(Charnums, Chars, CharKinds, ht);  //������������
	i = 0;
	ht.Path(ht.GetRoot(), first, last, NameNode, i); //����������������ַ���Ӧ�Ļ���������
	//          ***********************************************************        
	


	filein.open(filenameorg, ios::_Nocreate | ios::binary);
	filein.unsetf(ios::skipws);
	k = 0;
	j = 0;
	while (filein >> ch)
	{
		i = 0;
		while (ch != NameNode[i].charname)  //�ҵ�ch
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
				fileaimsize++;   //����ѹ���ļ���С
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
		fileaimsize++;            //����ѹ���ļ���С
	}
	fileout.seekp(0, ios::beg);
	fileout << 8 - k;                //�޸ķǷ������λ��
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
		NameNode[i].link = NULL;   //���������Ϣ
	}
	ht.Destroy();
	cout << "\t\t\t\t�����ļ�ѹ���ɹ�,ѹ����Ϊ��" << (fileaimsize * 100) / fileorgsize << '%' << endl;

	return;
}
//��ѹ������
void Decompress()
{
	unsigned char ch;
	int i, j, k;
	unsigned char Chars[256];        //�����湲ͬʹ�� ,��¼�ַ�
	int Charnums[256];        //��¼��Ӧ�ַ��ĸ���
	int CharKinds;            //�ַ�����
	unsigned int total;  //��¼�ַ�ת�������
	int fpend;                    //�ݴ��ļ�ָ������λ�á���
	char filenameorg[21];         //�ļ���������20���ַ� Դ�ļ���
	char filenameaim[21];        //Ŀ���ļ���

	HuffmanTree<unsigned char> ht;
	CharNameNode NameNode[256];        //�洢�ַ���Ӧ�Ļ���������
	BinTreeNode<unsigned char> *btn = NULL;
	Code *first = NULL;
	Code *last = NULL;

	ifstream filein;
	ofstream fileout;

	char filetype[5];
	int len;
	cout << "\t\t\t\t������Ҫ��ѹ�����ļ������ƣ�";
	cin >> filenameorg;

	len = strlen(filenameorg);
	if (len <= 4)
	{
		cout << filenameorg << "\t\t\t\t���ǻ���������ĳ����޷����н�ѹ��\n";
		return;
	}
	for (i = len - 1, j = 3; i >= len - 4; i--, j--)
		filetype[j] = filenameorg[i];
	filetype[4] = '\0';
	if (strcmp(filetype, ".rar") != 0)
	{
		cout << filenameorg << "\t\t\t\t���ǻ���������ĳ����޷����н�ѹ��\n";
		return;
	}
	filein.open(filenameorg, ios::_Nocreate | ios::binary);
	if (!filein)
	{
		cout << filenameorg << "\t\t\t\t������!\n";
		filein.clear();
		return;
	}
	filein.close();

	cout << "\t\t\t\t�������ѹ��������ļ����ƣ�";
	cin >> filenameaim;

	filein.open(filenameorg, ios::_Nocreate | ios::binary);
	if (!filein)
	{
		cout << "\t\t\t\t��ѹ�����ļ�ʧ��,������!\n";
		filein.clear();
		return;
	}
	filein.seekg(0, ios::end);
	fpend = filein.tellg();                //��¼�ļ�β��λ��
	filein.seekg(0, ios::beg);      //�ָ�    
	filein.unsetf(ios::skipws);
	filein >> k >> ch;            //���һ���ַ����Ϸ���λ��
	//filein>>filenameaim>>ch;

	filein >> CharKinds >> ch;
	for (i = 0; i<CharKinds; i++)
		filein >> Chars[i] >> ch >> Charnums[i] >> ch;  //�����ַ���Ϣ

	ht.Build(Charnums, Chars, CharKinds, ht);  //������������
	btn = ht.GetRoot();
	fileout.open(filenameaim, ios::binary);  //���ı��ļ���
	if (!fileout)
	{
		cout << "\t\t\t\tĿ�������ļ�����ʧ��,������!\n";
		fileout.clear();
		return;
	}
	while (filein >> ch)
	{
		total = (unsigned int)(ch);  //���ﶼ����ȷ��
		j = 0;
		//if (filein.tellg() == fpend)           //�����ļ�β         NONONONONONONONONO
		//	j = k;                        //��kλ�����
		for (i = 7; i >= j; i--)
		{
			if (total&(1 << i))   //��һλ��1����������
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
	cout << "\t\t\t\t�����ļ���ѹ�ɹ�!\n";
	cout << "\t\t\t\t������\"" << filenameaim << "\"��." << endl;

	return;
}

#endif
