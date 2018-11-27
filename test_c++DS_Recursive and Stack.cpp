//递归：
/*
有人送了我金、银、铜、铁、木五个宝箱，我想打开金箱子，却没有打开这个箱子的钥匙。
在金箱子上面写着一句话：“打开我的钥匙装在银箱子里。”
于是我来到银箱子前，发现还是没有打开银箱子的钥匙。
银箱子上也写着一句话：“打开我的钥匙装在铜箱子里。”
于是我再来到铜箱子前，发现还是没有打开铜箱子的钥匙。
铜箱子上也写着一句话：“打开我的钥匙装在铁箱子里。”
于是我又来到了铁箱子前，发现还是没有打开铁箱子的钥匙。
铁箱子上也写着一句话：“打开我的钥匙装在木箱子里。”

*/
/*
递归定义的数学函数：
1.阶乘函数：
Fact(n)=1;(n=0)  Fact(n)=n*Fact(n-1)   (n>1)

2.斐波那契数列
Fib(n)=1;  (n=1或n=2)  Fib(n)=Fib(n-1)+Fib(n-2); (其他)

3.具有递归特性的数据结构：树

4.可递归求解的问题：迷宫问题，汉诺塔问题
*/
//递归转向非递归需要指明运行次数，所以递归思路比较清晰简明，但是对于栈的开销比较大
//Fact(n) = n*Fact(n - 1) 阶乘转化为非递归
/*
long Fact ( long n ) 
{
	t=1;
	for(i=1; i<=n; i++)     
		t=t*i;
	return t; 
}

*/

//转化为非递归Fib(n) = Fib(n - 1) + Fib(n - 2);
/*
long Fib ( long n )
{
	if(n==1 || n==2) 
		return 1;
	else{
	t1=1; t2=1;
	for(i=3; i<=n; i++)
	{
        t3=t1+t2;
		t1=t2; t2=t3; 
	}
	return t3;
	}
}

*/
#include<iostream>
using namespace std;
int m = 0;//全局变量m表示移动的步数
void MoveInfo(int number, char pillar, char other_pillar)
{
	cout << "第" << ++m << "步，将编号为" << number << "的圆盘从第" << pillar << "个柱子移动到第" << other_pillar << "个柱子上" << endl;
}
void Hanoi(int n, char A, char B, char C)//n个圆盘，ABC三根柱子
{
	if (n == 1)
	{
		MoveInfo(1, A, C);//将编号为1的圆盘从A移动到C  1，2，3号圆盘从小到大
	}
	else
	{
		Hanoi(n - 1, A, C, B);//将A上编号为1到n-1号的圆盘从A移动到B，  C作为辅助塔
		MoveInfo(n, A, C);//输出信息
		Hanoi(n - 1, B, A, C);//将编号为1到n-1的圆盘从B移到C，A做辅助塔（表示执行完A到B后执行B到C）
	}
}
int main()
{
	int n;
	char a, b, c;
	a = 'A';
	b = 'B';
	c = 'C';
	n = 3;//圆盘个数
	Hanoi(n, a, b, c);
}