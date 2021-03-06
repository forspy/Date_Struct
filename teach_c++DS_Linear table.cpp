//时间复杂度T=O(n)
//n越大算法执行的时间越长
/*
排序：n为记录数
矩阵：n为阶数
多项式：n为多项式个数
集合：n为元素个数
树：n为树的节点个数
图：n为顶点数或者边数
*/
//时间复杂度：常数阶O(1),对数阶O(log2n),线性阶O(n),线性对数阶O(nlog2n),平方阶O(n^2),立方阶O(n^3)...指数阶O(2^n)
//对于一个多项式例如：P(x)=	10+5x-4x^2+3x^3+2x^4
//用数组去存下标对应指数，系数存入数组
/*
0  1  2  3  4（指数） 
10 5 -4  3  2（系数）
*/
//也可以使用多个数组，例如P（x）=7+5x+3x^99
/*
0  1  2（序号）
7  5  3（数组1：系数）
0  1  99（数组2：指数）
*/
//也可以使用链表，例如P（x）=7+5x+3x^99
/*
7|0->  5|1->  3|99//其中  7|0是一个节点
*/
/*
多项式相加：
例如A（x）=7+5x-2x^2+3x^99  B（x）=6x+2x^2+5x^3
A:7|0->5|1->-2|2     ->3|99
B:     6|1-> 2|2->5|3
两个链表相加：
  7|0->11|1->0|2->5|3->3|99   //涉及到链表的插入
对于node里面数据项系数为0的neode，删除
7|0->11|1->5|3->3|99
这样就完成了多项式的相加
*/