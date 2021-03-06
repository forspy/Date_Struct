#include "MatrixUDG.h"
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
//第i个点的DFS递归遍历
void MatrixUDG::DFS(int i,int* visited)
{
	int j;
	visited[i] = 1;//先将这个点设置为1表示访问过了
	cout << m_vertex[i] << " ";
	for (j = firstVertex(i); j >= 0; j = nextVertex(i, j))
	{
		if (visited[j] == 0)
			DFS(j,visited);//表示以i顶点邻接的这个j顶点为几点继续进行深度递归遍历
	}
}
//深度搜索简化版
void MatrixUDG::DFS_opt(int i, vector<bool>& visited)
{
	cout << m_vertex[i] << " ";//先输出当前点i
	visited[i] = true;//设置为已经访问过
	//看当前的顶点：1.是否有邻接点2.是否被访问过
	for (int j = 0; j < m_vertexNum; j++)
	{
		if (m_matrix[i][j]==1 && visited[j] == false)//如果这个顶点有邻接点，并且这个邻接点没有被访问过，那么对这个邻接点应用递归算法
			DFS_opt(j, visited);
	}
	//所以输出的顺序是按照邻接图的顺序
}
//返回第i个顶点的第一个邻接顶点的索引，没有则返回-1
int MatrixUDG::firstVertex(int i)
{
	int j;
	if (i<0 || i>(m_vertexNum - 1))//因为i从0开始，所以m_vertexNum - 1表示最后一个顶点
		return -1;
	for (j = 0; j < m_vertexNum; j++)
	{
		if (m_matrix[i][j] == 1)
			return j;
	}
	return -1;
}
//返回第i个顶点的相对于j邻接点的下一个邻接顶点的索引，没有则返回 - 1
int MatrixUDG::nextVertex(int i, int j)
{
	int j_next;//表示下一个邻接点的位置(纵坐标),心中要有二维邻接矩阵
	if (i<0 || i>(m_vertexNum - 1) || j<0 || i>(m_vertexNum - 1))
		return -1;
	for (j_next = j + 1; j_next < m_vertexNum; j_next++)
	{
		if (m_matrix[i][j_next] == 1)
			return j_next;
	}
	return -1;
}

