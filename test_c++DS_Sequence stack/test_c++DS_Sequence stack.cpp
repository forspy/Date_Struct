//ջ��ֻ���ڱ��һ�Σ�ջ�������в����ɾ����������Ա�
//�洢�ṹ��˳��ջ����ʽջ
//���Ա�����������Ե����������Ա���һ��ʼ�ͳ�ʼ������һ���ռ䣬������һ���ڵ�һ���ڵ�Ŀ�������
//
#include"Sequence stack.h"
#include<iostream>
using namespace std;
int main()
{
	const int num = 3;
	SqListStack List(100);//˳���ջ
	for (int i = 0; i < num; i++)
	{
		List.Push(i);
	}
	for (int i = 0; i < num; i++)
	{
		cout << List.Pop() << endl;
	}
}