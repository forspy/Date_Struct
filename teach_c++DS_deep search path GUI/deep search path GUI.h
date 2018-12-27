#pragma once
//���Ѱ·GUI---�������ı��˼��
#include<iostream>
#include<stack>//����stackջ���洢�߹��ĵ㣬��Ȼ��ʹ��listҲ��
using namespace std;


//1.׼���Թ��ַ�
enum MAZE_CHAR
{
	M_mouse = '&',//����
	M_way = ' ',//·
	M_wall = '#',//ǽ
	M_pass = '.',//�߹���·
	M_impass = 'x',//��ʾ��·
};
//2.׼������
enum PATH_DIR
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
};
//3.׼������ĳ���
const char mouseDir[5] = "^V<>";//��ʾ��������

//4.�����࣬����Ѱ·
class Mouse
{
private:
	int  mouse_row, mouse_col;//����λ�� 
	int m_countStep, m_validStep;//�ܲ�������Ч����
	PATH_DIR m_dir;//�淽��
	stack<PATH_DIR> m_brain;//��¼�߹��ķ��򣬼��߹��ĵ�

	//�������
	void Remember(PATH_DIR dir) { m_brain.push(dir); }//�������߹��ķ���ѹ��ջ�У��γɼ���
	//�������
	PATH_DIR Recall();
	friend class Maze;
	friend class Controller;
public:
	//�����ʼ�� ��Ҫ���λ�úͷ���
	Mouse(int row, int col, PATH_DIR dir) :mouse_row(row), mouse_col(col), m_dir(dir), m_countStep(0), m_validStep(0) { };

	//����ǰ��
	void Run(PATH_DIR dir);
	//�������
	void Back();
};

//�Թ���
class Maze
{
private:
	char** m_space;//�ö���ָ����������ά����
	int maze_row, maze_col;//�Թ��Ŀ�
	Mouse* m_pMouse; //����

	void InitMaze();//���ɵ�ͼ
	friend class Controller;
public:
	Maze(int row, int col);
	void ShowMaze();//��ʾ��ͼ
	~Maze();
};

//������--������������߶�
class Controller
{
private:
	Maze* m_pMaze;
	bool Step();//�ܶ���ʽ
public:
	Controller();//��Ҫ���˹����ͼ�ĳ�ʼ��
	void StarRun();//��ʼ�����ܶ�
}; 