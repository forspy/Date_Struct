//二叉树的度为2
/*
二叉树：叶子个数为n0，度为2的节点个数n2，n0=n2+1

完全二叉树：前面都是满二叉树最后一层的左子树存在


满二叉树：最后一层2^(n-1),总共2^k-1,一共n个节点，深度h=log2(n+1)
编号为i的二叉树的父亲节点为i/2，左子节点2i，右子节点2i+1（根节点编号为1，以满二叉树编号，普通二叉树空的地方补编号）
完全二叉树的编号：
       2^k
2^(k+1)  2^(k+1)+1
*/
/*
     A
   /   \
  B     C
 / \    /
D   E  F
*/
/*
遍历方式：
层次遍历：一层层遍历（从左往右）
先序遍历：根 左 右 A BDE CF
中序遍历：左 根 右 DBE A FC
后序遍历：左 右 根 DEB FC A
*/
//二叉树的顺序存储和链式存储
/*
顺序存储：
        A(1)
     /       \
   B(2)      C(3)
  / \        / \
D(4)NULL(5)NULL(6)E(5)
一般二叉树：[A,B,C,D,NULL,NULL,E],转换成完全二叉树，没有的叶子节点补空（虚节点），让其称为完全二叉树
*/
#include<iostream>
#include<vector>
using namespace std;
template<typename T>
class TreeArr
{
private:
	vector<T> vecBuff;//数组，编号从0开始
public:
	TreeArr();
	~TreeArr();//析构
	void clear();//主动析构
	void Init(T arr[], int len);
	bool find(const T& findVal);
	void appendNode(const T& data);
	//遍历方式
	void prePrint(int index = 0);//前序遍历，index表示编号（顺序存储特有），不一定从根开始遍历
	void midPrint(int index = 0);//中序遍历
	void backPrint(int index = 0);//后序遍历
};
//构造
template<typename T>
TreeArr<T>::TreeArr()
{
	vecBuff.clear();
}

template<typename T>
TreeArr<T>::~TreeArr()
{
	clear();
}

template<typename T>
void TreeArr<T>::clear()
{
	vecBuff.clear();
}

template<typename T>
void TreeArr<T>::Init(T arr[], int len)
{
	vecBuff.clear();
	//数组复制到vecbuff里面
	vecBuff.insert(vecBuff.end(), arr, arr + len);//vector范围插入
	/*
	vector _Where在第一元素插入的矢量的位置，_First要复制的元素范围中的第一个元素的位置，_Last要复制的元素范围之外的第一个元素的位置
	*/
}

template<typename T>
bool TreeArr<T>::find(const T & findVal)
{
	auto iter = vecBuff.find(vecBuff.begin(), vecBuff.end(), findVal);
	if (iter == vecBuff.end();)
		return false;
	else
	{
		return true;
	}
}

template<typename T>
void TreeArr<T>::appendNode(const T & data)
{
	vecBuff.push_back(data);
}
//先序遍历
template<typename T>
void TreeArr<T>::prePrint(int index)//index表示编号
{
	if (index < vecBuff.size() && index >= 0)
	{
		cout << vecBuff[index] << " ";//根节点
		prePrint(2 * index + 1);
		prePrint(2 * index + 2);
	}
	
}

template<typename T>
void TreeArr<T>::midPrint(int index)
{
	if (index < vecBuff.size() && index >= 0)
	{
		midPrint(2 * index + 1);
		cout << vecBuff[index] << " ";//根节点
		
		midPrint(2 * index + 2);
	}
	
}

template<typename T>
void TreeArr<T>::backPrint(int index)
{
	if (index < vecBuff.size() && index >= 0)
	{
		
		backPrint(2 * index + 1);
		backPrint(2 * index + 2);
		cout << vecBuff[index] << " ";//根节点
	}
	
}

int  main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int nSize = sizeof(arr) / sizeof(arr[0]);
	TreeArr<int> tree;
	tree.Init(arr, nSize);
	//bool b = tree.find(9);
	tree.prePrint();
	cout << endl;
	tree.midPrint();
	cout << endl;
	tree.backPrint();
	cout << endl;
}