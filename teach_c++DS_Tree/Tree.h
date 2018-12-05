#pragma once
#include<iostream>
using namespace std;
//���Ķ��������������������Ϊ�ڵ�������ӽڵ������
//�������Ϊ����
//��ʾ�������׺��ӱ�ʾ���������ֵܱ�ʾ��
/*
���׺��ӱ�ʾ��  �����ֵܱ�ʾ��
|*parent|      |data|*child|*brother|   
| data	|        
|*child |       
*/
template<typename T>
struct TreeNode
{
	TreeNode* parent;//ָ���׽ڵ�
	T data;
	TreeNode* child;//ָ���ӽڵ�
	TreeNode* brother;//ָ���ֵܽڵ�
};

template<typename T>
class Tree
{
private:
	TreeNode<T>* pRoot;//���ڵ�
	//ͨ�����ڵ�����ҵ����еĽڵ�
	void clear(TreeNode<T>*& root);
	TreeNode<T>* find(TreeNode<T>* root, const T& data);
public:
	Tree() { pRoot = nullptr; };
	~Tree() { clear(); };//��Ϊ���������ĵݹ鲻̫��д�����Դ���һ��clear()�������õݹ�
	//ע����Ϊ�������������˲�����������Ҫ��publicдһ���޲ε�clear����privateдһ�����ε�clear
	void clear();
	//����
	bool isFind(const T& data){ return find(pRoot, data) != nullptr; }//���ｫroot�޸�ΪpRoot
	void insert(const T& finddata, const T& insertdata, bool nextdeep = false);
	//��ָ��λ�ò��룬��Ϊ�к��ӽڵ���Ҫ�ں��ӽڵ���ֵܽڵ㴦���룬û�к��ӽڵ���Ҫ�ڵ�ǰ�ڵ���ֵܽڵ���루Ĭ��û�к��ӽڵ㣩
	TreeNode<T>* CreatNode(const T& insertdata);
};
//���ص�clear������
template<typename T>
inline void Tree<T>::clear(TreeNode<T>*& root)//ע�⴫���ڵ������
{
	if (root)//�����˵��������жϵ���Ҫ�ԣ���ֹ��������
	{
		clear(root->brother);//��������ֵܣ�������������һ���ֵ�
		clear(root->child);//���û���ֵܣ�������ֵܵĺ���
		delete root;//����ֵ�û�к��ӣ�������������ڵ㣬������Ҳֻ�����������ڵ�����Ŀռ䣬
		//��Ϊ�ڵ������з���T��������T�п����Լ������ڴ棬��������ͷ�����ڵ��Ԫ�ض����ͷŷ���T��������ڴ棬���п��ܵ���
		//�ڴ�й©����ȷ��������destroy(root) Ȼ�����ͷ�delete root
		root = nullptr;
	}
}
//����
template<typename T>
inline TreeNode<T>* Tree<T>::find(TreeNode<T>* root, const T & data)
{
	if (root)
	{
		if (root->data == data)//1.���ڵ�ƥ��
			return root;
		else if (find(root->brother, data))//2.�ֵܽڵ�ƥ��
			return find(root->brother, data);
		else//���ӽڵ�ƥ��
			return find(root->child, data);
		//������һ�׾���Ϊ���ж���һ�ø�ϵ�Ƿ���ƥ��
	}
	return nullptr;//����ƥ��
}
//�ͷ�
template<typename T>
inline void Tree<T>::clear()
{
	if (pRoot)
		clear(pRoot);
}
//��ָ����ĳһ���ڵ㴦����
template<typename T>
inline void Tree<T>::insert(const T & finddata, const T & insertdata, bool nextdeep)
//finddataΪҪ���ҵĽڵ�Ԫ�أ�insertdataΪҪ�����ֵ
{
	//׼��һ���ڵ�
	TreeNode<T>* newnode = CreatNode(insertdata);
	if (pRoot)//���ڵ㲻Ϊ�գ���λ�ò���ڵ�
	{
		TreeNode<T>* findNode = find(pRoot, finddata);
		if (findNode)//����ҵ���
		{
			if (nextdeep)//�����Ҫ����һ���¿��ӽڵ�
			{
				findNode->child = newnode;
				newnode->parent = findNode;
			}
			else//�ڱ������,��Ϊ�ֵܽڵ�
			{
				//β�巨���߼�����Ȼ
				TreeNode<T>* tempNode = findNode;
				while (tempNode->brother)
				{
					tempNode = tempNode->brother;
				}
				tempNode->brother = newnode;
				newnode->parent = findNode->parent;//Ϊ�ֵܽڵ㽨��parent���ӣ������Ҹ��׽ڵ�
			}
		}
		else//û�ҵ�
		{
			//����������㶨������涨���û���ҵ��Ļ����뵽�ӽڵ���ӽڵ���
			TreeNode<T>* tempNode = pRoot;
			while (tempNode->child)
			{
				tempNode = tempNode->child;//
			}
			tempNode->child = newnode;
			newnode->parent = tempNode;
		}
	}
	else//���ڵ�Ϊ��
	{
		pRoot = newnode;
	}
}
//����һ���ڵ�
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

