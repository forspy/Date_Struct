//����Ϊ���Է���
/*
#include<iostream>
using namespace std;
struct Node
{
	string name;
	Node* next;
};

//��ʽ1.��װnode* head
struct NodeHead
{
	Node* head;
	int num;//��ʽ1�ĺô��ǿ���Я����������Ϣ���ڲ������ɾ����ʱ����ȥ��������
};
void Init(NodeHead& nodehead)
{
	nodehead.head = new Node;
	nodehead.head->next = NULL;
}
//��ʽ2������Node* head;�ĵ�ַ&head���ö���ָ��ȥ�Ӹı�ָ��ָ��
//�ô�����������ķ�ʽչ��ͷָ������α��޸ĵ�
void Init(Node** headptr)
{
	*headptr = new Node;
	(*headptr)->next = NULL;
}
//��ʽ3��typedef
//�Զ���һ��ͷָ�����ͣ�Node*��ʹ����ṹ��������
typedef Node* NodeList;
void Init(NodeList& head)
{
	head = new Node;
	head->next = NULL;
}
*/