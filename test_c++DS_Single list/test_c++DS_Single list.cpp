#include"Single list.h"
#include<iostream>
using namespace std;
int main()
{
	NodeHead Head=NULL;//1.生成一个头节点指针(typedef Node* NodeHead)2.初始化
	InsertHead(Head, "xiaoming");
	InsertHead(Head, "xiaohong");
	InsertHead(Head, "xiaohua");
	ShowAll(Head);
	cout << ListFind(Head, 1) << endl;
	cout << ListFind(Head, 0) << endl;
	cout << ListFind_pos(Head, "xiaoming") << endl;
	Insert_pos(Head, 1, "xiaowang");
	ShowAll(Head);
	DelNode(Head, 2);
	ShowAll(Head);
	cout << "链表的长度为:" << GetListLenght(Head) << endl;
}