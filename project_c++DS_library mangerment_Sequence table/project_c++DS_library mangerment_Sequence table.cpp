#include"Sequence table.h"
#include<iostream>
#include<fstream>//�ļ���
#include<string>
using namespace std;
int main()
{
	SqList booklist;
	InitList(&booklist);
	Book book1 = { "12345", "C++prime", 50 };
	Book book2 = { "10002","python",30 };
	Book book3 = { "10003","java",35 };
	//Ԫ�ض�Ļ����Դ���book�������飬Ȼ��ʹ��forѭ������
	InsertElem_back(booklist, book1);//��book1���뵽booklist����
	InsertElem_back(booklist, book2);
	InsertElem_back(booklist, book3);
	//----
	LocateElem(booklist, "12345");
	cout << "��ʾ���е�����Ԫ��" << endl;
	ShowAll(booklist);
	Book book4 = { "10004","MFC",45 };
	InsertElem_pos(booklist, book4, 1);
	cout << "-------" << endl;
	ShowAll(booklist);
	cout << "DEL------" << endl;
	DelElem_ISBN(booklist, "10003");
	ShowAll(booklist);
	cout << "�޸�-----" << endl;
	book2 = { "10002","python",35 };
	ChangeElem(booklist, book2);
	ShowAll(booklist);
	//Ҳ����ʹ�����ַ�ʽ���ļ������ȡ
	string ISBN, NAME;
	int price;
	fstream file;
	file.open("message.txt");
	file >> ISBN >> NAME >> price;//����ȡint���ͣ���~ o(*������*)o����
	cout << ISBN << " " << NAME << " " << price << endl;
}