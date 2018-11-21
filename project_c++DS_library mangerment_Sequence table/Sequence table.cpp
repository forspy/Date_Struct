#include"Sequence table.h"
#include<iostream>
using namespace std;
void InitList(SqList* L)
{
	L->elem = new Book[MAXSIZE];
	if (!L->elem)
		exit(OVERFLOW);
	L->length = 0;
}
//销毁线性表（代表释放申请空间）
void DestroyList(SqList& L)
{
	if (L.elem)
		delete[] L.elem;
}
//清空线性表（代表拨动表内指针，重复使用）
void ClearList(SqList& L)
{
	L.length = 0;
}
//求线性表的长度
int GetLength(SqList & L)
{
	return L.length;
}
//判断线性表是否为空
bool IsEmpty(SqList & L)
{
	return L.length == 0;//true是空表false代表表内有节点
}
bool IsFull(SqList & L)
{
	return L.length >= MAXSIZE;
}
//获取线性表中的某个元素的内容
bool GetElem(SqList & L, int num,Book& book)
{
	if (num<0 || num>L.length)//注意逻辑或是||而不是|
	{
		cout << "超出范围" << endl;
		return false;
	}
	book = L.elem[num];
	return true;
}
//在线性表中查找Book节点
int LocateElem(SqList & L, char * ISBN)
{
	for (int i = 0; i < L.length; i++)
	{
		//cout << L.elem[i].no << endl;
		//cout << strcmp("hello", "helle") << endl;
		//cout << strcmp(L.elem[i].no, ISBN) << endl;
		if (strcmp(L.elem[i].no, ISBN)==0)//为0说明一样
		{
			cout << "找到了" << ISBN << " " << L.elem->name <<" "<< L.elem->price <<" "<< endl;
			return i;
		}
	}
	cout << "没有找到" << endl;
	return -1;
}
//尾部插入节点Book
void InsertElem_back(SqList & L, Book & book)
{
	if (!IsFull(L))
	{
		L.elem[L.length] = book;//默认operator=重载
		L.length++;
	}
}
//显示所有节点
void ShowAll(SqList & L)
{
	if (!IsEmpty(L))
	{
		for (int i = 0; i < L.length; i++)//用表内指数器length去控制输出
		{
			cout << "ISBN:" << L.elem[i].no << " " << L.elem[i].name << " " << L.elem[i].price << endl;
		}
	}
	else
		cout << "表为空" << endl;
}
//指定位置插入Book节点（表示把当前节点往后挤一位）
void InsertElem_pos(SqList & L, Book & book, int postion)
{
	if (!IsFull(L))
	{
		if (postion > L.length || postion < 0)
		{
			cout << "postion超出范围" << endl;
			return;
		}
		for (int i = L.length; i >= postion; i--)
		//所有元素完成前后移动一位，这也是顺序表比链表不足的地方，因为顺序表是内存紧挨着排列的一旦有元素插入会影响后面的所有元素
		{
			L.elem[i + 1] = L.elem[i];
		}
		L.elem[postion] = book;
		L.length++;
	}
}
//删除ISBN名字的节点
void DelElem_ISBN(SqList & L, char * ISBN)
{
	int postion = LocateElem(L, ISBN);
	if (postion)//表示找到了
	{
		for (int i = postion; i < L.length; i++)
		{
			L.elem[i] = L.elem[i + 1];//这里也是部分统统移位
		}
		L.length--;
	}
}
//修改图书的信息
void ChangeElem(SqList & L, Book & book)
{
	int postion = LocateElem(L, book.no);
	if (postion)
	{
		memset(L.elem[postion].name, 0, 50 * sizeof(char));//将name初始化为0
		strcpy_s(L.elem[postion].name, book.name);
		L.elem[postion].price = book.price;
		cout << "修改完毕" << endl;
	}
	
}

