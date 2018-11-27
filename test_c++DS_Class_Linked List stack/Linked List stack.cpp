#include "Linked List stack.h"
#include<iostream>
using namespace std;
//构造函数
LinkedListStack::LinkedListStack()
{
	//因为不需要头节点
	Base = Top = nullptr;
}
//释放整个栈destroy
LinkedListStack::~LinkedListStack()
{
	Node* p = Top;
	Node* temp;
	while (p)
	{
		temp = p;
		p = p->next;
		delete temp;
	}
	cout << "释放了整个链表栈" << endl;
}
//创建一个新的节点
Node * LinkedListStack::CreatNode(int d)
{
	Node* newnode = new Node;
	newnode->data = d;
	newnode->next = nullptr;
	return newnode;
}
bool LinkedListStack::IsEmpty()
{
	return Base == nullptr;
}
//top指向要插入的地方
void LinkedListStack::push(int d)
{
	Node* newnode = CreatNode(d);
	if (IsEmpty())
	{
		Base = newnode;//栈底指针指向第一个节点
		Top = newnode;//栈顶指针也指向第一个节点
	}
	else
	{
		newnode->next = Top;
		Top = newnode;
	}
}
//弹出一个节点,这就是一般不使用链表栈的一个原因：需要弹出一个Node该Node需要在main里面被释放
Node * LinkedListStack::pop()
{
	Node* temp;
	if (!IsEmpty())
	{
		temp = Top;
		Top = Top->next;
	}
	return temp;
}
//显示所有节点
void LinkedListStack::ShowAll()
{
	Node* p = Top;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
//显示栈内长度
void LinkedListStack::ShowLength()
{
	Node* p = Top;
	int num = 0;
	while (p)
	{
		p = p->next;
		num++;
	}
	cout << "一共有" << num << "栈内节点" << endl;
}
