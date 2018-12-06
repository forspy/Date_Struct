#include"binary tree linked.h"

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int nSize = sizeof(arr) / sizeof(arr[0]);
	BinaryTree<int> tree(arr, nSize);//存入是按照顺序结构存入的
	cout << "先序遍历" << endl;
	tree.preprint();
	cout << endl;
	cout << "中序遍历" << endl;
	tree.midprint();
	cout << endl;
	cout << "后序遍历" << endl;
	tree.backprint();
	cout << endl;
	cout << "层级遍历（非递归遍历）" << endl;
	tree.levelprint();
	cout << endl;
}
