#pragma once
//无向邻接表
//Graph=G(E,V) E表示顶点、V表示边 
#include<vector>
#define MAX 100
using namespace std;

class ListUDG
{
private:
	struct Enode//类内嵌套结构--边（表示邻接的节点）
	{
		//int wt;//权重
		int ivertex;//存放顶点(节点)下标
		char data;//节点的数据
		Enode* next;//指向下一个节点
	};
	struct Vnode//顶点结构，（表示起点顶点）
	{
		char data;//顶点的数据
		Enode* fistEdge;//指向第一条边
	};
	int m_vertexNum;//顶点数
	int m_edgeNum;//边数
	vector<Vnode> m_vertex;//顶点数组
	void DFS_opt(int i, vector<bool>& visited);//内部函数
	
public:
	ListUDG(char vertex[], char edge[][2], int vertexNum, int edgeNum);
	void PrintListUDG();//打印邻接表
	~ListUDG();//不同于邻接图，因为邻接图是一个二维数组，可以被直接创建，
	//而这里的Enode是节点需要new来创建分配内存，所以需要析构函数释放
	void DFS_opt();//深度优先搜索
	void BFS_opt();//广度优先搜索
};
//有向邻接表
class ListDG
{
private:
	struct Enode//类内嵌套结构--边
	{
		//int wt;//权重
		int ivertex;//存放顶点(节点)下标
		char data;//节点的数据
		Enode* next;//指向下一个节点
	};
	struct Vnode//顶点结构
	{
		char data;//顶点的数据
		Enode* fistEdge;//指向第一条边
	};
	int m_vertexNum;//顶点数
	int m_edgeNum;//边数
	vector<Vnode> m_vertex;//顶点数组

public:
	ListDG(char vertex[], char edge[][2], int vertexNum, int edgeNum);
	void PrintListDG();//打印邻接表
	~ListDG();//不同于邻接图，因为邻接图是一个二维数组，可以被直接创建，
			   //而这里的Enode是节点需要new来创建分配内存，所以需要析构函数释放
};
