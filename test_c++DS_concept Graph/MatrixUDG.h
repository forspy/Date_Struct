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
public:
	MatrixUDG(char vertax[],char edge[][2],int vertaxNum,int edgeNum);//��main���붥�����飬����������ߵĶ�ά���飬�ߵĸ���
	void PrintMatrixUDG();
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
