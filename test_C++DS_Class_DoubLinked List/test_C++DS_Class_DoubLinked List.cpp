#include"DoubLinked List.h"
#include<iostream>

int main()
{
	DoubList List;
	List.InsertHead("xiaoming");
	List.InsertHead("xiaozhang");
	List.InsertHead("xiaohua");
	List.ShowAll();
	cout << "˫������ĳ���Ϊ��" << List.ShowLength() << endl;
	List.InsertPos("xiaowang", 3);
	List.ShowAll();
	List.DelNode(3);
	List.ShowAll();
	cout << List.FindNode(0) << endl;
	List.ChangeNode(1, "xiaoqiu");
	List.ShowAll();
}