#pragma once
//˫��������
#include<string>
using namespace std;
class Node
{
public:
	Node* piror;//ǰָ��
	string name;
	Node* next;//��ָ��
};
//������ϵ,has-a �������нڵ�
//˫������
class DoubList
{
public:
	DoubList();
	~DoubList();
	Node* CreatNode(const string& str);//����һ���ڵ�
	void InsertHead(const string& str);//ͷ�巨����һ���ڵ�
	void ShowAll();//��ʾ���нڵ�
	int ShowLength();//��ʾ������
	void InsertPos(const string& str,int pos);//ָ��λ�ò���ڵ�
	void DelNode(int pos);//ָ��λ��ɾ���ڵ�
	string FindNode(int pos);//�ҵ�ָ��λ�õĽڵ���Ϣ
	void ChangeNode(int pos, const string& str);//�ı�ڵ���Ϣ
private:
	Node* m_head;
};
