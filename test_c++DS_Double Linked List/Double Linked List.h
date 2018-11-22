#pragma once
#include<iostream>
#include<string>
using namespace std;
struct DoubNode
{
	DoubNode* prior;//前指针
	string name;
	DoubNode* next;//后指针
};
//因为是双向链表，所以加入头尾指针更方便
typedef DoubNode* DoubHeadNode;
typedef DoubNode* DoubRearNode;
//双向循环链表:从循环链表中的任意一个节点位置都可以找到其他节点
//如果先求长度遍历太麻烦也可以设置一个全局变量 int lenght=0;在插入节点和删除节点的时候对lenght进行操作
/*
前指针prior指向前一个节点，后指针next指向后一个节点
要考虑有节点的情况和无节点的情况：1有节点的情况是四个链接2.无节点额情况是三个链接
在指定位置插入时要考虑链接顺序
*/
//非循环双向链表，无头节点模式

//创建一个新节点
DoubNode* CreatNewNode(const string& str);
//头部插入节点
void InsertHead(DoubHeadNode& head, DoubRearNode& rear,const string& str);
//尾部插入一个节点
void InsertRear(DoubHeadNode& head, DoubRearNode& rear, const string& str);
//指定位置插入
void InsertPos(DoubHeadNode& head, int pos, const string& str);//相对于头指针的位置
//指定位置删除
void DelPos(DoubHeadNode& head, int pos);//相对于头指针的位置
//查找指定位置的节点信息
void FindDoubList(DoubHeadNode& head, int pos);
//改变指定位置的节点信息
void ChangeNode(DoubHeadNode& head, int pos,const string& str);
//显示所有节点
void ShowAll(DoubHeadNode& head);
