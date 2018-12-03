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