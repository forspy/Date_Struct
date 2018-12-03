//关联性容器：set 集合
//底层数据结构 RBTree 红黑树
//key和value 一般是映关系
//set 集合里面 key就是vaule（相当于y（数据轴）=x（位置轴））
//不允许重复值，所有元素自动排序，不允许通过迭代器修改数据
#include<set>
#include<iostream>
#include<string>
using namespace std;
int main()
{
	set<int> test1;
	

	test1.insert(5);
	test1.insert(7);
	test1.insert(2);
	test1.insert(3);
	test1.insert(5);//重复元素不插入
	for (set<int>::iterator it = test1.begin(); it != test1.end(); it++)//会自动排序
	{
		cout << *it << " ";
	}
	cout << endl;
	set<int>::iterator iter = test1.find(7);
	test1.erase(iter);
	test1.erase(2);
	for (set<int>::iterator it = test1.begin(); it != test1.end(); it++)//会自动排序
	{
		cout << *it << " ";
	}
	cout << endl;

	set<string> test2;
	test2.insert("hello");
	test2.insert("world");
	for (set<string>::iterator it = test2.begin(); it != test2.end(); it++)//会按照字符串strcmp方式排序
	{
		cout << *it << " ";
	}
	cout << endl;
	multiset<int> test3;//可以重复
	test3.insert(3);
	test3.insert(3);
	test3.insert(2);
	for (set<int>::iterator it = test3.begin(); it != test3.end(); it++)//会自动排序
	{
		cout << *it << " ";
	}
	cout << endl;
}