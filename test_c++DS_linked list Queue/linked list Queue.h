#pragma once
//��ʽ����
struct Node
{
	int data;
	Node* next;
};
class Queue
{
private:
	Node* head;//ͷָ��
	Node* rear;//βָ��
public:
	Node* CreatNode(int d);
	bool IsEmpty();//
	void Enqueue(int d);
	int Dequeue();//���ص����Ľڵ��е�����
	void ShowAll();
	int GetFirst();//��ȡ���׵Ľڵ���Ϣ
	int GetListLength();//��ȡ���г���
	Queue();
};
//������������˳�����е��������ڣ�������еĵ��������ͷţ���˳�����еĵ�����û���ͷţ�����ɶ����ڵĳ��ֿյĴ洢�ռ�
//��ͷָ���λ��ȴ�ڲ��ϱ仯����ɶ��п�ʹ�õĿռ�Խ��ԽС����Ϊ˳����еĿռ��ǹ̶��ģ�ÿ����һ�ξ���һ����������˳�����
//��Ҫʹ��ѭ�����еķ�ʽ��(head+1)%Maxsize=rear;��β������ͷ��