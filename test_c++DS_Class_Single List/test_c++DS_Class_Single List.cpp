#include"Single List.h"
#include<iostream>

int main()
{
	SingleList List;
	List.InsertHead("xiaoming");
	List.InsertHead("xiaowang");
	List.InsertHead("xiaohua");
	List.ShowAll();
	List.InsertPos("xiahong", 2);
	List.ShowAll();
	List.DelNodePos(3);
	List.ShowAll();
	cout << List.FindNodePos(2) << endl;
	List.ChangeNodePos(2, "xiaoqiu");
	List.ShowAll();
}