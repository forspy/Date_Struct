#include "Sequence stack.h"
#include<iostream>
using namespace std;
bool SqListStack::IsEmpty()
{
	return top == base;//栈空返回true
}
bool SqListStack::IsFull()
{
	return top==(base+StackSize-1);
}
//压入
void SqListStack::Push(int data)
{
	if (!IsFull())//如果没满
	{
		*top = data;
		top++;
	}
	else
	{
		cout << "栈满了,无法压入" << endl;
		return;
	}
}
//弹出数据,pop的时候要先把指针下移一位再弹出
int SqListStack::Pop()
{
	if (!IsEmpty())//如果不是空栈
	{
		top--;
		int temp = *top;
		return temp;
	}
	else
	{
		cout << "栈为空，无法弹出更多元素" << endl;
		return -1;
	}
}
//清空栈内的所有元素
void SqListStack::StackClear()
{
	top = base;//把栈顶指针拨到栈底
}
//释放整个栈所占用的空间
void SqListStack::DestroyStack()
{
	delete base;
}
//构造函数
SqListStack::SqListStack(int Size)
{
	StackSize = Size;
	base = new int[StackSize];
	top = base;
}
