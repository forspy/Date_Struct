#include "Single list.h"
#include<iostream>
using namespace std;
//��ʼ��һ���ڵ�
//��Ϊ��ʹ����ͷ�ڵ�ģʽ����ֻ��Ҫ��ͷ�ڵ��ʼ��ΪNULL
//�ж������Ƿ�Ϊ��
bool IsEmpty(NodeHead & head)
{
	return head->next == NULL;//�շ���true
}
//����һ�������ͷ��ڴ棩
void destroy(NodeHead & head)
{
	while (head)//����нڵ��ѭ��
	{
		Node* temp = head;//��Ҫ����һ����ʱָ��ȥ����node
		head = head->next;//��ͷָ��ȥ����
		delete temp;
	}
}
//���
int ListLength(NodeHead & head)
{
	NodeHead p = head;//����һ��ָ��Pȥ��������
	int num=0;//��
	p = p->next;//��ָ���һ���ڵ�
	while (p)
	{
		p = p->next;
		num++;
	}
	return num;
}
//���������еĵ�n��Ԫ��(n��0��ʼ)
string ListFind(NodeHead & head,int n)
{
	NodeHead p = head;
	for (int i = 0; i < n; i++)
	{
		if (p == NULL)
		{
			cout << "���ҵ�λ�ó�������Χ" << endl;
			return "ERROR";
		}
		p = p->next;
	}
	return p->name;
}
//���������е�ĳ��Ԫ�����ڵ�λ��
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
	cout << "û���ҵ�" << endl;
	return -1;
}
//����(ͷ�巨)
void InsertHead(NodeHead & head, const string str)
{
	//1.����һ���ڵ�
	Node* newnode = new Node;
	newnode->next = NULL;
	newnode->name = str;
	//2.����������headβ��
	newnode->next = head;
	head= newnode;
}
//��ʾ��������Ԫ��
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
//��ָ��λ�ò���
void Insert_pos(NodeHead & head, int pos, const string str)
{
	//1.����һ���ڵ�
	Node* newnode = new Node;
	newnode->name = str;
	newnode->next = NULL;
	NodeHead p = head;
	//2.����
	for (int i = 0; i < pos; i++)
	{
		if (p == NULL)
		{
			cout << "λ�ó�����Χ" << endl;
			return;
		}
		p = p->next;
	}
	//3.����
	newnode->next = p->next;
	p->next = newnode;
	
}
//ɾ��ָ��λ�õĽڵ�
void DelNode(NodeHead & head, int pos)
{
	//1.������ǰһ���ڵ�
	NodeHead p = head;
	for (int i = 0; i < pos-1; i++)
	{
		if (p == NULL)
		{
			cout << "λ�ó�����Χ" << endl;
			return;
		}
		p = p->next;
	}
	//2.��Ҫһ����ʱ�ڵ㱣��
	Node* temp = p->next;//Ҫ�ͷŵ�Ŀ��ڵ�ʹp->next
	//3.����
	p->next = p->next->next;
	//4.�ͷ�
	delete temp;
}
//��ȡ������
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
