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
	//�����ĺϲ�������ķ����ǽ���ԭ�е���������lista��listb����listc����������������������ͷ�listc����listc�ĳ�����AB������ܺͣ�
	//������listc�Ժ�lista��listb�㲻���������������������������ʱ��Ҫ�������������Ż�
	//List2.ShowAll();
	//List1.ShowAll();
}