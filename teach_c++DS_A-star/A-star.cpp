#include "A-star.h"
#include<iostream>
#include<cmath>
using namespace std;
const int g_cost1 = 10;
const int g_cost2 = 14;
//�ҵ�����Fֵ�ĵ㲢����parent����
Point * Astar::FindPath(Point & startpoint, Point & endpoint)
{
	//�������뿪������
	m_openList.push_back(&startpoint);//m_openlist��������point*���Դ����ַ
	Point* curPoint;
	while (!m_openList.empty())
	{
		//�ӿ�������Ѱ��Fֵ��С�ĵ�
		//����������С�ĵ���Ϊ��ǰ�����
		curPoint = GetMinF();
		m_openList.remove(curPoint);//�ӵ�ǰ�����Ƴ�
		m_closeList.push_back(curPoint);//����رձ���
		//�Ұ˸��������ߵĵ�
		list<Point*> surroundPoint;//����ϸ�ĵ�
		for (int row = curPoint->row - 1; row <= curPoint->row + 1; row++)
		{
			//�ж��Ƿ�Խ��
			if (row<0 || row>m_map.size() - 1)//m_map.size()��ʾ�������
				continue;
			for (int col = curPoint->col - 1; col <= curPoint->col + 1; col++)
			{
				//�ж��Ƿ�Խ��
				if (col<0 || col>m_map[0].size() - 1)//m_map[0].size()��ʾ����
					continue;
				//�ҵ��ϸ�ĵ�
				Point* target = new Point(row, col);
				//�ų����ϸ�ĵ�
				if (m_map[row][col] == 1 || row == curPoint->row&&col == curPoint->col || IsIncloseList(target))//1��ʾǽ�ǲ��ܵ��ߣ���������Լ������Ҳ�ǲ����ߵģ������ڹرձ�����Ҳ�ǲ����ߵ�
				{
					//�ͷ������,��Ϊ��������Ҫ�ĵ㣬�����ͷ��Լ����ڴ�й©
					delete target;
					continue;
				}
				surroundPoint.push_back(target);//������ϸ�ĵ�ѹ��������
			}
		}
		//��ѡ�����ĺϸ�������Χ�����Ԥ�������¿���������ĵ�Gֵ
		//����c++11�ķ���
		for (auto& next : surroundPoint)
		{
			Point* tempPoint = IsInopenList(next);
			if (tempPoint)//����ڿ���������,����
			{
				int tempG = CalcG(curPoint, next);//���¿���������ĵ�Gֵ
				if (tempG < tempPoint->G)
				{
					tempPoint->parent = curPoint;
					tempPoint->G = tempG;//������������������Gֵ
					tempPoint->F = CalcF(tempPoint);
				}
			}
			else//������ڿ��������棬����Fֵ�����뿪����
			{
				next->parent = curPoint;
				next->G = CalcG(curPoint, next);
				next->H = CalcH(next, &endpoint);
				next->F = CalcF(next);
				m_openList.push_back(next);//���뿪����
			}
			if (next->row == endpoint.row&&next->col == endpoint.col)//��ʾ�����յ�
			{
				//�ͷ�surroundPoint���������ֵ,�����������ͷ���Ϊ�Ѿ�������parent���ӣ�����������ڴ�
				return next;
			}
		}
	}
	return nullptr;
}

Astar::Astar(vector<vector<int>>& map)
{
	m_map = map;//STL����vector����ֱ�Ӹ�ֵ��=�Ѿ�������
	m_openList.clear();
	m_closeList.clear();
}
//��ʾ·��
void Astar::GetPath(Point & startpoint, Point & endpoint)
{
	//����FindPath�ң��ҵ������յ��parent�𼶷������ӵõ�·����û�з���null
	Point* point=FindPath(startpoint, endpoint);//�ҵ���point
	//׼��һ����������
	list<Point*> path;
	while (point)
	{
		//��Ϊ�Ǵ��յ�ѹ��һ��ѹ����㣬������������ѡ���ͷ��ѹ�룬���������һ�����������ͷ��
		path.push_front(point);
		point = point->parent;
	}
	for (list<Point*>::iterator iter = path.begin(); iter != path.end(); iter++)
	{
		cout << "(" << (*iter)->row << "," << (*iter)->col << ")" << " G=" << (*iter)->G << " H=" << (*iter)->H << " F=" << (*iter)->F << endl;
	}
		
	/*c++11�÷�
	for (auto& it : path)
		cout << it->row << it->col << endl;
	*/
	//�ͷ�path������ڴ�,path�ڽ�������Զ�����
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
	//Ŀ��Gֵ=��ǰ���Gֵ+��ǰ�㵽Ŀ�������ģ������ŵ�
	int originalG = current->G;
	int costG = (abs(target->row - current->row) + abs(target->col - current->col)) == 1 ? g_cost1 : g_cost2;//�������1�������ķ���=1������б��
	return originalG + costG;
}

int Astar::CalcH(Point * point, Point * end)
{
	//���������پ���
	return abs(end->row - point->row) + abs(end->col - point->col)*g_cost1;
}

int Astar::CalcF(Point * point)
{
	return point->G + point->H;//����������Gֵ+Hֵ����Fֵ������
}

Point * Astar::GetMinF()
{
	list<Point*>::iterator iter;
	Point* minF_point = m_openList.front();//�ȶ�һ��minF_point��������ͷ����Fֵ
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
//		iter = m_openList.erase(iter);//������һ���ڵ�ĵ�����
//	for (iter = m_closeList.begin(); iter != m_closeList.end();)
//		iter = m_closeList.erase(iter);//������һ���ڵ�ĵ�����
//	vector<vector<int>>().swap(m_map);//���￼������swap�ͷ�m_map������ڴ�
//}
