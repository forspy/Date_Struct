#include "MatrixUDG.h"
#include<iostream>
#include<queue>
using namespace std;
//��i�����DFS�ݹ����
void MatrixUDG::DFS(int i,int* visited)
{
	int j;
	visited[i] = 1;//�Ƚ����������Ϊ1��ʾ���ʹ���
	cout << m_vertax[i] << " ";
	for (j = firstVertex(i); j >= 0; j = nextVertax(i, j))
	{
		if (visited[j] == 0)
			DFS(j,visited);//��ʾ��i�����ڽӵ����j����Ϊ�������������ȵݹ����
	}
}
//���ص�i������ĵ�һ���ڽӶ����������û���򷵻�-1
int MatrixUDG::firstVertex(int i)
{
	int j;
	if (i<0 || i>(m_vertaxNum - 1))//��Ϊi��0��ʼ������m_vertaxNum - 1��ʾ���һ������
		return -1;
	for (j = 0; j < m_vertaxNum; j++)
	{
		if (m_matrix[i][j] == 1)
			return j;
	}
	return -1;
}
//���ص�i������������j�ڽӵ����һ���ڽӶ����������û���򷵻� - 1
int MatrixUDG::nextVertax(int i, int j)
{
	int j_next;//��ʾ��һ���ڽӵ��λ��(������),����Ҫ�ж�ά�ڽӾ���
	if (i<0 || i>(m_vertaxNum - 1) || j<0 || i>(m_vertaxNum - 1))
		return -1;
	for (j_next = j + 1; j_next < m_vertaxNum; j_next++)
	{
		if (m_matrix[i][j_next] == 1)
			return j_next;
	}
	return -1;
}

