#pragma once
//����������
/*
int arr[] = { 5,1,2,7,6,4,9,3,8,0 };������������������������ǲ�һ����Ψһ��
����Ϊ��ÿ��Ԫ�شӸ���������ѭ�����С��ԭ��
       5
     /   \
    1     7
   /\    / \
  0  2  6   9
      \    /
       4  8
      /
    3
*/
template<typename T>
struct BSTreeNode
{
	T data;
	BSTreeNode* lchild;
	BSTreeNode* rchild;
	BSTreeNode* father;//Ϊ��ɾ��һ���ڵ��Լ������ӽڵ㣬����������Ǽ���ָ�򸸽ڵ���������������ҵ�Ŀ��ڵ�ĵ�ַ�Ժ󣬿���ͨ���ýڵ�ĸ��ڵ���ָ���ӽڵ������͵õ�һ����ֵ(ʵ��)����clear���ʵ��
	BSTreeNode(const T& data,BSTreeNode<T>* l=nullptr,BSTreeNode<T>* r=nullptr, BSTreeNode<T>* f = nullptr):data(data),lchild(l),rchild(r),father(f){ }
};

template<typename T>
class BSTree
{
private:
	BSTreeNode<T>* pRoot;
	void clear(BSTreeNode<T>*& node);//����һ��ע��Ҫ��ָ�������//����һ��ע��Ҫ��ָ�������,��Ϊ����clear�Ը�ָ����в���,�����ǶԿ������в���,����Կ������в���,
	//�ᵼ��ԭ����ָ�뻹��ָ������ڴ�(��û�б�����ֵ,����ָ�������ڴ��Ѿ����ͷ���)�������Զ�������ʱ��ᵼ�¶����ͷ�
	void insert(BSTreeNode<T>* root, BSTreeNode<T>* node);//��ָ��rootλ�ò���ڵ�,ע�������Ľڵ��Ǿֲ�����ֻ�ܴ�ָ�룬root������ָ��
	//Ҳ���������ã�����Ϊ�ڵ�����û��Ϊ��Աָ�뿪��new�ռ䣬����ǳ����������У�ע����������Ŀ����Ҫ����һ��һ���Ŀռ�
	BSTreeNode<T>* Search(BSTreeNode<T>* node, const T& data);//�ڲ���������Ҫ�ݹ�
	void prePrint(BSTreeNode<T>* node);//�����ڲ��ݹ����
	void midPrint(BSTreeNode<T>* node);//�����ڲ��ݹ����
	void backPrint(BSTreeNode<T>* node);//�����ڲ��ݹ����
	
public:
	BSTree():pRoot(nullptr){ }
	~BSTree() { clear(); }
	void clear();//�ͷ�
	void insert(const T& data);//����һ���ڵ�
	
	BSTreeNode<T>* Search(const T& data);//�ⲿ��������
	//��չ��ɾ��һ���ڵ㣨�ҵ�����ڵ㣬�������ڲ�clear������//�����㷨���ҵ�Ŀ��ڵ�ĸ��ڵ�
	void DelNode(const T& data);
	void prePrint();//�������
	void midPrint();//�������
	void backPrint();//�������
	BSTreeNode<T>* Min();//�ҵ��������������Сֵ
	BSTreeNode<T>* Max();//�ҵ���������������ֵ
};

template<typename T>
inline void BSTree<T>::clear(BSTreeNode<T>*& node)
{
	//�ݹ���գ��ȴ��ӽڵ�ɾ����
	if (node)
	{
		if (node->lchild)
			clear(node->lchild);
		if (node->rchild)//����ע�ⲻ��дelse if����Ϊÿ����������Ҫ�ж�
			clear(node->rchild);
		delete node;
		node = nullptr;//����ע��һ��Ҫ��ָ��ָ���
	}
}
//�ڲ���������
template<typename T>
inline BSTreeNode<T>* BSTree<T>::Search(BSTreeNode<T>* node, const T & data)
{
	if (node == nullptr)//�������ڵ�Ϊnullptr����nullptr
		return nullptr;
	if (node->data == data)//���������ȣ���������ڵ�
		return node;
	else if (node->data > data)//���dataС��node->data��ֵ�Ǿ�ȥ������������
		Search(node->lchild, data);
	else if (node->data < data)
		Search(node->rchild, data);
	/*else
		return nullptr;*/
	//����Ҳ����ͻ���������Һ��ӣ�ֱ���ҵ�Ҷ�ӽ�βnullptr
}


//�ݹ�������� �� �� ��
template<typename T>
inline void BSTree<T>::prePrint(BSTreeNode<T>* node)
{
	if (node)
	{
		cout << node->data << " ";
		prePrint(node->lchild);
		prePrint(node->rchild);
	}
}
//������� ��� ��
template<typename T>
inline void BSTree<T>::midPrint(BSTreeNode<T>* node)//ע������ʱ��ݹ��������- -��
{
	if (node)
	{
		midPrint(node->lchild);
		cout << node->data << " ";
		midPrint(node->rchild);
	}
}
//������� �� �� ��
template<typename T>
inline void BSTree<T>::backPrint(BSTreeNode<T>* node)
{
	if (node)
	{
		backPrint(node->lchild);
		backPrint(node->rchild);
		cout << node->data << " ";
	}
}
//�����㷨���ҵ�Ŀ��ڵ�ĸ��ڵ�


