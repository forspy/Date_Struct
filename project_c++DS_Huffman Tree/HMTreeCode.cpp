// HMTreeCode.cpp : �������̨Ӧ�ó������ڵ㡣
//
// �����������������
//

#include <iostream>
using namespace std;

#define MAX_MA 1000
#define MAX_ZF 100

// ���������洢����
typedef struct
{
	int weight;  // ����Ȩֵ
	int parent, lchild, rchild;  // ˫�ף����ӣ��Һ��ӵ��±�
}HTNode,*HuffManTree;       // ��̬�����������洢���������Ľ��

typedef char **HuffManCode;       // ��̬��������洢����������

//  ��������˫����Ϊ0��Ȩֵ��С�ĵ��±�
void Select(HuffManTree HT, int n, int &s1, int &s2)
{
	for (int i = 1; i <= n; i++)
	{
		if (HT[i].parent == 0)
		{
			s1 = i;  // s1��ʼ��Ϊi
			break;  // �ҵ�һ���������˳�ѭ��
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

// ������������
void CreateHuffManTree(HuffManTree &HT, int n)
{
	// ��ʼ��
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
		cin >> HT[i].weight;  // ������ǰn����Ԫ��Ҷ�ӽ���Ȩֵ
	}
	
	// ��������
	int s1, s2;
	for (int i = n + 1; i <= m; i++)
	{
		// ͨ��n-1�ε�ѡ��ɾ�� ���ϲ���������������
		Select(HT, i - 1, s1, s2);
		HT[s1].parent = i;
		HT[s2].parent = i;  // ERROR
		// s1 s2�ֱ���Ϊi�����Һ���
		HT[i].lchild = s1;
		HT[i].rchild = s2;

		// ���i��ȨֵΪs1 s2Ȩֵ֮��
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
}

// ��Ҷ�ӵ���������ÿ���ַ��Ĺ��������룬�洢�ڱ������HC
void CreateHuffManCode(HuffManTree HT, HuffManCode &HC, int n)
{
	HC = new char*[n + 1];
	char *cd = new char[n];
	cd[n - 1] = '\0';

	for (int i = 1; i <= n; i++) // ������ַ�����
	{
		int start = n - 1;
		int c = i;
		int f = HT[c].parent;
		while (f != 0)  // ��Ҷ�ӽ�㿪ʼ���ݣ�ֱ�������
		{
			--start;
			if (HT[f].lchild == c)
				cd[start] = '0';
			else
				cd[start]='1';
			c = f;
			f = HT[f].parent; // �������ϻ���
		}
		HC[i] = new char[n - start];
		strcpy(HC[i],&cd[start]);
	}

	delete cd;
}

// ����������
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
			q = 2 * n - 1; // ��ʼ��qΪ�������±꣬��������һ���ַ���ʱ��ӹ��������ĸ���㿪ʼ
		}
	}

	b[k] = '\0';

}

// �˵���� 
void SystemMenu()
{
	cout << endl;
	cout << "����������������������������������������������" << endl;
	cout << "��                                          ��" << endl;
	cout << "��        ʷ����ţ����������������          ��" << endl;
	cout << "��                                          ��" << endl;
	cout << "����������������������������������������������" << endl;
	cout << "��                                          ��" << endl;
	cout << "��      1 ������������   2 ����             ��" << endl;
	cout << "��                                          ��" << endl;
	cout << "��      3 ����           4 �˳�             ��" << endl;
	cout << "��                                          ��" << endl;
	cout << "��      Vico���ѣ��ո��ַ���'-'���         ��" << endl;
	cout << "��                                          ��" << endl;
	cout << "����������������������������������������������" << endl << endl;
}

int main()
{
	int flag;  // ��¼Ҫ������ַ�����
	char a[MAX_MA];  // �洢����Ķ������ַ�
	char b[MAX_ZF];  // �洢������ַ�
	char zf[MAX_ZF]; // �洢Ҫ������ַ�

	HuffManTree HT = NULL;
	HuffManCode HC = NULL;

	SystemMenu();
	while (true)
	{
		int num;
		cout << "��ѡ�����1���� 2���� 3���� 4�˳�����";
		cin >> num;
		switch (num)
		{
		case 1:
			cout << "���������ɹ��������ַ�����:";
			cin >> flag;
			cout << "����������" << flag << "���ַ�:";
			for (int i = 1; i <= flag; i++)
				cin >> zf[i];
			cout << "����������" << flag << "���ַ���Ȩֵ:";
			CreateHuffManTree(HT, flag);  // ���ô������������ĺ���
			cout << endl;
			cout << "�������������ɹ����������ֵ���£�" << endl;
			cout << "���i" << "\t" << "�ַ�" << "\t" << "Ȩֵ" << "\t" << "˫��" << "\t" << "����" << "\t" << "�Һ���" << endl;
			
			for (int i = 1; i <= flag * 2 - 1; i++)
			{
				cout << i << "\t" << zf[i] << "\t" << HT[i].weight << "\t" << HT[i].parent << "\t" << HT[i].lchild << "\t" << HT[i].rchild << endl;
			}
			cout << endl;
			break;
			
		case 2:
			CreateHuffManCode(HT, HC, flag);
			cout << endl;
			cout << "���ɹ����������ɹ�������������ֵ���£�" << endl;
			cout << "���i" << "\t" << "�ַ�" << "\t" << "Ȩֵ" << "\t" << "����" << endl;

			for (int i = 1; i <= flag; i++)
			{
				cout << i << "\t" << zf[i] << "\t" << HT[i].weight << "\t" << HC[i] << endl;
			}
			cout << endl;
			break;

		case 3:
			cout << "������Ҫ�����һ�������Ʊ���:";
			cin >> a;
			TranCode(HT, a, zf, b, flag);
			cout << endl;
			cout << "����ϵͳ����ɹ���������Ϊ:" << b << endl;
			cout << endl;
			break;
			
		case 4:
			cout << endl;
			cout << "�ɹ��˳���������." << endl;
			exit(0);
		default:
			break;
		}
	}



	return 0;
}

