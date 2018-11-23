#include "DoubLinked List.h"
#include<iostream>
//构造函数
DoubList::DoubList()
{
	m_head = new Node;
	m_head->piror = nullptr;
	m_head->next = nullptr;
}
//析构函数destroy
DoubList::~DoubList()
{
	Node* p = m_head;
	Node* temp;
	while (p)
	{
		temp = p;
		cout << "释放" << p->name << " ";
		p = p->next;
		delete temp;
	}
	cout << endl;
}
//创造一个节点
Node * DoubList::CreatNode(const string& str)
{
	Node* newnode = new Node;
	newnode->piror = nullptr;
	newnode->name = str;
	newnode->next = nullptr;
	return newnode;
}
//头插法插入一个节点
void DoubList::InsertHead(const string& str)
{
	Node* newnode = CreatNode(str);
	//两种情况有1个以上节点和只有头节点
	if (m_head->next)
	{
		newnode->next = m_head->next;
		m_head->next->piror = newnode;
		newnode->piror = m_head;
		m_head->next = newnode;
	}
	else
	{
		newnode->next = nullptr;

		newnode->piror = m_head;
		m_head->next = newnode;
	}
}
//显示所有节点
void DoubList::ShowAll()
{
	Node* p = m_head;
	p = p->next;
	while (p)
	{
		cout << p->name << "<=>";
		p = p->next;
	}
	cout << "NULL" << endl;
}
//显示链表长度
int DoubList::ShowLength()
{
	Node* p = m_head;
	int length=0;
	p = p->next;
	while (p)
	{
		length++;
		p = p->next;
	}
	return length;
}
//指定位置插入节点
void DoubList::InsertPos(const string& str,int pos)
{
	Node* newnode = CreatNode(str);
	Node* p = m_head;
	for (int i = 0; i < pos; i++)
	{
		p = p->next;
		if (p == NULL)
		{
			cout << "pos位置超出链表范围" << endl;
			return;
		}
	}
	//插在尾部和插在中间有区别
	//1.插在中间
	if (p->next)//只要p指针落在最后一个节点的前一个节点就行
	{
		//从m_head出发的
		newnode->next = p->next;
		p->next->piror = newnode;

		newnode->piror = p;
		p->next = newnode;
	}
	//插在尾部，即p落在了最后一个节点
	else
	{
		newnode->next = p->next;

		newnode->piror = p;
		p->next = newnode;
	}
}
//指定位置删除节点
void DoubList::DelNode(int pos)
{
	Node* p = m_head;
	Node* temp;
	for (int i = 0; i < pos; i++)
	{
		p = p->next;
		if (p == NULL)
		{
			cout << "pos位置超出链表范围" << endl;
			return;
		}
	}
	//1.如果在链表中，p落在倒数第三个节点之前
	if (p->next->next)
	{
		temp = p->next;//用一个临时指针保存要删除节点的地址
		p->next = p->next->next;
		p->next->piror = p;
		delete temp;
	}
	else if (p->next)//p落在倒数第二个节点之前，包括倒数第二个
	{
		temp = p->next;
		p->next = nullptr;
		delete temp;
	}
	//else return;//p落在最后一个节点上，本来下一个节点就为空不用释放

}
//找到指定位置的节点信息
string  DoubList::FindNode(int pos)
{
	Node* p = m_head;
	for (int i = 0; i < pos; i++)
	{
		p = p->next;
		if (p = nullptr)
		{
			cout << "pos超出链表范围" << endl;
			return "NULL";
		}
	}
	return p->next->name;
}
//改变节点信息
void DoubList::ChangeNode(int pos, const string & str)
{
	Node* p = m_head;
	for (int i = 0; i < pos; i++)
	{
		p = p->next;
		if (p == nullptr)//注意这里要写== 不雅写=
		{
			cout << "pos超出链表范围" << endl;
			return;
		}
	}
	p->next->name = str;
}
