#pragma once
//顺序表在物理和逻辑上都相邻
#define MAXSIZE 100//顺序表属于静态存储形式，数据元素不能自由扩充
struct Book
{
	char no[20];//图书ISBN
	char name[50];//图书名字
	float price;//图书价格
};

struct SqList//推荐使用结构体封装一下表指针和长度（最好带上长度，不然以后统计链表长度的时候需要反复遍历）
{
	Book* elem;//指向Book节点的指针
	int length;//表中的图书个数
};
//初始化
void InitList(SqList* L);
//销毁线性表L
void DestroyList(SqList& L);
//清空线性表
void ClearList(SqList& L);
//求线性表的长度
int GetLength(SqList& L);
//判断线性表是否为空
bool IsEmpty(SqList& L);
//判断是否满了
bool IsFull(SqList& L);
//获取线性表中的某个元素的内容
bool GetElem(SqList& L, int num,Book& book);
//在线性表中查找Book节点,并返回位置
int LocateElem(SqList& L, char* ISBN);
//尾部插入节点Book
void InsertElem_back(SqList& L, Book& book);
//显示所有节点
void ShowAll(SqList& L);
//指定位置插入Book节点
void InsertElem_pos(SqList& L, Book& book, int postion);
//删除ISBN名字的节点
void DelElem_ISBN(SqList& L, char* ISBN);
//修改图书的信息
void ChangeElem(SqList& L, Book& book);