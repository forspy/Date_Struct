#include "ordered List merge.h"
#include<iostream>
#include<fstream>
int main()
{
	SingleList List1;
	SingleList List2;
	int data;
	fstream file1;
	file1.open("A.txt");
	while (!file1.eof())
	{
		file1 >> data;
		List1.InsertBack(data);
	}
	file1.close();
	List1.ShowAll();
	fstream file2;
	file2.open("B.txt");
	while (!file2.eof())
	{
		file2 >> data;
		List2.InsertBack(data);
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