#include "MatrixUDG.h"
#include<iostream>
using namespace std;

MatrixUDG::MatrixUDG(char vertax[], char edge[][2], int vertaxNum, int edgeNum)
{
	memset(m_vertax, 0, sizeof(m_vertax));
	memset(m_matrix, 0, sizeof(m_matrix));//将邻接矩阵初始化为0
	//顶点数和边数赋值
	m_vertaxNum = vertaxNum;
	m_edgeNum = edgeNum;
	//用vertax[]初始化类中的顶点数组
	//memcpy(m_vertax, vertax, sizeof(vertax));//注意这里面的vertax已经是一个指针了而不是一个数组所以直接sizeof(vertax)是一个指针4个字节
	memcpy(m_vertax, vertax, sizeof(char)*vertaxNum);
	//通过邻接矩阵表示边
	int v_i, v_j;//表示邻接矩阵的横坐标和纵坐标，也都是顶点数组的下标
	for (int i = 0; i < edgeNum; i++)//遍历边的信息
	{
		for (v_i = 0; v_i < vertaxNum; v_i++)//寻找顶点数组中与第i边的第0个元素相同的值的位置
		{
			if (edge[i][0] == vertax[v_i])//找比如{'A','B'}的位置
				break;
		}
		for (v_j = 0; v_j < vertaxNum; v_j++)
		{
			if (edge[i][1] == vertax[v_j])
				break;
		}
		m_matrix[v_i][v_j] = 1;//将找到边对应的邻接矩阵元素赋值为1
		m_matrix[v_j][v_i] = 1;//因为是对称的，所以反转一下也赋为1，相当于有另外一组边矩阵，只是元素是反的比如（A,B）(B,A)
	}
}
//打印邻接矩阵
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
	memset(m_matrix, 0, sizeof(m_matrix));//将邻接矩阵初始化为0
										  //顶点数和边数赋值
	m_vertaxNum = vertaxNum;
	m_edgeNum = edgeNum;
	//用vertax[]初始化类中的顶点数组
	//memcpy(m_vertax, vertax, sizeof(vertax));//注意这里面的vertax已经是一个指针了而不是一个数组所以直接sizeof(vertax)是一个指针4个字节
	memcpy(m_vertax, vertax, sizeof(char)*vertaxNum);
	//通过邻接矩阵表示边
	int v_i, v_j;//表示邻接矩阵的横坐标和纵坐标，也都是顶点数组的下标
	for (int i = 0; i < edgeNum; i++)//遍历边的信息
	{
		for (v_i = 0; v_i < vertaxNum; v_i++)//寻找顶点数组中与第i边的第0个元素相同的值的位置
		{
			if (edge[i][0] == vertax[v_i])//找比如{'A','B'}的位置
				break;
		}
		for (v_j = 0; v_j < vertaxNum; v_j++)
		{
			if (edge[i][1] == vertax[v_j])
				break;
		}
		m_matrix[v_i][v_j] = 1;//将找到边对应的邻接矩阵元素赋值为1，有向图不是对称的
		//m_matrix[v_j][v_i] = 1;//因为是对称的，所以反转一下也赋为1
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
