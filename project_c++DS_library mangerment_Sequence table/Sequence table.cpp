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
//�������Ա������ͷ�����ռ䣩
void DestroyList(SqList& L)
{
	if (L.elem)
		delete[] L.elem;
}
//������Ա�����������ָ�룬�ظ�ʹ�ã�
void ClearList(SqList& L)
{
	L.length = 0;
}
//�����Ա�ĳ���
int GetLength(SqList & L)
{
	return L.length;
}
//�ж����Ա��Ƿ�Ϊ��
bool IsEmpty(SqList & L)
{
	return L.length == 0;//true�ǿձ�false��������нڵ�
}
bool IsFull(SqList & L)
{
	return L.length >= MAXSIZE;
}
//��ȡ���Ա��е�ĳ��Ԫ�ص�����
bool GetElem(SqList & L, int num,Book& book)
{
	if (num<0 || num>L.length)//ע���߼�����||������|
	{
		cout << "������Χ" << endl;
		return false;
	}
	book = L.elem[num];
	return true;
}
//�����Ա��в���Book�ڵ�
int LocateElem(SqList & L, char * ISBN)
{
	for (int i = 0; i < L.length; i++)
	{
		//cout << L.elem[i].no << endl;
		//cout << strcmp("hello", "helle") << endl;
		//cout << strcmp(L.elem[i].no, ISBN) << endl;
		if (strcmp(L.elem[i].no, ISBN)==0)//Ϊ0˵��һ��
		{
			cout << "�ҵ���" << ISBN << " " << L.elem->name <<" "<< L.elem->price <<" "<< endl;
			return i;
		}
	}
	cout << "û���ҵ�" << endl;
	return -1;
}
//β������ڵ�Book
void InsertElem_back(SqList & L, Book & book)
{
	if (!IsFull(L))
	{
		L.elem[L.length] = book;//Ĭ��operator=����
		L.length++;
	}
}
//��ʾ���нڵ�
void ShowAll(SqList & L)
{
	if (!IsEmpty(L))
	{
		for (int i = 0; i < L.length; i++)//�ñ���ָ����lengthȥ�������
		{
			cout << "ISBN:" << L.elem[i].no << " " << L.elem[i].name << " " << L.elem[i].price << endl;
		}
	}
	else
		cout << "��Ϊ��" << endl;
}
//ָ��λ�ò���Book�ڵ㣨��ʾ�ѵ�ǰ�ڵ�����һλ��
void InsertElem_pos(SqList & L, Book & book, int postion)
{
	if (!IsFull(L))
	{
		if (postion > L.length || postion < 0)
		{
			cout << "postion������Χ" << endl;
			return;
		}
		for (int i = L.length; i >= postion; i--)
		//����Ԫ�����ǰ���ƶ�һλ����Ҳ��˳����������ĵط�����Ϊ˳������ڴ���������е�һ����Ԫ�ز����Ӱ����������Ԫ��
		{
			L.elem[i + 1] = L.elem[i];
		}
		L.elem[postion] = book;
		L.length++;
	}
}
//ɾ��ISBN���ֵĽڵ�
void DelElem_ISBN(SqList & L, char * ISBN)
{
	int postion = LocateElem(L, ISBN);
	if (postion)//��ʾ�ҵ���
	{
		for (int i = postion; i < L.length; i++)
		{
			L.elem[i] = L.elem[i + 1];//����Ҳ�ǲ���ͳͳ��λ
		}
		L.length--;
	}
}
//�޸�ͼ�����Ϣ
void ChangeElem(SqList & L, Book & book)
{
	int postion = LocateElem(L, book.no);
	if (postion)
	{
		memset(L.elem[postion].name, 0, 50 * sizeof(char));//��name��ʼ��Ϊ0
		strcpy_s(L.elem[postion].name, book.name);
		L.elem[postion].price = book.price;
		cout << "�޸����" << endl;
	}
	
}

