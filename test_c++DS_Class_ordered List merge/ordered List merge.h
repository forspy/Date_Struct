#pragma once

using namespace std;
class Node
{
	public:
	int number;
	Node* next;
};
//��������+ͷ�ڵ�ģʽ
class SingleList
{
public:
	SingleList();
	//~SingleList();
	Node* CreatNode(const int num);//����һ���ڵ�
	void InsertHead(const int num);//ͷ�巨
	void InsertBack(const int num);//β�巨
	void ShowAll();//��ʾ���нڵ�
	void InsertPos(const int num, int position);//ָ��λ�ò���һ���ڵ�
	void DelNodePos(int pos);//ָ��λ��ɾ��һ���ڵ�
	int FindNodePos(int pos);//����ָ��λ�õĽڵ�
	void ChangeNodePos(int pos,const int num);//�ı�ָ��λ�õĽڵ�
	Node* GetHead() { return m_head; }
	Node* GetRear() { return m_rear; }
private:
	Node* m_head;//ͷָ��
	Node* m_rear;//βָ��
};
//�������Ա�ϲ����������� ��1��2��4...��
void MergeList(SingleList& listA, SingleList& listb, SingleList& listc);