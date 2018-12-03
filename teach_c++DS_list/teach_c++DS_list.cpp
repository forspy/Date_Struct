#include<list>//循环双向链表	
#include<iostream>
using namespace std;
int foo(int a);
//环状双向链表prv next data
//链表的插入比Vector快一些，因为list可以自由的增添节点，
//而Vector在nSize=nCapacity的时候尾部插入需要扩容，这时候就需要memcpy，所以整体慢一些，而在中间插入更慢，需要整体移动
//Vector的查询快一些，因为可以根据下标，所以时间是O(1)级别的，list会分情况，一般是O(n)级别
int main()
{
	list<int> L1;
	list<int> L2(5);//生成5个节点的链表，每个元素都为0
	list<int> L3(2, 3);//生成2个节点，每个元素为3
	list<int> L4(L3);//L4使用L3来拷贝构造
	list<int> L5 = L4;//=赋值构造
	L1.push_back(1);//末尾插入
	L1.push_back(2);
	L1.push_front(3);//list支持头部插入和删除
	L1.pop_back();//末尾删除
	L1.push_back(4);
	L1.sort();//list支持基本类型排序 （ps：vector没有sort()成员函数，使用的是算法库中的sort）
	//list支持链表合并merge 
	L1.clear();
	L1.push_back(1);
	L1.push_back(6);
	L2.assign(1,2);//重新设置L2
	L2.push_back(4);
	L1.merge(L2);//有序链表合并并排序
	L1.remove(6);//清除指定的元素值
	L1.remove_if(foo);//传入函数指针就行，清除指定条件的元素
	L1.remove_if([](int x) {return x == 1; });//c++11,也可以使用匿名函数
	for (int i = 0; i < 10; i++)
		L1.push_back(i);
	//splice从源列表中删除元素并将其插入到目标列表中。
	L1.push_back(9);
	L1.unique();//删除重复值
	for (list<int>::iterator it = L1.begin(); it != L1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	for (auto& i : L1)//c++11 &i表示引用变量对list操作其实可以修改list里面的值
		i++;
	for (auto& i : L1)
		cout << i << " ";
	cout << endl;
}
//条件函数
int foo(int a)
{
	return a % 2 == 0;
}
