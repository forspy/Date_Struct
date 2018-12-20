//霍夫曼树编码技术
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
	unsigned char charname;  //要这样才行
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
		Type temp = 0;  //可能有变
		key = ht1.key + ht2.key;
		root = new BinTreeNode<Type>(0, Copy(ht1.root), Copy(ht2.root));
	}
	void Build(int *fr, Type *value, int n, HuffmanTree<Type> &newtree);
	void Path(BinTreeNode<Type> *start, Code *first, Code *last, CharNameNode *Node, int &i); //一个数组

};

template <class Type>
void HuffmanTree<Type>::Build(int *fr, Type *value, int n, HuffmanTree<Type> &newtree)
{                                    //fr 为　value(值)　对应的权
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
	hp = MinHeap< HuffmanTree<Type> >(Node, n);//node调用key属性，为int类型，将输入“文本”初始化成为一个最小堆
	for (i = 0; i<n - 1; i++)
	{
		hp.RemoveMin(first);
		hp.RemoveMin(second);
		HuffmanTree<Type>* temp = new HuffmanTree<Type>(first, second);//temp为一棵霍夫曼树
		hp.Insert(*temp);
	}
	hp.RemoveMin(newtree);
}

template<class Type>
void HuffmanTree<Type>::Path(BinTreeNode<Type> *start, Code *first, Code *last, CharNameNode *Node, int &i) //一个数组
{

	if (start == NULL)
		return;
	//   if(start->GetData()!=0) //是叶结点  严重错误，可能叶结点也是0！！
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

	Code *temp = new Code;  //进入左子树
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

