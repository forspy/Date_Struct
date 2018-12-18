//深度寻路和广度寻路
#include<iostream>
#include<stack>
using namespace std;
//深度寻路不一定有最短路径
//只选择一条路径
//寻路的效率取决于方向
#define MAP_ROW 12
#define MAP_COL 12
enum pathDir{UP,DOWN,RIGHT,LEFT};//表示该点的四个方向
struct pathNode
{
	int row;//当前点的行
	int col;//当前点的列
	int val;//原始地图数据
	bool visited;//是否走过
	pathDir dir;//到达该点时会选择进行的方向
};
int main()
{
	//1.准备一个地图
	int arrMap[MAP_ROW][MAP_COL] = {
		{ 1,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,0,0,0,0,0,0,0,0,1,1,1 },
		{ 1,1,0,1,0,1,1,1,1,1,1,1 },
		{ 1,1,0,1,0,1,1,0,0,0,1,1 },
		{ 1,1,0,1,0,1,1,0,1,0,1,1 },
		{ 1,1,0,1,0,0,0,0,1,0,1,1 },
		{ 1,1,0,1,1,1,1,1,1,0,1,1 },
		{ 1,1,0,1,1,1,1,1,1,0,1,1 },
		{ 1,1,0,0,0,1,1,1,1,0,1,1 },
		{ 1,1,1,1,0,1,1,1,1,0,1,1 },
		{ 1,1,1,1,0,0,1,1,1,0,0,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1 },
	};

	//准备一个辅助数组来改变地图上的信息
	//2.创建一个二维点对象数组来保存信息，对象里面储存地图数据、visited、方向
	pathNode pathArr[MAP_ROW][MAP_COL];
	for (int i = 0; i < MAP_ROW; i++)
	{
		for (int j = 0; j < MAP_COL; j++)
		{
			pathArr[i][j].row = i;//给与这个点行信息
			pathArr[i][j].col = j;//给与这个点列信息
			pathArr[i][j].val = arrMap[i][j];
			pathArr[i][j].visited = false;
			pathArr[i][j].dir = RIGHT;//初始设置为向右，尽量选择有利于出去二点方向为初始方向,初始的设置很重要，要与switch的第一种情况匹配，这样才能遍历4个方向
		}
	}
	//3.设置起点和终点
	pathNode beginPoint = pathArr[1][1];
	//beginPoint.visited = true;
	pathNode endPoint = pathArr[10][10];
	//4.准备一个栈来保存走过的每一步，为什么是栈呢》因为，栈是后进先出，所以当走到死胡同的时候可以利用栈的弹出来进行回滚操作
	//另外，栈在非递归操作的时候作为承载的容器，能够存储父节点，因为可以利用栈代替递归操作，比如说DFS的非递归输出
	stack<pathNode> pathStack;//辅助栈
	//5.将起点压入栈中
	pathStack.push(beginPoint);
	//6.设置一个当前点,用来遍历
	pathNode curPoint = beginPoint;//初始化当前点为起点
	//7.开始寻路 
	pathNode nextPoint;//设置下一个点
	while (!pathStack.empty())//退出条件为栈空或者到达终点
	{
		//下一步怎么走,判断方向
		switch (curPoint.dir)
		{
	
		case RIGHT:
			 nextPoint = pathArr[curPoint.row ][curPoint.col+1];//使代码更加简洁
			if (curPoint.col+1  <= MAP_COL && nextPoint.val == 0 && nextPoint.visited == false)//判断上一个点不越界并且是路才可以通行
			{
				pathArr[curPoint.row ][curPoint.col+1].visited = true;//如果能走设置下一个点为true
				pathStack.push(nextPoint);//压入下一个点
				curPoint = nextPoint;//当前点等于下一个点
			}
			else
				curPoint.dir = DOWN;//不行就换方向
			break;
		case DOWN:
			 nextPoint = pathArr[curPoint.row + 1][curPoint.col];//使代码更加简洁
			if (curPoint.row + 1 <= MAP_ROW && nextPoint.val == 0 && nextPoint.visited == false)//判断上一个点不越界并且是路才可以通行
			{
				pathArr[curPoint.row+1][curPoint.col ].visited = true;//如果能走设置下一个点为true
				pathStack.push(nextPoint);//压入下一个点
				curPoint = nextPoint;//当前点等于下一个点
			}
			else
				curPoint.dir = LEFT;//不行就换方向
			break;
		case LEFT:
			 nextPoint = pathArr[curPoint.row ][curPoint.col-1];//使代码更加简洁
			if (curPoint.col- 1 >= 0 && nextPoint.val == 0 && nextPoint.visited == false)//判断上一个点不越界并且是路才可以通行
			{
				pathArr[curPoint.row][curPoint.col - 1].visited = true;//如果能走设置下一个点为true
				pathStack.push(nextPoint);//压入下一个点
				curPoint = nextPoint;//当前点等于下一个点
			}
			else//在所有方向都试过以后发现不能再换方向了，就开始弹出栈顶元素进行回滚
			{
				curPoint.dir = UP;
			}
			break;
		case UP:
			nextPoint = pathArr[curPoint.row - 1][curPoint.col];//使代码更加简洁
			if (curPoint.row - 1 >= 0 && nextPoint.val == 0 && nextPoint.visited == false)//判断上一个点不越界并且是路才可以通行
			{
				pathArr[curPoint.row - 1][curPoint.col].visited = true;//如果能走设置下一个点为true
				pathStack.push(nextPoint);//压入下一个点
				curPoint = nextPoint;//当前点等于下一个点
			}
			else//在所有方向都试过以后发现不能再换方向了，就开始弹出栈顶元素进行回滚
			{
				pathStack.pop();//退一步
				if (!pathStack.empty())
				{
					curPoint = pathStack.top();//把新的栈顶作为当前点
				}
			}
			break;
		}
		if (curPoint.row == endPoint.row&&curPoint.col == endPoint.col)//表示到达终点
			break;
	}
	//打印路径,即打印栈中的所有元素，路径为逆序，因为栈底表示开始，栈顶表示到达终点
	while (!pathStack.empty())
	{
		cout << "row=" << pathStack.top().row << ",col=" << pathStack.top().col << endl;
		pathStack.pop();
	}
}
/*
int arrMap[MAP_ROW][MAP_COL] = {
    0 1 2 3 4 5 6 7 8 9 1011
0 { 1,1,1,1,1,1,1,1,1,1,1,1 },
1 { 1,0,0,0,0,0,0,0,0,1,1,1 },
2 { 1,1,0,1,0,1,1,1,1,1,1,1 },
3 { 1,1,0,1,0,1,1,0,0,0,1,1 },
4 { 1,1,0,1,0,1,1,0,1,0,1,1 },
5 { 1,1,0,1,0,0,0,0,1,0,1,1 },
6 { 1,1,0,1,1,1,1,1,1,0,1,1 },
7 { 1,1,0,1,1,1,1,1,1,0,1,1 },
8 { 1,1,0,0,0,1,1,1,1,0,1,1 },
9 { 1,1,1,1,0,1,1,1,1,0,1,1 },
10{ 1,1,1,1,0,0,1,1,1,0,0,1 },
11{ 1,1,1,1,1,1,1,1,1,1,1,1 },
};
*/