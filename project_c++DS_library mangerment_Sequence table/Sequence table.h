#pragma once
//˳�����������߼��϶�����
#define MAXSIZE 100//˳������ھ�̬�洢��ʽ������Ԫ�ز�����������
struct Book
{
	char no[20];//ͼ��ISBN
	char name[50];//ͼ������
	float price;//ͼ��۸�
};

struct SqList//�Ƽ�ʹ�ýṹ���װһ�±�ָ��ͳ��ȣ���ô��ϳ��ȣ���Ȼ�Ժ�ͳ�������ȵ�ʱ����Ҫ����������
{
	Book* elem;//ָ��Book�ڵ��ָ��
	int length;//���е�ͼ�����
};
//��ʼ��
void InitList(SqList* L);
//�������Ա�L
void DestroyList(SqList& L);
//������Ա�
void ClearList(SqList& L);
//�����Ա�ĳ���
int GetLength(SqList& L);
//�ж����Ա��Ƿ�Ϊ��
bool IsEmpty(SqList& L);
//�ж��Ƿ�����
bool IsFull(SqList& L);
//��ȡ���Ա��е�ĳ��Ԫ�ص�����
bool GetElem(SqList& L, int num,Book& book);
//�����Ա��в���Book�ڵ�,������λ��
int LocateElem(SqList& L, char* ISBN);
//β������ڵ�Book
void InsertElem_back(SqList& L, Book& book);
//��ʾ���нڵ�
void ShowAll(SqList& L);
//ָ��λ�ò���Book�ڵ�
void InsertElem_pos(SqList& L, Book& book, int postion);
//ɾ��ISBN���ֵĽڵ�
void DelElem_ISBN(SqList& L, char* ISBN);
//�޸�ͼ�����Ϣ
void ChangeElem(SqList& L, Book& book);