MatrixUDG::MatrixUDG(char vertax[], char edge[][2], int vertaxNum, int edgeNum)
{
	memset(m_vertax, 0, sizeof(m_vertax));
	memset(m_matrix, 0, sizeof(m_matrix));//���ڽӾ����ʼ��Ϊ0
	//�������ͱ�����ֵ
	m_vertaxNum = vertaxNum;
	m_edgeNum = edgeNum;
	//��vertax[]��ʼ�����еĶ�������
	//memcpy(m_vertax, vertax, sizeof(vertax));//ע���������vertax�Ѿ���һ��ָ���˶�����һ����������ֱ��sizeof(vertax)��һ��ָ��4���ֽ�
	memcpy(m_vertax, vertax, sizeof(char)*vertaxNum);
	//ͨ���ڽӾ����ʾ��
	int v_i, v_j;//��ʾ�ڽӾ���ĺ�����������꣬Ҳ���Ƕ���������±�
	for (int i = 0; i < edgeNum; i++)//�����ߵ���Ϣ
	{
		for (v_i = 0; v_i < vertaxNum; v_i++)//Ѱ�Ҷ������������i�ߵĵ�0��Ԫ����ͬ��ֵ��λ��
		{
			if (edge[i][0] == vertax[v_i])//�ұ���{'A','B'}��λ��
				break;
		}
		for (v_j = 0; v_j < vertaxNum; v_j++)
		{
			if (edge[i][1] == vertax[v_j])
				break;
		}
		m_matrix[v_i][v_j] = 1;//���ҵ��߶�Ӧ���ڽӾ���Ԫ�ظ�ֵΪ1
		m_matrix[v_j][v_i] = 1;//��Ϊ�ǶԳƵģ����Է�תһ��Ҳ��Ϊ1���൱��������һ��߾���ֻ��Ԫ���Ƿ��ı��磨A,B��(B,A)
	}
	
}
//��ӡ�ڽӾ���
void MatrixUDG::PrintMatrixUDG()
{
	cout << "  ";
	for (int i = 0; i < m_vertaxNum; i++)
	{
		cout << m_vertax[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < m_vertaxNum; i++)
	{
		cout << m_vertax[i] << " ";
		for (int j = 0; j < m_vertaxNum; j++)
		{
			cout << m_matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void MatrixUDG::DFS()//�ⲿ�ӿ���ȱ���
{
	cout << __func__ << ":" << endl;
	int visited[MAX];
	//��ʼ�����ж������Ϊ0
	memset(visited, 0, sizeof(int)*MAX);
	int i;
	for (i = 0; i < m_vertaxNum; i++)
	{
		if (visited[i] == 0)
			DFS(i,visited);
	}
	cout << endl;
}
//����������������������Ĳ�α�������Ҫ����һ���������������Ǳ���
void MatrixUDG::BFS()
{
	//����һ�����ж���
	queue<int> que; //����Ƕ����±�
	int i;//��ʾҪ�����Ķ���
	int i_pop;//��ʾ�������еĶ�����±�
	int j;//��ʾ������ڽӶ���
	cout << __func__ << endl;
	int visited[MAX];
	memset(visited, 0, sizeof(int)*MAX);
	for (i = 0; i < m_vertaxNum; i++)//���ı����Ǳ���Ҫ�ģ���֤������ÿ��������Ϊ�����������ӣ���ͼ�����йµ��㣬����A���Բ�����B,C
	{
		//��m_vertaxNum����������ѹ��
		if (visited[i] == 0)//���û�б�����������㣬��ѹ��
		{
			visited[i] = 1;
			cout << m_vertax[i] << " ";
			que.push(i);//�������±�ѹ�����
		}
		while (!que.empty())//ÿһ��ѭ���������и�i�������ڵĶ���ѹ�벢������ӡ
		{
			i_pop = que.front();
			que.pop();
			for (j = firstVertex(i_pop); j >= 0; j = nextVertax(i_pop, j))//���α�������ĸ����ڽӶ���
			{
				if (visited[j] == 0)
				{
					visited[j] = 1;
					cout << m_vertax[j] << " ";//��ӡ����ڵ�
					que.push(j);//ѹ��
				}
			}
		}
	}
	cout << endl;
}

MatrixDG::MatrixDG(char vertax[], char edge[][2], int vertaxNum, int edgeNum)
{
	memset(m_vertax, 0, sizeof(m_vertax));
	memset(m_matrix, 0, sizeof(m_matrix));//���ڽӾ����ʼ��Ϊ0
										  //�������ͱ�����ֵ
	m_vertaxNum = vertaxNum;
	m_edgeNum = edgeNum;
	//��vertax[]��ʼ�����еĶ�������
	//memcpy(m_vertax, vertax, sizeof(vertax));//ע���������vertax�Ѿ���һ��ָ���˶�����һ����������ֱ��sizeof(vertax)��һ��ָ��4���ֽ�
	memcpy(m_vertax, vertax, sizeof(char)*vertaxNum);
	//ͨ���ڽӾ����ʾ��
	int v_i, v_j;//��ʾ�ڽӾ���ĺ�����������꣬Ҳ���Ƕ���������±�
	for (int i = 0; i < edgeNum; i++)//�����ߵ���Ϣ
	{
		for (v_i = 0; v_i < vertaxNum; v_i++)//Ѱ�Ҷ������������i�ߵĵ�0��Ԫ����ͬ��ֵ��λ��
		{
			if (edge[i][0] == vertax[v_i])//�ұ���{'A','B'}��λ��
				break;
		}
		for (v_j = 0; v_j < vertaxNum; v_j++)
		{
			if (edge[i][1] == vertax[v_j])
				break;
		}
		m_matrix[v_i][v_j] = 1;//���ҵ��߶�Ӧ���ڽӾ���Ԫ�ظ�ֵΪ1������ͼ���ǶԳƵ�
		//m_matrix[v_j][v_i] = 1;//��Ϊ�ǶԳƵģ����Է�תһ��Ҳ��Ϊ1
	}
}

void MatrixDG::PrintMatrixDG()
{
	cout << "  ";
	for (int i = 0; i < m_vertaxNum; i++)
	{
		cout << m_vertax[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < m_vertaxNum; i++)
	{
		cout << m_vertax[i] << " ";
		for (int j = 0; j < m_vertaxNum; j++)
		{
			cout << m_matrix[i][j] << " ";
		}
		cout << endl;
	}
}
