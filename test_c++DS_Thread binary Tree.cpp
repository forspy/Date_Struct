//树是一种组织数据的方式
//比如：文件夹->子文件夹->文件
//比如：二叉树
//   根节点T_node
//    /  \
//   /    \
//子节点A  子节点B
//通用树形结构设计（链表法）
/* __________
|        |
|  宿主  |
|        |
|________|
| 树节点 |
|________|
*/
//每一颗子树又是一个节点 根节点没有前驱，叶子节点没有后继
//二叉树，节点的度小于等于2
//应用：利用树进行数据压缩111 110 11 10
//利用二叉树求表达式的值（a+b*（c-d）-e/f）
//路由器中的路由表会得到一个树，进而得到路由节点的最短路径
//哈夫曼树，编码技术
//平面机器人运动可以利用一个四叉树，分别对应四个空间，空间运动对应八叉树
//STL用到红黑树；分布式用到B树或者B+树
//资源管理器：文件夹展开
//节点的度：该结点拥有的子树的数目，度为0称为叶子节点，度为非0的节点称为分支节点
//树的度：书中节点度的最大值
//深度：最大层次
//森林：不相交的树的集合
//二叉树：节点有左右子树
//满二叉树：左右都有
//完全二叉树：先满足左节点的为完全二叉树
//二叉树性质：
//二叉树第i层的节点个数：一颗非空二叉树的第i层最多有2^(i-1)个节点，i>=1
//具有n个节点的完全二叉树的深度为h=(log2n)+1;

//完全二叉树的顺序存储结构
/*
       A(1)
	  /   \
	B(2)  C(3)
	/ \    /
  D(4)E(5)F(6)
完全二叉树和数组的顺序对应：[A,B,C,D,E,F]，所以可以把一个数组转化成完全二叉树
       A(1)
    /       \
   B(2)      C(3)
  / \        / \
D(4)NULL(5)NULL(6)E(5)
一般二叉树：[A,B,C,D,NULL,NULL,E],转换成完全二叉树，没有的叶子节点补空（虚节点），让其称为完全二叉树
*/ 
/*
二叉树的数据结构：
|*lchild|data|*rchild|*parent|
*/
//二叉树的遍历
//一颗二叉树的组成：根节点，左子树，右子树
/*
先序遍历：根，左，右
中序遍历：左，根，右
后序遍历：左，右，根
*/
/*
      A
    /   \
   B     C
  / \    /
 D   E  F
先序遍历：A BDE CF
中序遍历：DBE A FC
后序遍历：DEB FC A
*/
//在递归遍历的时候把它想成最简单的模型一个两层的二叉树
/*线索二叉树：在二叉树的基础上增加了指向该节点的前驱还是后继（待解决）
ltag（表示指向前驱）：0 lchild指示节点的左孩子 1 lchild指示节点的直接前驱   没有左孩子，就是ltag=1，child节点指向根节点 有左孩子就直接链接 ltag=0
rtag（表示指向后继）：0 rchild指示节点的右孩子 1 rchild指示节点的直接后继
|ltag|lchild|data|rchild|rtag|
*/
/*
前驱节点：二叉树中序遍历完成后和这个节点相邻的前面的节点为该节点的前驱节点
后继节点：二叉树中序遍历完成后和这个节点相邻的后面的节点为该节点的后继节点
     A
   /   \
  B     C
 / \    /
D   E  F
中序遍历：DBE A FC   
E的前驱为B，E的后继为A
B的前驱为D，B的后继为E
https://blog.csdn.net/qq_40938077/article/details/80463299  讲的比较清除，其他网上的很多介绍的不清楚
https://blog.csdn.net/I_love_blog/article/details/60343787
方法：
前驱节点：
1.如果当前节点的有左子树，那么该点的前驱节点为该点左子树中最右的节点（比如A）     
2.若一个节点没有左子树，那么判断该节点和其父节点的关系 
a.若该节点是其父节点的右边孩子，那么该节点的前驱结点即为其父节点。 （比如E）
b.若该节点是其父节点的左边孩子，那么需要沿着其父亲节点一直向树的顶端寻找（从本节点开始），直到找到一个节点P，（比如F）
P节点是其父节点Q的右边孩子，那么Q就是该节点的前驱节点

后继节点：
1.若一个节点有右子树，那么该节点的后继节点是其右子树中最左的节点（比如A）
2.若一个节点没有右子树，那么判断该节点和其父节点的关系 
a.若该节点是其父节点的左边孩子，那么该节点的后继结点即为其父节点。 （比如D）
b.若该节点是其父节点的右边孩子，那么需要沿着其父亲节点一直向树的顶端寻找，直到找到一个节点P，(比如E)
P节点是其父节点Q的左边孩子，那么Q就是该节点的后继节点
*/

