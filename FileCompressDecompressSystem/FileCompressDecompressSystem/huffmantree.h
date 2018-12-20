//�����������뼼��
#ifndef HUFFMANTREE
#define HUFFMANTREE

#define Defaultsize 300

#include <iostream>
#include "bintree.h"
#include "heap.h"

using namespace std;


class Code
{
public:
	int code;
	Code *link;
	Code(int c = 0, Code *l = NULL) :code(c), link(l){};
};

class CharNameNode
{
public:
	unsigned char charname;  //Ҫ��������
	Code *link;
	CharNameNode(unsigned char c = 0, Code *l = NULL) :charname(c), link(l){};
};

template <class Type>
class HuffmanTree :public BinaryTree<Type>
{
public:
	int key;
	HuffmanTree(){};
	HuffmanTree(HuffmanTree<Type> &ht1, HuffmanTree<Type> &ht2)
	{
		Type temp = 0;  //�����б�
		key = ht1.key + ht2.key;
		root = new BinTreeNode<Type>(0, Copy(ht1.root), Copy(ht2.root));
	}
	void Build(int *fr, Type *value, int n, HuffmanTree<Type> &newtree);
	void Path(BinTreeNode<Type> *start, Code *first, Code *last, CharNameNode *Node, int &i); //һ������

};

template <class Type>
void HuffmanTree<Type>::Build(int *fr, Type *value, int n, HuffmanTree<Type> &newtree)
{                                    //fr Ϊ��value(ֵ)����Ӧ��Ȩ
	int i;
	HuffmanTree<Type> first, second;
	HuffmanTree<Type> Node[Defaultsize];
	MinHeap< HuffmanTree<Type> > hp;
	assert(n >= 0 && n <= Defaultsize);
	for (i = 0; i<n; i++)
	{
		Node[i].root = new BinTreeNode<Type>(value[i], NULL, NULL);
		Node[i].key = fr[i];
	}
	hp = MinHeap< HuffmanTree<Type> >(Node, n);//node����key���ԣ�Ϊint���ͣ������롰�ı�����ʼ����Ϊһ����С��
	for (i = 0; i<n - 1; i++)
	{
		hp.RemoveMin(first);
		hp.RemoveMin(second);
		HuffmanTree<Type>* temp = new HuffmanTree<Type>(first, second);//tempΪһ�û�������
		hp.Insert(*temp);
	}
	hp.RemoveMin(newtree);
}

template<class Type>
void HuffmanTree<Type>::Path(BinTreeNode<Type> *start, Code *first, Code *last, CharNameNode *Node, int &i) //һ������
{

	if (start == NULL)
		return;
	//   if(start->GetData()!=0) //��Ҷ���  ���ش��󣬿���Ҷ���Ҳ��0����
	if (start->GetLeft() == NULL&&start->GetRight() == NULL)
	{
		Node[i].charname = start->GetData();
		Node[i].link = NULL;
		if (first == NULL)
			return;
		Node[i].link = new Code(first->code);
		Code *p = first->link, *q = Node[i].link;
		while (p != NULL)
		{
			q->link = new Code(p->code);
			q = q->link;
			p = p->link;
		}
		q->link = NULL;
		i++;
		return;
	}

	Code *temp = new Code;  //����������
	assert(temp);
	if (first == NULL)
		first = last = temp;
	else
	{
		last->link = temp;
		last = last->link;
	}
	Path(start->GetLeft(), first, last, Node, i);
	last->code = 1;
	Path(start->GetRight(), first, last, Node, i);
	temp = first;
	if (first == last)
	{
		delete last;
		first = last = NULL;
		return;
	}
	while (temp->link != last)
		temp = temp->link;

	temp->link = NULL;
	delete last;
	last = temp;

}

#endif

