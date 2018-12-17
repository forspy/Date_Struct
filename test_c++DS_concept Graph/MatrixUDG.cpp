#include "MatrixUDG.h"
#include<iostream>
#include<queue>
#include<stack>
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
//��������򻯰�
void MatrixUDG::DFS_opt(int i, vector<bool>& visited)
{
	cout << m_vertax[i] << " ";//�������ǰ��i
	visited[i] = true;//����Ϊ�Ѿ����ʹ�
	//����ǰ�Ķ��㣺1.�Ƿ����ڽӵ�2.�Ƿ񱻷��ʹ�
	for (int j = 0; j < m_vertaxNum; j++)
	{
		if (m_matrix[i][j]==1 && visited[j] == false)//�������������ڽӵ㣬��������ڽӵ�û�б����ʹ�����ô������ڽӵ�Ӧ�õݹ��㷨
			DFS_opt(j, visited);
	}
	//���������˳���ǰ����ڽ�ͼ��˳��
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

void MatrixUDG::DFS()//�ⲿ�ӿ���ȱ���deep first search
{
	cout << __func__ << ":" << endl;
	int visited[MAX];
	//��ʼ�����ж������Ϊ0
	memset(visited, 0, sizeof(int)*MAX);
	for (int i = 0; i < m_vertaxNum; i++)
	{
		if (visited[i] == 0)
			DFS(i,visited);
	}
	cout << endl;
}
void MatrixUDG::DFS_opt()
{
	cout << __func__ << endl;
	//��������һ��������������¼��������ǲ����Ѿ����ʹ�
	vector<bool> visited(m_vertaxNum);//������ʼ��Ϊ0����false
	for (int i = 0; i < m_vertaxNum; i++)
	{
		if (visited[i] == false)
			DFS_opt(i, visited);
	}
	cout << endl;
}
void MatrixUDG::DFS_Non_recursive()//�ǵݹ�˼�룺���ø���ջ�������һ���ڽӸ��ڵ�Ĵ洢
{
	cout << __func__ << endl;
	//��������һ��������������¼��������ǲ����Ѿ����ʹ�
	vector<bool> visited(m_vertaxNum);//������ʼ��Ϊ0����false
	stack<int> s;//����һ����ջ��¼������±�
	int temp;
	for (int i = 0; i < m_vertaxNum; i++)
	{
		if (visited[i] == false)//����������û�б����ʹ�
		{
			temp = i;//��¼��ǰ����������������λ��
			s.push(i);//�Ͱ����������±�ѹ��ջ
			cout << m_vertax[i] << " ";//����������������
			visited[i] = true;//�������������Ϊ�Ѿ����ʹ�
			//���������������ڽӵ�
			for (int j = 0; ; j++)//����һ������ѭ������
			{
				if (m_matrix[i][j] == 1 && visited[j] == false)//�ҷ���Ҫ����ڽӵ�
				{
					visited[j] = true;
					s.push(j);//������ڽӶ�����±�ѹ��ջ
					cout << m_vertax[j] << " ";
					i = j;//�ڽӵ���Ϊ���
					j = 0;//��ʾ���¿�ʼ����
				}
				if (j == m_vertaxNum)//iû���ڽӵ�
				{
					if (temp == s.top())//���ջ������һ��ʼ�����Ľڵ��±�temp��˵�������������ڽ���ͨ���㶼�Ѿ��������ˣ��˳�ѭ��
						break;
					s.pop();//����������Ҫ��ĵ�
					i = s.top();//�൱��ѡȡ���ڽӽڵ�Ϊ���
					j = 0;//��ʾ���¿�ʼ����
				}
			}
		}
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
