#include "ordered List merge.h"
#include<iostream>
#include<fstream>
int main()
{
	SingleList List1;
	SingleList List2;
	double COFFN;
	int EXPN;
	fstream file1;
	file1.open("A.txt");
	while (!file1.eof())
	{
		file1 >> COFFN>>EXPN;
		List1.InsertBack(COFFN,EXPN);
	}
	file1.close();
	List1.ShowAll();
	fstream file2;
	file2.open("B.txt");
	while (!file2.eof())
	{
		file2 >> COFFN >> EXPN;
		List2.InsertBack(COFFN, EXPN);
	}
	file2.close();
	List2.ShowAll();
	SingleList List3;
	MergeList(List1, List2, List3);
	List3.ShowAll();
	//有序表的合并，这里的方法是借助原有的两条链表lista和listb生成listc，所以如果有析构函数先释放listc，但listc的长度是AB链表的总和，
	//析构完listc以后lista和listb便不能再析构，所以这里的做法是暂时不要析构函数，待优化
	//List2.ShowAll();
	//List1.ShowAll();
}