
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
	unsigned char Chars[256];    //�����湲ͬʹ�� ,��¼�ַ�
	int Charnums[256];    //��¼��Ӧ�ַ��ĸ���
	int CharKinds;        //�ַ�����
	unsigned char string[301];
	unsigned char *acharp;   //�ַ�ָ��
	int length; //���ĳ���

	HuffmanTree<unsigned char> ht;
	CharNameNode NameNode[256];            //�洢�ַ���Ӧ�Ļ���������
	BinTreeNode<unsigned char> *btn = NULL;
	Code *first = NULL;
	Code *last = NULL;
	Code *pCode = NULL;  //��ʱʹ��
	unsigned int total;
	int fpend;
	ofstream fileout;
	ifstream filein;

	cout << "������Ҫ���Ե��ַ���(���Ȳ�����300)��";
	cin >> string;
	acharp = string;

	for (i = 0; i<256; i++)
	{
		Charnum[i] = 0;        //��¼ÿһ���ַ��ĸ���   
		Charnums[i] = 0;      //��¼�ַ�Char[i]�ĸ���
	}
	while (*acharp != '\0')
	{
		Charnum[unsigned int(*acharp)]++;      //ͳ��ÿ���ַ���Ƶ��
		acharp++;
	}

	//  ******************************************************

	j = 0;
	for (i = 0; i<256; i++)
	{
		if (Charnum[i])
		{
			Chars[j] = unsigned char(i);     //ͳ���ַ����д��ڵ��ַ���
			Charnums[j] = Charnum[i];
			j++;
		}
	}
	CharKinds = j;

	fileout.open("temp.txt", ios::binary);  //�������ʱ�ļ��б���
	fileout << '0' << ' ';            //�Ƿ�λ����֮���޸ģ�
	fileout << CharKinds << ' '; //�����ַ�����
	for (i = 0; i<CharKinds; i++)
		fileout << Chars[i] << ' ' << Charnums[i] << ' ';//���ַ���Ϣ������ʱ�ļ�

	ht.Build(Charnums, Chars, CharKinds, ht);  //������������
	i = 0;
	ht.Path(ht.GetRoot(), first, last, NameNode, i); //����������������ַ���Ӧ�Ļ���������
	//          ***********************************************************    

	cout << "���ַ��Ļ��������룺\n";
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
	length = 0;  //���ĳ���
	acharp = string;
	cout << "���ģ�";
	while (*acharp != '\0')
	{

		i = 0;
		while (*acharp != NameNode[i].charname)  //�ҵ�ch
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
	cout << "\n���ȣ�" << length << endl;
	if (k<8)
	{
		j <<= (8 - k);
		fileout << unsigned char(j);
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

	filein.open("temp.txt", ios::binary);  //����ʱ�ļ���ȡ��Huffman��
	filein.seekg(0, ios::end);
	fpend = filein.tellg();                //��¼�ļ�β��λ��
	filein.seekg(0, ios::beg);      //�ָ�    
	filein.unsetf(ios::skipws);
	filein >> k >> ch;            //���һ���ַ����Ϸ���λ��
	filein >> CharKinds >> ch;
	for (i = 0; i<CharKinds; i++)
		filein >> Chars[i] >> ch >> Charnums[i] >> ch;  //�����ַ���Ϣ

	ht.Build(Charnums, Chars, CharKinds, ht);  //����������
	btn = ht.GetRoot();
	cout << "�������ĵĽ��룺";

	while (filein >> ch)
	{
		total = (unsigned int)(ch);  //���ﶼ����ȷ��
		j = 0;
		//if (filein.tellg()==fpend)           //�����ļ�β         NONONONONONONONONO
		//	j = k;                        //��kλ�����
		for (i = 7; i >= j; i--)
		{
			if (total&(1 << i))   //��һλ��1����������
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

	cout << "����Huffman����: ";
	cin >> string;
	acharp = string;
	cout << "������룺";
	while (*acharp != '\0')
	{
		if (*acharp == '1')    //��һλ��1����������
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


