#include"linked list Queue.h"
#include<iostream>
using namespace std;
int main()
{
	Queue List;
	for (int i = 0; i < 3; i++)
	{
		List.Enqueue(i);
	}
	cout << List.Dequeue() << endl;
	List.ShowAll();
	cout << List.GetFirst() << endl;
	cout << "���еĳ���Ϊ��" << List.GetListLength() << endl;

	int N = 10;
	Queue List1;
	while (N)
	{
		List1.Enqueue(N % 2);
		N = N / 2;
	}
	cout << "ʮ����10ת��λ2���ƣ����ҵ���(�ұ�Ϊ��λ)" << endl;
	List1.ShowAll();
}
