#include "ListUDG.h"
#include<iostream>
#include<queue>
using namespace std;
void ListUDG::DFS_opt(int i, vector<bool>& visited)//深度优先搜索内部函数
{
	cout << m_vertex[i].data << " ";//先输出当前点i
	visited[i] = true;//设置为已经访问过
					  //看当前的顶点：1.是否有邻接点2.是否被访问过
	Enode* tempNode;//设置一个用来遍历链表的节点指针
		//如果这个顶点有邻接点，并且这个邻接点没有被访问过，那么对这个邻接点应用递归算法
	tempNode = m_vertex[i].fistEdge;//初始化遍历节点指针
	while (tempNode&&visited[tempNode->ivertex]==false)
	{
		DFS_opt(tempNode->ivertex, visited);
		tempNode = tempNode->next;
	}
	//所以输出的顺序是按照邻接表的顺序
}
ListUDG::ListUDG(char vertex[], char edge[][2], int vertexNum, int edgeNum):m_vertex(MAX)//因为类的声明中不能开辟空间，所以建议在初始化列表中初始化成员变量
//构造函数就是为了构造成员变量,只能通过初始化列表进行
{
	m_vertexNum = vertexNum;//顶点数
	m_edgeNum = edgeNum;//边数
	//初始化邻接邻接表的顶点数组
	for (int i = 0; i < m_vertexNum; i++)
	{
		m_vertex[i].data = vertex[i];//存放的是头节点的数据比如{ 'A','B','C','D','E','F' };
		m_vertex[i].fistEdge = nullptr;
	}
	//找顶点和对应的顶点
	int v_i, v_j;//表示邻接表的顶点位置和链接的顶点位置，也都是顶点数组的下标
	for (int i = 0; i < edgeNum; i++)//遍历边的信息，比如{'A','B'}
	{
		for (v_i = 0; v_i < vertexNum; v_i++)
		{
			if (edge[i][0] == vertex[v_i])//
				break;//得到第几个顶点
		}
		for (v_j = 0; v_j < vertexNum; v_j++)
		{
			if (edge[i][1] == vertex[v_j])
				break;//得到这个顶点对应的顶点
		}
		//创建一个节点
		Enode* newnode = new Enode;
		newnode->ivertex = v_j;//节点的下标为v_j
		newnode->data = vertex[v_j];//节点的信息
		newnode->next = nullptr;
		//链接
		//1.如果顶点的fistedge指向的第一条边(顶点)为nullptr，那么直接链接
		if (m_vertex[v_i].fistEdge == nullptr)
		{
			m_vertex[v_i].fistEdge = newnode;
		}
		else//2.如果顶点的fistedge已经指向了一个节点，那么把这个节点放到最后
		{
			Enode* temp = m_vertex[v_i].fistEdge;
			while (temp->next)
			{
				temp = temp->next;
			}
			temp->next=newnode;
		}
		//因为是无向图所以A-B等价于B-A，所以B-A也要写一遍，即v_i,v_j反过来(4,2)<=>(2,4)
		//创建一个节点
		Enode* newnode1 = new Enode;
		newnode1->ivertex = v_i;//节点的下标为v_i
		newnode1->data = vertex[v_i];//节点的信息
		newnode1->next = nullptr;
		//链接
		//1.如果顶点的fistedge指向的第一条边(顶点)为nullptr，那么直接链接
		if (m_vertex[v_j].fistEdge == nullptr)
		{
			m_vertex[v_j].fistEdge = newnode1;
		}
		else//2.如果顶点的fistedge已经指向了一个节点，那么把这个节点放到最后
		{
			Enode* temp = m_vertex[v_j].fistEdge;
			while (temp->next)
			{
				temp = temp->next;
			}
			temp->next = newnode1;
		}
	}
}

void ListUDG::PrintListUDG()
{
	for (int i = 0; i < m_vertexNum; i++)//行数，顶点的个数
	{
		if (m_vertex[i].fistEdge)//如果有链接才打印这一行
		{
			//1.先打印头节点的信息
			cout <<i<< m_vertex[i].data << "->";
			//2.遍历打印链表中的各个节点
			Enode* temp = m_vertex[i].fistEdge;
			while (temp)
			{
				cout << temp->ivertex <<temp->data<< "->";
				temp = temp->next;
			}
			cout << "NULL" << endl;
		}
	}
}