#include <stdio.h>
#include <stdlib.h>

typedef char TElemType;

typedef enum PointerTag { Link, Thread };

typedef struct ThrBiNode {
	TElemType data;
	ThrBiNode *lchild, *rchild;  // 左右孩子指针
	PointerTag lTag, RTag;    // 左右指示
}ThrBiNode, *ThrBiTree;

// 中序遍历进行中序线索化（左 根 右）
void InThreading(ThrBiTree T, ThrBiTree &pre)
{
	if (T) {
		InThreading(T->lchild, pre);   // 左子树线索化

		if (!T->lchild) {
			// 当前结点的左孩子为空
			T->lTag = Thread;
			T->lchild = pre;
		}
		else
		{
			T->lTag = Link;
		}

		if (!pre->rchild) {
			// 前驱结点的左孩子为空
			pre->RTag = Thread;
			pre->rchild = T;
		}
		else
		{
			pre->RTag = Link;
		}
		pre = T;
		InThreading(T->rchild, pre);   // 右子树线索化
	}
}

// 中序遍历二叉树T，并将其中序线索化，Thrt指向头结点
void InOrderThreading(ThrBiTree T, ThrBiTree &Thrt)
{
	// 初始化线索链表，为建立一个头结点
	Thrt = (ThrBiTree)malloc(sizeof(ThrBiNode));
	Thrt->lTag = Link;
	Thrt->RTag = Thread;
	if (!T)    // 如果二叉树为空树，则Thrt->lchild指针回指
	{
		Thrt->lchild = Thrt;
		Thrt->rchild = Thrt;
	}
	else
	{
		Thrt->lchild = T;
		ThrBiNode *pre = Thrt;   // pre指针总指向当前结点的前驱结点
		InThreading(T, pre);
		// 继续为最后一个结点加入线索
		pre->RTag = Thread;
		pre->rchild = Thrt;// 最后一个结点的rchild域指针回指
		Thrt->rchild = pre;  // 头结点的rchild域指针指向最后一个结点
	}
}

// 中序遍历打印二叉线索树T（非递归算法）,T指向头结点，头结点的lchild链域指向二叉树的根结点
void InOrderTraversePrint(ThrBiTree T)
{
	ThrBiNode *p = T->lchild;  // p指向根结点
	while (p != T)  // 空树 或遍历结束 p==t
	{
		while (p->lTag == Link)
			p = p->lchild;

		// 此时p指向中序遍历序列的第一个结点（最左下的结点）
		printf("%c ", p->data);  // 打印其左子树为空的结点

		while (p->RTag == Thread && p->rchild != T)
		{
			p = p->rchild;
			printf("%c ", p->data);   // 访问后续结点
		}
		p = p->rchild;

	}
	printf("\n");
}

// 利用先序序列建立一颗二叉 树，'.'代表空树
// 测试数据：abc..de.g..f...#
void CreateBiTreePreOrder(ThrBiTree &T)
{
	char ch;
	scanf("%c", &ch);
	if (ch != '#')
	{
		if (ch == '.') {
			T = NULL;
		}
		else
		{
			T = (ThrBiNode*)malloc(sizeof(ThrBiNode));
			T->data = ch;
			CreateBiTreePreOrder(T->lchild);
			CreateBiTreePreOrder(T->rchild);
		}
	}
}

int main()
{
	ThrBiTree T;
	printf("请按先序次序输入二叉树各节点的值，以空格表示空树，以#号结束:\n");
	CreateBiTreePreOrder(T);  // 建立二叉树

	ThrBiTree Thrt;
	InOrderThreading(T, Thrt); // 将二叉树T中序线索化

							   // 中序遍历二叉线索树
	InOrderTraversePrint(Thrt);

	return 0;
}