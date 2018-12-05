#pragma once
#include<iostream>
using namespace std;
//树的度是这棵树的最大度数（度为节点下面的子节点个数）
//树的深度为几层
//表示法：父亲孩子表示法、孩子兄弟表示法
/*
父亲孩子表示法  孩子兄弟表示法
|*parent|      |data|*child|*brother|   
| data	|        
|*child |       
*/
template<typename T>
struct TreeNode
{
	TreeNode* parent;//指向父亲节点
	T data;
	TreeNode* child;//指向孩子节点
	TreeNode* brother;//指向兄弟节点
};

template<typename T>
class Tree
{
private:
	TreeNode<T>* pRoot;//根节点
	//通过根节点可以找到所有的节点
	void clear(TreeNode<T>*& root);
	TreeNode<T>* find(TreeNode<T>* root, const T& data);
public:
	Tree() { pRoot = nullptr; };
	~Tree() { clear(); };//因为析构函数的递归不太好写，所以创建一个clear()方法，用递归
	//注意因为析构函数传不了参数，所以需要在public写一个无参的clear，在private写一个含参的clear
	void clear();
	//查找
	bool isFind(const T& data){ return find(pRoot, data) != nullptr; }//这里将root修改为pRoot
	void insert(const T& finddata, const T& insertdata, bool nextdeep = false);
	//在指定位置插入，因为有孩子节点需要在孩子节点的兄弟节点处插入，没有孩子节点需要在当前节点的兄弟节点插入（默认没有孩子节点）
	TreeNode<T>* CreatNode(const T& insertdata);
};
//重载的clear，含参
template<typename T>
inline void Tree<T>::clear(TreeNode<T>*& root)//注意传根节点的引用
{
	if (root)//这里就说明了这个判断的重要性，防止析构两次
	{
		clear(root->brother);//如果还有兄弟，继续遍历到下一个兄弟
		clear(root->child);//如果没有兄弟，则遍历兄弟的孩子
		delete root;//如果兄弟没有孩子，就析构掉这个节点，但这里也只是清空了这个节点申请的空间，
		//因为节点里面有泛型T，而泛型T有可能自己开了内存，如果仅仅释放这个节点的元素而不释放泛型T所申请的内存，很有可能导致
		//内存泄漏，正确的做法是destroy(root) 然后再释放delete root
		root = nullptr;
	}
}
//查找
template<typename T>
inline TreeNode<T>* Tree<T>::find(TreeNode<T>* root, const T & data)
{
	if (root)
	{
		if (root->data == data)//1.根节点匹配
			return root;
		else if (find(root->brother, data))//2.兄弟节点匹配
			return find(root->brother, data);
		else//孩子节点匹配
			return find(root->child, data);
		//整个这一套就是为了判断这一棵根系是否有匹配
	}
	return nullptr;//都不匹配
}
//释放
template<typename T>
inline void Tree<T>::clear()
{
	if (pRoot)
		clear(pRoot);
}
//在指定的某一个节点处插入
template<typename T>
inline void Tree<T>::insert(const T & finddata, const T & insertdata, bool nextdeep)
//finddata为要查找的节点元素，insertdata为要插入的值
{
	//准备一个节点
	TreeNode<T>* newnode = CreatNode(insertdata);
	if (pRoot)//根节点不为空，找位置插入节点
	{
		TreeNode<T>* findNode = find(pRoot, finddata);
		if (findNode)//如果找到了
		{
			if (nextdeep)//如果需要在下一层新开子节点
			{
				findNode->child = newnode;
				newnode->parent = findNode;
			}
			else//在本层添加,作为兄弟节点
			{
				//尾插法，逻辑更自然
				TreeNode<T>* tempNode = findNode;
				while (tempNode->brother)
				{
					tempNode = tempNode->brother;
				}
				tempNode->brother = newnode;
				newnode->parent = findNode->parent;//为兄弟节点建立parent链接，方便找父亲节点
			}
		}
		else//没找到
		{
			//插入规则由你定，这里规定如果没有找到的化插入到子节点的子节点中
			TreeNode<T>* tempNode = pRoot;
			while (tempNode->child)
			{
				tempNode = tempNode->child;//
			}
			tempNode->child = newnode;
			newnode->parent = tempNode;
		}
	}
	else//根节点为空
	{
		pRoot = newnode;
	}
}
//创建一个节点
template<typename T>
inline TreeNode<T>* Tree<T>::CreatNode(const T & insertdata)
{
	TreeNode<T>* newnode = new TreeNode<T>;
	newnode->brother = nullptr;
	newnode->parent = nullptr;
	newnode->child = nullptr;
	newnode->data = insertdata;
	return newnode;
}

