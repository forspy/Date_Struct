#pragma once
#include<iostream>
using namespace std;
template<typename T>
class MaxHeap//小根堆
{
private:
	T* m_buff;//数组
	int m_size;//当前容量大小,如果不访问系统就会回收?，m_size表示个数，从1个开始
	int m_capcity;//最大容量，因为如果删除一个节点后，m_size就会改变，又要重新申请数组？(等一会我尝试一下没有m_capcity直接，改m_size)
				  //m_capcity-m_size之间的内存不会被系统回收
				  //向上调整
	void adjustUp(int cur);//大根堆是大值在上，所以向上调整和小根堆是相反的
	//向下调整
	void adjustDown(int cur);
public:
	MaxHeap(int capcity = 0);
	//插入
	bool insert(const T& data);
	//删除
	bool remove(const T& data);
	//查找
	int find(const T& data);
	//打印
	void print();
	~MaxHeap();
};

template<typename T>
inline void MaxHeap<T>::adjustUp(int cur)
{
	int parent = (cur - 1) / 2;//父节点位置
	T tempVal;
	while (m_buff[cur] > m_buff[parent])//当前待交换的子节点的值如果小于父节点的值，那么就继续交换
	{
		//值要换，坐标要换
		tempVal = m_buff[parent];//先将父节点的值存起来
		m_buff[parent] = m_buff[cur];
		m_buff[cur] = tempVal;
		//位置递进一层
		cur = parent;//更新当前节点的位置
		parent = (parent - 1) / 2;//更新父节点的位置
	}
}

template<typename T>
inline void MaxHeap<T>::adjustDown(int cur)
{
	int lchild = 2 * cur + 1;//左子树
							 //int rchild = lchild + 1;//右子树
	int tempVal;
	while (lchild <= m_size - 1)//
	{
		tempVal = m_buff[cur];
		//在左右孩子中选择一个最大的
		if (lchild<m_size - 1/*要可能有右孩子，所以选择< */ && m_buff[lchild]<m_buff[lchild + 1])//如果左孩子小于右孩子
			lchild++;//选择右孩子
		if (tempVal >= m_buff[lchild])//如果cur节点的值大于当前左右孩子中较大的节点的值，那么就退出
			break;
		else//否则就交换值，交换位置
		{
			m_buff[cur] = m_buff[lchild];
			m_buff[lchild] = tempVal;
			cur = lchild;//更新当前节点位置
			lchild = 2 * cur + 1;//更新左子节点位置
		}
	}
}

template<typename T>
inline MaxHeap<T>::MaxHeap(int capcity)
{
	if (capcity <= 0)//防呆设计
	{
		capcity = 20;
	}
	m_buff = new T[capcity];
	m_size = 0;
	m_capcity = capcity;
}

template<typename T>
inline bool MaxHeap<T>::insert(const T & data)
{
	if (m_capcity == m_size)//如果当前容量达到最大容量，则需要对当前容量进行扩充
	{
		m_capcity = 2 * m_capcity;//往两倍扩充最大容量
		T* tempbuff = new T[m_capcity];
		memcpy(tempbuff, m_buff, sizeof(T)*m_size);//复制m_buff里面的内存到tempbuff中
		delete[] m_buff;//释放m_buff里面的内存
		m_buff = tempbuff;//m_buff接管tempbuff里面的内存
	}
	m_buff[m_size] = data;//将元素插入到末尾
						  //调整最小堆
	adjustUp(m_size);//从m_size个元素开始调整，m_size插入一个元素表示在末尾再插入一个元素进行调整
	m_size++;
	return true;
}

template<typename T>
inline bool MaxHeap<T>::remove(const T & data)
{
	if (m_size == 0)//表示堆空了
		return false;
	int cur = find(data);//找到该点的索引
	if (cur == -1)
		return false;
	//用最后一个节点的代替当前节点的值，然后删除最后一个节点，然后进行向下调整
	m_buff[cur] = m_buff[m_size - 1];
	m_size--;
	adjustDown(cur);
	return true;
}

template<typename T>
inline int MaxHeap<T>::find(const T & data)
{
	for (int i = 0; i < m_size; ++i)//在递归的时候最好能使用++i,
	{
		if (data == m_buff[i])
			return i;
	}
	return -1;//没有就return -1
}

template<typename T>
inline void MaxHeap<T>::print()
{
	for (int i = 0; i < m_size; ++i)
	{
		cout << m_buff[i] << " ";//因为数组会自动调整，所以是按照层次遍历的顺序存到数组里面的，打印出来的结果也是层次遍历
	}
	cout << endl;
}

template<typename T>
inline MaxHeap<T>::~MaxHeap()
{
	if (m_buff)
	{
		delete[] m_buff;
		m_buff = nullptr;
	}
}
