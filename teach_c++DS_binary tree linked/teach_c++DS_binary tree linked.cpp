#include"binary tree linked.h"

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int nSize = sizeof(arr) / sizeof(arr[0]);
	BinaryTree<int> tree(arr, nSize);//�����ǰ���˳��ṹ�����
	cout << "�������" << endl;
	tree.preprint();
	cout << endl;
	cout << "�������" << endl;
	tree.midprint();
	cout << endl;
	cout << "�������" << endl;
	tree.backprint();
	cout << endl;
	cout << "�㼶�������ǵݹ������" << endl;
	tree.levelprint();
	cout << endl;
}
