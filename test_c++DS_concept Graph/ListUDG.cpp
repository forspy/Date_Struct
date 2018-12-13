#include "ListUDG.h"
#include<iostream>
using namespace std;
ListUDG::ListUDG(char vertax[], char edge[][2], int vertaxNum, int edgeNum):m_vertax(MAX)//因为类的声明中不能开辟空间，所以建议在初始化列表中初始化成员变量
//构造函数就是为了构造成员变量,只能通过初始化列表进行
{
	m_vertexNum = vertaxNum;//顶点数
	m_edgeNum = edgeNum;//边数
	//初始化邻接邻接表的顶点数组
	for (int i = 0; i < m_vertexNum; i++)
	{
		m_vertax[i].data = vertax[i];//存放的是头节点的数据比如{ 'A','B','C','D','E','F' };
		m_vertax[i].fistEdge = nullptr;
	}
	//找顶点和对应的顶点
	int v_i, v_j;//表示邻接表的顶点位置和链接的顶点位置，也都是顶点数组的下标
	for (int i = 0; i < edgeNum; i++)//遍历边的信息，比如{'A','B'}
	{
		for (v_i = 0; v_i < vertaxNum; v_i++)
		{
			if (edge[i][0] == vertax[v_i])//
				break;//得到第几个顶点
		}
		for (v_j = 0; v_j < vertaxNum; v_j++)
		{
			if (edge[i][1] == vertax[v_j])
				break;//得到这个顶点对应的顶点
		}
		//创建一个节点
		Enode* newnode = new Enode;
		newnode->ivertax = v_j;//节点的下标为v_j
		newnode->data = vertax[v_j];//节点的信息
		newnode->next = nullptr;
		//链接
		//1.如果顶点的fistedge指向的第一条边(顶点)为nullptr，那么直接链接
		if (m_vertax[v_i].fistEdge == nullptr)
		{
			m_vertax[v_i].fistEdge = newnode;
		}
		else//2.如果顶点的fistedge已经指向了一个节点，那么把这个节点放到最后
		{
			Enode* temp = m_vertax[v_i].fistEdge;
			while (temp->next)
			{
				temp = temp->next;
			}
			temp->next=newnode;
		}
		//因为是无向图所以A-B等价于B-A，所以B-A也要写一遍，即v_i,v_j反过来(4,2)<=>(2,4)
		//创建一个节点
		Enode* newnode1 = new Enode;
		newnode1->ivertax = v_i;//节点的下标为v_i
		newnode1->data = vertax[v_i];//节点的信息
		newnode1->next = nullptr;
		//链接
		//1.如果顶点的fistedge指向的第一条边(顶点)为nullptr，那么直接链接
		if (m_vertax[v_j].fistEdge == nullptr)
		{
			m_vertax[v_j].fistEdge = newnode1;
		}
		else//2.如果顶点的fistedge已经指向了一个节点，那么把这个节点放到最后
		{
			Enode* temp = m_vertax[v_j].fistEdge;
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
		if (m_vertax[i].fistEdge)//如果有链接才打印这一行
		{
			//1.先打印头节点的信息
			cout <<i<< m_vertax[i].data << "->";
			//2.遍历打印链表中的各个节点
			Enode* temp = m_vertax[i].fistEdge;
			while (temp)
			{
				cout << temp->ivertax <<temp->data<< "->";
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
		Enode* p = m_vertax[i].fistEdge;
		Enode* temp;
		while (p)
		{
			temp = p;
			p = p->next;
			delete temp;
		}
	}
}

ListDG::ListDG(char vertax[], char edge[][2], int vertaxNum, int edgeNum) :m_vertax(MAX)
{
	m_vertexNum = vertaxNum;//顶点数
	m_edgeNum = edgeNum;//边数
						//初始化邻接邻接表的顶点数组
	for (int i = 0; i < m_vertexNum; i++)
	{
		m_vertax[i].data = vertax[i];//存放的是头节点的数据比如{ 'A','B','C','D','E','F' };
		m_vertax[i].fistEdge = nullptr;
	}
	//找顶点和对应的顶点
	int v_i, v_j;//表示邻接表的顶点位置和链接的顶点位置，也都是顶点数组的下标
	for (int i = 0; i < edgeNum; i++)//遍历边的信息，比如{'A','B'}
	{
		for (v_i = 0; v_i < vertaxNum; v_i++)
		{
			if (edge[i][0] == vertax[v_i])//
				break;//得到第几个顶点
		}
		for (v_j = 0; v_j < vertaxNum; v_j++)
		{
			if (edge[i][1] == vertax[v_j])
				break;//得到这个顶点对应的顶点
		}
		//创建一个节点
		Enode* newnode = new Enode;
		newnode->ivertax = v_j;//节点的下标为v_j
		newnode->data = vertax[v_j];//节点的信息
		newnode->next = nullptr;
		//链接
		//1.如果顶点的fistedge指向的第一条边(顶点)为nullptr，那么直接链接
		if (m_vertax[v_i].fistEdge == nullptr)
		{
			m_vertax[v_i].fistEdge = newnode;
		}
		else//2.如果顶点的fistedge已经指向了一个节点，那么把这个节点放到最后
		{
			Enode* temp = m_vertax[v_i].fistEdge;
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
		if (m_vertax[i].fistEdge)//如果有链接才打印这一行
		{
			//1.先打印头节点的信息
			cout << i << m_vertax[i].data << "->";
			//2.遍历打印链表中的各个节点
			Enode* temp = m_vertax[i].fistEdge;
			while (temp)
			{
				cout << temp->ivertax << temp->data << "->";
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
		Enode* p = m_vertax[i].fistEdge;
		Enode* temp;
		while (p)
		{
			temp = p;
			p = p->next;
			delete temp;
		}
	}
}
