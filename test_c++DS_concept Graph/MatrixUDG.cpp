#include "MatrixUDG.h"
#include<iostream>
#include<queue>
using namespace std;
//第i个点的DFS递归遍历
void MatrixUDG::DFS(int i,int* visited)
{
	int j;
	visited[i] = 1;//先将这个点设置为1表示访问过了
	cout << m_vertax[i] << " ";
	for (j = firstVertex(i); j >= 0; j = nextVertax(i, j))
	{
		if (visited[j] == 0)
			DFS(j,visited);//表示以i顶点邻接的这个j顶点为几点继续进行深度递归遍历
	}
}
//返回第i个顶点的第一个邻接顶点的索引，没有则返回-1
int MatrixUDG::firstVertex(int i)
{
	int j;
	if (i<0 || i>(m_vertaxNum - 1))//因为i从0开始，所以m_vertaxNum - 1表示最后一个顶点
		return -1;
	for (j = 0; j < m_vertaxNum; j++)
	{
		if (m_matrix[i][j] == 1)
			return j;
	}
	return -1;
}
//返回第i个顶点的相对于j邻接点的下一个邻接顶点的索引，没有则返回 - 1
int MatrixUDG::nextVertax(int i, int j)
{
	int j_next;//表示下一个邻接点的位置(纵坐标),心中要有二维邻接矩阵
	if (i<0 || i>(m_vertaxNum - 1) || j<0 || i>(m_vertaxNum - 1))
		return -1;
	for (j_next = j + 1; j_next < m_vertaxNum; j_next++)
	{
		if (m_matrix[i][j_next] == 1)
			return j_next;
	}
	return -1;
}

MatrixUDG::MatrixUDG(char vertax[], char edge[][2], int vertaxNum, int edgeNum)
{
	memset(m_vertax, 0, sizeof(m_vertax));
	memset(m_matrix, 0, sizeof(m_matrix));//将邻接矩阵初始化为0
	//顶点数和边数赋值
	m_vertaxNum = vertaxNum;
	m_edgeNum = edgeNum;
	//用vertax[]初始化类中的顶点数组
	//memcpy(m_vertax, vertax, sizeof(vertax));//注意这里面的vertax已经是一个指针了而不是一个数组所以直接sizeof(vertax)是一个指针4个字节
	memcpy(m_vertax, vertax, sizeof(char)*vertaxNum);
	//通过邻接矩阵表示边
	int v_i, v_j;//表示邻接矩阵的横坐标和纵坐标，也都是顶点数组的下标
	for (int i = 0; i < edgeNum; i++)//遍历边的信息
	{
		for (v_i = 0; v_i < vertaxNum; v_i++)//寻找顶点数组中与第i边的第0个元素相同的值的位置
		{
			if (edge[i][0] == vertax[v_i])//找比如{'A','B'}的位置
				break;
		}
		for (v_j = 0; v_j < vertaxNum; v_j++)
		{
			if (edge[i][1] == vertax[v_j])
				break;
		}
		m_matrix[v_i][v_j] = 1;//将找到边对应的邻接矩阵元素赋值为1
		m_matrix[v_j][v_i] = 1;//因为是对称的，所以反转一下也赋为1，相当于有另外一组边矩阵，只是元素是反的比如（A,B）(B,A)
	}
	
}
//打印邻接矩阵
void MatrixUDG::PrintMatrixUDG()
{
	cout << "  ";
	for (int i = 0; i < m_vertaxNum; i++)
	{
		cout << m_vertax[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < m_vertaxNum; i++)
	{
		cout << m_vertax[i] << " ";
		for (int j = 0; j < m_vertaxNum; j++)
		{
			cout << m_matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void MatrixUDG::DFS()//外部接口深度遍历
{
	cout << __func__ << ":" << endl;
	int visited[MAX];
	//初始化所有顶点访问为0
	memset(visited, 0, sizeof(int)*MAX);
	int i;
	for (i = 0; i < m_vertaxNum; i++)
	{
		if (visited[i] == 0)
			DFS(i,visited);
	}
	cout << endl;
}
//广度优先搜索，类似于树的层次遍历，需要引入一个队列来帮助我们遍历
void MatrixUDG::BFS()
{
	//创建一个队列对象
	queue<int> que; //存的是顶点下标
	int i;//表示要遍历的顶点
	int i_pop;//表示弹出队列的顶点的下标
	int j;//表示顶点的邻接顶点
	cout << __func__ << endl;
	int visited[MAX];
	memset(visited, 0, sizeof(int)*MAX);
	for (i = 0; i < m_vertaxNum; i++)//外层的遍历是必须要的，保证遍历到每个顶点因为树必须有链接，而图可以有孤单点，比如A可以不连接B,C
	{
		//把m_vertaxNum个顶点依次压入
		if (visited[i] == 0)//如果没有遍历过这个顶点，就压入
		{
			visited[i] = 1;
			cout << m_vertax[i] << " ";
			que.push(i);//将顶点下标压入队列
		}
		while (!que.empty())//每一次循环都把所有根i顶点相邻的顶点压入并弹出打印
		{
			i_pop = que.front();
			que.pop();
			for (j = firstVertex(i_pop); j >= 0; j = nextVertax(i_pop, j))//依次遍历顶点的各个邻接顶点
			{
				if (visited[j] == 0)
				{
					visited[j] = 1;
					cout << m_vertax[j] << " ";//打印这个节点
					que.push(j);//压入
				}
			}
		}
	}
	cout << endl;
}

MatrixDG::MatrixDG(char vertax[], char edge[][2], int vertaxNum, int edgeNum)
{
	memset(m_vertax, 0, sizeof(m_vertax));
	memset(m_matrix, 0, sizeof(m_matrix));//将邻接矩阵初始化为0
										  //顶点数和边数赋值
	m_vertaxNum = vertaxNum;
	m_edgeNum = edgeNum;
	//用vertax[]初始化类中的顶点数组
	//memcpy(m_vertax, vertax, sizeof(vertax));//注意这里面的vertax已经是一个指针了而不是一个数组所以直接sizeof(vertax)是一个指针4个字节
	memcpy(m_vertax, vertax, sizeof(char)*vertaxNum);
	//通过邻接矩阵表示边
	int v_i, v_j;//表示邻接矩阵的横坐标和纵坐标，也都是顶点数组的下标
	for (int i = 0; i < edgeNum; i++)//遍历边的信息
	{
		for (v_i = 0; v_i < vertaxNum; v_i++)//寻找顶点数组中与第i边的第0个元素相同的值的位置
		{
			if (edge[i][0] == vertax[v_i])//找比如{'A','B'}的位置
				break;
		}
		for (v_j = 0; v_j < vertaxNum; v_j++)
		{
			if (edge[i][1] == vertax[v_j])
				break;
		}
		m_matrix[v_i][v_j] = 1;//将找到边对应的邻接矩阵元素赋值为1，有向图不是对称的
		//m_matrix[v_j][v_i] = 1;//因为是对称的，所以反转一下也赋为1
	}
}

void MatrixDG::PrintMatrixDG()
{
	cout << "  ";
	for (int i = 0; i < m_vertaxNum; i++)
	{
		cout << m_vertax[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < m_vertaxNum; i++)
	{
		cout << m_vertax[i] << " ";
		for (int j = 0; j < m_vertaxNum; j++)
		{
			cout << m_matrix[i][j] << " ";
		}
		cout << endl;
	}
}
