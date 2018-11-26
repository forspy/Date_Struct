#pragma once
using namespace std;
class Node
{
	public:
	int expn;//指数
	double coffn;//系数
	Node* next;
};
//单链表类+头节点模式
class SingleList
{
public:
	SingleList();
	Node* CreatNode(double c,int e);//创建一个节点
	void InsertHead(double c, int e);//头插法
	void InsertBack(double c, int e);//尾插法
	void ShowAll();//显示所有节点
	void InsertPos(double c, int e, int position);//指定位置插入一个节点
	void DelNodePos(int pos);//指定位置删除一个节点
	int FindNodePos(int pos);//查找指定位置的节点
	void ChangeNodePos(int pos, double c, int e);//改变指定位置的节点
	Node* GetHead() { return m_head; }
	Node* GetRear() { return m_rear; }

private:
	Node* m_head;//头指针
	Node* m_rear;//尾指针
};
//有序线性表合并技术（升序 如1，2，4...）
void MergeList(SingleList& listA, SingleList& listb, SingleList& listc);