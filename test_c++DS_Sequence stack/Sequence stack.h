#pragma once
struct SqListStack
{
private:
	int* base;//ջ��ָ��
	int* top;//ջ��ָ��
	int StackSize;//ջ��ʹ�õ��������
public:
	bool IsEmpty();//�ж�ջ��
	bool IsFull();//�ж�ջ��
	void Push(int data);//ѹ��
	int Pop();//����
	void StackClear();//���ջ�ڵ�����Ԫ��
	void DestroyStack();//�ͷ�����ջ��ռ�õĿռ�
	SqListStack(int Size=100);
};