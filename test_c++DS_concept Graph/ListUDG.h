#pragma once
//�����ڽӱ�
//Graph=G(E,V) E��ʾ���㡢V��ʾ�� 
#include<vector>
#define MAX 100
using namespace std;

class ListUDG
{
private:
	struct Enode//����Ƕ�׽ṹ--��
	{
		//int wt;//Ȩ��
		int ivertax;//��Ŷ���(�ڵ�)�±�
		char data;//�ڵ������
		Enode* next;//ָ����һ���ڵ�
	};
	struct Vnode//����ṹ
	{
		char data;//���������
		Enode* fistEdge;//ָ���һ����
	};
	int m_vertexNum;//������
	int m_edgeNum;//����
	vector<Vnode> m_vertax;//��������
	
public:
	ListUDG(char vertax[], char edge[][2], int vertaxNum, int edgeNum);
	void PrintListUDG();//��ӡ�ڽӱ�
	~ListUDG();//��ͬ���ڽ�ͼ����Ϊ�ڽ�ͼ��һ����ά���飬���Ա�ֱ�Ӵ�����
	//�������Enode�ǽڵ���Ҫnew�����������ڴ棬������Ҫ���������ͷ�
};
//�����ڽӱ�
class ListDG
{
private:
	struct Enode//����Ƕ�׽ṹ--��
	{
		//int wt;//Ȩ��
		int ivertax;//��Ŷ���(�ڵ�)�±�
		char data;//�ڵ������
		Enode* next;//ָ����һ���ڵ�
	};
	struct Vnode//����ṹ
	{
		char data;//���������
		Enode* fistEdge;//ָ���һ����
	};
	int m_vertexNum;//������
	int m_edgeNum;//����
	vector<Vnode> m_vertax;//��������

public:
	ListDG(char vertax[], char edge[][2], int vertaxNum, int edgeNum);
	void PrintListDG();//��ӡ�ڽӱ�
	~ListDG();//��ͬ���ڽ�ͼ����Ϊ�ڽ�ͼ��һ����ά���飬���Ա�ֱ�Ӵ�����
			   //�������Enode�ǽڵ���Ҫnew�����������ڴ棬������Ҫ���������ͷ�
};
