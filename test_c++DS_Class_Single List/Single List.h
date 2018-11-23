#pragma once
#include<string>
using namespace std;
class Node
{
	public:
	string name;
	Node* next;
};
//单链表类+头节点模式
class SingleList
{
public:
	SingleList();
	~SingleList();
	Node* CreatNode(const string str);//创建一个节点
	void InsertHead(const string str);//头插法
	void ShowAll();//显示所有节点
	void InsertPos(const string str, int position);//指定位置插入一个节点
	void DelNodePos(int pos);//指定位置删除一个节点
	string& FindNodePos(int pos);//查找指定位置的节点
	void ChangeNodePos(int pos,const string str);//改变指定位置的节点
private:
	Node* m_head;
};