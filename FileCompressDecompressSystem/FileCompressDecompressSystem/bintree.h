//��ָ��ʵ�ֵĶ�����
//Type ���ͱ���������<<��>>��������

#ifndef BINTREE
#define BINTREE

#include <assert.h>
#include <iostream>
using namespace std;

int Max(int a, int b)
{
	return a>b ? a : b;
}

template <class Type>
class BinaryTree;

template <class Type>
class BinTreeNode
{
	friend class BinaryTree<Type>;
public:
	BinTreeNode() :leftchild(NULL), rightchild(NULL){};
	BinTreeNode(Type item, BinTreeNode<Type> *left = NULL, BinTreeNode<Type> *right = NULL)
		:data(item), leftchild(left), rightchild(right){};
	Type GetData()const { return data; }
	BinTreeNode<Type> *GetLeft()const { return leftchild; }
	BinTreeNode<Type> *GetRight()const { return rightchild; }
	void SetData(const Type &item){ data = item; }
	void SetLeft(BinTreeNode <Type> *L){ leftchild = L; }
	void SetRight(BinTreeNode <Type> *R){ rightchild = R; }
private:
	BinTreeNode<Type> *leftchild, *rightchild;
	Type data;
};

template <class Type>
class BinaryTree
{
public:
	BinaryTree() :root(NULL){};
	BinaryTree(const BinaryTree<Type> &bt){ root = Copy(bt.root); }
	BinaryTree(const Type &temp, const BinaryTree<Type> &bt1, const BinaryTree<Type> &bt2);
	BinaryTree(Type value) :RefValue(value), root(NULL){};
	void operator =(const BinaryTree<Type> &bt);
	virtual ~BinaryTree(){ Destroy(root); }
	void Destroy(){ Destroy(root); root = NULL; }

	virtual int IsEmpty(){ return root == NULL ? 1 : 0; }
	virtual BinTreeNode <Type> *Parent(BinTreeNode <Type> *current)
	{
		return root == NULL || root == current ? NULL : Parent(root, current);
	}
	virtual BinTreeNode <Type> *LeftChild(BinTreeNode <Type> *current)
	{
		return root != NULL ? current->leftchild : NULL;
	}
	virtual BinTreeNode <Type> *RightChild(BinTreeNode <Type> *current)
	{
		return root != NULL ? current->rightchild : NULL;
	}
	virtual int Insert(const Type &item);
	virtual int Find(const Type &item)const;
	BinTreeNode <Type> *GetRoot()const{ return root; }
	friend int Equal(BinTreeNode<Type> *a, BinTreeNode<Type> *b);
	friend int operator ==(const BinaryTree<Type> &bt1, const BinaryTree<Type> &bt2);
	friend istream& operator >>(istream &in, BinaryTree<Type> &Tree);
	friend ostream& operator <<(ostream &out, BinaryTree<Type> &Tree);

	void InOrder();                   //����
	void PreOrder();
	void PostOrder();
	//******************************************          //һЩӦ��
	int Size(){ return Size(root); }   //ͳ�ƽ����
	int Depth(){ return Depth(root); } //�����������
	int Leaves(){ return Leaves(root); }
	int Degrees1(){ return Degrees1(root); }
	int Degrees2(){ return Degrees2(root); }
protected:
	BinTreeNode <Type> *root;
	Type RefValue;
	BinTreeNode<Type> *Parent(BinTreeNode<Type> *start, BinTreeNode<Type> *current);
	int Insert(BinTreeNode<Type> *current, const Type &item);
	int Find(BinTreeNode<Type> *current, const Type &item)const;
	BinTreeNode<Type>* Copy(BinTreeNode<Type> *originode);
	void Destroy(BinTreeNode<Type> *current);

	//******************************************
	void InOrder(BinTreeNode<Type> *current);
	void PreOrder(BinTreeNode<Type> *current);
	void PostOrder(BinTreeNode<Type> *current);
	//******************************************          //һЩӦ��
	int Size(const BinTreeNode<Type> *t)const;
	int Depth(const BinTreeNode<Type> *t)const;
	int Leaves(const BinTreeNode<Type> *t)const;
	int Degrees1(const BinTreeNode<Type> *t)const;
	int Degrees2(const BinTreeNode<Type> *t)const;
};

template <class Type>
BinTreeNode<Type>*  BinaryTree<Type>::Copy(BinTreeNode<Type> *orignode)
{
	if (orignode == NULL)
		return NULL;
	BinTreeNode<Type> *temp = new BinTreeNode<Type>;
	temp->data = orignode->data;
	temp->leftchild = Copy(orignode->leftchild);
	temp->rightchild = Copy(orignode->rightchild);
	return temp;
}

template <class Type>
BinaryTree<Type>::BinaryTree(const Type &temp, const BinaryTree<Type> &bt1, const BinaryTree<Type> &bt2)
{
	root = new BinTreeNode<Type>(temp, Copy(bt1.root), Copy(bt2.root));
}

template <class Type>
void BinaryTree<Type>::operator =(const BinaryTree<Type> &bt1)
{
	Destroy();
	//    Destroy(root);root=NULL;  //ΪʲôҪ����������
	root = Copy(bt1.root);
}

template<class Type>
void BinaryTree<Type>::Destroy(BinTreeNode<Type> *current)
{
	if (current != NULL)
	{
		Destroy(current->leftchild);
		Destroy(current->rightchild);
		delete current;
	}
}

