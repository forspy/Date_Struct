#pragma once
#include <vector>
#include <list>
using namespace std;
const int kCost1 = 10; //直移一格消耗
const int kCost2 = 14; //斜移一格消耗

struct Point
{
	int x, y; //点坐标，这里为了方便按照C++的数组来计算，x代表横排，y代表竖列
	int F, G, H; //F=G+H
	Point *parent; //parent的坐标，这里没有用指针，从而简化代码
	Point(int _x, int _y) :x(_x), y(_y), F(0), G(0), H(0), parent(NULL) {}  //变量初始化
};

class Astar
{
public:
	Astar(vector<vector<int>> &_maze) :maze(_maze) {}
	list<Point *> GetPath(Point &startPoint, Point &endPoint, bool isIgnoreCorner);
private:
	Point *findPath(Point &startPoint, Point &endPoint, bool isIgnoreCorner);
	vector<Point *> getSurroundPoints(const Point *point, bool isIgnoreCorner) const;
	bool isCanreach(const Point *point, const Point *target, bool isIgnoreCorner) const; //判断某点是否可以用于下一步判断(是否可达)
	Point *isInList(const list<Point *> &list, const Point *point) const; //判断开启/关闭列表中是否包含某点
	Point *getLeastFpoint(); //从开启列表中返回F值最小的节点
							 //计算FGH值
	int calG(Point *temp_start, Point *point);
	int calH(Point *point, Point *end);
	int calF(Point *point);
private:
	vector<vector<int>> maze;
	list<Point *> openList;  //开启列表
	list<Point *> closeList; //关闭列表
};
