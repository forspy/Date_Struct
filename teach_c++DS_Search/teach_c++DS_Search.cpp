#include<iostream>
#include"BinSearchTree.h"
using namespace std;
int SequenceSearch(int* arr, int size, int findValue);//顺序查找
int BinSearch(int* arr, int left,int right,int findValue);//二分查找,需要保证有序
int BinSearch(int* arr, int size, int findValue);//二分查找非递归版,需要保证有序
int InsertSearch(int* arr, int left, int right, int findValue);//插值查找，二分查找的优化，需要保证有序
int InsertSearch(int* arr, int size, int findValue);//插值查找，非递归版

int main()
{
	int arr[] = { 5,1,2,7,6,4,9,3,8,0 };
	int arr1[] = { 0,1,2,3,4,5,6,7,8,9 };
	int size = sizeof(arr) / sizeof(arr[0]);
	cout << SequenceSearch(arr, size, 7) << endl;
	cout << BinSearch(arr1, 0, size - 1, 7) << endl;
	cout << BinSearch(arr1, size, 7) << endl;
	cout << InsertSearch(arr1, 0, size - 1, 7) << endl;
	cout << InsertSearch(arr1, size, 7) << endl;
	cout << "--------" << endl;
	BSTree<int> BinFindTree;//建立一个二叉查找树
	for (int i = 0; i < size; i++)
	{
		BinFindTree.insert(arr[i]);
	}

	BinFindTree.DelNode(3);
	BinFindTree.prePrint();//先序遍历
	//BinFindTree.midPrint();//中序遍历
	//BinFindTree.backPrint();//后序遍历
	//cout << BinFindTree.Search(8) << endl;//搜素可以返回一个节点地址

}

int SequenceSearch(int * arr, int size, int findValue)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == findValue)
			return i;
	}
	return -1;
}
//二分查找(递归版)
int BinSearch(int* arr, int left, int right, int findValue)
{
	if (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] == findValue)
			return mid;
		else if (arr[mid] < findValue)
			BinSearch(arr, mid + 1, right, findValue);
		else if (arr[mid] > findValue)
			BinSearch(arr, left, mid - 1, findValue);
	}
	else
		return -1;
	//递归不是所有控件路径都返回值
}
//二分查找非递归版,所有控件路径都返回值
int BinSearch(int * arr, int size, int findValue)
{
	int left = 0;
	int right = size - 1;
	int mid;
	while (left<=right)
	{
		mid = (left + right) / 2;
		if (arr[mid] == findValue)
			return mid;
		else if (arr[mid] < findValue)
			left = mid + 1;
		else if (arr[mid] > findValue)
			left = mid-1;
	}
	return -1;
}
//插值查找需要元素尽量保证均匀分布，这样找到的index才是较好的
int InsertSearch(int * arr, int left, int right, int findValue)
{
	//通过查找值索引 index，而不是像二分那样对半
	//(index-left)/(findValue-arr[left])=(right-left)/(arr[right]-arr[left]);
	if (left <= right)
	{
		int index = (right - left) / (arr[right] - arr[left])*(findValue - arr[left]) + left;
		if (arr[index] == findValue)
			return index;
		else if (arr[index] < findValue)
			BinSearch(arr, index + 1, right, findValue);
		else if (arr[index] > findValue)
			BinSearch(arr, left, index - 1, findValue);
	}
	else
		return -1;
}

int InsertSearch(int * arr, int size, int findValue)
{
	int left = 0;
	int right = size - 1;
	int index;
	while (left <= right)
	{
		index = (right - left) / (arr[right] - arr[left])*(findValue - arr[left]) + left;
		if (arr[index] == findValue)
			return index;
		else if (arr[index] < findValue)
			left = index + 1;
		else if (arr[index] > findValue)
			left = index - 1;
	}
	return -1;
}

