//���Ѱ·������ķ����ǹ���һ����(4��)�����б�������
#include<iostream>
#include<vector>
#define MAP_ROW 12
#define MAP_COL 12
using namespace std;

enum pathDir{UP,DOWN,RIGHT,LEFT};
struct pathInfo//�ڵ���Ϣ
{
	int row;
	int col;
	int val;//��·����ǽ
	bool visited;
	pathDir dir;//Ҫ�ߵķ���
};
//׼��һ���ڵ����γ�һ����
struct pathNode//���Ľڵ�
{
	pathInfo  info;//�ڵ���Ϣ
	pathNode* parent;//��ָ�룬����������ݸ��ڵ㣬���γ�������·��
	vector<pathNode*> child;//ָ���ӽڵ�ָ�������
};
//���ڵ��Ƿ����ͨ��
bool isPass(pathInfo& curPos,pathInfo pathArr[][MAP_COL]);
//�ͷŽڵ��ڴ�
void clear(pathNode*& root);
int main()
{
	int mapArr[MAP_ROW][MAP_COL] =
	{
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
	//����һ�����õĵ�ͼ��Ϣ����Ķ�ά����
	pathInfo pathArr[MAP_ROW][MAP_COL];
	//��ʼ��
	for (int i = 0; i < MAP_ROW; i++)
	{
		for (int j = 0; j < MAP_COL; j++)
		{
			pathArr[i][j].row = i;
			pathArr[i][j].col = j;
			pathArr[i][j].dir = RIGHT;//��ʼ������Ϊ�� 
			pathArr[i][j].val= mapArr[i][j];
			pathArr[i][j].visited = false;
		}
	}
	//��������յ�
	pathInfo beginPosInfo = pathArr[1][1];
	pathInfo endPosInfo = pathArr[10][10];
	//�ڵ�ͼ�Ͻ������Ϊ�Ѿ�����
	pathArr[beginPosInfo.row][beginPosInfo.col].visited = true;
	//����һ�����ڵ�,����ʼ��
	pathNode* pRoot = new pathNode;
	pRoot->info = beginPosInfo;
	pRoot->parent = nullptr;
	pRoot->child.clear();
	//��������vector��һ��v1�������һ������׼����չ�Ľڵ㣬Ȼ����һ��ڵ���ӽڵ㣬�ŵ���һ��v2��
	vector<pathNode*> nodeArr;
	vector<pathNode*> nodeNext;

	nodeArr.push_back(pRoot);//�Ȱ�prootѹ��
	pathInfo tempPosInfo;//��һ����ʱ��ͼλ����Ϣ��������������
	while (true)
	{
		//bool isFind = false;//�Ƿ��ҵ�
		for (size_t i = 0; i < nodeArr.size(); i++)
		{
			for (int j = 0; j < 4; j++)
			{
				tempPosInfo = nodeArr[i]->info;//tempposInfo׼����ʾΪ�ӽڵ������һ��������ʵtempInfoֻ�ṩ����λ�ã�isPassͨ��arrPth���ж�
				switch (j)//0-3��Ӧ�ĸ�����
				{
				case UP:
					tempPosInfo.row--;
					//��Ϊ��4����������������Ĳ��øİ���val��dir��visited(visitedҪȷ��ispass��Ÿ�)����ʵtempInfoֻ�ṩ����λ��
					break;
				case DOWN:
					tempPosInfo.row++;
					break;
				case LEFT:
					tempPosInfo.col--;
					break;
				case RIGHT:
					tempPosInfo.col++;
					break;
				}
				if (isPass(tempPosInfo,pathArr))//���ж��ӽڵ��ǲ�������
				{
					//���÷��������ĵ�ͼ���������ӽڵ㲢����
					pathNode* newnode = new pathNode;
					newnode->info = pathArr[tempPosInfo.row][tempPosInfo.col];//����newnode����Ϣ
					newnode->parent = nodeArr[i];//�ӽڵ�/���Ӹ��ڵ�
					nodeArr[i]->child.push_back(newnode);//�ø��ڵ������ӽڵ�
					//����Ϊ����
					pathArr[tempPosInfo.row][tempPosInfo.col].visited = true;
					//�ӽڵ����ڶ�������
					nodeNext.push_back(newnode);
					//����õ����յ�
					if (tempPosInfo.row == endPosInfo.row&&tempPosInfo.col == endPosInfo.col)
					{
						//isFind = true;
						//��ӡ·��
						pathNode* tempNode = newnode;//����һ����ʱ�ڵ���б�����ӡ�������Ľڵ�����������ӵĸ��ڵ�
						while (tempNode)
						{
							cout << "row=" << tempNode->info.row << ",col=" << tempNode->info.col << endl;
							tempNode = tempNode->parent;
						}
						clear(pRoot);//�ҵ��յ��˲���ӡ���ˣ��������ڵ�����Ϳ����ͷ��ڴ��ˣ����������������Ϳ��Ե�һ����ͷ�
						return 1;//�˳�����ѭ��
					}
				}
			}
		}
		if (nodeNext.size() == 0)//��ʾ���ߵ������е�Ҷ�ӽڵ㣬û�н���ȥ�Ľڵ��ѹ�룬��û��·��
			break;
		nodeArr = nodeNext;//����һ��Ľڵ㸳����һ�㣬��ֵ�Ĺ��̻��Զ�����һ��Ľڵ���գ����Բ���Ҫ����һ��vector����clear()
		nodeNext.clear();//����һ������
	}
}
//�����Ƿ����ͨ��
bool isPass(pathInfo& curPos, pathInfo pathArr[][MAP_COL])//���Ż�,���Ż���curPosֻ�ṩ��ǰ������
{
	
	if (curPos.row >= 0 && curPos.row <= MAP_ROW&&curPos.col >= 0 && curPos.col <= MAP_COL
		&&pathArr[curPos.row][curPos.col].val==0
		&& pathArr[curPos.row][curPos.col].visited==false)
	{
		return true;
	}
	return false;
}
//�ͷŽڵ��ڴ棬���ӽڵ㿪ʼ���
void clear(pathNode *& root)
{
	if (root)
	{
		for (size_t i = 0; i < root->child.size(); i++)//�����ҵ�vector�����ŵ������ӽڵ�ָ������ͷ�
		{
			clear(root->child[i]);
		}
		delete root;//�ͷŸ��ڵ�
		root = nullptr;//��Ϊ��
	}
}
