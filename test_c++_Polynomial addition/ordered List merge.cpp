#include "ordered List merge.h"
#include<iostream>
//���캯��
SingleList::SingleList()
{
	//ͷָ���ָ��ͷ�ڵ�βָ��ָ��ͷ�ڵ��next
	m_head = new Node;
	m_head->next = nullptr;
	m_rear = m_head;
	m_rear= nullptr;
}
//��������destroy
//SingleList::~SingleList()
//{
//	Node* p = m_head;
//	Node* temp;
//	while (p)//��ͷ�ڵ㿪ʼ�ͷ�
//	{
//		temp = p;
//		cout << "�ͷ�" << p->number << " ";
//		p = p->next;
//		delete temp;
//	}
//	cout << endl;
//}
//����һ���ڵ�
Node* SingleList::CreatNode(double c, int e)
{
	Node* newnode = new Node;
	newnode->expn = e;
	newnode->coffn = c;
	newnode->next = nullptr;
	return newnode;
}
//ͷ�巨����Ӱ��βָ�룩
void SingleList::InsertHead(double c, int e)
{
	Node* newnode = CreatNode(c,e);
	//--�����һ���ڵ�����ʱ��Ҫ��βָ������ýڵ㣬�Ժ�ͷ�巨��Ӱ�첻��βָ����
	if (m_head->next == nullptr)
		m_rear = newnode;
	//----
	newnode->next = m_head->next;
	m_head->next = newnode;//ͷ�ڵ��nextָ��newnode
	
}
//β�巨
void SingleList::InsertBack(double c, int e)
{
	Node* newnode = CreatNode(c,e);
	//β�巨��Ҫ������û�е�һ���ڵ�
	if (m_rear == nullptr)
	{
		newnode->next = nullptr;
		m_head->next = newnode;
		m_rear = newnode;
	}
	else
	{
		newnode->next = nullptr;
		m_rear->next = newnode;
		m_rear = newnode;
	}
}

//��ʾ���нڵ�
void SingleList::ShowAll()
{
	Node* p = m_head;
	p = p->next;//�ƶ�����һ���ڵ�
	while (p)
	{
		if (p->expn)
		{
			cout << p->coffn << "x^" << p->expn << "+";
			p = p->next;
		}
		else
		{
			cout << p->coffn << "+";
			p = p->next;
		}
	}
	cout << "NULL" << endl;
}
//��ָ��λ�ò���ڵ㣨��Ҫ���ǳ��������ȵ������
void SingleList::InsertPos(double c, int e, int position)
{
	Node* newnode = CreatNode(c,e);
	Node* p = m_head;
	for (int i = 0; i < position; i++)
	{
		p = p->next;
	}
	//����һ��һ���ڵ㶼û���ƶ������
	newnode->next = p->next;
	p->next = newnode;
}
//ָ��λ��ɾ��һ���ڵ�
void SingleList::DelNodePos(int pos)
{
	Node* p = m_head;
	Node* temp;
	for (int i = 0; i < pos; i++)
	{
		p = p->next;
	}
	temp = p->next;
	p->next = p->next->next;
	delete temp;
}
//����ָ��λ�õĽڵ�
int SingleList::FindNodePos(int pos)
{
	Node* p = m_head;
	for (int i = 0; i < pos; i++)
	{
		p = p->next;
	}
	return p->next->expn;
}
//�ı�ڵ�Ԫ����Ϣ
void SingleList::ChangeNodePos(int pos, double c, int e)
{
	Node* p = m_head;
	for (int i = 0; i < pos; i++)
	{
		p = p->next;
	}
	p->next->expn = e;
}
//�������Ա�ϲ����������� ��1��2��4...��
//A(x)=7+3x+9x^8+5x^17;
//B(x)=8x+22x^7-9x^8;
//---------------------------
void MergeList(SingleList & lista, SingleList & listb, SingleList & listc)
{
	//���ȶ���ָ���������ָ��pa,pb,pc���ϲ����µ�����listc��
	Node* pa = lista.GetHead()->next;//paָ��lisa�ĵ�һ���ڵ�
	Node* pb = listb.GetHead()->next;//pbָ��lisb�ĵ�һ���ڵ�
	Node* pc = listc.GetHead();//pc��ʱָ��listc��ͷ�ڵ�
	//ע��listc�����¿���һ������listc����lista��listb��ѡ��Ԫ������
	while (pa&&pb)//�������ǿ�
	{
		if (pa->expn == pb->expn)//�����������ʽϵ����ȣ���ʼ���
		{
			pa->coffn += pb->coffn;
			pc->next = pa;
			pc = pa;
			pa = pa->next;
			pb = pb->next;
		}
		else if (pa->expn <= pb->expn)
		{
			pc->next = pa;//���paָ��Ľڵ������Ԫ��ֵС��pb�ڵ㣬pc��next����pa�ڵ�
			pc = pa;//pcָ��ָ��pa�ڵ�
			pa = pa->next;
		}
		else if(pa->expn>pb->expn)
		{
			pc->next = pb;//���pbָ��Ľڵ������Ԫ��ֵС��pa�ڵ㣬pc��next����pb�ڵ�
			pc = pb;//pcָ��ָ��pb�ڵ�
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;//�����Ŀ˵�����pc->next=pa,����pa���ΪNULL����pc->next=pb��ע����=������==
	//delete listb.GetHead();
	//ȥ��listc�е�0ϵ����
	Node* p = listc.GetHead();
	Node* temp;
	while (p->next)
	{
		if (p->next->coffn == 0)
		{
			temp = p->next;
			p->next = p->next->next;
			delete temp;
			//p = p->next;//ע����������ɾ��һ���ڵ����Բ�������
		}
		else
		{
			p = p->next;
		}
	}
}
