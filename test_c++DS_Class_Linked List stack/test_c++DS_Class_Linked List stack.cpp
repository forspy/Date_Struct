#include"Linked List stack.h"
#include<iostream>
using namespace std;
int main()
{
	LinkedListStack List;
	for (int i = 0; i < 5; i++)
	{
		List.push(i);
	}
	List.ShowAll();
	cout << List.pop()->data << endl;
	List.ShowAll();
	List.ShowLength();
}