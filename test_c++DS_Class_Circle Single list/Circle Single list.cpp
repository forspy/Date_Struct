#include"Circle Single list.h"
#include<iostream>

CirSingleList::CirSingleList()
{
	//带头节点模式,在循环链表中的好处多多啊
	m_head = new Node;
	m_head->next = m_head;//因为是循环链表所以头节点一开始指向自己
	m_rear = m_head;
}
//析构函数释放整个链表destroy
CirSingleList::~CirSingleList()
{
	Node* p = m_head;
	p = p->next;//到达第一个节点
	Node* temp;//临时指针
	while (p != m_head)
	{
		temp = p;
		cout << "释放了" << p->m_name << " ";
		p = p->next;
		delete temp;
	}
	delete p;//最后释放头节点
}
//创建一个节点
Node * CirSingleList::CreatNode()
{
	Node* newnode = new Node;
	file >> newnode->m_ISBN >> newnode->m_name >> newnode->m_price;
	newnode->next = NULL;
	return newnode;
}
//重载一个创造节点的方法
Node * CirSingleList::CreatNode(const string ISBN, const string name, double price)
{
	Node* newnode = new Node;
	newnode->m_ISBN = ISBN;
	newnode->m_name = name;
	newnode->m_price = price;
	return newnode;
}
//创建指定长度的链表,从文件导入信息
void CirSingleList::ImportDataList()
{
	Node* p = m_head;//p指针是一个可移动的指针
	Node* newnode;
	file.open("source.txt");
	while(!file.eof())//遍历整个文件
	{
		newnode = CreatNode();
		//循环链表采用尾部插入的方法
		newnode->next = m_head;
		p->next = newnode;
		p = newnode;//将临时指针拨动到新节点位置
		m_rear = newnode;//顺表将尾指针指向新节点
	}
	file.close();
}
//显示所有节点
void CirSingleList::ShowAll()
{
	Node* p = m_head;
	//因为有头节点所以操作起来顺畅点
	p = p->next;//从头节点的下一个位置开始遍历
	while (p != m_head)
	{
		cout << p->m_ISBN << " " << p->m_name << " " << p->m_price << "->" << endl;
		p = p->next;
	}
}
//尾部插入节点
void CirSingleList::InsertBack(const string ISBN, const string name, double price)
{
	Node* newnode = CreatNode(ISBN, name, price);
	newnode->next = m_head;
	m_rear->next = newnode;
	m_rear = newnode;
}
//头部插入节点
void CirSingleList::InsertHead(const string ISBN, const string name, double price)
{
	Node* newnode = CreatNode(ISBN, name, price);
	newnode->next = m_head->next;//在头节点后面插入
	m_head->next = newnode;
}
//指定位置插入节点
void CirSingleList::InsertPos(const string ISBN, const string name, double price,int position)
{
	Node* p = m_head;
	for (int i = 0; i < position; i++)
	{
		p = p->next;
	}
	Node* newnode = CreatNode(ISBN, name, price);
	newnode->next = p->next;
	p->next = newnode;
}
//删除一个节点
void CirSingleList::DelNode(int position)
{
	Node* p = m_head;
	for (int i = 0; i < position; i++)
	{
		p = p->next;
	}
	//这样是到指定位置的前一个节点
	Node* temp = p->next;//使用一个临时指针保存
	p->next = p->next->next;
	delete temp;
}
