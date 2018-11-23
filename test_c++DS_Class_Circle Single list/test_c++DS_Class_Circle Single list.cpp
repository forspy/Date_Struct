#include"Circle Single list.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	CirSingleList CList;
	CList.ImportDataList();
	CList.ShowAll();
	cout << "-----------" << endl;
	CList.InsertBack("10006", "Linux", 70);
	CList.InsertHead("10007", "JavaScript", 35);
	CList.ShowAll();
	cout << "----------" << endl;
	CList.InsertPos("10099", "new language", 99, 3);
	CList.ShowAll();
	cout << "---------" << endl;
	CList.DelNode(3);
	CList.ShowAll();
}