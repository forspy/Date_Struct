#pragma once
//�����ڽӱ�
//Graph=G(E,V) E��ʾ���㡢V��ʾ�� 
#include<vector>
#define MAX 100
using namespace std;

class ListUDG
{
private:
	struct Enode//����Ƕ�׽ṹ--�ߣ���ʾ�ڽӵĽڵ㣩
	{
		//int wt;//Ȩ��
		int ivertex;//��Ŷ���(�ڵ�)�±�
		char data;//�ڵ������
		Enode* next;//ָ����һ���ڵ�
	};
	struct Vnode//����ṹ������ʾ��㶥�㣩
	{
		char data;//���������
		Enode* fistEdge;//ָ���һ����
	};
	int m_vertexNum;//������
	int m_edgeNum;//����
	vector<Vnode> m_vertex;//��������
	void DFS_opt(int i, vector<bool>& visited);//�ڲ�����
	
public:
	ListUDG(char vertex[], char edge[][2], int vertexNum, int edgeNum);
	void PrintListUDG();//��ӡ�ڽӱ�
	~ListUDG();//��ͬ���ڽ�ͼ����Ϊ�ڽ�ͼ��һ����ά���飬���Ա�ֱ�Ӵ�����
	//�������Enode�ǽڵ���Ҫnew�����������ڴ棬������Ҫ���������ͷ�
	void DFS_opt();//�����������
	void BFS_opt();//�����������
};
//�����ڽӱ�
class ListDG
{
private:
	struct Enode//����Ƕ�׽ṹ--��
	{
		//int wt;//Ȩ��
		int ivertex;//��Ŷ���(�ڵ�)�±�
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
	vector<Vnode> m_vertex;//��������

public:
	ListDG(char vertex[], char edge[][2], int vertexNum, int edgeNum);
	void PrintListDG();//��ӡ�ڽӱ�
	~ListDG();//��ͬ���ڽ�ͼ����Ϊ�ڽ�ͼ��һ����ά���飬���Ա�ֱ�Ӵ�����
			   //�������Enode�ǽڵ���Ҫnew�����������ڴ棬������Ҫ���������ͷ�
};
