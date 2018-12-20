//不同于new里面的堆，这里所说的堆是一种数据结构
//堆可以看作是一颗完全二叉树
#include<iostream>
#include"MinHeap.h"
#include"MaxHeap.h"
using namespace std;

//这里实现一下二叉堆的数据结构
//二叉堆分为两种分布：大根堆(根节点>=子节点)、小根堆(根节点<=子节点)
//这里利用数组来实现堆数据的存储(而不是采用链表)，这样在进行调整的时候更加方便快捷
//既然要用到数组就要涉及下标，对于下标从0开始的根节点来说：
/*
第i个节点的父节点为(i-1)/2  左子节点为2*i+1 右子节点为2*i+2
*/
int main()
{
	int arr[] = { 10,20,40,30,60,80,90,50,70 };
	int len = sizeof(arr) / sizeof(arr[0]);
	MinHeap<int> minheap(20);
	for (int i = 0; i < len; ++i)
	{
		minheap.insert(arr[i]);
	}
	cout << "小根堆：" << endl;
	minheap.print();
	cout << "插入15之后的小根堆" << endl;
	minheap.insert(15);
	minheap.print();
	cout << "插入12之后的小根堆" << endl;
	minheap.insert(12);
	minheap.print();
	cout << "删除12之后的小根堆" << endl;
	minheap.remove(12);
	minheap.print();
	cout << "删除15之后的小根堆" << endl;
	minheap.remove(15);
	minheap.print();

	MaxHeap<int> maxheap(20);
	for (int i = 0; i < len; ++i)
	{
		maxheap.insert(arr[i]);
	}
	cout << "大根堆：" << endl;
	maxheap.print();
	cout << "插入75之后的大根堆" << endl;
	maxheap.insert(75);
	maxheap.print();
	cout << "插入65之后的大根堆" << endl;
	maxheap.insert(65);
	maxheap.print();
	cout << "删除65之后的大根堆" << endl;
	maxheap.remove(65);
	maxheap.print();
	cout << "删除75之后的大根堆" << endl;
	maxheap.remove(75);
	maxheap.print();
	//堆排序思想：输出每一次堆排序的头一个值，对身下的元素继续进行堆排序
	cout << "堆排序" << endl;
	int temp;
	for (int i = 0; i < len; ++i)
	{
		temp=minheap.getFront();
		cout << temp << " ";
		minheap.remove(temp);
	}
	cout << endl;
}