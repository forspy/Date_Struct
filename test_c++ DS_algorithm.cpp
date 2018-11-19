//算法的设计要求：
/*
1.正确性
2.可读性
3.健壮性(robustness):指对于异常的输入数据的处理
4.效率与低储存量
*/
//重复执行的次数为时间复杂度T(n)=O(f(n))
//{x++; s = 0; } O(1)
//------
//for (i = 0; i < n; i++) { x++; s += x; } O(n)
//-------
//for(j=0;j<n;j++)
//	for (i = 0; i < n; i++)
//	{
//		x++;
//	}  O(n^2)

//例如对于一个冒泡算法
/*
int bubble_max(int a[], int n)
{
	for (int i = 0; i < n; i++)//排n次
		for (int j = 0; j < n - 1 - i; j++)//从0排到n-1-i
			if (a[j] > a[j + 1])
				swap(&a[j], &a[j + 1]);

	return a[n - 1];
}
*/
//时间复杂度为O(n^2)  最坏情况是大->小有序 排n-1,n-2,...,2,1次=n(n-1)/2 复杂度也是O(n^2) 
//来看一个归并排序
#include<iostream>
using namespace std;
int main()
{
	//已知数组AB有序
	int A[4] = { 3,5,8,11 };
	int B[7] = { 2,6,8,9,11,15,20 };
	//目标是把AB数组融合并形成一个有序的数组C
	const int lenA = sizeof(A) / sizeof(int);
	const int lenB = sizeof(B) / sizeof(int);
	const int lenC = lenA+lenB;
	int C[lenC] = { 0 };
	int i, j, k;
	i = j = k = 0;
	while (i<lenA&&j<lenB)
	{
		if (A[i] <= B[j])
		{
			C[k] = A[i];
			k++;
			i++;
		}
		else
		{
			C[k] = B[j];
			k++;
			j++;
		}
	}
	//因为两个数组不一样长，所以必然有一方先插完，所以剩下的那一方的数组元素都比较大直接插入即可
	while (i < lenA)//也就是说B组都插完了，把剩下的A组全不插入
	{
		C[k] = A[i];
		k++;
		i++;
	}
	while (j < lenB)//同理
	{
		C[k] = B[j];
		k++;
		j++;
	}
	for (int i = 0; i < lenC; i++)
		cout << C[i] << endl;
}
//时间复杂度为O(A(n)+B(n))