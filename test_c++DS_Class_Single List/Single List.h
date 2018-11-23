#pragma once
#include<string>
using namespace std;
class Node
{
	public:
	string name;
	Node* next;
};
//��������+ͷ�ڵ�ģʽ
class SingleList
{
public:
	SingleList();
	~SingleList();
	Node* CreatNode(const string str);//����һ���ڵ�
	void InsertHead(const string str);//ͷ�巨
	void ShowAll();//��ʾ���нڵ�
	void InsertPos(const string str, int position);//ָ��λ�ò���һ���ڵ�
	void DelNodePos(int pos);//ָ��λ��ɾ��һ���ڵ�
	string& FindNodePos(int pos);//����ָ��λ�õĽڵ�
	void ChangeNodePos(int pos,const string str);//�ı�ָ��λ�õĽڵ�
private:
	Node* m_head;
};