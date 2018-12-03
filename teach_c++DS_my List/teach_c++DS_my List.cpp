#include"my List.h"
#include<iostream>
using namespace std;
int main()
{
	List<int> L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	List<int>::iterator it;
	for (it = L1.begin(); it != L1.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}