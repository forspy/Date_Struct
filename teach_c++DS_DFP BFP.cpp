//���Ѱ·�͹��Ѱ·
#include<iostream>
#include<stack>
using namespace std;
//���Ѱ·��һ�������·��
//ֻѡ��һ��·��
//Ѱ·��Ч��ȡ���ڷ���
#define MAP_ROW 12
#define MAP_COL 12
enum pathDir{UP,DOWN,RIGHT,LEFT};//��ʾ�õ���ĸ�����
struct pathNode
{
	int row;//��ǰ�����
	int col;//��ǰ�����
	int val;//ԭʼ��ͼ����
	bool visited;//�Ƿ��߹�
	pathDir dir;//����õ�ʱ��ѡ����еķ���
};
int main()
{
	//1.׼��һ����ͼ
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

	//׼��һ�������������ı��ͼ�ϵ���Ϣ
	//2.����һ����ά�����������������Ϣ���������洢���ͼ���ݡ�visited������
	pathNode pathArr[MAP_ROW][MAP_COL];
	for (int i = 0; i < MAP_ROW; i++)
	{
		for (int j = 0; j < MAP_COL; i++)
		{
			pathArr[i][j].row = i;//�������������Ϣ
			pathArr[i][j].col = j;//�������������Ϣ
			pathArr[i][j].val = arrMap[i][j];
			pathArr[i][j].visited = false;
			pathArr[i][j].dir = RIGHT;//��ʼ����Ϊ���ң�����ѡ�������ڳ�ȥ���㷽��Ϊ��ʼ����
		}
	}
	//3.���������յ�
	pathNode beginPoint = pathArr[1][1];
	//beginPoint.visited = true;
	pathNode endPoint = pathArr[10][10];
	//4.׼��һ��ջ�������߹���ÿһ����Ϊʲô��ջ�ء���Ϊ��ջ�Ǻ���ȳ������Ե��ߵ�����ͬ��ʱ���������ջ�ĵ��������лع�����
	//���⣬ջ�ڷǵݹ������ʱ����Ϊ���ص��������ܹ��洢���ڵ㣬��Ϊ��������ջ����ݹ����������˵DFS�ķǵݹ����
	stack<pathNode> pathStack;//����ջ
	//5.�����ѹ��ջ��
	pathStack.push(beginPoint);
	//6.����һ����ǰ��,��������
	pathNode curPoint = beginPoint;//��ʼ����ǰ��Ϊ���
	//7.��ʼѰ· 
	pathNode nextPoint;
	while (!pathStack.empty())//�˳�����Ϊջ�ջ��ߵ����յ�
	{
		//��һ����ô��,�жϷ���
		switch (pathArr[curPoint.row][curPoint.col].dir)
		{
		case UP:
			 nextPoint = pathArr[curPoint.row - 1][curPoint.col];//ʹ������Ӽ��
			if (curPoint.row - 1 >= 0 && nextPoint.val == 0 && nextPoint.visited == false)//�ж���һ���㲻Խ�粢����·�ſ���ͨ��
			{
				curPoint.visited = true;//�������������һ����Ϊtrue
				pathStack.push(nextPoint);//ѹ����һ����
				curPoint = nextPoint;//��ǰ�������һ����
			}
			else
				curPoint.dir = RIGHT;//���оͻ�����
			break;
		case RIGHT:
			 nextPoint = pathArr[curPoint.row ][curPoint.col+1];//ʹ������Ӽ��
			if (curPoint.col+1  <= MAP_COL && nextPoint.val == 0 && nextPoint.visited == false)//�ж���һ���㲻Խ�粢����·�ſ���ͨ��
			{
				curPoint.visited = true;//�������������һ����Ϊtrue
				pathStack.push(nextPoint);//ѹ����һ����
				curPoint = nextPoint;//��ǰ�������һ����
			}
			else
				curPoint.dir = DOWN;//���оͻ�����
			break;
		case DOWN:
			 nextPoint = pathArr[curPoint.row + 1][curPoint.col];//ʹ������Ӽ��
			if (curPoint.row + 1 >= MAP_ROW && nextPoint.val == 0 && nextPoint.visited == false)//�ж���һ���㲻Խ�粢����·�ſ���ͨ��
			{
				curPoint.visited = true;//�������������һ����Ϊtrue
				pathStack.push(nextPoint);//ѹ����һ����
				curPoint = nextPoint;//��ǰ�������һ����
			}
			else
				curPoint.dir = LEFT;//���оͻ�����
			break;
		case LEFT:
			 nextPoint = pathArr[curPoint.row ][curPoint.col-1];//ʹ������Ӽ��
			if (curPoint.col- 1 >= 0 && nextPoint.val == 0 && nextPoint.visited == false)//�ж���һ���㲻Խ�粢����·�ſ���ͨ��
			{
				curPoint.visited = true;//�������������һ����Ϊtrue
				pathStack.push(nextPoint);//ѹ����һ����
				curPoint = nextPoint;//��ǰ�������һ����
			}
			else//�����з����Թ��Ժ��ֲ����ٻ������ˣ��Ϳ�ʼ����ջ��Ԫ�ؽ��лع�
			{
				curPoint.visited = true;
				pathStack.pop();//��һ��
				if (!pathStack.empty())
				{
					curPoint = pathStack.top();//���µ�ջ����Ϊ��ǰ��
				}
			}
			break;
		}
		if (curPoint.row == endPoint.row&&curPoint.col == endPoint.col)//��ʾ�����յ�
			break;
	}
	//��ӡ·��,����ӡջ�е�����Ԫ�أ�·��Ϊ������Ϊջ�ױ�ʾ��ʼ��ջ����ʾ�����յ�
	while (!pathStack.empty())
	{
		cout << "row=" << pathStack.top().row << ",col=" << pathStack.top().col << endl;
		pathStack.pop();
	}
}