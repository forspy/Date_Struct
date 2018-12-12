#include<iostream>
#include"BinSearchTree.h"
using namespace std;
int SequenceSearch(int* arr, int size, int findValue);//˳�����
int BinSearch(int* arr, int left,int right,int findValue);//���ֲ���,��Ҫ��֤����
int BinSearch(int* arr, int size, int findValue);//���ֲ��ҷǵݹ��,��Ҫ��֤����
int InsertSearch(int* arr, int left, int right, int findValue);//��ֵ���ң����ֲ��ҵ��Ż�����Ҫ��֤����
int InsertSearch(int* arr, int size, int findValue);//��ֵ���ң��ǵݹ��

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
	BSTree<int> BinFindTree;//����һ�����������
	for (int i = 0; i < size; i++)
	{
		BinFindTree.insert(arr[i]);
	}

	BinFindTree.DelNode(3);
	BinFindTree.prePrint();//�������
	//BinFindTree.midPrint();//�������
	//BinFindTree.backPrint();//�������
	//cout << BinFindTree.Search(8) << endl;//���ؿ��Է���һ���ڵ��ַ

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
//���ֲ���(�ݹ��)
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
	//�ݹ鲻�����пؼ�·��������ֵ
}
//���ֲ��ҷǵݹ��,���пؼ�·��������ֵ
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
//��ֵ������ҪԪ�ؾ�����֤���ȷֲ��������ҵ���index���ǽϺõ�
int InsertSearch(int * arr, int left, int right, int findValue)
{
	//ͨ������ֵ���� index������������������԰�
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

