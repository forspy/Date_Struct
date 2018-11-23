#include "DoubLinked List.h"
#include<iostream>
//���캯��
DoubList::DoubList()
{
	m_head = new Node;
	m_head->piror = nullptr;
	m_head->next = nullptr;
}
//��������destroy
DoubList::~DoubList()
{
	Node* p = m_head;
	Node* temp;
	while (p)
	{
		temp = p;
		cout << "�ͷ�" << p->name << " ";
		p = p->next;
		delete temp;
	}
	cout << endl;
}
//����һ���ڵ�
Node * DoubList::CreatNode(const string& str)
{
	Node* newnode = new Node;
	newnode->piror = nullptr;
	newnode->name = str;
	newnode->next = nullptr;
	return newnode;
}
//ͷ�巨����һ���ڵ�
void DoubList::InsertHead(const string& str)
{
	Node* newnode = CreatNode(str);
	//���������1�����Ͻڵ��ֻ��ͷ�ڵ�
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
//��ʾ���нڵ�
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
//��ʾ������
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
//ָ��λ�ò���ڵ�
void DoubList::InsertPos(const string& str,int pos)
{
	Node* newnode = CreatNode(str);
	Node* p = m_head;
	for (int i = 0; i < pos; i++)
	{
		p = p->next;
		if (p == NULL)
		{
			cout << "posλ�ó�������Χ" << endl;
			return;
		}
	}
	//����β���Ͳ����м�������
	//1.�����м�
	if (p->next)//ֻҪpָ���������һ���ڵ��ǰһ���ڵ����
	{
		//��m_head������
		newnode->next = p->next;
		p->next->piror = newnode;

		newnode->piror = p;
		p->next = newnode;
	}
	//����β������p���������һ���ڵ�
	else
	{
		newnode->next = p->next;

		newnode->piror = p;
		p->next = newnode;
	}
}
//ָ��λ��ɾ���ڵ�
void DoubList::DelNode(int pos)
{
	Node* p = m_head;
	Node* temp;
	for (int i = 0; i < pos; i++)
	{
		p = p->next;
		if (p == NULL)
		{
			cout << "posλ�ó�������Χ" << endl;
			return;
		}
	}
	//1.����������У�p���ڵ����������ڵ�֮ǰ
	if (p->next->next)
	{
		temp = p->next;//��һ����ʱָ�뱣��Ҫɾ���ڵ�ĵ�ַ
		p->next = p->next->next;
		p->next->piror = p;
		delete temp;
	}
	else if (p->next)//p���ڵ����ڶ����ڵ�֮ǰ�����������ڶ���
	{
		temp = p->next;
		p->next = nullptr;
		delete temp;
	}
	//else return;//p�������һ���ڵ��ϣ�������һ���ڵ��Ϊ�ղ����ͷ�

}
//�ҵ�ָ��λ�õĽڵ���Ϣ
string  DoubList::FindNode(int pos)
{
	Node* p = m_head;
	for (int i = 0; i < pos; i++)
	{
		p = p->next;
		if (p = nullptr)
		{
			cout << "pos��������Χ" << endl;
			return "NULL";
		}
	}
	return p->next->name;
}
//�ı�ڵ���Ϣ
void DoubList::ChangeNode(int pos, const string & str)
{
	Node* p = m_head;
	for (int i = 0; i < pos; i++)
	{
		p = p->next;
		if (p == nullptr)//ע������Ҫд== ����д=
		{
			cout << "pos��������Χ" << endl;
			return;
		}
	}
	p->next->name = str;
}
