#include"Sequence table.h"
#include<iostream>
#include<fstream>//文件流
#include<string>
using namespace std;
int main()
{
	SqList booklist;
	InitList(&booklist);
	Book book1 = { "12345", "C++prime", 50 };
	Book book2 = { "10002","python",30 };
	Book book3 = { "10003","java",35 };
	//元素多的化可以创建book对象数组，然后使用for循环输入
	InsertElem_back(booklist, book1);//将book1插入到booklist表中
	InsertElem_back(booklist, book2);
	InsertElem_back(booklist, book3);
	//----
	LocateElem(booklist, "12345");
	cout << "显示表中的所有元素" << endl;
	ShowAll(booklist);
	Book book4 = { "10004","MFC",45 };
	InsertElem_pos(booklist, book4, 1);
	cout << "-------" << endl;
	ShowAll(booklist);
	cout << "DEL------" << endl;
	DelElem_ISBN(booklist, "10003");
	ShowAll(booklist);
	cout << "修改-----" << endl;
	book2 = { "10002","python",35 };
	ChangeElem(booklist, book2);
	ShowAll(booklist);
	//也可以使用这种方式从文件里面读取
	string ISBN, NAME;
	int price;
	fstream file;
	file.open("message.txt");
	file >> ISBN >> NAME >> price;//能提取int类型，嗯~ o(*￣▽￣*)o不错
	cout << ISBN << " " << NAME << " " << price << endl;
}