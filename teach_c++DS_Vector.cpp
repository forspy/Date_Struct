//vector可变大小的序列
//分配内存：实际大小+预留大小 当存到上限会重新realloc 1.5倍空间
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
void vecttest()
{
	vector<int> test;
	int nsize;//
	int ncapacity;
	for (int i = 0; i < 100; i++)
	{
		test.push_back(i);
		nsize = test.size();//元素个数
		ncapacity = test.capacity();//实际容量
		if (nsize == ncapacity)
		{
			cout << "元素个数:" << nsize << '\t' << "实际容量:" << ncapacity << endl;
		}
	}
}
int main()
{
	vector<int> vec1;
	vector<int> vec2(5);//开辟5个元素
	vector<int> vec3(5, 1);//开辟5个元素，并且每个元素赋值为1
	vector<int> vec4 = vec3;//深拷贝对象赋值
	vector<int> vec5(vec3);//深拷贝构造

	int arr[5] = { 1,2,3,4,5 };
	vector<int> vec6(arr, arr + 5);
	vector<int> vec7(&arr[0], &arr[5]);

	//末尾添加元素
	vec1.push_back(10);
	vec1.push_back(20);
	vec1.push_back(30);
	//10 20 30
	vec1.pop_back();//10 20

	//迭代器访问---
	cout << *vec1.begin() << endl;//开始迭代器
	cout << *(vec1.end() - 1) << endl;//末尾迭代器 指向最后一个元素的下一个位置 所以要-1
	//常迭代器
	//vec1.cbegin(); //常成员.常函数,所以显示是vector里面的常元素，不能改
	//vec1.cend();
	cout << vec1[1] << endl;//利用下标访问 不会检查越界
	cout << vec1.at(1) << endl;//利用方法访问，会检查错误
	cout << "------------" << endl;
	//-------------
	//通过成员函数访问
	cout << vec1.front() << endl;
	cout << vec1.back() << endl;

	//-------
	int*p = vec1.data();//.data()返回一个指向vector数组的指针

	vec1.clear();//清空并释放内存?
	cout << sizeof(vec1) << endl;

	for (int i = 0; i < 10; i++)
	{
		vec1.push_back(i);//插入数据
	}
	cout << "--------------" << endl;
	//----------
	vector<int>::iterator iter;//声明一个迭代器
	for (iter = vec1.begin(); iter != vec1.end(); iter++)//也可以使用auto iter=vec1.begin() 自动声明迭代器的类型
	{
		cout << *iter << endl;
	}
	cout << "元素个数" << vec1.size() << endl;
	//元素反转
	reverse(vec1.begin(), vec1.end());//算法库里面的函数
	for (iter = vec1.begin(); iter != vec1.end(); iter++)//也可以使用auto iter=vec1.begin() 自动声明迭代器的类型
	{
		cout << *iter << endl;
	}
	//部分反转
	reverse(vec1.begin(), vec1.begin()+2);//开始从第0个到第1个反转
	cout << "-----------" << endl;
	for (iter = vec1.begin(); iter != vec1.end(); iter++)//也可以使用auto iter=vec1.begin() 自动声明迭代器的类型
	{
		cout << *iter << endl;
	}
	//排序
	sort(vec1.begin(), vec1.end());
	for (auto it : vec1)//c++11
	{
		cout << it << " ";
	}
	cout << endl;

	vec2 = { 10,20,30,40,50 };
	//交换
	vec1.swap(vec2);
	for (auto it : vec1)
	{
		cout << it << " ";
	}
	cout << endl;
	vec1.empty();//空为true

	//扩容（默认1.5倍）
	vec3.reserve(10);//vec是5个扩容到10个，也就是预留5个，默认是预留7.5-5=2个
	//重新设置
	vec3.assign(3, 5);//改为三个5
	for (auto it : vec3)
	{
		cout << it << " ";
	}
	cout << endl;
	//扩容并修改扩容的值
	vec3.resize(10, 8);//原来的值不变，扩充的变为8
	for (auto it : vec3)
	{
		cout << it << " ";
	}
	cout << endl;
	//证明vector会自动扩容并且是之前的1.5倍
	vecttest();
	//vector成员函数详见MSDN（最好看英文）
}