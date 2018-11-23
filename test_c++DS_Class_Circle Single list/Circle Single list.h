#pragma once
//节点类
#include<string>
#include<fstream>
using namespace std;
//循环链表的好处时可以从任意一个节点出发找到所需节点
class Node
{
public:
	string m_ISBN;//图书编号
	string m_name;//名字
	double m_price;//价格
	Node* next;//指向下一个节点的指针
};
//声明单向循环链表，类的一个好处是：
//因为头指针在类中所以类的所有方法都可以使用头指针，不需要再传入头指针引用了
class CirSingleList
{
public:
	CirSingleList();
	~CirSingleList() ;//析构应该是释放整个链表，等以下写
	Node* CreatNode();//创建一个节点
	Node* CreatNode(const string ISBN, const string name, double price);//重载一个创造节点的方法
	void ImportDataList();//创建指定长度的链表
	void ShowAll();//显示所有节点
	void InsertBack(const string ISBN, const string name, double price);//尾部插入节点
	void InsertHead(const string ISBN, const string name, double price);//头部插入节点
	void InsertPos(const string ISBN, const string name, double price,int position);//指定位置插入节点
	void DelNode(int position);//删除一个节点
private:
	Node* m_head;//声明一个头指针
	Node* m_rear;//声明一个尾指针，方便尾部插入
	fstream file;
};

