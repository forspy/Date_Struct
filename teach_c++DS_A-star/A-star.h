#pragma once
//A*寻路
/*
A* [1]  （A-Star)算法是一种静态路网中求解最短路径最有效的直接搜索方法，也是许多其他问题的常用启发式算法。
注意——是最有效的直接搜索算法，之后涌现了很多预处理算法（如ALT，CH，HL等等），在线查询效率是A*算法的数千甚至上万倍。
公式表示为： f(n)=g(n)+h(n),
其中， f(n) 是从初始状态经由状态n到目标状态的代价估计，
g(n) 是在状态空间中从初始状态到状态n的实际代价，
h(n) 是从状态n到目标状态的最佳路径的估计代价。
（对于路径搜索问题，状态就是图中的节点，代价就是距离）
*/
#include<vector>
#include<list>
using namespace std;
struct Point
{
	int row, col;//点的坐标
	int F, G, H;//评估值
	Point* parent;//从哪个点过来到该点
	Point(int _row,int _col):row(_row),col(_col),F(0),G(0),H(0),parent(nullptr){ }
};

class Astar
{
private:
	vector<vector<int>> m_map;//建立一个二维数组表示地图
	//需要一个开启表和一个关闭表，开启表用来查找，关闭表用来剔除要查找的点，利用list链表来存储，更加高效
	list<Point*> m_openList;
	list<Point*> m_closeList;
	Point* FindPath(Point& startpoint, Point& endpoint);
	int CalcG(Point* current, Point* target);
	int CalcH(Point* point, Point* end);
	int CalcF(Point* point);
	Point* GetMinF();//获取最小的f值所在的点
	bool IsIncloseList(const Point* point);//判断是否在关闭表里面
	Point* IsInopenList(const Point* point);//判断是否在开启表里面
public:
	Astar(vector<vector<int>>& map);
	void GetPath(Point& startpoint, Point& endpoint);//显示路径
	
	/*~Astar();*/
};