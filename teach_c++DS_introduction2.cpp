//数据结构+算法=程序
// 食材   工序= 菜
//逻辑结构：集合 线性 树形 图形
//物理结构： 内存连续 数组 内存链式 链表、树、图
//算法：
/*
int sum(int a,int b)
{
  return a+b;
}
*/

//时间复杂度
int foo()
{
	int n = 10;
	for (int i = 0; i < n; i++)
	{
		//执行一次循环的时间是O(1)级
	}//执行n次，时间复杂度 O（n）

	for (int i = 1; i < n;)
	{
		i = i * 2;//
	}//运行log2n次 时间复杂度O(logn)
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{

		}
	}//时间复杂度O（n^2）
}

//standrd template library==STL 标准模板库 （常用的数据结构算法、流模型，例如list就是双向循环链表）
//序列式容器：
/*
下标是有顺序的
vector deque list
*/
//关联式容器：
/*
集合的关系（有映射关系 key和value、二叉树）
set map multiset  multimap
*/
//容器适配器：
/*
stack栈 队列queue 优先级队列priority_queue
*/
//迭代器：指向容器内的元素（封装成结构体的指针）
/*
具备遍历复杂数据结构的能力，可以重载运算符（* ++ == ！= =）
*/


