#include"Single list.h"
#include<iostream>
using namespace std;
int main()
{
	NodeHead Head=NULL;//1.����һ��ͷ�ڵ�ָ��(typedef Node* NodeHead)2.��ʼ��
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
	cout << "����ĳ���Ϊ:" << GetListLenght(Head) << endl;
}