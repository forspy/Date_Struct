#include "Single list.h"
#include<iostream>
using namespace std;
//初始化一个节点
//因为是使用无头节点模式所以只需要将头节点初始化为NULL
//判断链表是否为空
bool IsEmpty(NodeHead & head)
{
	return head->next == NULL;//空返回true
}
//销毁一个链表（释放内存）
void destroy(NodeHead & head)
{
	while (head)//如果有节点就循环
	{
		Node* temp = head;//需要定义一个临时指针去接受node
		head = head->next;//让头指针去遍历
		delete temp;
	}
}
//求表长
int ListLength(NodeHead & head)
{
	NodeHead p = head;//定义一个指针P去遍历链表
	int num=0;//表长
	p = p->next;//先指向第一个节点
	while (p)
	{
		p = p->next;
		num++;
	}
	return num;
}
//查找链表中的第n个元素(n从0开始)
string ListFind(NodeHead & head,int n)
{
	NodeHead p = head;
	for (int i = 0; i < n; i++)
	{
		if (p == NULL)
		{
			cout << "查找的位置超出链表范围" << endl;
			return "ERROR";
		}
		p = p->next;
	}
	return p->name;
}
//查找链表中的某个元素所在的位置
int ListFind_pos(NodeHead & head, const string str)
{
	NodeHead p = head;
	int pos = 0;
	while (p)
	{
		pos++;
		if (p->name == str)
			return pos;
		p = p->next;
	}
	cout << "没有找到" << endl;
	return -1;
}
//插入(头插法)
void InsertHead(NodeHead & head, const string str)
{
	//1.创建一个节点
	Node* newnode = new Node;
	newnode->next = NULL;
	newnode->name = str;
	//2.链接先链接head尾部
	newnode->next = head;
	head= newnode;
}
//显示所有链表元素
void ShowAll(NodeHead & head)
{
	NodeHead p = head;
	while (p)
	{
		cout << p->name << "->";
		p = p->next;
	}
	cout << "NULL" << endl;
}
//在指定位置插入
void Insert_pos(NodeHead & head, int pos, const string str)
{
	//1.创建一个节点
	Node* newnode = new Node;
	newnode->name = str;
	newnode->next = NULL;
	NodeHead p = head;
	//2.遍历
	for (int i = 0; i < pos; i++)
	{
		if (p == NULL)
		{
			cout << "位置超出范围" << endl;
			return;
		}
		p = p->next;
	}
	//3.链接
	newnode->next = p->next;
	p->next = newnode;
	
}
//删除指定位置的节点
void DelNode(NodeHead & head, int pos)
{
	//1.遍历到前一个节点
	NodeHead p = head;
	for (int i = 0; i < pos-1; i++)
	{
		if (p == NULL)
		{
			cout << "位置超出范围" << endl;
			return;
		}
		p = p->next;
	}
	//2.需要一个临时节点保存
	Node* temp = p->next;//要释放的目标节点使p->next
	//3.链接
	p->next = p->next->next;
	//4.释放
	delete temp;
}
//获取链表长度
int GetListLenght(NodeHead & head)
{
	NodeHead p = head;
	int num = 0;
	while (p)
	{
		num++;
		p = p->next;
	}
	return num;
}
