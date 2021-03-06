#include "ordered List merge.h"
#include<iostream>
//构造函数
SingleList::SingleList()
{
	//头指针均指向头节点尾指针指向头节点的next
	m_head = new Node;
	m_head->next = nullptr;
	m_rear = m_head;
	m_rear= nullptr;
}
//析构函数destroy
//SingleList::~SingleList()
//{
//	Node* p = m_head;
//	Node* temp;
//	while (p)//从头节点开始释放
//	{
//		temp = p;
//		cout << "释放" << p->number << " ";
//		p = p->next;
//		delete temp;
//	}
//	cout << endl;
//}
//创建一个节点
Node* SingleList::CreatNode(double c, int e)
{
	Node* newnode = new Node;
	newnode->expn = e;
	newnode->coffn = c;
	newnode->next = nullptr;
	return newnode;
}
//头插法（不影响尾指针）
void SingleList::InsertHead(double c, int e)
{
	Node* newnode = CreatNode(c,e);
	//--插入第一个节点的情况时需要把尾指针移向该节点，以后头插法就影响不到尾指针了
	if (m_head->next == nullptr)
		m_rear = newnode;
	//----
	newnode->next = m_head->next;
	m_head->next = newnode;//头节点的next指向newnode
	
}
//尾插法
void SingleList::InsertBack(double c, int e)
{
	Node* newnode = CreatNode(c,e);
	//尾插法需要考虑有没有第一个节点
	if (m_rear == nullptr)
	{
		newnode->next = nullptr;
		m_head->next = newnode;
		m_rear = newnode;
	}
	else
	{
		newnode->next = nullptr;
		m_rear->next = newnode;
		m_rear = newnode;
	}
}

//显示所有节点
void SingleList::ShowAll()
{
	Node* p = m_head;
	p = p->next;//移动到第一个节点
	while (p)
	{
		if (p->expn)
		{
			cout << p->coffn << "x^" << p->expn << "+";
			p = p->next;
		}
		else
		{
			cout << p->coffn << "+";
			p = p->next;
		}
	}
	cout << "NULL" << endl;
}
//在指定位置插入节点（需要考虑超出链表长度的情况）
void SingleList::InsertPos(double c, int e, int position)
{
	Node* newnode = CreatNode(c,e);
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
int SingleList::FindNodePos(int pos)
{
	Node* p = m_head;
	for (int i = 0; i < pos; i++)
	{
		p = p->next;
	}
	return p->next->expn;
}
//改变节点元素信息
void SingleList::ChangeNodePos(int pos, double c, int e)
{
	Node* p = m_head;
	for (int i = 0; i < pos; i++)
	{
		p = p->next;
	}
	p->next->expn = e;
}
//有序线性表合并技术（升序 如1，2，4...）
//A(x)=7+3x+9x^8+5x^17;
//B(x)=8x+22x^7-9x^8;
//---------------------------
void MergeList(SingleList & lista, SingleList & listb, SingleList & listc)
{
	//首先定义指向三个表的指针pa,pb,pc（合并到新的链表listc）
	Node* pa = lista.GetHead()->next;//pa指向lisa的第一个节点
	Node* pb = listb.GetHead()->next;//pb指向lisb的第一个节点
	Node* pc = listc.GetHead();//pc暂时指向listc的头节点
	//注意listc不是新开的一条链表，listc是在lista和listb中选择元素链接
	while (pa&&pb)//两个表都非空
	{
		if (pa->expn == pb->expn)//如果两个多项式系数相等，则开始相加
		{
			pa->coffn += pb->coffn;
			pc->next = pa;
			pc = pa;
			pa = pa->next;
			pb = pb->next;
		}
		else if (pa->expn <= pb->expn)
		{
			pc->next = pa;//如果pa指向的节点里面的元素值小于pb节点，pc的next链接pa节点
			pc = pa;//pc指针指向pa节点
			pa = pa->next;
		}
		else if(pa->expn>pb->expn)
		{
			pc->next = pb;//如果pb指向的节点里面的元素值小于pa节点，pc的next链接pb节点
			pc = pb;//pc指针指向pb节点
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;//这个三目说明如果pc->next=pa,这里pa如果为NULL就让pc->next=pb，注意是=而不是==
	//delete listb.GetHead();
	//去掉listc中的0系数项
	Node* p = listc.GetHead();
	Node* temp;
	while (p->next)
	{
		if (p->next->coffn == 0)
		{
			temp = p->next;
			p->next = p->next->next;
			delete temp;
			//p = p->next;//注意这里由于删了一个节点所以不用跳了
		}
		else
		{
			p = p->next;
		}
	}
}
