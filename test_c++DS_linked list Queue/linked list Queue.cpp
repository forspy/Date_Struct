#include "linked list Queue.h"
#include<iostream>
using namespace std;
Node* Queue::CreatNode(int d)
{
	Node* newnode = new Node;
	//有头节点的好处多多，首先是只有一个节点的时候头指针不需要移到，始终指向头节点
	newnode->next = nullptr;
	newnode->data = d;
	return newnode;
}
bool Queue::IsEmpty()
{
	return head == rear;
}
//入队列
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
//出队列
int Queue::Dequeue()
{
	if (IsEmpty())
	{
		cout << "队列为空，不能弹出更多节点" << endl;
		return -1;
	}
	Node* temp;
	temp = head->next;
	head->next = head->next->next;
	int temp_data=temp->data;
	//如果最后一个节点也被弹出，则尾指针指向头节点
	if (head->next == nullptr)//这里需要使用头部指针去判断，因为尾部指针没有重置
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
		cout << "队列为空" << endl;
		return -1;
	}
}
int Queue::GetListLength()
{
	Node* p = head;
	if (IsEmpty())
	{
		cout << "空队列" << endl;
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
//构造函数
Queue::Queue()
{
	head = new Node;//有头节点模式
	head->next = nullptr;
	rear = head;
}