template<typename T>
inline void BSTree<T>::clear()
{
	clear(pRoot);//����˽�еݹ��clear
}
//����ڵ㣬Ϊ���ø��ڵ�pRoot���ӵ����еĿռ�
template<typename T>
inline void BSTree<T>::insert(const T & data)
{
	BSTreeNode<T>* newnode = new BSTreeNode<T>(data);
	if (pRoot == nullptr)
	{
		pRoot = newnode;
	}
	else
	{
		insert(pRoot,newnode);
	}
}
template<typename T>
inline void BSTree<T>::insert(BSTreeNode<T>* root, BSTreeNode<T>* node)
{
	if (root->data > node->data)//���node->data��root->dataС���������ӽڵ�
	{
		if (root->lchild == nullptr)
		{
			root->lchild = node;
			root->lchild->father = root;
		}
		else
			insert(root->lchild, node);//�ݹ���ã���ʱ����root->rchildΪroot�ڵ��ж�
	}
	else if (root->data <=node->data)//���node->data��root->data�󣬷������ӽڵ�,�����Ⱦ���Ϊrchild
	{
		if (root->rchild == nullptr)
		{
			root->rchild = node;
			root->rchild->father = root;
		}
		else
			insert(root->rchild, node);
	}
}
//���ֲ��뷽ʽ�ľ�����ÿ����һ��ֵ����Ҫ�Ӹ��ڵ��ж�һ�Σ����Ժ���Ż�ʹ���������������в��룬�����
//����
template<typename T>
inline BSTreeNode<T>* BSTree<T>::Search(const T & data)
{
	BSTreeNode<T>*temp = Search(pRoot, data);
	if (temp)
		cout << "�ҵ��ˣ����������Ԫ��" << endl;
	else
		cout << "û���ҵ�" << endl;
	return temp;
}
//ɾ��һ���ڵ�(���������ӽڵ�)
//Ϊ��ɾ��һ���ڵ��Լ������ӽڵ㣬����������Ǽ���ָ�򸸽ڵ���������������ҵ�Ŀ��ڵ�ĵ�ַ�Ժ�
//����ͨ���ýڵ�ĸ��ڵ���ָ���ӽڵ������͵õ�һ����ֵ(ʵ��)����clear���ʵ��
template<typename T>
inline void BSTree<T>::DelNode(const T & data)
{
	//BSTreeNode<T>* temp = Search(data);//ע������Ὣtemp��ʱ����ָ����ڴ��ͷ�,���ҽ�temp����Ϊnullptr,
	//��û�а������Ľڵ��ַ����Ϊnullptr,����Ӧ�ô����Ӧ�ڵ��ַ������
	//��Ϊ �޷��ӡ�BSTreeNode<T> *��ת��Ϊ��BSTreeNode<T> *&��	�������Ǹı���Կ���search����һ�����ã�Ȼ���ݹ�����nullptr���ܵ������÷���
	//�������Ǹı����ȥ��Ŀ��ڵ�ĸ��ڵ㣬ͨ��Ŀ��ڵ��father�����ҵ����ڵ㣬��ͨ�����ڵ��ҵ��ӽڵ㣬�������ӽڵ����һ��ʵ��ָ��(��ֵ),���Ե���clear()����
	BSTreeNode<T>* findNode = Search(pRoot, data);
	
	if (findNode->father->lchild->data == data)
		clear(findNode->father->lchild);//�������ö�����,��������һ��
	else
		clear(findNode->father->rchild);
	//�ҵ�����ڵ��parent��Ȼ�������child����ֵ


}

template<typename T>
inline void BSTree<T>::prePrint()
{
	cout << __func__ << ":";//���������
	prePrint(pRoot);
	cout << endl;
}

template<typename T>
inline void BSTree<T>::midPrint()
{
	cout << __func__ << ":";
	midPrint(pRoot);
	cout << endl;
}

template<typename T>
inline void BSTree<T>::backPrint()
{
	cout << __func__ << ":";
	backPrint(pRoot);
	cout << endl;
}

template<typename T>
inline BSTreeNode<T>* BSTree<T>::Min()
{
	if (pRoot)
	{
		//��������������Сֵһ��������ߵ���
		BSTreeNode<T>* temp = pRoot;
		while (temp->lchild)
		{
			temp = temp->lchild;
		}
		return temp;
	}
	else
	{
		return nullptr;
	}
}

template<typename T>
inline BSTreeNode<T>* BSTree<T>::Max()
{
	if (pRoot)
	{
		//�����ұߵ����������ֵ
		BSTreeNode<T>* temp = pRoot;
		while (temp->rchild)
		{
			temp = temp->rchild;
		}
		return temp;
	}
	else
	{
		return nullptr;
	}
}


