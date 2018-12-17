//图的存储结构：数组表示法（邻接矩阵），链表表示法（邻接表）
/*
邻接矩阵表示法：
两个顶点表在行和列方向，利用二维矩阵表示顶点的关系(对称矩阵)
  v1 v2 v3 v4
v1 0  1  1  0
v2 1  0  1  1（例如v2的度为第二行1的个数，所以v2的度为3，表示有三个顶点和v2相连）
v3 1  1  0  1
v4 0  1  1  0

v1--v2
|  / |
v3--v4
在有向图中第i行表示出度顶点
有向图的邻接矩阵可能是不对称的
顶点的出度=第i行的元素之和
顶点的入度=第i列的元素之和
顶点的度=第i行的元素之和+第i列的元素之和

网（有权图）的邻接矩阵的表示方法
邻接矩阵类似于一般图，只是把1换成了权，没有连接的把0改成∞

邻接矩阵表示法的特点：
优点：容易实现图的操作，例如求某顶点的度，判断顶点之间是否有边，找顶点的连接点等。
缺点：n个顶点需要n*n个单元储存边，空间复杂度为O（n^2）,对稀疏图而言尤其浪费空间
*/
//链式图
/*
|序号|链域|数据域(权值)|
比如上图：
每个单链表有一个头节点，头节点存放vi的信息，所有有几个节点就有几个单链表
无向图的邻接表示
|0|->|2|->|1|(最好链接节点的序号从大到小，但其实不唯一，链接顺序是任意的)
|1|->|3|->|2|->|1|
|2|->|3|->|1|->|0|
|3|->|2|->|1|
线上的值表示权值，存在节点的数据域中
其实可以使用一个vector存放0-3序号的节点信息，vector里面的元素为头节点，指向各自的单链表，
因为对应的是链表，没有相连的节点就不进行链接，所以节省了空间
邻接链表的空间效率为O(n+2e)若是稀疏图，比邻接矩阵的表示法O(n^2节省空间)
TD表示单链表中的链接节点个数
有向邻接链表只链接出度的节点，链接的节点顺序任意，空间效率O(n+e)
TD=OD(出度)+ID(入度)

*/
/*
邻接矩阵图和邻接链表的区别是：
1.对于任意确定的无向图，邻接矩阵是唯一的，而邻接表不唯一，因为链接的顺序可以是任意的
2.邻接矩阵的空间复杂度为O(n^2),而邻接表的空间复杂度为O(n+e)
3.邻接表一个单链表对应邻接矩阵的一行
4.邻接矩阵多用于稠密图，邻接表多用于稀疏图
*/
/*
十字链表：
|数据域|序号|出度指针域|入度指针域|
*/

#include"MatrixUDG.h"
#include<iostream>
#include<vector>
#include"ListUDG.h"
using namespace std;
int main()
{
	//边的信息
	char vertax[] = { 'A','B','C','D','E','F' };
	int vertaxNum = sizeof(vertax) / sizeof(vertax[0]);
	char edge[][2] = {//无向图的边信息
		{'A','B'},
		{'A','C'},
		{'B','C'},
		{'B','E'},
		{'B','F'},
		{'C','F'},
		{'C','E'},
		{'C','D'},
		{'E','F'},
	};
	int edgeNum = sizeof(edge) / sizeof(edge[0]);
	//int a=sizeof(edge);
	MatrixUDG MUDG(vertax, edge, vertaxNum, edgeNum);
	cout << "无向图的邻接矩阵" << endl;
	MUDG.PrintMatrixUDG();
	cout << "无向图的深度遍历" << endl;
	MUDG.DFS();
	cout << "无向图的深度遍历简化版" << endl;
	MUDG.DFS_opt();
	cout << "无向图的深度遍历非递归版" << endl;
	MUDG.DFS_Non_recursive();
	cout << "无向图的广度遍历" << endl;
	MUDG.BFS();
	//-------------------------------
	char vertax1[] = { 'A','B','C','D','E','F' };
	int vertaxNum1 = sizeof(vertax) / sizeof(vertax[0]);
	char edge1[][2] = {
		{'A','B'},
		{'B','C'},
		{'B','E'},
		{'B','F'},
		{'C','D'},
		{'C','F'},
		{'E','F'},
		{'F','C'},
	};
	int edgeNum1 = sizeof(edge1) / sizeof(edge1[0]);
	MatrixDG MDG(vertax1, edge1, vertaxNum1, edgeNum1);
	cout << "有向图的邻接矩阵" << endl;
	MDG.PrintMatrixDG();

	//----------------邻接表
	ListUDG LUDG(vertax, edge, vertaxNum, edgeNum);
	cout << "无向图的邻接表" << endl;
	LUDG.PrintListUDG();
	ListDG LDG(vertax1, edge1, vertaxNum1, edgeNum1);
	cout << "有向图的邻接表" << endl;
	LDG.PrintListDG();
}