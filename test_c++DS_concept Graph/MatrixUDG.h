#pragma once
//����ͼ�ڽӾ����ʾ��
//Ŀ����ͨ���ߵĶ�ά��������ת��Ϊ�ڽӾ���
#define MAX 100
class MatrixUDG
{
private:
	char m_vertax[MAX];//����
	//char m_edge[MAX][2];//�ߣ���Ϊ������ͼ�п���3������ͻ���6���ߣ�������max�����Ȳ��������Ա����������ͨ���ڽӾ����ʾ��
	int m_matrix[MAX][MAX];//�ڽӾ���
	int m_vertaxNum;//������
	int m_edgeNum;//����
	//int visited[MAX];//������,���ǰѶ����Ƿŵ�DFS��BFS���棬��Ϊջ�����飬����ͬʱ����DFS��BFS�Ͳ����໥Ӱ���ˣ������Ҫ������ȱ�����ͬʱ���й�ȱ���������Ҫ�ѱ�������������
	void DFS(int i,int* visited);//��i��������DFS�ݹ����
	int firstVertex(int i);//���ص�i������ĵ�һ���ڽӶ����������û���򷵻�-1
	int nextVertax(int i, int j);//���ص�i������������j�ڽӵ����һ���ڽӶ����������û���򷵻�-1
public:
	MatrixUDG(char vertax[],char edge[][2],int vertaxNum,int edgeNum);//��main���붥�����飬����������ߵĶ�ά���飬�ߵĸ���
	void PrintMatrixUDG();//��ӡ����ͼ
	void DFS();//���������������ͼ���ݹ�����������(�ȱ�����һ���ڽӵ㣬����У���������ڽӵ�Ϊ����ݹ��������������Ѿ��������Ķ��㣬������ö������һ���ڽӵ�)
	void BFS();//����������������������Ĳ�α�������Ҫ����һ���������������Ǳ���

};
//����ͼ�ڽӾ����ʾ��
class MatrixDG
{
private:
	char m_vertax[MAX];//����
					   //char m_edge[MAX][2];//�ߣ���Ϊ������ͼ�п���3������ͻ���6���ߣ�������max�����Ȳ��������Ա����������ͨ���ڽӾ����ʾ��
	int m_matrix[MAX][MAX];//�ڽӾ���
	int m_vertaxNum;//������
	int m_edgeNum;//����
public:
	MatrixDG(char vertax[], char edge[][2], int vertaxNum, int edgeNum);//��main���붥�����飬����������ߵĶ�ά���飬�ߵĸ���
	void PrintMatrixDG();
};
