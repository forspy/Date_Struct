#pragma once
struct Node
{
	int data;
	Node* next;
};
class LinkedListStack
{
public:
	LinkedListStack();//����Ҫ����ͷ�ڵ���
	~LinkedListStack();//
	Node* CreatNode(int d);
	bool IsEmpty();
	void push(int d);//ѹ��һ���ڵ�
	Node* pop();//����һ���ڵ�
	void ShowAll();//��ʾ���нڵ�
	void ShowLength();//��ʾջ�ڳ���
private:
	Node *Base;//ջ��ָ��
	Node* Top;//ջ��ָ��
};
