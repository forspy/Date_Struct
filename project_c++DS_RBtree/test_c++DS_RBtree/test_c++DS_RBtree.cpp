//红黑树是一种自平衡二叉查找树
/*
特征：
1.任意一个节点的键值大于等于左孩子的键值，小于等于右孩子的键值
2.数据域储存颜色红或黑
a.根节点黑色
b.为空的叶子节点为黑色
c.如果一个节点为红，叶子节点为黑
d.从一个节点到该节点的子孙节点的所有路径上包含相同数目的黑节点（RBtree是一种相对平衡的二叉树，最长路径<=2*最短路径）
*/
//红黑树的基本操作是添加删除旋转，在添加删除之后会用到旋转方法，因为添加删除之后可能红黑树不是一个红黑树了，通过旋转保持一个红黑树特征
//左旋，右旋会根据特征1调整节点位置
/*
红黑树和AVL树类似，都是在进行插入和删除操作时通过特定操作保持二叉查找树的平衡，从而获得较高的查找性能。
它虽然是复杂的，但它的最坏情况运行时间也是非常良好的，并且在实践中是高效的： 
它可以在O(log n)时间内做查找，插入和删除，这里的n 是树中元素的数目。
*/
/*
红黑树在很多地方都有应用。在C++ STL中，很多部分(包括set, multiset, map, multimap)应用了红黑树的变体
.find()方法
*/
/*
问题：如何提高二叉排序树的查找效率？
	尽量让二叉树的形状均衡
  平衡二叉树特征：
左、右子树是平衡二叉树；
所有结点的左、右子树深度之差的绝对值≤ 1
*/
/*
如果在一棵AVL树中插入一个新结点，就有可能造成失衡，此时必须重新调整树的结构，使之恢复平衡。我们称调整平衡过程为平衡旋转。
LL平衡旋转
RR平衡旋转
LR平衡旋转
RL平衡旋转
保证二叉排序树的次序不变
旋转需要进一步讨论，待解决
*/
