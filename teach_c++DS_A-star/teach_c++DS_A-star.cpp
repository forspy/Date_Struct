#include"A-star.h"
//#include"vld.h"
int main()
{
	vector<vector<int>> map = {
		{ 1,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,0,0,1,1,0,0,0,0,0,0,1 },
		{ 1,1,0,0,0,0,1,1,1,1,0,1 },
		{ 1,1,1,0,0,0,1,1,1,1,0,1 },
		{ 1,1,1,1,0,1,0,0,1,1,0,1 },
		{ 1,1,1,1,1,0,1,0,0,1,0,1 },
		{ 1,1,1,1,1,1,1,1,0,0,0,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1 },
	};
	Astar astar(map);
	Point start(1, 1);
	Point end(6, 10);
	astar.GetPath(start, end);
}