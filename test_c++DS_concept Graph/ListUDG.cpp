#include "ListUDG.h"
#include<iostream>
#include<queue>
using namespace std;
void ListUDG::DFS_opt(int i, vector<bool>& visited)//������������ڲ�����
{
	cout << m_vertex[i].data << " ";//�������ǰ��i
	visited[i] = true;//����Ϊ�Ѿ����ʹ�
					  //����ǰ�Ķ��㣺1.�Ƿ����ڽӵ�2.�Ƿ񱻷��ʹ�
	Enode* tempNode;//����һ��������������Ľڵ�ָ��
		//�������������ڽӵ㣬��������ڽӵ�û�б����ʹ�����ô������ڽӵ�Ӧ�õݹ��㷨
	tempNode = m_vertex[i].fistEdge;//��ʼ�������ڵ�ָ��
	while (tempNode&&visited[tempNode->ivertex]==false)
	{
		DFS_opt(tempNode->ivertex, visited);
		tempNode = tempNode->next;
	}
	//���������˳���ǰ����ڽӱ��˳��
}
ListUDG::ListUDG(char vertex[], char edge[][2], int vertexNum, int edgeNum):m_vertex(MAX)//��Ϊ��������в��ܿ��ٿռ䣬���Խ����ڳ�ʼ���б��г�ʼ����Ա����
//���캯������Ϊ�˹����Ա����,ֻ��ͨ����ʼ���б����
{
	m_vertexNum = vertexNum;//������
	m_edgeNum = edgeNum;//����
	//��ʼ���ڽ��ڽӱ�Ķ�������
	for (int i = 0; i < m_vertexNum; i++)
	{
		m_vertex[i].data = vertex[i];//��ŵ���ͷ�ڵ�����ݱ���{ 'A','B','C','D','E','F' };
		m_vertex[i].fistEdge = nullptr;
	}
	//�Ҷ���Ͷ�Ӧ�Ķ���
	int v_i, v_j;//��ʾ�ڽӱ�Ķ���λ�ú����ӵĶ���λ�ã�Ҳ���Ƕ���������±�
	for (int i = 0; i < edgeNum; i++)//�����ߵ���Ϣ������{'A','B'}
	{
		for (v_i = 0; v_i < vertexNum; v_i++)
		{
			if (edge[i][0] == vertex[v_i])//
				break;//�õ��ڼ�������
		}
		for (v_j = 0; v_j < vertexNum; v_j++)
		{
			if (edge[i][1] == vertex[v_j])
				break;//�õ���������Ӧ�Ķ���
		}
		//����һ���ڵ�
		Enode* newnode = new Enode;
		newnode->ivertex = v_j;//�ڵ���±�Ϊv_j
		newnode->data = vertex[v_j];//�ڵ����Ϣ
		newnode->next = nullptr;
		//����
		//1.��������fistedgeָ��ĵ�һ����(����)Ϊnullptr����ôֱ������
		if (m_vertex[v_i].fistEdge == nullptr)
		{
			m_vertex[v_i].fistEdge = newnode;
		}
		else//2.��������fistedge�Ѿ�ָ����һ���ڵ㣬��ô������ڵ�ŵ����
		{
			Enode* temp = m_vertex[v_i].fistEdge;
			while (temp->next)
			{
				temp = temp->next;
			}
			temp->next=newnode;
		}
		//��Ϊ������ͼ����A-B�ȼ���B-A������B-AҲҪдһ�飬��v_i,v_j������(4,2)<=>(2,4)
		//����һ���ڵ�
		Enode* newnode1 = new Enode;
		newnode1->ivertex = v_i;//�ڵ���±�Ϊv_i
		newnode1->data = vertex[v_i];//�ڵ����Ϣ
		newnode1->next = nullptr;
		//����
		//1.��������fistedgeָ��ĵ�һ����(����)Ϊnullptr����ôֱ������
		if (m_vertex[v_j].fistEdge == nullptr)
		{
			m_vertex[v_j].fistEdge = newnode1;
		}
		else//2.��������fistedge�Ѿ�ָ����һ���ڵ㣬��ô������ڵ�ŵ����
		{
			Enode* temp = m_vertex[v_j].fistEdge;
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
		if (m_vertex[i].fistEdge)//��������ӲŴ�ӡ��һ��
		{
			//1.�ȴ�ӡͷ�ڵ����Ϣ
			cout <<i<< m_vertex[i].data << "->";
			//2.������ӡ�����еĸ����ڵ�
			Enode* temp = m_vertex[i].fistEdge;
			while (temp)
			{
				cout << temp->ivertex <<temp->data<< "->";
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
		Enode* p = m_vertex[i].fistEdge;
		Enode* temp;
		while (p)
		{
			temp = p;
			p = p->next;
			delete temp;
		}
	}
}

void ListUDG::DFS_opt()
{
	cout << __func__ << endl;
	//��������һ��������������¼��������ǲ����Ѿ����ʹ�
	vector<bool> visited(m_vertexNum);//������ʼ��Ϊ0����false
	for (int i = 0; i < m_vertexNum; i++)
	{
		if (visited[i] == false)
			DFS_opt(i, visited);
	}
	cout << endl;
}
//�ڽӱ�Ĺ����������
void ListUDG::BFS_opt()
{
	cout << __func__ << endl;
	queue<int> q;//���ö��д����±�
	vector<bool> visited(m_vertexNum);
	for (int i = 0; i < m_vertexNum; i++)
	{
		if (visited[i] == false)
		{
			visited[i] = true;
			cout << m_vertex[i].data << " ";
			q.push(i);//�Ѹö�����±�ѹ�����

			while (!q.empty())
			{
				int start = q.front();//�Ѷ���ͷ��Ϊ��㶥�����Ѱ��
				q.pop();//��������ͷ 
				Enode* tempNode;//����һ��������������Ľڵ�ָ��
								//�������������ڽӵ㣬��������ڽӵ�û�б����ʹ�����ô������ڽӵ�Ӧ�õݹ��㷨
				tempNode = m_vertex[start].fistEdge;//��ʼ�������ڵ�ָ��
				while (tempNode && visited[tempNode->ivertex] == false)
				{
					q.push(tempNode->ivertex);//ѹ���ڽӵ�
					visited[tempNode->ivertex] = true;
					cout << m_vertex[tempNode->ivertex].data << " ";//�������ڽӵ�
					tempNode = tempNode->next;
				}
				
			}
		}
	}
	cout << endl;
}


ListDG::ListDG(char vertex[], char edge[][2], int vertexNum, int edgeNum) :m_vertex(MAX)
{
	m_vertexNum = vertexNum;//������
	m_edgeNum = edgeNum;//����
						//��ʼ���ڽ��ڽӱ�Ķ�������
	for (int i = 0; i < m_vertexNum; i++)
	{
		m_vertex[i].data = vertex[i];//��ŵ���ͷ�ڵ�����ݱ���{ 'A','B','C','D','E','F' };
		m_vertex[i].fistEdge = nullptr;
	}
	//�Ҷ���Ͷ�Ӧ�Ķ���
	int v_i, v_j;//��ʾ�ڽӱ�Ķ���λ�ú����ӵĶ���λ�ã�Ҳ���Ƕ���������±�
	for (int i = 0; i < edgeNum; i++)//�����ߵ���Ϣ������{'A','B'}
	{
		for (v_i = 0; v_i < vertexNum; v_i++)
		{
			if (edge[i][0] == vertex[v_i])//
				break;//�õ��ڼ�������
		}
		for (v_j = 0; v_j < vertexNum; v_j++)
		{
			if (edge[i][1] == vertex[v_j])
				break;//�õ���������Ӧ�Ķ���
		}
		//����һ���ڵ�
		Enode* newnode = new Enode;
		newnode->ivertex = v_j;//�ڵ���±�Ϊv_j
		newnode->data = vertex[v_j];//�ڵ����Ϣ
		newnode->next = nullptr;
		//����
		//1.��������fistedgeָ��ĵ�һ����(����)Ϊnullptr����ôֱ������
		if (m_vertex[v_i].fistEdge == nullptr)
		{
			m_vertex[v_i].fistEdge = newnode;
		}
		else//2.��������fistedge�Ѿ�ָ����һ���ڵ㣬��ô������ڵ�ŵ����
		{
			Enode* temp = m_vertex[v_i].fistEdge;
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
		if (m_vertex[i].fistEdge)//��������ӲŴ�ӡ��һ��
		{
			//1.�ȴ�ӡͷ�ڵ����Ϣ
			cout << i << m_vertex[i].data << "->";
			//2.������ӡ�����еĸ����ڵ�
			Enode* temp = m_vertex[i].fistEdge;
			while (temp)
			{
				cout << temp->ivertex << temp->data << "->";
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
		Enode* p = m_vertex[i].fistEdge;
		Enode* temp;
		while (p)
		{
			temp = p;
			p = p->next;
			delete temp;
		}
	}
}
