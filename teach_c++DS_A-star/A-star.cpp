#include "A-star.h"
#include<iostream>
#include<cmath>
using namespace std;
const int g_cost1 = 10;
const int g_cost2 = 14;
//找到最优F值的点并建立parent链接
Point * Astar::FindPath(Point & startpoint, Point & endpoint)
{
	//将起点放入开启表中
	m_openList.push_back(&startpoint);//m_openlist里面存的是point*所以传入地址
	Point* curPoint;
	while (!m_openList.empty())
	{
		//从开启表中寻找F值最小的点
		//开启表中最小的点作为当前点查找
		curPoint = GetMinF();
		m_openList.remove(curPoint);//从当前表中移除
		m_closeList.push_back(curPoint);//加入关闭表中
		//找八个方向能走的点
		list<Point*> surroundPoint;//储存合格的点
		for (int row = curPoint->row - 1; row <= curPoint->row + 1; row++)
		{
			//判断是否越界
			if (row<0 || row>m_map.size() - 1)//m_map.size()表示外层行数
				continue;
			for (int col = curPoint->col - 1; col <= curPoint->col + 1; col++)
			{
				//判断是否越界
				if (col<0 || col>m_map[0].size() - 1)//m_map[0].size()表示列数
					continue;
				//找到合格的点
				Point* target = new Point(row, col);
				//排除不合格的点
				if (m_map[row][col] == 1 || row == curPoint->row&&col == curPoint->col || IsIncloseList(target))//1表示墙是不能的走，或者如果自己这个点也是不能走的，或者在关闭表里面也是不能走的
				{
					//释放这个点,因为不是所需要的点，所以释放以减少内存泄漏
					delete target;
					continue;
				}
				surroundPoint.push_back(target);//把这个合格的点压入容器中
			}
		}
		//在选出来的合格点里对周围点进行预估，更新开启表里面的点G值
		//采用c++11的方法
		for (auto& next : surroundPoint)
		{
			Point* tempPoint = IsInopenList(next);
			if (tempPoint)//如果在开启表里面,更新
			{
				int tempG = CalcG(curPoint, next);//更新开启表里面的点G值
				if (tempG < tempPoint->G)
				{
					tempPoint->parent = curPoint;
					tempPoint->G = tempG;//更新这个开启表里面的G值
					tempPoint->F = CalcF(tempPoint);
				}
			}
			else//如果不在开启表里面，计算F值并加入开启表
			{
				next->parent = curPoint;
				next->G = CalcG(curPoint, next);
				next->H = CalcH(next, &endpoint);
				next->F = CalcF(next);
				m_openList.push_back(next);//加入开启表
			}
			if (next->row == endpoint.row&&next->col == endpoint.col)//表示到达终点
			{
				//释放surroundPoint容器里面的值,不能在这里释放因为已经建立了parent链接，必须存在于内存
				return next;
			}
		}
	}
	return nullptr;
}

Astar::Astar(vector<vector<int>>& map)
{
	m_map = map;//STL容器vector可以直接赋值，=已经重载了
	m_openList.clear();
	m_closeList.clear();
}
//显示路径
void Astar::GetPath(Point & startpoint, Point & endpoint)
{
	//利用FindPath找，找到利用终点的parent逐级返回链接得到路径，没有返回null
	Point* point=FindPath(startpoint, endpoint);//找到的point
	//准备一个容器接收
	list<Point*> path;
	while (point)
	{
		//因为是从终点压入一致压到起点，所以在容器中选择从头部压入，这样到最后一个就是起点在头部
		path.push_front(point);
		point = point->parent;
	}
	for (list<Point*>::iterator iter = path.begin(); iter != path.end(); iter++)
	{
		cout << "(" << (*iter)->row << "," << (*iter)->col << ")" << " G=" << (*iter)->G << " H=" << (*iter)->H << " F=" << (*iter)->F << endl;
	}
		
	/*c++11用法
	for (auto& it : path)
		cout << it->row << it->col << endl;
	*/
	//释放path里面的内存,path在结束后会自动析构
}

bool Astar::IsIncloseList( const Point * point)
{
	list<Point*>::iterator iter;
	for (iter = m_closeList.begin(); iter != m_closeList.end(); iter++)
	{
		if ((*iter)->row == point->row && (*iter)->col == point->col)
			return true;
	}
	return false;
}

Point* Astar::IsInopenList(const Point * point)
{
	list<Point*>::iterator iter;
	for (iter = m_openList.begin(); iter != m_openList.end(); iter++)
	{
		if ((*iter)->row == point->row && (*iter)->col == point->col)
			return *iter;
	}
	return nullptr;
}

int Astar::CalcG(Point * current, Point * target)
{
	//目标G值=当前点的G值+当前点到目标点的消耗，紧挨着的
	int originalG = current->G;
	int costG = (abs(target->row - current->row) + abs(target->col - current->col)) == 1 ? g_cost1 : g_cost2;//如果等于1就是在四方！=1就是在斜方
	return originalG + costG;
}

int Astar::CalcH(Point * point, Point * end)
{
	//采用曼哈顿距离
	return abs(end->row - point->row) + abs(end->col - point->col)*g_cost1;
}

int Astar::CalcF(Point * point)
{
	return point->G + point->H;//返回这个点的G值+H值就是F值的评估
}

Point * Astar::GetMinF()
{
	list<Point*>::iterator iter;
	Point* minF_point = m_openList.front();//先定一个minF_point等于链表头部的F值
	if (!m_openList.empty())
	{
		for (iter = m_openList.begin(); iter != m_openList.end(); iter++)
		{
			if ((*iter)->F < minF_point->F)
				minF_point = *iter;
		}
		return minF_point;
	}
	return nullptr;
}
//
//Astar::~Astar()
//{
//	list<Point*>::iterator iter;
//	for (iter = m_openList.begin(); iter != m_openList.end();)
//		iter = m_openList.erase(iter);//返回下一个节点的迭代器
//	for (iter = m_closeList.begin(); iter != m_closeList.end();)
//		iter = m_closeList.erase(iter);//返回下一个节点的迭代器
//	vector<vector<int>>().swap(m_map);//这里考虑利用swap释放m_map里面的内存
//}