MatrixUDG::MatrixUDG(char vertex[], char edge[][2], int vertexNum, int edgeNum)
{
	memset(m_vertex, 0, sizeof(m_vertex));
	memset(m_matrix, 0, sizeof(m_matrix));//将邻接矩阵初始化为0
	//顶点数和边数赋值
	m_vertexNum = vertexNum;
	m_edgeNum = edgeNum;
	//用vertex[]初始化类中的顶点数组
	//memcpy(m_vertex, vertex, sizeof(vertex));//注意这里面的vertex已经是一个指针了而不是一个数组所以直接sizeof(vertex)是一个指针4个字节
	memcpy(m_vertex, vertex, sizeof(char)*vertexNum);
	//通过邻接矩阵表示边
	int v_i, v_j;//表示邻接矩阵的横坐标和纵坐标，也都是顶点数组的下标
	for (int i = 0; i < edgeNum; i++)//遍历边的信息
	{
		for (v_i = 0; v_i < vertexNum; v_i++)//寻找顶点数组中与第i边的第0个元素相同的值的位置
		{
			if (edge[i][0] == vertex[v_i])//找比如{'A','B'}的位置
				break;
		}
		for (v_j = 0; v_j < vertexNum; v_j++)
		{
			if (edge[i][1] == vertex[v_j])
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
	for (int i = 0; i < m_vertexNum; i++)
	{
		cout << m_vertex[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < m_vertexNum; i++)
	{
		cout << m_vertex[i] << " ";
		for (int j = 0; j < m_vertexNum; j++)
		{
			cout << m_matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void MatrixUDG::DFS()//外部接口深度遍历deep first search
{
	cout << __func__ << ":" << endl;
	int visited[MAX];
	//初始化所有顶点访问为0
	memset(visited, 0, sizeof(int)*MAX);
	for (int i = 0; i < m_vertexNum; i++)
	{
		if (visited[i] == 0)
			DFS(i,visited);
	}
	cout << endl;
}
void MatrixUDG::DFS_opt()
{
	cout << __func__ << endl;
	//首先利用一个辅助数组来记录这个顶点是不是已经访问过
	vector<bool> visited(m_vertexNum);//这样初始化为0，即false
	for (int i = 0; i < m_vertexNum; i++)
	{
		if (visited[i] == false)
			DFS_opt(i, visited);
	}
	cout << endl;
}
void MatrixUDG::DFS_Non_recursive()//非递归思想：利用辅助栈来完成上一个邻接父节点的存储
{
	cout << __func__ << endl;
	//首先利用一个辅助数组来记录这个顶点是不是已经访问过
	vector<bool> visited(m_vertexNum);//这样初始化为0，即false
	stack<int> s;//创建一个堆栈记录顶点的下标
	int temp;
	for (int i = 0; i < m_vertexNum; i++)
	{
		if (visited[i] == false)//如果这个顶点没有被访问过
		{
			temp = i;//记录当前遍历到的这个顶点的位置
			s.push(i);//就把这个顶点的下标压入栈
			cout << m_vertex[i] << " ";//把这个顶点输出出来
			visited[i] = true;//把这个顶点设置为已经访问过
			//接着找这个顶点的邻接点
			for (int j = 0; ; j++)//设置一个无限循环计数
			{
				if (m_matrix[i][j] == 1 && visited[j] == false)//找符合要求额邻接点
				{
					visited[j] = true;
					s.push(j);//把这个邻接顶点的下标压入栈
					cout << m_vertex[j] << " ";
					i = j;//邻接点作为起点
					j = 0;//表示重新开始计数
				}
				if (j == m_vertexNum)//i没有邻接点
				{
					if (temp == s.top())//如果栈顶等于一开始遍历的节点下标temp，说明在它的所有邻接联通顶点都已经被弹光了，退出循环
						break;
					s.pop();//弹出不符合要求的点
					i = s.top();//相当于选取父邻接节点为起点
					j = 0;//表示重新开始计数
				}
			}
		}
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
	for (i = 0; i < m_vertexNum; i++)//外层的遍历是必须要的，保证遍历到每个顶点因为树必须有链接，而图可以有孤单点，比如A可以不连接B,C
	{
		//把m_vertexNum个顶点依次压入
		if (visited[i] == 0)//如果没有遍历过这个顶点，就压入
		{
			visited[i] = 1;
			cout << m_vertex[i] << " ";
			que.push(i);//将顶点下标压入队列
		}
		while (!que.empty())//每一次循环都把所有根i顶点相邻的顶点压入并弹出打印
		{
			i_pop = que.front();
			que.pop();
			for (j = firstVertex(i_pop); j >= 0; j = nextVertex(i_pop, j))//依次遍历顶点的各个邻接顶点
			{
				if (visited[j] == 0)
				{
					visited[j] = 1;
					cout << m_vertex[j] << " ";//打印这个节点
					que.push(j);//压入
				}
			}
		}
	}
	cout << endl;
}

void MatrixUDG::BFS_opt()
{
	cout << __func__ << endl;
	queue<int> q;//利用队列储存下标
	vector<bool> visited(m_vertexNum);
	for (int i = 0; i < m_vertexNum; i++)
	{
		if (visited[i] == false)
		{
			visited[i] = true;
			cout << m_vertex[i]<< " ";
			q.push(i);//把改顶点的下表压入队列
			while (!q.empty())
			{
				int start = q.front();//把队列头作为起点顶点继续寻找
				q.pop();
				for (int j = 0; j < m_vertexNum; j++)
				{
					if (m_matrix[start][j] == 1 && visited[j] == false)
					{
						q.push(j);//压入邻接点
						visited[j] = true;
						cout << m_vertex[j] << " ";//输出这个邻接点
					}
				}
			}
		}
	}
	cout << endl;
}

MatrixDG::MatrixDG(char vertex[], char edge[][2], int vertexNum, int edgeNum)
{
	memset(m_vertex, 0, sizeof(m_vertex));
	memset(m_matrix, 0, sizeof(m_matrix));//将邻接矩阵初始化为0
										  //顶点数和边数赋值
	m_vertexNum = vertexNum;
	m_edgeNum = edgeNum;
	//用vertex[]初始化类中的顶点数组
	//memcpy(m_vertex, vertex, sizeof(vertex));//注意这里面的vertex已经是一个指针了而不是一个数组所以直接sizeof(vertex)是一个指针4个字节
	memcpy(m_vertex, vertex, sizeof(char)*vertexNum);
	//通过邻接矩阵表示边
	int v_i, v_j;//表示邻接矩阵的横坐标和纵坐标，也都是顶点数组的下标
	for (int i = 0; i < edgeNum; i++)//遍历边的信息
	{
		for (v_i = 0; v_i < vertexNum; v_i++)//寻找顶点数组中与第i边的第0个元素相同的值的位置
		{
			if (edge[i][0] == vertex[v_i])//找比如{'A','B'}的位置
				break;
		}
		for (v_j = 0; v_j < vertexNum; v_j++)
		{
			if (edge[i][1] == vertex[v_j])
				break;
		}
		m_matrix[v_i][v_j] = 1;//将找到边对应的邻接矩阵元素赋值为1，有向图不是对称的
		//m_matrix[v_j][v_i] = 1;//因为是对称的，所以反转一下也赋为1
	}
}

void MatrixDG::PrintMatrixDG()
{
	cout << "  ";
	for (int i = 0; i < m_vertexNum; i++)
	{
		cout << m_vertex[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < m_vertexNum; i++)
	{
		cout << m_vertex[i] << " ";
		for (int j = 0; j < m_vertexNum; j++)
		{
			cout << m_matrix[i][j] << " ";
		}
		cout << endl;
	}
}
