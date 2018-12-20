//��ͬ��new����Ķѣ�������˵�Ķ���һ�����ݽṹ
//�ѿ��Կ�����һ����ȫ������
#include<iostream>
#include"MinHeap.h"
using namespace std;

//����ʵ��һ�¶���ѵ����ݽṹ
//����ѷ�Ϊ���ֲַ��������(���ڵ�>=�ӽڵ�)��С����(���ڵ�<=�ӽڵ�)
//��������������ʵ�ֶ����ݵĴ洢(�����ǲ�������)�������ڽ��е�����ʱ����ӷ�����
//��ȻҪ�õ������Ҫ�漰�±꣬�����±��0��ʼ�ĸ��ڵ���˵��
/*
��i���ڵ�ĸ��ڵ�Ϊ(i-1)/2  ���ӽڵ�Ϊ2*i+1 ���ӽڵ�Ϊ2*i+2
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
	cout << "С���ѣ�" << endl;
	minheap.print();
	cout << "����15֮���С����" << endl;
	minheap.insert(15);
	minheap.print();
	cout << "����12֮���С����" << endl;
	minheap.insert(12);
	minheap.print();
	cout << "ɾ��12֮���С����" << endl;
	minheap.remove(12);
	minheap.print();
	cout << "ɾ��15֮���С����" << endl;
	minheap.remove(15);
	minheap.print();
}