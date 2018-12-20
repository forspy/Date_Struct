#pragma once
#include<iostream>
using namespace std;
template<typename T>
class MinHeap//С����
{
private:
	T* m_buff;//����
	int m_size;//��ǰ������С,���������ϵͳ�ͻ����?��m_size��ʾ��������1����ʼ
	int m_capcity;//�����������Ϊ���ɾ��һ���ڵ��m_size�ͻ�ı䣬��Ҫ�����������飿(��һ���ҳ���һ��û��m_capcityֱ�ӣ���m_size)
	//m_capcity-m_size֮����ڴ治�ᱻϵͳ����
	//���ϵ���
	void adjustUp(int cur);
	//���µ���
	void adjustDown(int cur);
public:
	MinHeap(int capcity=0);
	//����
	bool insert(const T& data);
	//ɾ��
	bool remove(const T& data);
	//����
	int find(const T& data);
	//��ӡ
	void print();


	~MinHeap();
};

template<typename T>
inline MinHeap<T>::MinHeap(int capcity)
{
	if (capcity <= 0)//�������
	{
		capcity = 20;
	}
	m_buff = new T[capcity];
	m_size = 0;
	m_capcity = capcity;
}
//����
template<typename T>
inline bool MinHeap<T>::insert(const T & data)
{
	if (m_capcity == m_size)//�����ǰ�����ﵽ�������������Ҫ�Ե�ǰ������������
	{
		m_capcity = 2 * m_capcity;//�����������������
		T* tempbuff = new T[m_capcity];
		memcpy(tempbuff, m_buff, sizeof(T)*m_size);//����m_buff������ڴ浽tempbuff��
		delete[] m_buff;//�ͷ�m_buff������ڴ�
		m_buff = tempbuff;//m_buff�ӹ�tempbuff������ڴ�
	}
	m_buff[m_size] = data;//��Ԫ�ز��뵽ĩβ
	//������С��
	adjustUp(m_size);//��m_size��Ԫ�ؿ�ʼ������m_size����һ��Ԫ�ر�ʾ��ĩβ�ٲ���һ��Ԫ�ؽ��е���
	m_size++;
	return true;
}
//ɾ��
template<typename T>
inline bool MinHeap<T>::remove(const T & data)
{
	if (m_size == 0)//��ʾ�ѿ���
		return false;
	int cur = find(data);//�ҵ��õ������
	if (cur == -1)
		return false;
	//�����һ���ڵ�Ĵ��浱ǰ�ڵ��ֵ��Ȼ��ɾ�����һ���ڵ㣬Ȼ��������µ���
	m_buff[cur] = m_buff[m_size - 1];
	m_size--;
	adjustDown(cur);
	return true;
}

template<typename T>
inline int MinHeap<T>::find(const T & data)
{
	for (int i = 0; i < m_size; ++i)//�ڵݹ��ʱ�������ʹ��++i,
	{
		if (data == m_buff[i])
			return i;
	}
	return -1;//û�о�return -1
}

template<typename T>
inline void MinHeap<T>::print()
{
	for (int i = 0; i < m_size; ++i)
	{
		cout << m_buff[i] << " ";//��Ϊ������Զ������������ǰ��ղ�α�����˳��浽��������ģ���ӡ�����Ľ��Ҳ�ǲ�α���
	}
	cout << endl;
}
//���ϵ���
template<typename T>
inline void MinHeap<T>::adjustUp(int cur)
{
	int parent = (cur - 1) / 2;//���ڵ�λ��
	T tempVal ;
	while (m_buff[cur] < m_buff[parent])//��ǰ���������ӽڵ��ֵ���С�ڸ��ڵ��ֵ����ô�ͼ�������
	{
		//ֵҪ��������Ҫ��
		tempVal = m_buff[parent];//�Ƚ����ڵ��ֵ������
		m_buff[parent] = m_buff[cur];
		m_buff[cur] = tempVal;
		//λ�õݽ�һ��
		cur = parent;//���µ�ǰ�ڵ��λ��
		parent = (parent - 1) / 2;//���¸��ڵ��λ��
	}
}
//���µ���
template<typename T>
inline void MinHeap<T>::adjustDown(int cur)
{
	int lchild = 2 * cur + 1;//������
	//int rchild = lchild + 1;//������
	int tempVal;
	while (lchild<=m_size-1)//
	{
		tempVal = m_buff[cur];
		//�����Һ�����ѡ��һ����С��
		if (lchild<m_size - 1/*Ҫ�������Һ��ӣ�����ѡ��< */ && m_buff[lchild]>m_buff[lchild + 1])//���Ӵ����Һ���
			lchild++;
		if (tempVal <= m_buff[lchild])//���cur�ڵ��ֵС�ڵ�ǰ���Һ����н�С�Ľڵ��ֵ����ô���˳�
			break;
		else//����ͽ���ֵ������λ��
		{
			m_buff[cur] = m_buff[lchild];
			m_buff[lchild] = tempVal;
			cur = lchild;//���µ�ǰ�ڵ�λ��
			lchild = 2 * cur + 1;//�������ӽڵ�λ��
		}
	}
}

template<typename T>
inline MinHeap<T>::~MinHeap()
{
	if (m_buff)
	{
		delete[] m_buff;
		m_buff = nullptr;
	}
}
