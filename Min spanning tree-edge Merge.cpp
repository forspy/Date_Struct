#include <iostream>
using namespace std;

typedef char VerTexType;
typedef int ArcType;

#define MVNum 100
#define MaxInt 65535  // 表示极大值

// 定义图的邻接矩阵存储类型
typedef struct {
	VerTexType vexs[MVNum];  // 顶点表
	ArcType arcs[MVNum][MVNum]; // 邻接矩阵
	int vexnum, arcnum; // 顶点 边数
}AMGraph;

// 辅助数组Edges的定义
struct {
	VerTexType Head;  // 边的始点
	VerTexType Tail;  // 边的终点
	ArcType lowcost;  // 边的权值
}Edge[(MVNum*(MVNum - 1)) / 2];

// 辅助数组Vexset
int VexSet[MVNum];


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

		Edge[k].lowcost = w;
		Edge[k].Head = v1;
		Edge[k].Tail = v2;
	}
}

// 使用冒泡排序处理
void SortT(AMGraph G) {
	int m = G.arcnum - 2;
	int flag = 1;

	while (m > 0 && flag == 1) {
		flag = 0;
		for (int j = 0; j <= m; j++) {
			if (Edge[j].lowcost > Edge[j + 1].lowcost) {
				flag = 1;

				VerTexType temp_Head = Edge[j].Head;
				Edge[j].Head = Edge[j + 1].Head;
				Edge[j + 1].Head = temp_Head;

				VerTexType temp_tail = Edge[j].Tail;
				Edge[j].Tail = Edge[j + 1].Tail;
				Edge[j + 1].Tail = temp_tail;

				ArcType temp_lowcost = Edge[j].lowcost;
				Edge[j].lowcost = Edge[j + 1].lowcost;
				Edge[j + 1].lowcost = temp_lowcost;
			}
		}
		--m;
	}
}

void MiniSpan_Krushal(AMGraph G) {
	int i, j, v1, v2, vs1, vs2;

	SortT(G); // 将数组Edge中的元素按权值从小到大排序

			  // 辅助数组，表示各顶点自生成一个连通分量
	for (i = 0; i < G.vexnum; i++)
		VexSet[i] = i;

	for (i = 0; i < G.arcnum; i++) {  //依次查看排好序数组Edge中边是否在同一连通分量上
		v1 = LocateVex(G, Edge[i].Head);   // v1为边的始点head的下标
		v2 = LocateVex(G, Edge[i].Tail);   // v2为边的终点Tail的下标
		vs1 = VexSet[v1];  // 获取边Edge[i]的始点所在连通分量vs1
		vs2 = VexSet[v2];

		if (vs1 != vs2) {
			cout << Edge[i].Head << "------>" << Edge[i].Tail << endl;
			for (j = 0; j < G.vexnum; j++)
				if (VexSet[j] == vs2)   // 集合编号为vs2改为vs1
					VexSet[j] = vs1;
		}
	}
}

int main()
{

	cout << "测试克鲁斯卡尔算法." << endl;
	cout << endl;

	AMGraph G;

	CreateUDN(G);
	cout << endl;

	cout << "无向网G创建成功." << endl;
	cout << endl;

	MiniSpan_Krushal(G);

	return 0;
}