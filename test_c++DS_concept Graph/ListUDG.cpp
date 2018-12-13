#include "ListUDG.h"
#include<iostream>
using namespace std;
ListUDG::ListUDG(char vertax[], char edge[][2], int vertaxNum, int edgeNum):m_vertax(MAX)//��Ϊ��������в��ܿ��ٿռ䣬���Խ����ڳ�ʼ���б��г�ʼ����Ա����
//���캯������Ϊ�˹����Ա����,ֻ��ͨ����ʼ���б����
{
	m_vertexNum = vertaxNum;//������
	m_edgeNum = edgeNum;//����
	//��ʼ���ڽ��ڽӱ�Ķ�������
	for (int i = 0; i < m_vertexNum; i++)
	{
		m_vertax[i].data = vertax[i];//��ŵ���ͷ�ڵ�����ݱ���{ 'A','B','C','D','E','F' };
		m_vertax[i].fistEdge = nullptr;
	}
	//�Ҷ���Ͷ�Ӧ�Ķ���
	int v_i, v_j;//��ʾ�ڽӱ�Ķ���λ�ú����ӵĶ���λ�ã�Ҳ���Ƕ���������±�
	for (int i = 0; i < edgeNum; i++)//�����ߵ���Ϣ������{'A','B'}
	{
		for (v_i = 0; v_i < vertaxNum; v_i++)
		{
			if (edge[i][0] == vertax[v_i])//
				break;//�õ��ڼ�������
		}
		for (v_j = 0; v_j < vertaxNum; v_j++)
		{
			if (edge[i][1] == vertax[v_j])
				break;//�õ���������Ӧ�Ķ���
		}
		//����һ���ڵ�
		Enode* newnode = new Enode;
		newnode->ivertax = v_j;//�ڵ���±�Ϊv_j
		newnode->data = vertax[v_j];//�ڵ����Ϣ
		newnode->next = nullptr;
		//����
		//1.��������fistedgeָ��ĵ�һ����(����)Ϊnullptr����ôֱ������
		if (m_vertax[v_i].fistEdge == nullptr)
		{
			m_vertax[v_i].fistEdge = newnode;
		}
		else//2.��������fistedge�Ѿ�ָ����һ���ڵ㣬��ô������ڵ�ŵ����
		{
			Enode* temp = m_vertax[v_i].fistEdge;
			while (temp->next)
			{
				temp = temp->next;
			}
			temp->next=newnode;
		}
		//��Ϊ������ͼ����A-B�ȼ���B-A������B-AҲҪдһ�飬��v_i,v_j������(4,2)<=>(2,4)
		//����һ���ڵ�
		Enode* newnode1 = new Enode;
		newnode1->ivertax = v_i;//�ڵ���±�Ϊv_i
		newnode1->data = vertax[v_i];//�ڵ����Ϣ
		newnode1->next = nullptr;
		//����
		//1.��������fistedgeָ��ĵ�һ����(����)Ϊnullptr����ôֱ������
		if (m_vertax[v_j].fistEdge == nullptr)
		{
			m_vertax[v_j].fistEdge = newnode1;
		}
		else//2.��������fistedge�Ѿ�ָ����һ���ڵ㣬��ô������ڵ�ŵ����
		{
			Enode* temp = m_vertax[v_j].fistEdge;
			while (temp->next)
			{
				temp = temp->next;
			}
			temp->next = newnode1;
		}
	}
}

void ListUDG::PrintListUDG()
{
	for (int i = 0; i < m_vertexNum; i++)//����������ĸ���
	{
		if (m_vertax[i].fistEdge)//��������ӲŴ�ӡ��һ��
		{
			//1.�ȴ�ӡͷ�ڵ����Ϣ
			cout <<i<< m_vertax[i].data << "->";
			//2.������ӡ�����еĸ����ڵ�
			Enode* temp = m_vertax[i].fistEdge;
			while (temp)
			{
				cout << temp->ivertax <<temp->data<< "->";
				temp = temp->next;
			}
			cout << "NULL" << endl;
		}
	}
}

ListUDG::~ListUDG()
{
	//�ͷž������ҵ�ÿһ�н����ͷ�
	for (int i = 0; i < m_vertexNum; i++)
	{
		Enode* p = m_vertax[i].fistEdge;
		Enode* temp;
		while (p)
		{
			temp = p;
			p = p->next;
			delete temp;
		}
	}
}

ListDG::ListDG(char vertax[], char edge[][2], int vertaxNum, int edgeNum) :m_vertax(MAX)
{
	m_vertexNum = vertaxNum;//������
	m_edgeNum = edgeNum;//����
						//��ʼ���ڽ��ڽӱ�Ķ�������
	for (int i = 0; i < m_vertexNum; i++)
	{
		m_vertax[i].data = vertax[i];//��ŵ���ͷ�ڵ�����ݱ���{ 'A','B','C','D','E','F' };
		m_vertax[i].fistEdge = nullptr;
	}
	//�Ҷ���Ͷ�Ӧ�Ķ���
	int v_i, v_j;//��ʾ�ڽӱ�Ķ���λ�ú����ӵĶ���λ�ã�Ҳ���Ƕ���������±�
	for (int i = 0; i < edgeNum; i++)//�����ߵ���Ϣ������{'A','B'}
	{
		for (v_i = 0; v_i < vertaxNum; v_i++)
		{
			if (edge[i][0] == vertax[v_i])//
				break;//�õ��ڼ�������
		}
		for (v_j = 0; v_j < vertaxNum; v_j++)
		{
			if (edge[i][1] == vertax[v_j])
				break;//�õ���������Ӧ�Ķ���
		}
		//����һ���ڵ�
		Enode* newnode = new Enode;
		newnode->ivertax = v_j;//�ڵ���±�Ϊv_j
		newnode->data = vertax[v_j];//�ڵ����Ϣ
		newnode->next = nullptr;
		//����
		//1.��������fistedgeָ��ĵ�һ����(����)Ϊnullptr����ôֱ������
		if (m_vertax[v_i].fistEdge == nullptr)
		{
			m_vertax[v_i].fistEdge = newnode;
		}
		else//2.��������fistedge�Ѿ�ָ����һ���ڵ㣬��ô������ڵ�ŵ����
		{
			Enode* temp = m_vertax[v_i].fistEdge;
			while (temp->next)
			{
				temp = temp->next;
			}
			temp->next = newnode;
		}
		//����ͼ��Ϊ������ģ�A->B���У�����Ҫ����
	}
}

void ListDG::PrintListDG()
{
	for (int i = 0; i < m_vertexNum; i++)//����������ĸ���
	{
		if (m_vertax[i].fistEdge)//��������ӲŴ�ӡ��һ��
		{
			//1.�ȴ�ӡͷ�ڵ����Ϣ
			cout << i << m_vertax[i].data << "->";
			//2.������ӡ�����еĸ����ڵ�
			Enode* temp = m_vertax[i].fistEdge;
			while (temp)
			{
				cout << temp->ivertax << temp->data << "->";
				temp = temp->next;
			}
			cout << "NULL" << endl;
		}
	}
}

ListDG::~ListDG()
{
	//�ͷž������ҵ�ÿһ�н����ͷ�
	for (int i = 0; i < m_vertexNum; i++)
	{
		Enode* p = m_vertax[i].fistEdge;
		Enode* temp;
		while (p)
		{
			temp = p;
			p = p->next;
			delete temp;
		}
	}
}
