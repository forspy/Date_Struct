//完全二叉树的链式存储结构
#include<iostream>
#include<queue>
using namespace std;
template<typename T>
struct TreeNode
{
	T data;//数据域
	TreeNode* lchild;//左子节点
	TreeNode* rchild;//右子节点
	TreeNode():lchild(nullptr),rchild(nullptr){ }
};

template<typename T>
class BinaryTree
{
private:
	TreeNode<T>* pRoot;
	void clear(TreeNode<T>*& root);
	void preprint(TreeNode<T>* root);//先序遍历
	void midprint(TreeNode<T>* root);//中序遍历
	void backprint(TreeNode<T>* root);//后序遍历
public:
	//因为需要用到递归init所以这里不使用构造函数，而是新建一个成员函数,然后构造函数调用init
	BinaryTree(T arr[], int len, int start = 0) { pRoot=Init(arr, len, start); };
	TreeNode<T>* Init(T arr[], int len, int start = 0);
	~BinaryTree() { clear(pRoot); };//直接调用clear()
	//void clear();
	//遍历方式
	void preprint();//先序遍历
	void midprint();//中序遍历
	void backprint();//后序遍历
	void levelprint();//层级遍历
	/*
	判断一棵树是否是完全二叉树 :一层满了，下一层优先满左子树
	思路:层次遍历二叉树，找到第一个非满结点（这个节点只有两种情况，孩子为空或者只有左没有右），如果之后的节点还有非满结点，则不是。 
	将所有的结点全部压入队列中，每次判断队列的头如果队列头为空了则跳出循环，如果此后队列中还有元素则不是完全二叉树。
};
	*/ 

template<typename T>
inline void BinaryTree<T>::clear(TreeNode<T>*& root)//注意这里要传节点指针的引用
{
	if (root)
	{
		clear(root->lchild);//从下往上释放节点
		clear(root->rchild);
		delete root;
		root = nullptr;//注意节点指针必须重置为空，每次释放都要把指针置空，养成好习惯
	}
}

template<typename T>
inline void BinaryTree<T>::preprint(TreeNode<T>* root)
{
	if (root)
	{
		cout << root->data << " ";
		preprint(root->lchild);
		preprint(root->rchild);
	}
}
//中序遍历
template<typename T>
inline void BinaryTree<T>::midprint(TreeNode<T>* root)
{
	if (root)
	{
		midprint(root->lchild);
		cout << root->data << " ";
		midprint(root->rchild);
	}
}
//后续遍历
template<typename T>
inline void BinaryTree<T>::backprint(TreeNode<T>* root)
{
	if (root)
	{
		backprint(root->lchild);
		backprint(root->rchild);
		cout << root->data << " ";
	}
}
//借助队列 通过弹出队列头和压入左右子节点反复操作，直到全部输出(非递归输出)
template<typename T>
inline void BinaryTree<T>::levelprint()
{
	queue<TreeNode<T>*> que;//创建一个队列对象
	TreeNode<T>* temp;
	que.push(pRoot);
	while (!que.empty())
	{
		temp = que.front();
		que.pop();//弹出头
		cout << temp->data << " ";
		if (temp->lchild)
			que.push(temp->lchild);
		if (temp->rchild)
			que.push(temp->rchild);
	}
}

//通过数组构造一个完全二叉树,二叉树的下标按照层次编号
template<typename T>
inline TreeNode<T>* BinaryTree<T>::Init(T arr[], int len, int start)//start表示从数组的第几个位置开始构造
{
	if (start >= len)
		return nullptr;
	//前序构造 根 左 右
	//创建根节点---
	TreeNode<T>* newnode = new TreeNode<T>;
	newnode->data = arr[start];
	//--
	newnode->lchild = Init(arr, len, start * 2 + 1);//创建左子节点
	newnode->rchild = Init(arr, len, start * 2 + 2);//创建右子节点
	return newnode;//返回nennode更科学
	//对于一般的树第i层最左边数组下标不是2^(i-1)次了，但是可以自己写好一个伴随数组下标比如0 11 222 333
}
//递归清空，需要传入参数
//template<typename T>
//void BinaryTree<T>::clear()//因为clear是给外部调用的，没有参数，所以要写一个内部的clear
//{
//	clear(pRoot);
//}
//前序遍历
template<typename T>
inline void BinaryTree<T>::preprint()
{
	preprint(pRoot);
}

template<typename T>
inline void BinaryTree<T>::midprint()
{
	midprint(pRoot);
}

template<typename T>
inline void BinaryTree<T>::backprint()
{
	backprint(pRoot);
}
