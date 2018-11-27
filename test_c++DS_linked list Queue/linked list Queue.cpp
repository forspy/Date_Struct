#include "linked list Queue.h"
#include<iostream>
using namespace std;
Node* Queue::CreatNode(int d)
{
	Node* newnode = new Node;
	//��ͷ�ڵ�ĺô���࣬������ֻ��һ���ڵ��ʱ��ͷָ�벻��Ҫ�Ƶ���ʼ��ָ��ͷ�ڵ�
	newnode->next = nullptr;
	newnode->data = d;
	return newnode;
}
bool Queue::IsEmpty()
{
	return head == rear;
}
//�����
void Queue::Enqueue(int d)
{
	Node* newnode = CreatNode(d);
	if (IsEmpty())
	{
		newnode->next = nullptr;
		head->next = newnode;
		rear = newnode;
	}
	else
	{
		newnode->next = nullptr;
		rear->next = newnode;
		rear = newnode;
	}
}
//������
int Queue::Dequeue()
{
	if (IsEmpty())
	{
		cout << "����Ϊ�գ����ܵ�������ڵ�" << endl;
		return -1;
	}
	Node* temp;
	temp = head->next;
	head->next = head->next->next;
	int temp_data=temp->data;
	//������һ���ڵ�Ҳ����������βָ��ָ��ͷ�ڵ�
	if (head->next == nullptr)//������Ҫʹ��ͷ��ָ��ȥ�жϣ���Ϊβ��ָ��û������
	{
		rear = head;
	}
	delete temp;
	return temp_data;
}
void Queue::ShowAll()
{
	Node* p = head;
	p = p->next;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
int Queue::GetFirst()
{
	if(!IsEmpty())
	   return head->next->data;
	else
	{
		cout << "����Ϊ��" << endl;
		return -1;
	}
}
int Queue::GetListLength()
{
	Node* p = head;
	if (IsEmpty())
	{
		cout << "�ն���" << endl;
		return -1;
	}
	else
	{
		p = p->next;
		int num = 0;
		while (p)
		{
			num++;
			p = p->next;
		}
		return num;
	}
}
//���캯��
Queue::Queue()
{
	head = new Node;//��ͷ�ڵ�ģʽ
	head->next = nullptr;
	rear = head;
}
