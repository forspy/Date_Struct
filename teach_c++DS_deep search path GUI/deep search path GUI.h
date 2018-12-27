#pragma once
//深度寻路GUI---面向对象的编程思想
#include<iostream>
#include<stack>//利用stack栈来存储走过的点，当然，使用list也行
using namespace std;


//1.准备迷宫字符
enum MAZE_CHAR
{
	M_mouse = '&',//老鼠
	M_way = ' ',//路
	M_wall = '#',//墙
	M_pass = '.',//走过的路
	M_impass = 'x',//表示死路
};
//2.准备方向
enum PATH_DIR
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
};
//3.准备老鼠的朝向
const char mouseDir[5] = "^V<>";//表示上下左右

//4.老鼠类，用来寻路
class Mouse
{
private:
	int  mouse_row, mouse_col;//老鼠位置 
	int m_countStep, m_validStep;//总步数，有效步数
	PATH_DIR m_dir;//存方向
	stack<PATH_DIR> m_brain;//记录走过的方向，即走过的点

	//老鼠记忆
	void Remember(PATH_DIR dir) { m_brain.push(dir); }//将老鼠走过的方向压入栈中，形成记忆
	//老鼠回忆
	PATH_DIR Recall();
	friend class Maze;
	friend class Controller;
public:
	//老鼠初始化 需要起点位置和方向
	Mouse(int row, int col, PATH_DIR dir) :mouse_row(row), mouse_col(col), m_dir(dir), m_countStep(0), m_validStep(0) { };

	//老鼠前进
	void Run(PATH_DIR dir);
	//老鼠回退
	void Back();
};

//迷宫类
class Maze
{
private:
	char** m_space;//用二级指针来创建二维数组
	int maze_row, maze_col;//迷宫的宽长
	Mouse* m_pMouse; //老鼠

	void InitMaze();//生成地图
	friend class Controller;
public:
	Maze(int row, int col);
	void ShowMaze();//显示地图
	~Maze();
};

//控制器--来控制老鼠的走动
class Controller
{
private:
	Maze* m_pMaze;
	bool Step();//跑动方式
public:
	Controller();//不要忘了构造地图的初始化
	void StarRun();//开始控制跑动
}; 