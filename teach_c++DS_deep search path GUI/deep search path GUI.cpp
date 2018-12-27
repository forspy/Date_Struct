#include "deep search path GUI.h"
#include<ctime>
#include <windows.h>
//老鼠回忆
PATH_DIR Mouse::Recall()
{
	PATH_DIR dir = m_brain.top();//将栈顶的元素记下
	m_brain.pop();//弹出栈顶的元素 
	return dir;
}
//老鼠前进(压栈+保持方向)
void Mouse::Run(PATH_DIR dir)
{
	switch (dir)
	{
	//因为出口是在右下所以优先判断右/下能够提高效率
	case RIGHT:
		mouse_col++;
		m_dir = RIGHT;
		break;
	case DOWN:
		mouse_row++;
		m_dir = DOWN;
		break;
	case LEFT:
		mouse_col--;
		m_dir = LEFT;
		break;
	case UP:
		mouse_row--;
		m_dir = UP;
		break;
	}
	//不管往哪个方向，总步数和有效步数都要++
	m_countStep++;
	m_validStep++; 
	Remember(m_dir);//记住行进方向 
}
//老鼠回退(弹栈+改变方向)
void Mouse::Back()
{
	//所以应该是回忆里面(原来栈顶的数据)的反方向
	switch (Recall())//表示原来前进的方向，回退就是相反方向
	{
	case RIGHT:
		mouse_col--;
		m_dir = LEFT;
		break;
	case DOWN:
		mouse_row--;
		m_dir = UP;
		break;
	case LEFT:
		mouse_col++;
		m_dir = RIGHT;
		break;
	case UP:
		mouse_row++;
		m_dir = DOWN;
		break;
	}
	m_countStep++;//总步数还是++
	m_validStep--;//有效步数--
	//退的时候stack就pop了所以不需要记忆，在recall()里面就已经做完了
}

//

Maze::Maze(int row, int col):maze_row(row),maze_col(col)
{
	//创建地图
	//先创建一排一级指针
	m_space = new char*[row];
	//对每个一级指针创建col个内存，即列
	for (int i = 0; i < row; i++)
	{
		m_space[i] = new char[col];
	}
	//创建老鼠,起点定为（0，1），初始方向向右
	m_pMouse = new Mouse(0, 1, RIGHT);
	//画地图
	InitMaze();
}
void Maze::ShowMaze()
{
	system("cls");//每次画之前清屏
	for (int i = 0; i < maze_row; i++)
	{
		for (int j = 0; j < maze_col; j++)
		{
			char c=(m_space[i][j] == M_mouse )? mouseDir[m_pMouse->m_dir] : m_space[i][j];//如果是老鼠就画出老鼠的朝向，否则画出空间该点元素
			cout << c << " ";//打印一个字符空一格
		}
		cout << endl;//打印完一行换行
	}
	cout << "总共走了" << m_pMouse->m_countStep << "步" << endl;
	cout << "有效步数为" << m_pMouse->m_validStep << "步" << endl;
	Sleep(200);//300ms打印一次（需要头文件window.h）
}
Maze::~Maze()
{
	if (m_space)
	{
		//释放
		//1.先释放指针数组中一个指针对应的一维动态数组内存
		for (int j = 0; j < maze_col; j++)
			delete[] m_space[j];
		//2.再释放一排指针数组
		delete[] m_space;
		m_space = nullptr;
	}
	if (m_pMouse)
	{
		delete m_pMouse;
		m_pMouse = nullptr;
	}
}
//生成地图
void Maze::InitMaze()
{
	srand((unsigned int)time(nullptr));//建立随机数种子
	for (int i = 0; i < maze_row; i++)
	{
		for (int j = 0; j < maze_col ; j++)
		{
			//判断该点是不是老鼠,并且需要使得Maze类拿到Mouse类的私有权限，所以需要在Mouse类中添加Maze类为友元
			if (i == m_pMouse->mouse_row&& j == m_pMouse->mouse_col)
			{
				m_space[i][j] = M_mouse;
			}
			//因为地图是随机生成的，为了让老鼠寻路更有游戏体验，将前三格个最后三格挖通
			else if ((i == 1 && j < 4) || (i == maze_row - 2 && j > maze_col - 4))
			{
				m_space[i][j] = M_way;
			}
			//画围墙
			else if (i == 0 || i == maze_row - 1 || j == 0 || j == maze_col - 1)
			{
				m_space[i][j] = M_wall;
			}
			//其他情况生成墙和路
			else
			{
				m_space[i][j] = rand() % 3 ? M_way : M_wall;//按照2：1的比例生成路和墙
			}
		}
	}
}
//跑动方式
bool Controller::Step()
{
	//当前的坐标
	int row = m_pMaze->m_pMouse->mouse_row;
	int col = m_pMaze->m_pMouse->mouse_col;
	m_pMaze->m_space[row][col] = M_pass;//把当前这一点写成路径
	
	if (col <= m_pMaze->maze_col - 2 && m_pMaze->m_space[row][col + 1] == M_way)//下一步往右走（不越界）并且下一步在地图中是路
		m_pMaze->m_pMouse->Run(RIGHT);//就让老鼠往右走,注意maze_col-1表示最后一列，所以要取倒数第2列
	else if (row <= m_pMaze->maze_row - 2 && m_pMaze->m_space[row + 1][col] == M_way)
		m_pMaze->m_pMouse->Run(DOWN);//就让老鼠往下走
	else if (col >= 1 && m_pMaze->m_space[row][col - 1] == M_way)
		m_pMaze->m_pMouse->Run(LEFT);//就让老鼠往左走
	else if (row >= 1 && m_pMaze->m_space[row - 1][col] == M_way)
		m_pMaze->m_pMouse->Run(UP);//就让老鼠往上走
	else//四个方向都每路，往回退
	{
		m_pMaze->m_space[row][col] = M_impass;//设置为已经走过的路X
		m_pMaze->m_pMouse->Back();//回退
	}
	//更新当前位置坐标
	row = m_pMaze->m_pMouse->mouse_row;
	col = m_pMaze->m_pMouse->mouse_col;
	//当前地图位置更新为老鼠字符
	m_pMaze->m_space[row][col] = M_mouse;
	//更新完一次显示一次
	m_pMaze->ShowMaze();
	//当前位置是终点
	if (row == m_pMaze->maze_row - 2 && col == m_pMaze->maze_col - 1)//表示到达终点位置，退出
	{
		cout << "找到了出口！" << endl;
		return false;
	}
	//回到了起点,说明没有找到
	if (row == 1 && col == 0)
	{
		cout << "没有找到了出口，嘤嘤嘤！" << endl;
		return false;
	}
	return true;//不然就一直走下去
}
Controller::Controller()
{
	m_pMaze = new Maze(20, 20);
}
//开始控制跑动
void Controller::StarRun()
{
	//因为至少要跑动一次，所以用do while循环
	do
	{
		m_pMaze->ShowMaze();
	} while (Step());
}
