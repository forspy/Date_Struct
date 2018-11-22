//以下为测试方法
/*
#include<iostream>
using namespace std;
struct Node
{
	string name;
	Node* next;
};

//方式1.封装node* head
struct NodeHead
{
	Node* head;
	int num;//方式1的好处是可以携带链表长度信息，在插入或者删除的时候不用去遍历链表
};
void Init(NodeHead& nodehead)
{
	nodehead.head = new Node;
	nodehead.head->next = NULL;
}
//方式2：传入Node* head;的地址&head，用二级指针去接改变指针指向
//好处是用最基本的方式展现头指针是如何被修改的
void Init(Node** headptr)
{
	*headptr = new Node;
	(*headptr)->next = NULL;
}
//方式3：typedef
//自定义一个头指针类型（Node*）使代码结构更加清晰
typedef Node* NodeList;
void Init(NodeList& head)
{
	head = new Node;
	head->next = NULL;
}
*/