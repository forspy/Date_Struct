#pragma once
//节点：数据域+指针域
//链表：链式存储结构
/*
节点只有一个指针域的链表，称为单链表
有两个指针域的链表，称为双链表
首尾相接的链表成为循环链表
*/
//有头节点单链表：头指针head指向单链表的第一个节点，即头节点 数据域内只放空/表长等信息，并且头节点不计入链表长度值
//无头节点单链表：头指针head指向单链表的第一个节点，即信息节点
//有头节点的时候，头节点的指针域指针指向NULL就是空表
//无头节点的时候，头指针head直接指向NULL就是空表
//
//链表的特点，节点在储存器中的位置是任意的，通过节点指针域的指针相连
/*
优点：
数据元素（节点）可以自由扩充
插入删除等操作不必移动数据，只需修改链接指针，效率高
*/

/*
单链表缺点：只能顺序存储，一个连一个，访问/查找也是一个连一个（后面的hash表能解决一部分这种问题）
*/
/*
写一下我不太喜欢的typedef：
typedef struct LNode{
 ElemType data;
 struct Lnode* next;
}LNode,*LinkList;
表示把这个结构体LNode重命名为LNode，和*LinkList（*LinkList为Lnode类型的指针） LNode* p（我还是喜欢这么写） 等价于LinkList p
*/
#include<string>
using namespace std;
//无头节点单链表
//节点
struct Node
{
	string name;
	Node* next;
};
typedef Node* NodeHead;//自定义一个头指针类型（Node*）使代码结构更加清晰

//判断链表是否为空
bool IsEmpty(NodeHead& head);
//销毁一个链表（释放内存）
void destroy(NodeHead& head);
//求表长
int ListLength(NodeHead& head);
//查找链表中的第n个元素
string ListFind(NodeHead& head,int n);
//查找链表中的某个元素所在的位置
int ListFind_pos(NodeHead& head,const string str);
//插入一个节点(头插法)
void InsertHead(NodeHead& head, const string str);
//显示所有链表元素
void ShowAll(NodeHead& head);
//在指定位置插入
void Insert_pos(NodeHead& head, int pos, const string str);
//删除指定位置的节点
void DelNode(NodeHead& head, int pos);
//获取链表长度
int GetListLenght(NodeHead& head);