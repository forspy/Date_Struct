#include "Linked List stack.h"
#include<iostream>
using namespace std;
//���캯��
LinkedListStack::LinkedListStack()
{
	//��Ϊ����Ҫͷ�ڵ�
	Base = Top = nullptr;
}
//�ͷ�����ջdestroy
LinkedListStack::~LinkedListStack()
{
	Node* p = Top;
	Node* temp;
	while (p)
	{
		temp = p;
		p = p->next;
		delete temp;
	}
	cout << "�ͷ�����������ջ" << endl;
}
//����һ���µĽڵ�
Node * LinkedListStack::CreatNode(int d)
{
	Node* newnode = new Node;
	newnode->data = d;
	newnode->next = nullptr;
	return newnode;
}
bool LinkedListStack::IsEmpty()
{
	return Base == nullptr;
}
//topָ��Ҫ����ĵط�
void LinkedListStack::push(int d)
{
	Node* newnode = CreatNode(d);
	if (IsEmpty())
	{
		Base = newnode;//ջ��ָ��ָ���һ���ڵ�
		Top = newnode;//ջ��ָ��Ҳָ���һ���ڵ�
	}
	else
	{
		newnode->next = Top;
		Top = newnode;
	}
}
//����һ���ڵ�,�����һ�㲻ʹ������ջ��һ��ԭ����Ҫ����һ��Node��Node��Ҫ��main���汻�ͷ�
Node * LinkedListStack::pop()
{
	Node* temp;
	if (!IsEmpty())
	{
		temp = Top;
		Top = Top->next;
	}
	return temp;
}
//��ʾ���нڵ�
void LinkedListStack::ShowAll()
{
	Node* p = Top;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
//��ʾջ�ڳ���
void LinkedListStack::ShowLength()
{
	Node* p = Top;
	int num = 0;
	while (p)
	{
		p = p->next;
		num++;
	}
	cout << "һ����" << num << "ջ�ڽڵ�" << endl;
}
