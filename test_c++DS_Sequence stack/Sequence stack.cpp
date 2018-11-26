#include "Sequence stack.h"
#include<iostream>
using namespace std;
bool SqListStack::IsEmpty()
{
	return top == base;//ջ�շ���true
}
bool SqListStack::IsFull()
{
	return top==(base+StackSize-1);
}
//ѹ��
void SqListStack::Push(int data)
{
	if (!IsFull())//���û��
	{
		*top = data;
		top++;
	}
	else
	{
		cout << "ջ����,�޷�ѹ��" << endl;
		return;
	}
}
//��������,pop��ʱ��Ҫ�Ȱ�ָ������һλ�ٵ���
int SqListStack::Pop()
{
	if (!IsEmpty())//������ǿ�ջ
	{
		top--;
		int temp = *top;
		return temp;
	}
	else
	{
		cout << "ջΪ�գ��޷���������Ԫ��" << endl;
		return -1;
	}
}
//���ջ�ڵ�����Ԫ��
void SqListStack::StackClear()
{
	top = base;//��ջ��ָ�벦��ջ��
}
//�ͷ�����ջ��ռ�õĿռ�
void SqListStack::DestroyStack()
{
	delete base;
}
//���캯��
SqListStack::SqListStack(int Size)
{
	StackSize = Size;
	base = new int[StackSize];
	top = base;
}
