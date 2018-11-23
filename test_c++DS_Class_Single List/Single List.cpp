#include "Single List.h"
#include<iostream>
//���캯��
SingleList::SingleList()
{
	m_head = new Node;
	m_head->next = nullptr;
}
//��������destroy
SingleList::~SingleList()
{
	Node* p = m_head;
	Node* temp;
	while (p)//��ͷ�ڵ㿪ʼ�ͷ�
	{
		temp = p;
		cout << "�ͷ�" << p->name << " ";
		p = p->next;
		delete temp;
	}
	cout << endl;
}
//����һ���ڵ�
Node* SingleList::CreatNode(const string str)
{
	Node* newnode = new Node;
	newnode->name = str;
	newnode->next = nullptr;
	return newnode;
}
//ͷ�巨
void SingleList::InsertHead(const string str)
{
	Node* newnode = CreatNode(str);
	newnode->next = m_head->next;
	m_head->next = newnode;//ͷ�ڵ��nextָ��newnode
}
//��ʾ���нڵ�
void SingleList::ShowAll()
{
	Node* p = m_head;
	p = p->next;//�ƶ�����һ���ڵ�
	while (p)
	{
		cout << p->name << "->";
		p = p->next;
	}
	cout << "NILL" << endl;
}
//��ָ��λ�ò���ڵ�
void SingleList::InsertPos(const string str, int position)
{
	Node* newnode = CreatNode(str);
	Node* p = m_head;
	for (int i = 0; i < position; i++)
	{
		p = p->next;
	}
	//����һ��һ���ڵ㶼û���ƶ������
	newnode->next = p->next;
	p->next = newnode;
}
//ָ��λ��ɾ��һ���ڵ�
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
//����ָ��λ�õĽڵ�
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