template<class Type>
BinTreeNode <Type>* BinaryTree<Type>::Parent(BinTreeNode<Type> *start, BinTreeNode<Type> *current)
{
	if (start == NULL) return NULL;
	if (start->leftchild == current || start->rightchild == current)
		return start;
	BinTreeNode <Type> *p = NULL;
	if ((p = Parent(start->leftchild, current)) != NULL)   //��start������������
		return p;
	else
		return Parent(start->rightchild, current);
}

template<class Type>
int BinaryTree<Type>::Insert(BinTreeNode<Type> *current, const Type &item)
{
	if (current == NULL)
		return 0;
	BinTreeNode<Type> *p = new BinTreeNode<Type>(item, NULL, NULL);
	if (current->leftchild == NULL)
		current->leftchild = p;
	else if (current->rightchild == NULL)
		current->rightchild = p;
	else
		Insert(current->leftchild, item);   //��������ǹ�������״�ģ�����һ�ð�
	return 1;
}

template<class Type>
int BinaryTree<Type>::Insert(const Type &item)
{
	if (root == NULL)
	{
		root = new BinTreeNode<Type>(item, NULL, NULL);
		return 1;
	}
	return Insert(root, item);
}

template<class Type>
int BinaryTree<Type>::Find(BinTreeNode<Type> *current, const Type &item)const
{
	if (current == NULL)
		return 0;
	if (current->data == item)
		return 1;
	int k;
	if ((k = Find(current->leftchild, item)) != 0)
		return 1;
	else
		return Find(current->rightchild, item);
}

template<class Type>
int BinaryTree<Type>::Find(const Type &item)const
{
	return Find(root, item);
}

template<class Type>
int Equal(BinTreeNode<Type> *a, BinTreeNode<Type> *b)
{
	if (a == NULL&&b == NULL)
		return 1;
	if (a != NULL&&b != NULL&&a->GetData() == b->GetData()
		&& Equal(a->GetLeft(), b->GetLeft()) && Equal(a->GetRight(), b->GetRight()))
		return 1;
	return 0;
}

template<class Type>
int operator ==(const BinaryTree<Type> &bt1, const BinaryTree<Type> &bt2)
{
	return Equal(bt1.root, bt2.root);
}

template<class Type>
istream& operator>>(istream &in, BinaryTree<Type> &Tree)
{
	Type item;
	cout << "���������:\n";
	cout << "��������(��" << Tree.RefValue << "����): ";
	in >> item;
	while (item != Tree.RefValue)
	{
		Tree.Insert(item);
		cout << "��������(��" << Tree.RefValue << "����): ";
		in >> item;
	}
	return in;
}

template<class Type>
ostream& operator<<(ostream &out, BinaryTree<Type> &Tree)
{
	out << "��������ǰ�����.\n";
	Tree.PreOrder();
	out << endl;
	return out;
}

//*****************************************************************************

template <class Type>
void BinaryTree <Type>::InOrder()
{
	InOrder(root);
}

template <class Type> void BinaryTree<Type>::InOrder(BinTreeNode<Type> *current)
{
	if (current != NULL)
	{
		InOrder(current->leftchild);
		cout << current->data << ' ';
		InOrder(current->rightchild);
	}
}

template <class Type>
void BinaryTree <Type>::PreOrder()
{
	PreOrder(root);
}

template <class Type>
void BinaryTree<Type>::PreOrder(BinTreeNode<Type> *current)
{
	if (current != NULL)
	{
		cout << current->data << ' ';
		PreOrder(current->leftchild);
		PreOrder(current->rightchild);
	}
}

template <class Type>
void  BinaryTree<Type>::PostOrder()
{
	PostOrder(root);
}

template <class Type>
void BinaryTree<Type>::PostOrder(BinTreeNode<Type> *current)
{
	if (current != NULL)
	{
		PostOrder(current->leftchild);
		PostOrder(current->rightchild);
		cout << current->data << ' ';
	}
}

//***************************************************����//һЩӦ��
template <class Type>
int BinaryTree<Type>::Size(const BinTreeNode<Type> *t)const
{
	if (t == NULL)
		return 0;
	else
		return 1 + Size(t->leftchild) + Size(t->rightchild);
}

template <class Type>
int BinaryTree<Type>::Depth(const BinTreeNode<Type> *t)const
{
	if (t == NULL)
		return -1;
	else
		return 1 + Max(Depth(t->leftchild), Depth(t->rightchild));
}

template <class Type>
int BinaryTree<Type>::Leaves(const BinTreeNode<Type> *t)const
{
	if (t == NULL)
		return 0;
	if (t->leftchild == NULL&&t->rightchild == NULL)  //t��Ҷ�ӽ��
		return 1;
	return Leaves(t->leftchild) + Leaves(t->rightchild);
}

template <class Type>
int BinaryTree<Type>::Degrees1(const BinTreeNode<Type> *t)const
{
	if (t == NULL)
		return 0;
	if ((t->leftchild == NULL&&t->rightchild != NULL)
		|| (t->leftchild != NULL&&t->rightchild == NULL))  //t�Ķ�Ϊ1��
		return 1 + Degrees1(t->leftchild) + Degrees1(t->rightchild);
	return Degrees1(t->leftchild) + Degrees1(t->rightchild);
}

template <class Type>
int BinaryTree<Type>::Degrees2(const BinTreeNode<Type> *t)const
{
	if (t == NULL)
		return 0;
	if (t->leftchild != NULL&&t->rightchild != NULL) //t �Ķ�Ϊ2
		return 1 + Degrees2(t->leftchild) + Degrees2(t->rightchild);
	return Degrees2(t->leftchild) + Degrees2(t->rightchild);
}

#endif
