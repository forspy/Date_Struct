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
	//int visited[MAX];//顶点标记,我们把顶点标记放到DFS和BFS里面，作为栈内数组，这样同时调用DFS和BFS就不会相互影响了，如果想要进行深度遍历的同时进行广度遍历，则需要把标记数组放在类中
	void DFS(int i,int* visited);//第i个顶点点的DFS递归遍历
	int firstVertex(int i);//返回第i个顶点的第一个邻接顶点的索引，没有则返回-1
	int nextVertax(int i, int j);//返回第i个顶点的相对于j邻接点的下一个邻接顶点的索引，没有则返回-1
public:
	MatrixUDG(char vertax[],char edge[][2],int vertaxNum,int edgeNum);//从main传入顶点数组，顶点个数，边的二维数组，边的个数
	void PrintMatrixUDG();//打印无向图
	void DFS();//深度优先搜索遍历图，递归遍历逐个顶点(先遍历第一个邻接点，如果有，就以这个邻接点为顶点递归遍历，如果碰到已经遍历过的顶点，则遍历该顶点的下一个邻接点)
	void BFS();//广度优先搜索，类似于树的层次遍历，需要引入一个队列来帮助我们遍历

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
