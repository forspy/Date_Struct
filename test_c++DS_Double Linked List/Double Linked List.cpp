#include "Double Linked List.h"

//头部插入节点
void InsertHead(DoubHeadNode & head,DoubRearNode& rear,const string& str)
{
	DoubNode* newnode = CreatNewNode(str);
	if (head)//如果有节点存在
	{
		newnode->next = head;
		head->prior = newnode;
		newnode->prior = NULL;
		head = newnode;
	}
	else//如果没有节点
	{
		newnode->next = NULL;
		newnode->prior = NULL;
		head = rear = newnode;
	}
}
//尾部插入一个节点
void InsertRear(DoubHeadNode & head, DoubRearNode & rear, const string & str)
{
	DoubNode* newnode = CreatNewNode(str);
	if (rear)
	{
		//尾节点先从prior接起
		newnode->prior = rear;
		rear->next = newnode;
		newnode->next = NULL;
		rear = newnode;
	}
	else//如果没有节点
	{
		newnode->next = NULL;
		newnode->prior = NULL;
		head = rear = newnode;
	}
}
//指定位置插入
void InsertPos(DoubHeadNode & head, int pos, const string & str)
{
	//从头开始遍历
	DoubNode* newnode = CreatNewNode(str);
	DoubHeadNode p = head;
	for (int i = 0; i < pos; i++)
	{
		p = p->next;
	}
	//注意顺序,先完成与前面节点的链接
	newnode->prior = p->prior;//先链接前面，这样就不会影响到P
	p->prior->next = newnode;
	//再链接后面
	newnode->next = p;
	p->prior = newnode;
}
//指定位置删除，删除指定位置的节点
void DelPos(DoubHeadNode & head, int pos)
{
	DoubHeadNode p = head;
	for (int i = 0; i < pos; i++)
	{
		p = p->next;
	}
	DoubNode* temp = p;//先拿一个temp指针保存p指向节点的位置
	p->next->prior = p->prior;//p后面的节点的prior链接p前面的节点
	p->prior->next = p->next;//p前面的节点的next链接p后面的节点
	delete temp;//释放临时指针
}
// 查找指定位置的节点信息
void FindDoubList(DoubHeadNode & head, int pos)
{
	DoubHeadNode p = head;
	for (int i = 0; i < pos; i++)
	{
		p = p->next;
	}
	cout << p->name << endl;
}
//改变指定位置的节点信息
void ChangeNode(DoubHeadNode & head, int pos,const string& str)
{
	DoubHeadNode p = head;
	for (int i = 0; i < pos; i++)
	{
		p = p->next;
	}
	p->name = str;
}
//创建一个新节点
DoubNode * CreatNewNode(const string& str)
{
	DoubNode* newnode = new DoubNode;
	newnode->prior = NULL;
	newnode->name = str;
	newnode->next = NULL;
	return newnode;
}
//显示所有节点
void ShowAll(DoubHeadNode & head)
{
	DoubHeadNode p = head;
	while (p)
	{
		cout << p->name << "<->";
		p = p->next;
	}
	cout << "NULL" << endl;
}
