#pragma once
//�ڵ���
#include<string>
#include<fstream>
using namespace std;
//ѭ������ĺô�ʱ���Դ�����һ���ڵ�����ҵ�����ڵ�
class Node
{
public:
	string m_ISBN;//ͼ����
	string m_name;//����
	double m_price;//�۸�
	Node* next;//ָ����һ���ڵ��ָ��
};
//��������ѭ���������һ���ô��ǣ�
//��Ϊͷָ������������������з���������ʹ��ͷָ�룬����Ҫ�ٴ���ͷָ��������
class CirSingleList
{
public:
	CirSingleList();
	~CirSingleList() ;//����Ӧ�����ͷ���������������д
	Node* CreatNode();//����һ���ڵ�
	Node* CreatNode(const string ISBN, const string name, double price);//����һ������ڵ�ķ���
	void ImportDataList();//����ָ�����ȵ�����
	void ShowAll();//��ʾ���нڵ�
	void InsertBack(const string ISBN, const string name, double price);//β������ڵ�
	void InsertHead(const string ISBN, const string name, double price);//ͷ������ڵ�
	void InsertPos(const string ISBN, const string name, double price,int position);//ָ��λ�ò���ڵ�
	void DelNode(int position);//ɾ��һ���ڵ�
private:
	Node* m_head;//����һ��ͷָ��
	Node* m_rear;//����һ��βָ�룬����β������
	fstream file;
};

