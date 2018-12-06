// HMTreeCode.cpp : 定义控制台应用程序的入口点。
//
// 哈夫曼树编码和译码
//

#include <iostream>
using namespace std;

#define MAX_MA 1000
#define MAX_ZF 100

// 哈夫曼树存储定义
typedef struct
{
	int weight;  // 结点的权值
	int parent, lchild, rchild;  // 双亲，左孩子，右孩子的下标
}HTNode,*HuffManTree;       // 动态分配数组来存储哈夫曼树的结点

typedef char **HuffManCode;       // 动态分配数组存储哈夫曼编码

//  返回两个双亲域为0且权值最小的点下标
void Select(HuffManTree HT, int n, int &s1, int &s2)
{
	for (int i = 1; i <= n; i++)
	{
		if (HT[i].parent == 0)
		{
			s1 = i;  // s1初始化为i
			break;  // 找到一个后立即退出循环
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (HT[i].weight < HT[s1].weight && HT[i].parent == 0)
			s1 = i;
	}

	for (int i = 1; i <= n; i++)
	{
		if (HT[i].parent == 0 && i != s1)
		{
			s2 = i;
			break;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (HT[i].weight < HT[s2].weight && HT[i].parent == 0 && i != s1)
			s2 = i;
	}
}

// 创建哈夫曼树
void CreateHuffManTree(HuffManTree &HT, int n)
{
	// 初始化
	if (n <= 1)
		return;
	int m = 2 * n - 1;
	HT = new HTNode[m + 1];
	for (int i = 1; i <= m; i++)
	{
		HT[i].parent = 0; HT[i].lchild = 0; HT[i].rchild = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> HT[i].weight;  // 请输入前n个单元中叶子结点的权值
	}
	
	// 创建操作
	int s1, s2;
	for (int i = n + 1; i <= m; i++)
	{
		// 通过n-1次的选择，删除 ，合并来创建哈夫曼树
		Select(HT, i - 1, s1, s2);
		HT[s1].parent = i;
		HT[s2].parent = i;  // ERROR
		// s1 s2分别作为i的左右孩子
		HT[i].lchild = s1;
		HT[i].rchild = s2;

		// 结点i的权值为s1 s2权值之和
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
}

// 从叶子到树逆向求每个字符的哈夫曼编码，存储在编码表当中HC
void CreateHuffManCode(HuffManTree HT, HuffManCode &HC, int n)
{
	HC = new char*[n + 1];
	char *cd = new char[n];
	cd[n - 1] = '\0';

	for (int i = 1; i <= n; i++) // 逐个求字符编码
	{
		int start = n - 1;
		int c = i;
		int f = HT[c].parent;
		while (f != 0)  // 从叶子结点开始回溯，直到根结点
		{
			--start;
			if (HT[f].lchild == c)
				cd[start] = '0';
			else
				cd[start]='1';
			c = f;
			f = HT[f].parent; // 继续向上回溯
		}
		HC[i] = new char[n - start];
		strcpy(HC[i],&cd[start]);
	}

	delete cd;
}

// 哈夫曼译码
void TranCode(HuffManTree HT, char a[], char zf[], char b[], int n)
{
	printf("OK");
	int q = 2 * n - 1;
	int k = 0;
	int i = 0;
	for (i = 0;a[i] != '\0'; i++)
	{
		if (a[i] == '0')
		{
			q = HT[q].lchild;
		}
		else if (a[i] == '1')
		{
			q = HT[q].rchild;
		}

		if (HT[q].lchild == 0 && HT[q].rchild == 0)
		{
			b[k++] = zf[q];
			q = 2 * n - 1; // 初始化q为根结点的下标，继续译下一个字符的时候从哈夫曼树的根结点开始
		}
	}

	b[k] = '\0';

}

// 菜单设计 
void SystemMenu()
{
	cout << endl;
	cout << "□□□□□□□□□□□□□□□□□□□□□□□" << endl;
	cout << "□                                          □" << endl;
	cout << "□        史上最牛哈夫曼编码与译码          □" << endl;
	cout << "□                                          □" << endl;
	cout << "□□□□□□□□□□□□□□□□□□□□□□□" << endl;
	cout << "□                                          □" << endl;
	cout << "□      1 创建哈夫曼树   2 编码             □" << endl;
	cout << "□                                          □" << endl;
	cout << "□      3 译码           4 退出             □" << endl;
	cout << "□                                          □" << endl;
	cout << "□      Vico提醒：空格字符用'-'替代         □" << endl;
	cout << "□                                          □" << endl;
	cout << "□□□□□□□□□□□□□□□□□□□□□□□" << endl << endl;
}

int main()
{
	int flag;  // 记录要编码的字符个数
	char a[MAX_MA];  // 存储输入的二进制字符
	char b[MAX_ZF];  // 存储译出的字符
	char zf[MAX_ZF]; // 存储要编码的字符

	HuffManTree HT = NULL;
	HuffManCode HC = NULL;

	SystemMenu();
	while (true)
	{
		int num;
		cout << "请选择功能项【1创建 2编码 3译码 4退出】：";
		cin >> num;
		switch (num)
		{
		case 1:
			cout << "请输入生成哈夫曼树字符个数:";
			cin >> flag;
			cout << "请依次输入" << flag << "个字符:";
			for (int i = 1; i <= flag; i++)
				cin >> zf[i];
			cout << "请依次输入" << flag << "个字符的权值:";
			CreateHuffManTree(HT, flag);  // 调用创建哈夫曼树的函数
			cout << endl;
			cout << "哈夫曼树创建成功，输出参数值如下：" << endl;
			cout << "结点i" << "\t" << "字符" << "\t" << "权值" << "\t" << "双亲" << "\t" << "左孩子" << "\t" << "右孩子" << endl;
			
			for (int i = 1; i <= flag * 2 - 1; i++)
			{
				cout << i << "\t" << zf[i] << "\t" << HT[i].weight << "\t" << HT[i].parent << "\t" << HT[i].lchild << "\t" << HT[i].rchild << endl;
			}
			cout << endl;
			break;
			
		case 2:
			CreateHuffManCode(HT, HC, flag);
			cout << endl;
			cout << "生成哈夫曼编码表成功，输出编码参数值如下：" << endl;
			cout << "结点i" << "\t" << "字符" << "\t" << "权值" << "\t" << "编码" << endl;

			for (int i = 1; i <= flag; i++)
			{
				cout << i << "\t" << zf[i] << "\t" << HT[i].weight << "\t" << HC[i] << endl;
			}
			cout << endl;
			break;

		case 3:
			cout << "请输入要翻译的一串二进制编码:";
			cin >> a;
			TranCode(HT, a, zf, b, flag);
			cout << endl;
			cout << "数据系统译码成功，翻译结果为:" << b << endl;
			cout << endl;
			break;
			
		case 4:
			cout << endl;
			cout << "成功退出哈夫曼树." << endl;
			exit(0);
		default:
			break;
		}
	}



	return 0;
}

