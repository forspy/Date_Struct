#pragma once
//�ڵ㣺������+ָ����
//������ʽ�洢�ṹ
/*
�ڵ�ֻ��һ��ָ�����������Ϊ������
������ָ�����������Ϊ˫����
��β��ӵ������Ϊѭ������
*/
//��ͷ�ڵ㵥����ͷָ��headָ������ĵ�һ���ڵ㣬��ͷ�ڵ� ��������ֻ�ſ�/������Ϣ������ͷ�ڵ㲻����������ֵ
//��ͷ�ڵ㵥����ͷָ��headָ������ĵ�һ���ڵ㣬����Ϣ�ڵ�
//��ͷ�ڵ��ʱ��ͷ�ڵ��ָ����ָ��ָ��NULL���ǿձ�
//��ͷ�ڵ��ʱ��ͷָ��headֱ��ָ��NULL���ǿձ�
//
//������ص㣬�ڵ��ڴ������е�λ��������ģ�ͨ���ڵ�ָ�����ָ������
/*
�ŵ㣺
����Ԫ�أ��ڵ㣩������������
����ɾ���Ȳ��������ƶ����ݣ�ֻ���޸�����ָ�룬Ч�ʸ�
*/

/*
������ȱ�㣺ֻ��˳��洢��һ����һ��������/����Ҳ��һ����һ���������hash���ܽ��һ�����������⣩
*/
/*
дһ���Ҳ�̫ϲ����typedef��
typedef struct LNode{
 ElemType data;
 struct Lnode* next;
}LNode,*LinkList;
��ʾ������ṹ��LNode������ΪLNode����*LinkList��*LinkListΪLnode���͵�ָ�룩 LNode* p���һ���ϲ����ôд�� �ȼ���LinkList p
*/
#include<string>
using namespace std;
//��ͷ�ڵ㵥����
//�ڵ�
struct Node
{
	string name;
	Node* next;
};
typedef Node* NodeHead;//�Զ���һ��ͷָ�����ͣ�Node*��ʹ����ṹ��������

//�ж������Ƿ�Ϊ��
bool IsEmpty(NodeHead& head);
//����һ�������ͷ��ڴ棩
void destroy(NodeHead& head);
//���
int ListLength(NodeHead& head);
//���������еĵ�n��Ԫ��
string ListFind(NodeHead& head,int n);
//���������е�ĳ��Ԫ�����ڵ�λ��
int ListFind_pos(NodeHead& head,const string str);
//����һ���ڵ�(ͷ�巨)
void InsertHead(NodeHead& head, const string str);
//��ʾ��������Ԫ��
void ShowAll(NodeHead& head);
//��ָ��λ�ò���
void Insert_pos(NodeHead& head, int pos, const string str);
//ɾ��ָ��λ�õĽڵ�
void DelNode(NodeHead& head, int pos);
//��ȡ������
int GetListLenght(NodeHead& head);