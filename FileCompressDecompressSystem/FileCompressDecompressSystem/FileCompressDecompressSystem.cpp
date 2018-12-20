// FileCompressDecompressSystem.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

//�����������ֳƹ���������huffman��

//-----------------------------------------------------------------------------
//huffmantreemain.cpp
//������

#include <iostream>
#include <fstream>
#include <conio.h>

#include "huffmantree.h"
#include "compress.h"
#include "TestData.h"

using namespace std;


void CompressMenu()
{
	cout << "\n\n\t\t\t\t��������������������������������������������������������������" << endl;
	cout << "\t\t\t\t��                                                          ��" << endl;
	cout << "\t\t\t\t��              1.ѹ������         2.��ѹ����               ��" << endl;
	cout << "\t\t\t\t��                                                          ��" << endl;
	cout << "\t\t\t\t��              3.��������         0.�˳�ϵͳ               ��" << endl;
	cout << "\t\t\t\t��                                                          ��" << endl;
	cout << "\t\t\t\t��������������������������������������������������������������" << endl;
	return;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char meiyong;

	cout << "\n\n\n\n\n\n\t\t\t\t��������������������������������������������������������������" << endl;
	cout << "\t\t\t\t��                                                          ��" << endl;
	cout << "\t\t\t\t��              ������ѹ�����ѹϵͳ�������㷨              ��" << endl;
	cout << "\t\t\t\t��                                                          ��" << endl;
	cout << "\t\t\t\t��������������������������������������������������������������" << endl;
	cout << "\t\t\t\t��                                                          ��" << endl;
	cout << "\t\t\t\t��           ʹ�ô�ϵͳ֮ǰ����������ϸ�Ķ����˵��         ��" << endl;
	cout << "\t\t\t\t��                                                          ��" << endl;
	cout << "\t\t\t\t��                      ����Ȩ����:Vico��������             ��" << endl;
	cout << "\t\t\t\t��                                                          ��" << endl;
	cout << "\t\t\t\t��������������������������������������������������������������" << endl;

	cin.unsetf(ios::skipws);
	cin >> meiyong;
	cin.setf(ios::skipws);
	ifstream fin("ReadmeVico.txt", ios::binary);
	fin.unsetf(ios::skipws);
	while (fin >> meiyong)
	{
		cout << meiyong;
	}
	cout << endl;
	getch();
	fin.setf(ios::skipws);
	fin.close();

	system("pause");
	system("CLS");

	cout << "\n\n\n\n\n\n\t\t\t\t��������������������������������������������������������������" << endl;
	cout << "\t\t\t\t��                                                          ��" << endl;
	cout << "\t\t\t\t��         ��ӭʹ�á�����ѹ�����ѹϵͳ�������㷨           ��" << endl;
	cout << "\t\t\t\t��                                                          ��" << endl;
	cout << "\t\t\t\t��������������������������������������������������������������" << endl;

	CompressMenu();

	char choice;
	cout << "\t\t\t\t��ѡ�������:";
	cin >> choice;
	while (1)
	{
		switch (choice)
		{
		case '1':
			Compress();
			break;
		case '2':
			Decompress();
			break;
		case '3':
			Ceshi();
			break;
		case '0':
		{
			system("CLS");
			cout << "\n\n\n\n\n\n\t\t\t\t��������������������������������������������������������������" << endl;
			cout << "\t\t\t\t��                                                          ��" << endl;
			cout << "\t\t\t\t��          ��лʹ�á�����ѹ�����ѹϵͳ�������㷨          ��" << endl;
			cout << "\t\t\t\t��                                                          ��" << endl;
			cout << "\t\t\t\t��������������������������������������������������������������" << endl;
		}
			return 1;

		default:
			cout << "\t\t\t\t�Բ����޴˲���������������ѡ��.\n\n";
		}
		cout << endl << "\t\t\t\t��ѡ�������:";
		cin >> choice;
	}

	return 0;
}

