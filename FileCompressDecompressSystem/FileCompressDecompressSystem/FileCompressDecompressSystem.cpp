// FileCompressDecompressSystem.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

//霍夫曼树，又称哈夫曼数，huffman树

//-----------------------------------------------------------------------------
//huffmantreemain.cpp
//主界面

#include <iostream>
#include <fstream>
#include <conio.h>

#include "huffmantree.h"
#include "compress.h"
#include "TestData.h"

using namespace std;


void CompressMenu()
{
	cout << "\n\n\t\t\t\t□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□" << endl;
	cout << "\t\t\t\t□                                                          □" << endl;
	cout << "\t\t\t\t□              1.压缩数据         2.解压数据               □" << endl;
	cout << "\t\t\t\t□                                                          □" << endl;
	cout << "\t\t\t\t□              3.测试数据         0.退出系统               □" << endl;
	cout << "\t\t\t\t□                                                          □" << endl;
	cout << "\t\t\t\t□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□" << endl;
	return;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char meiyong;

	cout << "\n\n\n\n\n\n\t\t\t\t□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□" << endl;
	cout << "\t\t\t\t□                                                          □" << endl;
	cout << "\t\t\t\t□              《数据压缩与解压系统》超级算法              □" << endl;
	cout << "\t\t\t\t□                                                          □" << endl;
	cout << "\t\t\t\t□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□" << endl;
	cout << "\t\t\t\t□                                                          □" << endl;
	cout << "\t\t\t\t□           使用此系统之前，请认真仔细阅读相关说明         □" << endl;
	cout << "\t\t\t\t□                                                          □" << endl;
	cout << "\t\t\t\t□                      著作权属于:Vico本人所有             □" << endl;
	cout << "\t\t\t\t□                                                          □" << endl;
	cout << "\t\t\t\t□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□" << endl;

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

	cout << "\n\n\n\n\n\n\t\t\t\t□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□" << endl;
	cout << "\t\t\t\t□                                                          □" << endl;
	cout << "\t\t\t\t□         欢迎使用《数据压缩与解压系统》超级算法           □" << endl;
	cout << "\t\t\t\t□                                                          □" << endl;
	cout << "\t\t\t\t□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□" << endl;

	CompressMenu();

	char choice;
	cout << "\t\t\t\t请选择操作项:";
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
			cout << "\n\n\n\n\n\n\t\t\t\t□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□" << endl;
			cout << "\t\t\t\t□                                                          □" << endl;
			cout << "\t\t\t\t□          感谢使用《数据压缩与解压系统》超级算法          □" << endl;
			cout << "\t\t\t\t□                                                          □" << endl;
			cout << "\t\t\t\t□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□" << endl;
		}
			return 1;

		default:
			cout << "\t\t\t\t对不起无此操作，请重新输入选项.\n\n";
		}
		cout << endl << "\t\t\t\t请选择操作项:";
		cin >> choice;
	}

	return 0;
}

