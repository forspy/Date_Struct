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
}
