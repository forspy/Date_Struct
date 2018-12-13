#include "MatrixUDG.h"
#include<iostream>
using namespace std;

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
