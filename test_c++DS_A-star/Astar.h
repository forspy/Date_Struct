#pragma once
#include <vector>
#include <list>
using namespace std;
const int kCost1 = 10; //ֱ��һ������
const int kCost2 = 14; //б��һ������

struct Point
{
	int x, y; //�����꣬����Ϊ�˷��㰴��C++�����������㣬x������ţ�y��������
	int F, G, H; //F=G+H
	Point *parent; //parent�����꣬����û����ָ�룬�Ӷ��򻯴���
	Point(int _x, int _y) :x(_x), y(_y), F(0), G(0), H(0), parent(NULL) {}  //������ʼ��
};

class Astar
{
public:
	Astar(vector<vector<int>> &_maze) :maze(_maze) {}
	list<Point *> GetPath(Point &startPoint, Point &endPoint, bool isIgnoreCorner);
private:
	Point *findPath(Point &startPoint, Point &endPoint, bool isIgnoreCorner);
	vector<Point *> getSurroundPoints(const Point *point, bool isIgnoreCorner) const;
	bool isCanreach(const Point *point, const Point *target, bool isIgnoreCorner) const; //�ж�ĳ���Ƿ����������һ���ж�(�Ƿ�ɴ�)
	Point *isInList(const list<Point *> &list, const Point *point) const; //�жϿ���/�ر��б����Ƿ����ĳ��
	Point *getLeastFpoint(); //�ӿ����б��з���Fֵ��С�Ľڵ�
							 //����FGHֵ
	int calG(Point *temp_start, Point *point);
	int calH(Point *point, Point *end);
	int calF(Point *point);
private:
	vector<vector<int>> maze;
	list<Point *> openList;  //�����б�
	list<Point *> closeList; //�ر��б�
};
