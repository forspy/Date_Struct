#pragma once
//����ͼ�ڽӾ����ʾ��
//Ŀ����ͨ���ߵĶ�ά��������ת��Ϊ�ڽӾ���
#define MAX 100
#include<vector>
using namespace std;
class MatrixUDG
{
private:
	char m_vertex[MAX];//����
	//char m_edge[MAX][2];//�ߣ���Ϊ������ͼ�п���3������ͻ���6���ߣ�������max�����Ȳ��������Ա����������ͨ���ڽӾ����ʾ��
	int m_matrix[MAX][MAX];//�ڽӾ���
	int m_vertexNum;//������
	int m_edgeNum;//����
	//int visited[MAX];//������,���ǰѶ����Ƿŵ�DFS��BFS���棬��Ϊջ�����飬����ͬʱ����DFS��BFS�Ͳ����໥Ӱ���ˣ������Ҫ������ȱ�����ͬʱ���й�ȱ���������Ҫ�ѱ�������������
	void DFS(int i,int* visited);//��i��������DFS�ݹ����
	void DFS_opt(int i, vector<bool>& visited);
	int firstVertex(int i);//���ص�i������ĵ�һ���ڽӶ����������û���򷵻�-1
	int nextVertex(int i, int j);//���ص�i������������j�ڽӵ����һ���ڽӶ����������û���򷵻�-1
public:
	MatrixUDG(char vertex[],char edge[][2],int vertexNum,int edgeNum);//��main���붥�����飬����������ߵĶ�ά���飬�ߵĸ���
	void PrintMatrixUDG();//��ӡ����ͼ
	void DFS();//���������������ͼ���ݹ�����������(�ȱ�����һ���ڽӵ㣬����У���������ڽӵ�Ϊ����ݹ��������������Ѿ��������Ķ��㣬������ö������һ���ڽӵ�)
	//�����������������
	void DFS_opt();
	//������������ǵݹ��
	void DFS_Non_recursive();
	void BFS();//����������������������Ĳ�α�������Ҫ����һ���������������Ǳ���
	void BFS_opt();//����������ؼ򻯰�
};
//����ͼ�ڽӾ����ʾ��
class MatrixDG
{
private:
	char m_vertex[MAX];//����
					   //char m_edge[MAX][2];//�ߣ���Ϊ������ͼ�п���3������ͻ���6���ߣ�������max�����Ȳ��������Ա����������ͨ���ڽӾ����ʾ��
	int m_matrix[MAX][MAX];//�ڽӾ���
	int m_vertexNum;//������
	int m_edgeNum;//����
public:
	MatrixDG(char vertex[], char edge[][2], int vertexNum, int edgeNum);//��main���붥�����飬����������ߵĶ�ά���飬�ߵĸ���
	void PrintMatrixDG();
};
