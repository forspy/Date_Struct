//������������ͼG���ж���ļ�С��ͨ��ͼ��n - 1���ߣ���
//N����������γ�N(N-1)/2���ߣ���ΪA-B=B-A����Ҫ/2
//��С�������������Ķ���������У�Ѱ��һ������Ȩֵ֮����С��������
/*������С��������׼��(���·��)
����ֻʹ�ø����еı���������С��������
����ʹ���ҽ�ʹ��n-1���������������е�n������
����ʹ�ò�����·�ı�
*/
/*
ʵ�����⣺
����n�����м佨��ͨ��������n������Ӧ��n-1����·������Ϊÿ����·�����ж�Ӧ�ľ��óɱ���
��n�����п�����n(n-1)/2 ����·����ô�����ѡ��n�C1����·��ʹ�ܷ������٣�
*/
//���䣺̰���㷨(Greedy Algorithm)
/*
�㷨ԭ���Ե�ǰ���Ϊ����������ѡ�񣬶������Ǹ��ֿ��ܵ��������������̰�ķ���Ҫ���ݡ�
�㷨�ŵ㣺��Ϊʡȥ��ΪѰ�ҽ������п���������ķѵĴ���ʱ�䣬����㷨Ч�ʸߡ�
ע�⣺̰���㷨�ľ�����ǡ�ֻ����λ����ǰ�������桱,��ʱ��һ�������Ž⡣
*/
//�������С������
/*
Prim�㷨: �鲢���㣬������޹أ����ڳ�����
Kruskal�㷨���鲢�ߣ�����ϡ����
*/
/*
����ķ�㷨�Ļ���˼�롪���鲢����
1. ��ĳ���� u0 ������ѡ�����������ľ�����СȨֵ�ı�(u0, v)�����䶥����뵽�������Ķ��㼯��U��
2. ÿһ����һ��������U�У�����һ�����㲻��U�еĸ�������ѡ��Ȩֵ��С�ı�(u, v),�����Ķ�����뵽U��
3. ֱ�����ж��㶼���뵽���������㼯��U��Ϊֹ
*/
/*
��³˹�����㷨�Ļ���˼�룭�鲢��
1. ����һ��ֻ�� n �����㣬û�бߵķ���ͨͼ T = { V, null }, ÿ�������Գ�һ����ͨ����(�ݹ�Ĺ��̱�֤��������ͨͼ)
2. �� E ��ѡ��СȨֵ�ı�,���ñߵ������������ڲ�ͬ����ͨ�����ϣ������ T �У�������ȥ������ѡ��
3. �ظ���ȥ��ֱ�����ж�����ͬһ��ͨ������Ϊֹ
*/
/*
Ӧ�ã�
������;����ͨ���⡣�磺����A������B�ж�����·����ÿ����·�Ľ�ͨ�ѣ�������ʱ�䣩��ͬ����ô�����ѡ��һ����·��
ʹ�ܷ��ã�����ʱ�䣩���٣�
��������ڴ�Ȩ����ͼ��A�㣨Դ�㣩����B�㣨�յ㣩�Ķ���·���У�Ѱ��һ������Ȩֵ֮����С��·���������·����
ע�����·������С��������ͬ�����·����һ������N������
����Ӧ�ã�
���������·��
������̽·
��Ϸ����

*/
#include <iostream>
using namespace std;

typedef char VerTexType;
typedef int ArcType;

#define MVNum 100
#define MaxInt 65535  // ��ʾ����ֵ

// ��������Ķ��壬������¼�Ӷ��㼯U��V-U��Ȩֵ��С�ı�
struct {
	VerTexType adjvex;  // ��С����U�еĶ���
	ArcType lowcost;  // ��С���ϵ�Ȩֵ
}closedge[MVNum];

// ����ͼ���ڽӱ�洢����
typedef char VerTexType; // �������������Ϊ�ַ�
typedef int ArcType; // ��Ȩֵ����
typedef struct {
	VerTexType vexs[MVNum];  // �����
	ArcType arcs[MVNum][MVNum]; // �ڽӾ���
	int vexnum, arcnum; // ���� ����
}AMGraph;

// ȷ��v��Gͼ�е�λ��
int LocateVex(AMGraph G, VerTexType v) {
	for (int i = 0; i < G.vexnum; i++)
		if (G.vexs[i] == v)
			return i;
	return -1;
}

// ������������G�������ڽӾ����ʾ
void CreateUDN(AMGraph &G) {
	int i, j, k;
	cout << "�����붥�� ���������ÿո����:";
	cin >> G.vexnum >> G.arcnum;
	cout << endl;

	cout << "�����붥������ƣ�����:A" << endl;

	for (i = 0; i < G.vexnum; i++) {
		cout << "�������" << (i + 1) << "���������:";
		cin >> G.vexs[i];
	}
	cout << endl;

	// ��ʼ���ڽӾ��󣬱ߵ�Ȩֵ

	for (i = 0; i < G.vexnum; i++)
		for (j = 0; j < G.vexnum; j++)
			G.arcs[i][j] = MaxInt;

	cout << "������������Ķ��㼰Ȩֵ: ����:A B 89" << endl;
	for (k = 0; k < G.arcnum; k++)
	{
		VerTexType v1, v2;
		ArcType w;
		cout << "�������" << (k + 1) << "���������Ķ��㼰Ȩֵ:";
		cin >> v1 >> v2 >> w;

		// ȷ��v1 v2��Gͼ��λ�ã����������±� 
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);

		G.arcs[i][j] = w;  // �� <v1,v2>Ȩֵ
		G.arcs[j][i] = G.arcs[i][j]; // <v1,v2>  <v2,v1> ��ȨֵΪw
	}
}

// ����Ȩֵ��С�ĵ�
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

// ������G���ڽӾ�����ʽ�洢���Ӷ���u��������G����С������T�����T�ĸ�����
void MiniSpan_Prim(AMGraph G, VerTexType u) {
	int i, j, k;
	VerTexType u0, v0;

	k = LocateVex(G, u);  // ��ʾkΪ����u���±� 

	for (j = 0; j < G.vexnum; j++) {
		if (j != k) {
			closedge[j].adjvex = u;
			closedge[j].lowcost = G.arcs[k][j];
		}
	}

	closedge[k].lowcost = 0;
	for (i = 1; i < G.vexnum; i++) {
		k = Min(G);   // ѡ������n-1�����㣬����n-1����

		u0 = closedge[k].adjvex;  // u0Ϊ��С��һ������ uo����U
		v0 = G.vexs[k];    // v0Ϊ��С�ߵ���һ������ v0����V
		cout << "��  " << u0 << "------>" << v0 << endl;  // �����С��

														 // ��k�����㲢��U��
		closedge[k].lowcost = 0;
		for (j = 0; j < G.vexnum; j++)
			if (G.arcs[k][j] < closedge[j].lowcost) {  // �¶��㲢��U������ѡ����С��
				closedge[j].adjvex = G.vexs[k];
				closedge[j].lowcost = G.arcs[k][j];
			}
	}
}

int main()
{
	cout << "��������ķ�㷨" << endl;
	AMGraph G;

	CreateUDN(G);
	cout << endl;

	cout << "������G�����ɹ�.\n";
	cout << endl;

	cout << "ͨ������ķ�㷨������С�������������:" << endl;
	MiniSpan_Prim(G, 'a');
	cout << endl;

	return 0;
}