#include"Circle Single list.h"
#include<iostream>

CirSingleList::CirSingleList()
{
	//��ͷ�ڵ�ģʽ,��ѭ�������еĺô���డ
	m_head = new Node;
	m_head->next = m_head;//��Ϊ��ѭ����������ͷ�ڵ�һ��ʼָ���Լ�
	m_rear = m_head;
}
//���������ͷ���������destroy
CirSingleList::~CirSingleList()
{
	Node* p = m_head;
	p = p->next;//�����һ���ڵ�
	Node* temp;//��ʱָ��
	while (p != m_head)
	{
		temp = p;
		cout << "�ͷ���" << p->m_name << " ";
		p = p->next;
		delete temp;
	}
	delete p;//����ͷ�ͷ�ڵ�
}
//����һ���ڵ�
Node * CirSingleList::CreatNode()
{
	Node* newnode = new Node;
	file >> newnode->m_ISBN >> newnode->m_name >> newnode->m_price;
	newnode->next = NULL;
	return newnode;
}
//����һ������ڵ�ķ���
Node * CirSingleList::CreatNode(const string ISBN, const string name, double price)
{
	Node* newnode = new Node;
	newnode->m_ISBN = ISBN;
	newnode->m_name = name;
	newnode->m_price = price;
	return newnode;
}
//����ָ�����ȵ�����,���ļ�������Ϣ
void CirSingleList::ImportDataList()
{
	Node* p = m_head;//pָ����һ�����ƶ���ָ��
	Node* newnode;
	file.open("source.txt");
	while(!file.eof())//���������ļ�
	{
		newnode = CreatNode();
		//ѭ���������β������ķ���
		newnode->next = m_head;
		p->next = newnode;
		p = newnode;//����ʱָ�벦�����½ڵ�λ��
		m_rear = newnode;//˳��βָ��ָ���½ڵ�
	}
	file.close();
}
//��ʾ���нڵ�
void CirSingleList::ShowAll()
{
	Node* p = m_head;
	//��Ϊ��ͷ�ڵ����Բ�������˳����
	p = p->next;//��ͷ�ڵ����һ��λ�ÿ�ʼ����
	while (p != m_head)
	{
		cout << p->m_ISBN << " " << p->m_name << " " << p->m_price << "->" << endl;
		p = p->next;
	}
}
//β������ڵ�
void CirSingleList::InsertBack(const string ISBN, const string name, double price)
{
	Node* newnode = CreatNode(ISBN, name, price);
	newnode->next = m_head;
	m_rear->next = newnode;
	m_rear = newnode;
}
//ͷ������ڵ�
void CirSingleList::InsertHead(const string ISBN, const string name, double price)
{
	Node* newnode = CreatNode(ISBN, name, price);
	newnode->next = m_head->next;//��ͷ�ڵ�������
	m_head->next = newnode;
}
//ָ��λ�ò���ڵ�
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
//ɾ��һ���ڵ�
void CirSingleList::DelNode(int position)
{
	Node* p = m_head;
	for (int i = 0; i < position; i++)
	{
		p = p->next;
	}
	//�����ǵ�ָ��λ�õ�ǰһ���ڵ�
	Node* temp = p->next;//ʹ��һ����ʱָ�뱣��
	p->next = p->next->next;
	delete temp;
}
