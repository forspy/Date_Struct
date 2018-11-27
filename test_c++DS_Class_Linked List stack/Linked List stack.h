#pragma once
struct Node
{
	int data;
	Node* next;
};
class LinkedListStack
{
public:
	LinkedListStack();//不需要建立头节点了
	~LinkedListStack();//
	Node* CreatNode(int d);
	bool IsEmpty();
	void push(int d);//压入一个节点
	Node* pop();//弹出一个节点
	void ShowAll();//显示所有节点
	void ShowLength();//显示栈内长度
private:
	Node *Base;//栈底指针
	Node* Top;//栈顶指针
};
