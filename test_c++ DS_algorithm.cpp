//�㷨�����Ҫ��
/*
1.��ȷ��
2.�ɶ���
3.��׳��(robustness):ָ�����쳣���������ݵĴ���
4.Ч����ʹ�����
*/
//�ظ�ִ�еĴ���Ϊʱ�临�Ӷ�T(n)=O(f(n))
//{x++; s = 0; } O(1)
//------
//for (i = 0; i < n; i++) { x++; s += x; } O(n)
//-------
//for(j=0;j<n;j++)
//	for (i = 0; i < n; i++)
//	{
//		x++;
//	}  O(n^2)

//�������һ��ð���㷨
/*
int bubble_max(int a[], int n)
{
	for (int i = 0; i < n; i++)//��n��
		for (int j = 0; j < n - 1 - i; j++)//��0�ŵ�n-1-i
			if (a[j] > a[j + 1])
				swap(&a[j], &a[j + 1]);

	return a[n - 1];
}
*/
//ʱ�临�Ӷ�ΪO(n^2)  �����Ǵ�->С���� ��n-1,n-2,...,2,1��=n(n-1)/2 ���Ӷ�Ҳ��O(n^2) 
//����һ���鲢����
#include<iostream>
using namespace std;
int main()
{
	//��֪����AB����
	int A[4] = { 3,5,8,11 };
	int B[7] = { 2,6,8,9,11,15,20 };
	//Ŀ���ǰ�AB�����ںϲ��γ�һ�����������C
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
	//��Ϊ�������鲻һ���������Ա�Ȼ��һ���Ȳ��꣬����ʣ�µ���һ��������Ԫ�ض��Ƚϴ�ֱ�Ӳ��뼴��
	while (i < lenA)//Ҳ����˵B�鶼�����ˣ���ʣ�µ�A��ȫ������
	{
		C[k] = A[i];
		k++;
		i++;
	}
	while (j < lenB)//ͬ��
	{
		C[k] = B[j];
		k++;
		j++;
	}
	for (int i = 0; i < lenC; i++)
		cout << C[i] << endl;
}
//ʱ�临�Ӷ�ΪO(A(n)+B(n))