ListUDG::~ListUDG()
{
	//释放就依次找到每一行进行释放
	for (int i = 0; i < m_vertexNum; i++)
	{
		Enode* p = m_vertex[i].fistEdge;
		Enode* temp;
		while (p)
		{
			temp = p;
			p = p->next;
			delete temp;
		}
	}
}

void ListUDG::DFS_opt()
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
//邻接表的广度优先搜索
void ListUDG::BFS_opt()
{
	cout << __func__ << endl;
	queue<int> q;//利用队列储存下标
	vector<bool> visited(m_vertexNum);
	for (int i = 0; i < m_vertexNum; i++)
	{
		if (visited[i] == false)
		{
			visited[i] = true;
			cout << m_vertex[i].data << " ";
			q.push(i);//把该顶点的下标压入队列

			while (!q.empty())
			{
				int start = q.front();//把队列头作为起点顶点继续寻找
				q.pop();//弹出队列头 
				Enode* tempNode;//设置一个用来遍历链表的节点指针
								//如果这个顶点有邻接点，并且这个邻接点没有被访问过，那么对这个邻接点应用递归算法
				tempNode = m_vertex[start].fistEdge;//初始化遍历节点指针
				while (tempNode && visited[tempNode->ivertex] == false)
				{
					q.push(tempNode->ivertex);//压入邻接点
					visited[tempNode->ivertex] = true;
					cout << m_vertex[tempNode->ivertex].data << " ";//输出这个邻接点
					tempNode = tempNode->next;
				}
				
			}
		}
	}
	cout << endl;
}


ListDG::ListDG(char vertex[], char edge[][2], int vertexNum, int edgeNum) :m_vertex(MAX)
{
	m_vertexNum = vertexNum;//顶点数
	m_edgeNum = edgeNum;//边数
						//初始化邻接邻接表的顶点数组
	for (int i = 0; i < m_vertexNum; i++)
	{
		m_vertex[i].data = vertex[i];//存放的是头节点的数据比如{ 'A','B','C','D','E','F' };
		m_vertex[i].fistEdge = nullptr;
	}
	//找顶点和对应的顶点
	int v_i, v_j;//表示邻接表的顶点位置和链接的顶点位置，也都是顶点数组的下标
	for (int i = 0; i < edgeNum; i++)//遍历边的信息，比如{'A','B'}
	{
		for (v_i = 0; v_i < vertexNum; v_i++)
		{
			if (edge[i][0] == vertex[v_i])//
				break;//得到第几个顶点
		}
		for (v_j = 0; v_j < vertexNum; v_j++)
		{
			if (edge[i][1] == vertex[v_j])
				break;//得到这个顶点对应的顶点
		}
		//创建一个节点
		Enode* newnode = new Enode;
		newnode->ivertex = v_j;//节点的下标为v_j
		newnode->data = vertex[v_j];//节点的信息
		newnode->next = nullptr;
		//链接
		//1.如果顶点的fistedge指向的第一条边(顶点)为nullptr，那么直接链接
		if (m_vertex[v_i].fistEdge == nullptr)
		{
			m_vertex[v_i].fistEdge = newnode;
		}
		else//2.如果顶点的fistedge已经指向了一个节点，那么把这个节点放到最后
		{
			Enode* temp = m_vertex[v_i].fistEdge;
			while (temp->next)
			{
				temp = temp->next;
			}
			temp->next = newnode;
		}
		//有向图因为是有向的，A->B就行，不需要反向
	}
}

void ListDG::PrintListDG()
{
	for (int i = 0; i < m_vertexNum; i++)//行数，顶点的个数
	{
		if (m_vertex[i].fistEdge)//如果有链接才打印这一行
		{
			//1.先打印头节点的信息
			cout << i << m_vertex[i].data << "->";
			//2.遍历打印链表中的各个节点
			Enode* temp = m_vertex[i].fistEdge;
			while (temp)
			{
				cout << temp->ivertex << temp->data << "->";
				temp = temp->next;
			}
			cout << "NULL" << endl;
		}
	}
}

ListDG::~ListDG()
{
	//释放就依次找到每一行进行释放
	for (int i = 0; i < m_vertexNum; i++)
	{
		Enode* p = m_vertex[i].fistEdge;
		Enode* temp;
		while (p)
		{
			temp = p;
			p = p->next;
			delete temp;
		}
	}
}
