#include <iostream>
using namespace std;

typedef char VerTexType;
typedef int ArcType;

#define MVNum 100
#define MaxInt 65535  // ��ʾ����ֵ

// ����ͼ���ڽӾ���洢����
typedef struct {
	VerTexType vexs[MVNum];  // �����
	ArcType arcs[MVNum][MVNum]; // �ڽӾ���
	int vexnum, arcnum; // ���� ����
}AMGraph;

// ��������Edges�Ķ���
struct {
	VerTexType Head;  // �ߵ�ʼ��
	VerTexType Tail;  // �ߵ��յ�
	ArcType lowcost;  // �ߵ�Ȩֵ
}Edge[(MVNum*(MVNum - 1)) / 2];

// ��������Vexset
int VexSet[MVNum];


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

		Edge[k].lowcost = w;
		Edge[k].Head = v1;
		Edge[k].Tail = v2;
	}
}

// ʹ��ð��������
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

	SortT(G); // ������Edge�е�Ԫ�ذ�Ȩֵ��С��������

			  // �������飬��ʾ������������һ����ͨ����
	for (i = 0; i < G.vexnum; i++)
		VexSet[i] = i;

	for (i = 0; i < G.arcnum; i++) {  //���β鿴�ź�������Edge�б��Ƿ���ͬһ��ͨ������
		v1 = LocateVex(G, Edge[i].Head);   // v1Ϊ�ߵ�ʼ��head���±�
		v2 = LocateVex(G, Edge[i].Tail);   // v2Ϊ�ߵ��յ�Tail���±�
		vs1 = VexSet[v1];  // ��ȡ��Edge[i]��ʼ��������ͨ����vs1
		vs2 = VexSet[v2];

		if (vs1 != vs2) {
			cout << Edge[i].Head << "------>" << Edge[i].Tail << endl;
			for (j = 0; j < G.vexnum; j++)
				if (VexSet[j] == vs2)   // ���ϱ��Ϊvs2��Ϊvs1
					VexSet[j] = vs1;
		}
	}
}

int main()
{

	cout << "���Կ�³˹�����㷨." << endl;
	cout << endl;

	AMGraph G;

	CreateUDN(G);
	cout << endl;

	cout << "������G�����ɹ�." << endl;
	cout << endl;

	MiniSpan_Krushal(G);

	return 0;
}