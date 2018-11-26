#pragma once
using namespace std;
class Node
{
	public:
	int expn;//ָ��
	double coffn;//ϵ��
	Node* next;
};
//��������+ͷ�ڵ�ģʽ
class SingleList
{
public:
	SingleList();
	Node* CreatNode(double c,int e);//����һ���ڵ�
	void InsertHead(double c, int e);//ͷ�巨
	void InsertBack(double c, int e);//β�巨
	void ShowAll();//��ʾ���нڵ�
	void InsertPos(double c, int e, int position);//ָ��λ�ò���һ���ڵ�
	void DelNodePos(int pos);//ָ��λ��ɾ��һ���ڵ�
	int FindNodePos(int pos);//����ָ��λ�õĽڵ�
	void ChangeNodePos(int pos, double c, int e);//�ı�ָ��λ�õĽڵ�
	Node* GetHead() { return m_head; }
	Node* GetRear() { return m_rear; }

private:
	Node* m_head;//ͷָ��
	Node* m_rear;//βָ��
};
//�������Ա�ϲ����������� ��1��2��4...��
void MergeList(SingleList& listA, SingleList& listb, SingleList& listc);