#pragma once
//链式队列
struct Node
{
	int data;
	Node* next;
};
class Queue
{
private:
	Node* head;//头指针
	Node* rear;//尾指针
public:
	Node* CreatNode(int d);
	bool IsEmpty();//
	void Enqueue(int d);
	int Dequeue();//返回弹出的节点中的数据
	void ShowAll();
	int GetFirst();//获取队首的节点信息
	int GetListLength();//获取队列长度
	Queue();
};
//链表队列相对于顺序表队列的优势在于，链表队列的弹出就是释放，而顺序表队列的弹出并没有释放，会造成队列内的出现空的存储空间
//而头指针的位置却在不断变化，造成队列可使用的空间越来越小（因为顺序队列的空间是固定的，每弹出一次就少一个），所以顺序队列
//需要使用循环队列的方式，(head+1)%Maxsize=rear;即尾部结向头部