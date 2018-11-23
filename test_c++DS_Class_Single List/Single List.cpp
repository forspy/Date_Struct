#include "Single List.h"
#include<iostream>
//构造函数
SingleList::SingleList()
{
	m_head = new Node;
	m_head->next = nullptr;
}
//析构函数destroy
SingleList::~SingleList()
{
	Node* p = m_head;
	Node* temp;
	while (p)//从头节点开始释放
	{
		temp = p;
		cout << "释放" << p->name << " ";
		p = p->next;
		delete temp;
	}
	cout << endl;
}
//创建一个节点
Node* SingleList::CreatNode(const string str)
{
	Node* newnode = new Node;
	newnode->name = str;
	newnode->next = nullptr;
	return newnode;
}
//头插法
void SingleList::InsertHead(const string str)
{
	Node* newnode = CreatNode(str);
	newnode->next = m_head->next;
	m_head->next = newnode;//头节点的next指向newnode
}
//显示所有节点
void SingleList::ShowAll()
{
	Node* p = m_head;
	p = p->next;//移动到第一个节点
	while (p)
	{
		cout << p->name << "->";
		p = p->next;
	}
	cout << "NILL" << endl;
}
//在指定位置插入节点
void SingleList::InsertPos(const string str, int position)
{
	Node* newnode = CreatNode(str);
	Node* p = m_head;
	for (int i = 0; i < position; i++)
	{
		p = p->next;
	}
	//想象一下一个节点都没有移动的情况
	newnode->next = p->next;
	p->next = newnode;
}
//指定位置删除一个节点
void SingleList::DelNodePos(int pos)
{
	Node* p = m_head;
	Node* temp;
	for (int i = 0; i < pos; i++)
	{
		p = p->next;
	}
	temp = p->next;
	p->next = p->next->next;
	delete temp;
}
//查找指定位置的节点
string & SingleList::FindNodePos(int pos)
{
	Node* p = m_head;
	for (int i = 0; i < pos; i++)
	{
		p = p->next;
	}
	return p->next->name;
}

void SingleList::ChangeNodePos(int pos,const string str)
{
	Node* p = m_head;
	for (int i = 0; i < pos; i++)
	{
		p = p->next;
	}
	p->next->name = str;
}
