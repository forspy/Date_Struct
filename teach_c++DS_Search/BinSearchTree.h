#pragma once
//二叉搜索树
/*
int arr[] = { 5,1,2,7,6,4,9,3,8,0 };对于这样的数组二叉搜素树是不一定是唯一的
方法为将每个元素从根部比起，遵循左大右小的原则
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
	BSTreeNode* father;//为了删除一个节点以及它的子节点，这里的做法是加入指向父节点的索引，这样当找到目标节点的地址以后，可以通过该节点的父节点再指向子节点这样就得到一个左值(实体)，再clear这个实体
	BSTreeNode(const T& data,BSTreeNode<T>* l=nullptr,BSTreeNode<T>* r=nullptr, BSTreeNode<T>* f = nullptr):data(data),lchild(l),rchild(r),father(f){ }
};

template<typename T>
class BSTree
{
private:
	BSTreeNode<T>* pRoot;
	void clear(BSTreeNode<T>*& node);//这里一定注意要传指针的引用//这里一定注意要传指针的引用,因为调用clear对该指针进行操作,而不是对拷贝进行操作,如果对拷贝进行操作,
	//会导致原来的指针还是指向这个内存(而没有被赋空值,并且指向的这块内存已经被释放了)所以在自动析构的时候会导致二次释放
	void insert(BSTreeNode<T>* root, BSTreeNode<T>* node);//在指定root位置插入节点,注意待插入的节点是局部变量只能传指针，root可以是指针
	//也可以是引用，又因为节点里面没有为成员指针开辟new空间，所以浅拷贝构造就行，注意深拷贝构造的目的是要复制一个一样的空间
	BSTreeNode<T>* Search(BSTreeNode<T>* node, const T& data);//内部的搜索需要递归
	void prePrint(BSTreeNode<T>* node);//先序内部递归遍历
	void midPrint(BSTreeNode<T>* node);//中序内部递归遍历
	void backPrint(BSTreeNode<T>* node);//后序内部递归遍历
	
public:
	BSTree():pRoot(nullptr){ }
	~BSTree() { clear(); }
	void clear();//释放
	void insert(const T& data);//插入一个节点
	
	BSTreeNode<T>* Search(const T& data);//外部搜索方法
	//拓展：删除一个节点（找到这个节点，并调用内部clear方法）//辅助算法：找到目标节点的父节点
	void DelNode(const T& data);
	void prePrint();//先序遍历
	void midPrint();//中序遍历
	void backPrint();//后序遍历
	BSTreeNode<T>* Min();//找到二叉查找树的最小值
	BSTreeNode<T>* Max();//找到二叉查找树的最大值
};

template<typename T>
inline void BSTree<T>::clear(BSTreeNode<T>*& node)
{
	//递归清空，先从子节点删起来
	if (node)
	{
		if (node->lchild)
			clear(node->lchild);
		if (node->rchild)//这里注意不能写else if，因为每个条件都需要判断
			clear(node->rchild);
		delete node;
		node = nullptr;//这里注意一定要将指针指向空
	}
}
//内部搜索方法
template<typename T>
inline BSTreeNode<T>* BSTree<T>::Search(BSTreeNode<T>* node, const T & data)
{
	if (node == nullptr)//如果这个节点为nullptr返回nullptr
		return nullptr;
	if (node->data == data)//如果数据相等，返回这个节点
		return node;
	else if (node->data > data)//如果data小于node->data的值那就去找他的左子树
		Search(node->lchild, data);
	else if (node->data < data)
		Search(node->rchild, data);
	/*else
		return nullptr;*/
	//如果找不到就会继续找左右孩子，直到找到叶子结尾nullptr
}


//递归先序遍历 根 左 右
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
//中序遍历 左根 右
template<typename T>
inline void BSTree<T>::midPrint(BSTreeNode<T>* node)//注意贴的时候递归别贴错了- -！
{
	if (node)
	{
		midPrint(node->lchild);
		cout << node->data << " ";
		midPrint(node->rchild);
	}
}
//后序遍历 左 右 根
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
//辅助算法：找到目标节点的父节点


template<typename T>
inline void BSTree<T>::clear()
{
	clear(pRoot);//调用私有递归版clear
}
//插入节点，为了让根节点pRoot链接到所有的空间
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
	if (root->data > node->data)//如果node->data比root->data小，放在左子节点
	{
		if (root->lchild == nullptr)
		{
			root->lchild = node;
			root->lchild->father = root;
		}
		else
			insert(root->lchild, node);//递归调用，这时候以root->rchild为root节点判断
	}
	else if (root->data <=node->data)//如果node->data比root->data大，放在右子节点,如果相等就作为rchild
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
//这种插入方式的局限是每插入一个值，都要从根节点判断一次，所以后面才会使用索引二叉树进行插入，待解决
//搜索
template<typename T>
inline BSTreeNode<T>* BSTree<T>::Search(const T & data)
{
	BSTreeNode<T>*temp = Search(pRoot, data);
	if (temp)
		cout << "找到了，树中有这个元素" << endl;
	else
		cout << "没有找到" << endl;
	return temp;
}
//删除一个节点(包括他的子节点)
//为了删除一个节点以及它的子节点，这里的做法是加入指向父节点的索引，这样当找到目标节点的地址以后，
//可以通过该节点的父节点再指向子节点这样就得到一个左值(实体)，再clear这个实体
template<typename T>
inline void BSTree<T>::DelNode(const T & data)
{
	//BSTreeNode<T>* temp = Search(data);//注意这里会将temp临时变量指向的内存释放,并且将temp设置为nullptr,
	//并没有把真正的节点地址设置为nullptr,所以应该传入对应节点地址的引用
	//因为 无法从“BSTreeNode<T> *”转换为“BSTreeNode<T> *&”	所以我们改变策略考虑search返回一个引用，然而递归中有nullptr不能当作引用返回
	//所以我们改变策略去求目标节点的父节点，通过目标节点的father索引找到父节点，再通过父节点找到子节点，这样的子节点就是一个实体指针(左值),可以调用clear()操作
	BSTreeNode<T>* findNode = Search(pRoot, data);
	
	if (findNode->father->lchild->data == data)
		clear(findNode->father->lchild);//而且引用对引用,保持类型一致
	else
		clear(findNode->father->rchild);
	//找到这个节点的parent，然后对他的child赋空值


}

template<typename T>
inline void BSTree<T>::prePrint()
{
	cout << __func__ << ":";//输出函数名
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
		//二叉搜索树的最小值一定是最左边的树
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
		//找最右边的树就是最大值
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


