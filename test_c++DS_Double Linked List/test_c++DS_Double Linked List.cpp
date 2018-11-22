#include"Double Linked List.h"

int main()
{
	DoubHeadNode Head=NULL;//Õ∑÷∏’Î
	DoubRearNode Rear = NULL;//Œ≤÷∏’Î
	InsertHead(Head, Rear, "xiaoming");
	InsertHead(Head, Rear, "xiaohong");
	InsertHead(Head, Rear, "xiaohua");
	InsertRear(Head, Rear, "xiangwang");
	ShowAll(Head);
	InsertPos(Head, 2, "xiaozhang");
	ShowAll(Head);
	DelPos(Head, 3);
	ShowAll(Head);
	FindDoubList(Head, 3);
	ChangeNode(Head, 2, "xiaodong");
	ShowAll(Head);
}