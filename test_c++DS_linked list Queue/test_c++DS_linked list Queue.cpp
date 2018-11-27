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
	cout << "队列的长度为：" << List.GetListLength() << endl;

	int N = 10;
	Queue List1;
	while (N)
	{
		List1.Enqueue(N % 2);
		N = N / 2;
	}
	cout << "十进制10转化位2进制，从右到左(右边为高位)" << endl;
	List1.ShowAll();
}
