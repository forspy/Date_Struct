#include "deep search path GUI.h"
#include<ctime>
#include <windows.h>
//�������
PATH_DIR Mouse::Recall()
{
	PATH_DIR dir = m_brain.top();//��ջ����Ԫ�ؼ���
	m_brain.pop();//����ջ����Ԫ�� 
	return dir;
}
//����ǰ��(ѹջ+���ַ���)
void Mouse::Run(PATH_DIR dir)
{
	switch (dir)
	{
	//��Ϊ���������������������ж���/���ܹ����Ч��
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
	//�������ĸ������ܲ�������Ч������Ҫ++
	m_countStep++;
	m_validStep++; 
	Remember(m_dir);//��ס�н����� 
}
//�������(��ջ+�ı䷽��)
void Mouse::Back()
{
	//����Ӧ���ǻ�������(ԭ��ջ��������)�ķ�����
	switch (Recall())//��ʾԭ��ǰ���ķ��򣬻��˾����෴����
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
	m_countStep++;//�ܲ�������++
	m_validStep--;//��Ч����--
	//�˵�ʱ��stack��pop�����Բ���Ҫ���䣬��recall()������Ѿ�������
}

//

Maze::Maze(int row, int col):maze_row(row),maze_col(col)
{
	//������ͼ
	//�ȴ���һ��һ��ָ��
	m_space = new char*[row];
	//��ÿ��һ��ָ�봴��col���ڴ棬����
	for (int i = 0; i < row; i++)
	{
		m_space[i] = new char[col];
	}
	//��������,��㶨Ϊ��0��1������ʼ��������
	m_pMouse = new Mouse(0, 1, RIGHT);
	//����ͼ
	InitMaze();
}
void Maze::ShowMaze()
{
	system("cls");//ÿ�λ�֮ǰ����
	for (int i = 0; i < maze_row; i++)
	{
		for (int j = 0; j < maze_col; j++)
		{
			char c=(m_space[i][j] == M_mouse )? mouseDir[m_pMouse->m_dir] : m_space[i][j];//���������ͻ�������ĳ��򣬷��򻭳��ռ�õ�Ԫ��
			cout << c << " ";//��ӡһ���ַ���һ��
		}
		cout << endl;//��ӡ��һ�л���
	}
	cout << "�ܹ�����" << m_pMouse->m_countStep << "��" << endl;
	cout << "��Ч����Ϊ" << m_pMouse->m_validStep << "��" << endl;
	Sleep(200);//300ms��ӡһ�Σ���Ҫͷ�ļ�window.h��
}
Maze::~Maze()
{
	if (m_space)
	{
		//�ͷ�
		//1.���ͷ�ָ��������һ��ָ���Ӧ��һά��̬�����ڴ�
		for (int j = 0; j < maze_col; j++)
			delete[] m_space[j];
		//2.���ͷ�һ��ָ������
		delete[] m_space;
		m_space = nullptr;
	}
	if (m_pMouse)
	{
		delete m_pMouse;
		m_pMouse = nullptr;
	}
}
//���ɵ�ͼ
void Maze::InitMaze()
{
	srand((unsigned int)time(nullptr));//�������������
	for (int i = 0; i < maze_row; i++)
	{
		for (int j = 0; j < maze_col ; j++)
		{
			//�жϸõ��ǲ�������,������Ҫʹ��Maze���õ�Mouse���˽��Ȩ�ޣ�������Ҫ��Mouse�������Maze��Ϊ��Ԫ
			if (i == m_pMouse->mouse_row&& j == m_pMouse->mouse_col)
			{
				m_space[i][j] = M_mouse;
			}
			//��Ϊ��ͼ��������ɵģ�Ϊ��������Ѱ·������Ϸ���飬��ǰ��������������ͨ
			else if ((i == 1 && j < 4) || (i == maze_row - 2 && j > maze_col - 4))
			{
				m_space[i][j] = M_way;
			}
			//��Χǽ
			else if (i == 0 || i == maze_row - 1 || j == 0 || j == maze_col - 1)
			{
				m_space[i][j] = M_wall;
			}
			//�����������ǽ��·
			else
			{
				m_space[i][j] = rand() % 3 ? M_way : M_wall;//����2��1�ı�������·��ǽ
			}
		}
	}
}
//�ܶ���ʽ
bool Controller::Step()
{
	//��ǰ������
	int row = m_pMaze->m_pMouse->mouse_row;
	int col = m_pMaze->m_pMouse->mouse_col;
	m_pMaze->m_space[row][col] = M_pass;//�ѵ�ǰ��һ��д��·��
	
	if (col <= m_pMaze->maze_col - 2 && m_pMaze->m_space[row][col + 1] == M_way)//��һ�������ߣ���Խ�磩������һ���ڵ�ͼ����·
		m_pMaze->m_pMouse->Run(RIGHT);//��������������,ע��maze_col-1��ʾ���һ�У�����Ҫȡ������2��
	else if (row <= m_pMaze->maze_row - 2 && m_pMaze->m_space[row + 1][col] == M_way)
		m_pMaze->m_pMouse->Run(DOWN);//��������������
	else if (col >= 1 && m_pMaze->m_space[row][col - 1] == M_way)
		m_pMaze->m_pMouse->Run(LEFT);//��������������
	else if (row >= 1 && m_pMaze->m_space[row - 1][col] == M_way)
		m_pMaze->m_pMouse->Run(UP);//��������������
	else//�ĸ�����ÿ·��������
	{
		m_pMaze->m_space[row][col] = M_impass;//����Ϊ�Ѿ��߹���·X
		m_pMaze->m_pMouse->Back();//����
	}
	//���µ�ǰλ������
	row = m_pMaze->m_pMouse->mouse_row;
	col = m_pMaze->m_pMouse->mouse_col;
	//��ǰ��ͼλ�ø���Ϊ�����ַ�
	m_pMaze->m_space[row][col] = M_mouse;
	//������һ����ʾһ��
	m_pMaze->ShowMaze();
	//��ǰλ�����յ�
	if (row == m_pMaze->maze_row - 2 && col == m_pMaze->maze_col - 1)//��ʾ�����յ�λ�ã��˳�
	{
		cout << "�ҵ��˳��ڣ�" << endl;
		return false;
	}
	//�ص������,˵��û���ҵ�
	if (row == 1 && col == 0)
	{
		cout << "û���ҵ��˳��ڣ������ӣ�" << endl;
		return false;
	}
	return true;//��Ȼ��һֱ����ȥ
}
Controller::Controller()
{
	m_pMaze = new Maze(20, 20);
}
//��ʼ�����ܶ�
void Controller::StarRun()
{
	//��Ϊ����Ҫ�ܶ�һ�Σ�������do whileѭ��
	do
	{
		m_pMaze->ShowMaze();
	} while (Step());
}
