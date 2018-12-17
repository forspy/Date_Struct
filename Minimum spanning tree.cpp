//生成树：包含图G所有顶点的极小连通子图（n - 1条边）。
//N个顶点最多形成N(N-1)/2条边，因为A-B=B-A所以要/2
//最小生成树：在网的多个生成树中，寻找一个各边权值之和最小的生成树
/*构造最小生成树的准则：(最短路径)
必须只使用该网中的边来构造最小生成树；
必须使用且仅使用n-1条边来联结网络中的n个顶点
不能使用产生回路的边
*/
/*
实际问题：
欲在n个城市间建立通信网，则n个城市应铺n-1条线路；但因为每条线路都会有对应的经济成本，
而n个城市可能有n(n-1)/2 条线路，那么，如何选择n–1条线路，使总费用最少？
*/
//补充：贪心算法(Greedy Algorithm)
/*
算法原理：以当前情况为基础作最优选择，而不考虑各种可能的整体情况，所以贪心法不要回溯。
算法优点：因为省去了为寻找解而穷尽所有可能所必须耗费的大量时间，因此算法效率高。
注意：贪婪算法的精神就是“只顾如何获得眼前最大的利益”,有时不一定是最优解。
*/
//如何求最小生成树
/*
Prim算法: 归并顶点，与边数无关，适于稠密网
Kruskal算法：归并边，适于稀疏网
*/
/*
普里姆算法的基本思想——归并顶点
1. 从某顶点 u0 出发，选择与它关联的具有最小权值的边(u0, v)，将其顶点加入到生成树的顶点集合U中
2. 每一步从一个顶点在U中，而另一个顶点不在U中的各条边中选择权值最小的边(u, v),把它的顶点加入到U中
3. 直到所有顶点都加入到生成树顶点集合U中为止
*/
/*
克鲁斯卡尔算法的基本思想－归并边
1. 构造一个只有 n 个顶点，没有边的非连通图 T = { V, null }, 每个顶点自成一个连通分量(递归的过程保证不构成连通图)
2. 在 E 中选最小权值的边,若该边的两个顶点落在不同的连通分量上，则加入 T 中；否则舍去，重新选择
3. 重复下去，直到所有顶点在同一连通分量上为止
*/
/*
应用：
典型用途：交通问题。如：城市A到城市B有多条线路，但每条线路的交通费（或所需时间）不同，那么，如何选择一条线路，
使总费用（或总时间）最少？
问题抽象：在带权有向图中A点（源点）到达B点（终点）的多条路径中，寻找一条各边权值之和最小的路径，即最短路径。
注意最短路径与最小生成树不同，最短路径不一定包含N个顶点
其他应用：
计算机网络路由
机器人探路
游戏开发

*/
#include <iostream>
using namespace std;

typedef char VerTexType;
typedef int ArcType;

#define MVNum 100
#define MaxInt 65535  // 表示极大值

// 辅助数组的定义，用来记录从顶点集U到V-U的权值最小的边
struct {
	VerTexType adjvex;  // 最小边在U中的顶点
	ArcType lowcost;  // 最小边上的权值
}closedge[MVNum];

// 定义图的邻接表存储类型
typedef char VerTexType; // 顶点的数据类型为字符
typedef int ArcType; // 边权值类型
typedef struct {
	VerTexType vexs[MVNum];  // 顶点表
	ArcType arcs[MVNum][MVNum]; // 邻接矩阵
	int vexnum, arcnum; // 顶点 边数
}AMGraph;

// 确定v在G图中的位置
int LocateVex(AMGraph G, VerTexType v) {
	for (int i = 0; i < G.vexnum; i++)
		if (G.vexs[i] == v)
			return i;
	return -1;
}

// 创建无向网（G），用邻接矩阵表示
void CreateUDN(AMGraph &G) {
	int i, j, k;
	cout << "请输入顶点 边总数，用空格隔开:";
	cin >> G.vexnum >> G.arcnum;
	cout << endl;

	cout << "请输入顶点的名称，比如:A" << endl;

	for (i = 0; i < G.vexnum; i++) {
		cout << "请输入第" << (i + 1) << "个点的名称:";
		cin >> G.vexs[i];
	}
	cout << endl;

	// 初始化邻接矩阵，边的权值

	for (i = 0; i < G.vexnum; i++)
		for (j = 0; j < G.vexnum; j++)
			G.arcs[i][j] = MaxInt;

	cout << "请输入边所附的顶点及权值: 比如:A B 89" << endl;
	for (k = 0; k < G.arcnum; k++)
	{
		VerTexType v1, v2;
		ArcType w;
		cout << "请输入第" << (k + 1) << "条边依附的顶点及权值:";
		cin >> v1 >> v2 >> w;

		// 确定v1 v2在G图中位置，顶点数组下标 
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);

		G.arcs[i][j] = w;  // 边 <v1,v2>权值
		G.arcs[j][i] = G.arcs[i][j]; // <v1,v2>  <v2,v1> 的权值为w
	}
}

// 返回权值最小的点
int Min(AMGraph G) {
	int i;
	int index = -1;
	int min = MaxInt;
	for (i = 0; i < G.vexnum; i++) {
		if (min>closedge[i].lowcost && closedge[i].lowcost != 0) {
			min = closedge[i].lowcost;
			index = i;
		}
	}

	return index;
}

// 无向网G以邻接矩阵形式存储，从顶点u出发构造G的最小生成树T，输出T的各条边
void MiniSpan_Prim(AMGraph G, VerTexType u) {
	int i, j, k;
	VerTexType u0, v0;

	k = LocateVex(G, u);  // 表示k为顶点u的下标 

	for (j = 0; j < G.vexnum; j++) {
		if (j != k) {
			closedge[j].adjvex = u;
			closedge[j].lowcost = G.arcs[k][j];
		}
	}

	closedge[k].lowcost = 0;
	for (i = 1; i < G.vexnum; i++) {
		k = Min(G);   // 选择其余n-1个顶点，生成n-1条边

		u0 = closedge[k].adjvex;  // u0为最小的一个顶点 uo属于U
		v0 = G.vexs[k];    // v0为最小边的另一个顶点 v0属于V
		cout << "边  " << u0 << "------>" << v0 << endl;  // 输出最小边

														 // 第k个顶点并入U集
		closedge[k].lowcost = 0;
		for (j = 0; j < G.vexnum; j++)
			if (G.arcs[k][j] < closedge[j].lowcost) {  // 新顶点并入U后重新选择最小边
				closedge[j].adjvex = G.vexs[k];
				closedge[j].lowcost = G.arcs[k][j];
			}
	}
}

int main()
{
	cout << "测试普里姆算法" << endl;
	AMGraph G;

	CreateUDN(G);
	cout << endl;

	cout << "无向网G创建成功.\n";
	cout << endl;

	cout << "通过普里姆算法构造最小生成树结果如下:" << endl;
	MiniSpan_Prim(G, 'a');
	cout << endl;

	return 0;
}