#include "Double Linked List.h"

//ͷ������ڵ�
void InsertHead(DoubHeadNode & head,DoubRearNode& rear,const string& str)
{
	DoubNode* newnode = CreatNewNode(str);
	if (head)//����нڵ����
	{
		newnode->next = head;
		head->prior = newnode;
		newnode->prior = NULL;
		head = newnode;
	}
	else//���û�нڵ�
	{
		newnode->next = NULL;
		newnode->prior = NULL;
		head = rear = newnode;
	}
}
//β������һ���ڵ�
void InsertRear(DoubHeadNode & head, DoubRearNode & rear, const string & str)
{
	DoubNode* newnode = CreatNewNode(str);
	if (rear)
	{
		//β�ڵ��ȴ�prior����
		newnode->prior = rear;
		rear->next = newnode;
		newnode->next = NULL;
		rear = newnode;
	}
	else//���û�нڵ�
	{
		newnode->next = NULL;
		newnode->prior = NULL;
		head = rear = newnode;
	}
}
//ָ��λ�ò���
void InsertPos(DoubHeadNode & head, int pos, const string & str)
{
	//��ͷ��ʼ����
	DoubNode* newnode = CreatNewNode(str);
	DoubHeadNode p = head;
	for (int i = 0; i < pos; i++)
	{
		p = p->next;
	}
	//ע��˳��,�������ǰ��ڵ������
	newnode->prior = p->prior;//������ǰ�棬�����Ͳ���Ӱ�쵽P
	p->prior->next = newnode;
	//�����Ӻ���
	newnode->next = p;
	p->prior = newnode;
}
//ָ��λ��ɾ����ɾ��ָ��λ�õĽڵ�
void DelPos(DoubHeadNode & head, int pos)
{
	DoubHeadNode p = head;
	for (int i = 0; i < pos; i++)
	{
		p = p->next;
	}
	DoubNode* temp = p;//����һ��tempָ�뱣��pָ��ڵ��λ��
	p->next->prior = p->prior;//p����Ľڵ��prior����pǰ��Ľڵ�
	p->prior->next = p->next;//pǰ��Ľڵ��next����p����Ľڵ�
	delete temp;//�ͷ���ʱָ��
}
// ����ָ��λ�õĽڵ���Ϣ
void FindDoubList(DoubHeadNode & head, int pos)
{
	DoubHeadNode p = head;
	for (int i = 0; i < pos; i++)
	{
		p = p->next;
	}
	cout << p->name << endl;
}
//�ı�ָ��λ�õĽڵ���Ϣ
void ChangeNode(DoubHeadNode & head, int pos,const string& str)
{
	DoubHeadNode p = head;
	for (int i = 0; i < pos; i++)
	{
		p = p->next;
	}
	p->name = str;
}
//����һ���½ڵ�
DoubNode * CreatNewNode(const string& str)
{
	DoubNode* newnode = new DoubNode;
	newnode->prior = NULL;
	newnode->name = str;
	newnode->next = NULL;
	return newnode;
}
//��ʾ���нڵ�
void ShowAll(DoubHeadNode & head)
{
	DoubHeadNode p = head;
	while (p)
	{
		cout << p->name << "<->";
		p = p->next;
	}
	cout << "NULL" << endl;
}
