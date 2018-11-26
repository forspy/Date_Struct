//栈：只能在表的一段（栈顶）进行插入和删除运算的线性表
//存储结构：顺序栈或链式栈
//线性表和链表最明显的区别是线性表在一开始就初始化开辟一串空间，链表是一个节点一个节点的开辟链接
//
#include"Sequence stack.h"
#include<iostream>
using namespace std;
int main()
{
	const int num = 3;
	SqListStack List(100);//顺序表栈
	for (int i = 0; i < num; i++)
	{
		List.Push(i);
	}
	for (int i = 0; i < num; i++)
	{
		cout << List.Pop() << endl;
	}
}