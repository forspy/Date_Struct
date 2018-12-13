#pragma once
//无向图邻接矩阵表示法
//目标是通过边的二维矩阵描述转化为邻接矩阵
#define MAX 100
class MatrixUDG
{
private:
	char m_vertax[MAX];//顶点
	//char m_edge[MAX][2];//边，因为在有向图中可能3个顶点就会有6条边，超过了max所以先不加这个成员变量，而是通过邻接矩阵表示边
	int m_matrix[MAX][MAX];//邻接矩阵
	int m_vertaxNum;//顶点数
	int m_edgeNum;//边数
public:
	MatrixUDG(char vertax[],char edge[][2],int vertaxNum,int edgeNum);//从main传入顶点数组，顶点个数，边的二维数组，边的个数
	void PrintMatrixUDG();
};
//有向图邻接矩阵表示法
class MatrixDG
{
private:
	char m_vertax[MAX];//顶点
					   //char m_edge[MAX][2];//边，因为在有向图中可能3个顶点就会有6条边，超过了max所以先不加这个成员变量，而是通过邻接矩阵表示边
	int m_matrix[MAX][MAX];//邻接矩阵
	int m_vertaxNum;//顶点数
	int m_edgeNum;//边数
public:
	MatrixDG(char vertax[], char edge[][2], int vertaxNum, int edgeNum);//从main传入顶点数组，顶点个数，边的二维数组，边的个数
	void PrintMatrixDG();
};
