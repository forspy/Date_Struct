//��ȫ����������ʽ�洢�ṹ
#include<iostream>
#include<queue>
using namespace std;
template<typename T>
struct TreeNode
{
	T data;//������
	TreeNode* lchild;//���ӽڵ�
	TreeNode* rchild;//���ӽڵ�
	TreeNode():lchild(nullptr),rchild(nullptr){ }
};

template<typename T>
class BinaryTree
{
private:
	TreeNode<T>* pRoot;
	void clear(TreeNode<T>*& root);
	void preprint(TreeNode<T>* root);//�������
	void midprint(TreeNode<T>* root);//�������
	void backprint(TreeNode<T>* root);//�������
public:
	//��Ϊ��Ҫ�õ��ݹ�init�������ﲻʹ�ù��캯���������½�һ����Ա����,Ȼ���캯������init
	BinaryTree(T arr[], int len, int start = 0) { Init(arr, len, start); };
	TreeNode<T>* Init(T arr[], int len, int start = 0);
	~BinaryTree() { clear(pRoot); };//ֱ�ӵ���clear()
	//void clear();
	//������ʽ
	void preprint();//�������
	void midprint();//�������
	void backprint();//�������
	void levelprint();//�㼶����
};

template<typename T>
inline void BinaryTree<T>::clear(TreeNode<T>*& root)//ע������Ҫ���ڵ�ָ�������
{
	if (root)
	{
		clear(root->lchild);//���������ͷŽڵ�
		clear(root->rchild);
		delete root;
		root = nullptr;//ע��ڵ�ָ���������Ϊ�գ�ÿ���ͷŶ�Ҫ��ָ���ÿգ����ɺ�ϰ��
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
//�������
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
//��������
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
//�������� ͨ����������ͷ��ѹ�������ӽڵ㷴��������ֱ��ȫ�����(�ǵݹ����)
template<typename T>
inline void BinaryTree<T>::levelprint()
{
	queue<TreeNode<T>*> que;//����һ�����ж���
	TreeNode<T>* temp;
	que.push(pRoot);
	while (!que.empty())
	{
		temp = que.front();
		que.pop();//����ͷ
		cout << temp->data << " ";
		if (temp->lchild)
			que.push(temp->lchild);
		if (temp->rchild)
			que.push(temp->rchild);
	}
}

//ͨ�����鹹��һ����ȫ������,���������±갴�ղ�α��
template<typename T>
inline TreeNode<T>* BinaryTree<T>::Init(T arr[], int len, int start)//start��ʾ������ĵڼ���λ�ÿ�ʼ����
{
	if (start >= len)
		return nullptr;
	//ǰ���� �� �� ��
	//�������ڵ�---
	TreeNode<T>* newnode = new TreeNode<T>;
	newnode->data = arr[start];
	//--
	newnode->lchild = Init(arr, len, start * 2 + 1);//�������ӽڵ�
	newnode->rchild = Init(arr, len, start * 2 + 2);//�������ӽڵ�
	pRoot = newnode;
	return pRoot;
}
//�ݹ���գ���Ҫ�������
//template<typename T>
//void BinaryTree<T>::clear()//��Ϊclear�Ǹ��ⲿ���õģ�û�в���������Ҫдһ���ڲ���clear
//{
//	clear(pRoot);
//}
//ǰ�����
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
