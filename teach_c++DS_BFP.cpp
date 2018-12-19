//广度寻路：这里的方法是构造一颗树(4叉)来进行遍历搜索
#include<iostream>
#include<vector>
#define MAP_ROW 12
#define MAP_COL 12
using namespace std;

enum pathDir{UP,DOWN,RIGHT,LEFT};
struct pathInfo//节点信息
{
	int row;
	int col;
	int val;//是路还是墙
	bool visited;
	pathDir dir;//要走的方向
};
//准备一个节点以形成一颗树
struct pathNode//树的节点
{
	pathInfo  info;//节点信息
	pathNode* parent;//父指针，用来逆向回溯父节点，以形成完整的路径
	vector<pathNode*> child;//指向子节点指针的数组
};
//检查节点是否可以通行
bool isPass(pathInfo& curPos,pathInfo pathArr[][MAP_COL]);
//释放节点内存
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
	//构建一个备用的地图信息对象的二维数组
	pathInfo pathArr[MAP_ROW][MAP_COL];
	//初始化
	for (int i = 0; i < MAP_ROW; i++)
	{
		for (int j = 0; j < MAP_COL; j++)
		{
			pathArr[i][j].row = i;
			pathArr[i][j].col = j;
			pathArr[i][j].dir = RIGHT;//初始化方向为右 
			pathArr[i][j].val= mapArr[i][j];
			pathArr[i][j].visited = false;
		}
	}
	//标记起点和终点
	pathInfo beginPosInfo = pathArr[1][1];
	pathInfo endPosInfo = pathArr[10][10];
	//在地图上将起点标记为已经访问
	pathArr[beginPosInfo.row][beginPosInfo.col].visited = true;
	//定义一个根节点,并初始化
	pathNode* pRoot = new pathNode;
	pRoot->info = beginPosInfo;
	pRoot->parent = nullptr;
	pRoot->child.clear();
	//定义两个vector，一个v1来存放这一层所有准备扩展的节点，然后这一层节点的子节点，放到下一层v2中
	vector<pathNode*> nodeArr;
	vector<pathNode*> nodeNext;

	nodeArr.push_back(pRoot);//先把proot压入
	pathInfo tempPosInfo;//用一个临时地图位置信息来帮助遍历查找
	while (true)
	{
		//bool isFind = false;//是否找到
		for (size_t i = 0; i < nodeArr.size(); i++)
		{
			for (int j = 0; j < 4; j++)
			{
				tempPosInfo = nodeArr[i]->info;//tempposInfo准备表示为子节点的其中一个方向，其实tempInfo只提供坐标位置，isPass通过arrPth来判断
				switch (j)//0-3对应四个方向
				{
				case UP:
					tempPosInfo.row--;
					//因为是4个方向的所以其他的不用改包括val、dir、visited(visited要确定ispass后才改)，其实tempInfo只提供坐标位置
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
				if (isPass(tempPosInfo,pathArr))//来判断子节点是不是能走
				{
					//利用符合条件的地图点来建立子节点并链接
					pathNode* newnode = new pathNode;
					newnode->info = pathArr[tempPosInfo.row][tempPosInfo.col];//输入newnode的信息
					newnode->parent = nodeArr[i];//子节点/链接父节点
					nodeArr[i]->child.push_back(newnode);//让父节点链接子节点
					//设置为访问
					pathArr[tempPosInfo.row][tempPosInfo.col].visited = true;
					//子节点加入第二个容器
					nodeNext.push_back(newnode);
					//如果该点是终点
					if (tempPosInfo.row == endPosInfo.row&&tempPosInfo.col == endPosInfo.col)
					{
						//isFind = true;
						//打印路径
						pathNode* tempNode = newnode;//利用一个临时节点进行遍历打印，从最后的节点往上输出链接的父节点
						while (tempNode)
						{
							cout << "row=" << tempNode->info.row << ",col=" << tempNode->info.col << endl;
							tempNode = tempNode->parent;
						}
						clear(pRoot);//找到终点了并打印完了，根据现在的需求就可以释放内存了，如过还有其他需求就可以等一会儿释放
						return 1;//退出所有循环
					}
				}
			}
		}
		if (nodeNext.size() == 0)//表示树走到了所有的叶子节点，没有接下去的节点可压入，即没有路了
			break;
		nodeArr = nodeNext;//把下一层的节点赋给上一层，赋值的过程会自动把上一层的节点清空，所以不需要对上一层vector进行clear()
		nodeNext.clear();//把下一层的清空
	}
}
//检查点是否可以通行
bool isPass(pathInfo& curPos, pathInfo pathArr[][MAP_COL])//待优化,已优化，curPos只提供当前的坐标
{
	
	if (curPos.row >= 0 && curPos.row <= MAP_ROW&&curPos.col >= 0 && curPos.col <= MAP_COL
		&&pathArr[curPos.row][curPos.col].val==0
		&& pathArr[curPos.row][curPos.col].visited==false)
	{
		return true;
	}
	return false;
}
//释放节点内存，从子节点开始清空
void clear(pathNode *& root)
{
	if (root)
	{
		for (size_t i = 0; i < root->child.size(); i++)//依次找到vector里面存放的所有子节点指针进行释放
		{
			clear(root->child[i]);
		}
		delete root;//释放根节点
		root = nullptr;//置为空
	}
}
