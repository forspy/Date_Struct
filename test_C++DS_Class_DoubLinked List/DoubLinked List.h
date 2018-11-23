#pragma once
//双向链表类
#include<string>
using namespace std;
class Node
{
public:
	Node* piror;//前指针
	string name;
	Node* next;//后指针
};
//包含关系,has-a 链表里有节点
//双向链表
class DoubList
{
public:
	DoubList();
	~DoubList();
	Node* CreatNode(const string& str);//创造一个节点
	void InsertHead(const string& str);//头插法插入一个节点
	void ShowAll();//显示所有节点
	int ShowLength();//显示链表长度
	void InsertPos(const string& str,int pos);//指定位置插入节点
	void DelNode(int pos);//指定位置删除节点
	string FindNode(int pos);//找到指定位置的节点信息
	void ChangeNode(int pos, const string& str);//改变节点信息
private:
	Node* m_head;
};
