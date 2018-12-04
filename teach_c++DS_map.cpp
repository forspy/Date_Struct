//map key(位置) value（值）
//一个key对应一个value，但一个value可以对应多个key  映射关系
#include<map>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	map<int, string> test1;//空map
	map<int, string>test2(test1.begin(), test1.end());//范围构造
	map<int, string>test3 = test2;
	//pair为map里面的对象 键-值队
	map<int, string>test4(test3);
	map<int, string>test5{ pair<int, string>(1, "aaa"), pair<int, string>(2, "bbb") };//{ pair}赋值（）构造
	map<int, string>test6{ pair<int, string>(1, "aaa") };
	map<int, string>test7{ make_pair<int, string>(1, "aaa") };
	//map<int, string>test6{}
	//1.插入数据
	test1[100] = "obj100";
	test1[1] = "obj1";
	test1[2] = "obj2";
	//修改
	test1[100] = "obj1001";
	map<int, string>::iterator it;
	for (it = test1.begin(); it != test1.end(); ++it)
	{
		cout << "key:" << it->first << "value:" << it->second << endl;
	}
	//2.集合式容器都是insert()
	test1.insert(pair<int, string>(3, "obj3"));
	test1.insert(pair<int, string>(4, "obj4"));
	test1.insert(pair<int, string>(100, "obj**"));//insert插入重复的key不会改value
	test1.insert({ 9,"obj9" });//c++11标准
	cout << "---------" << endl;
	for (it = test1.begin(); it != test1.end(); ++it)
	{
		cout << "key:" << it->first << "value:" << it->second << endl;
	}
	//3.用insert插入value_type
	test1.insert(map<int, string>::value_type(5, "obj5"));
	test1.insert(map<int, string>::value_type(100, "obj**"));//insert插入重复的key不会改value
	test1.insert(map<int, string>::value_type(0, "obj5"));
	cout << "---------" << endl;
	for (it = test1.begin(); it != test1.end(); ++it)
	{
		cout << "key:" << it->first << "value:" << it->second << endl;
	}
	//也可以反向遍历
	cout << "----------" << endl;
	map<int, string>::reverse_iterator rit;
	for (rit = test1.rbegin(); rit != test1.rend(); ++rit)
	{
		cout << "key:" << rit->first << "value:" << rit->second << endl;
	}
	//查找获取元素
	//1.count判断关键字存不存在
	cout << test1.count(1) << endl;//count()来检测key存不存在，存在返回1 不存在返回0，也可以用作计数
	cout << test1.count(99) << endl;

	//2.find 返回一个iterator 找到返回指向这个pair的迭代器，没有返回end()迭代器
	map<int, string>::iterator iter;
	iter = test1.find(1);
	if (iter != test1.end())
		cout << "找到了" << "key:" << iter->first << "value:" << iter->second << endl;
	else
		cout << "没找到" << endl;
	iter = test1.lower_bound(50);//找key里面大于或等于50的第一个元素,所以是key为100的数
	if (iter != test1.end())
		cout << "找到了" << "key:" << iter->first << "value:" << iter->second << endl;
	else
		cout << "没找到" << endl;
	iter = test1.upper_bound(1);//找key里面大于1的第一个元素,所以是key为100的数
	if (iter != test1.end())
		cout << "找到了" << "key:" << iter->first << "value:" << iter->second << endl;
	else
		cout << "没找到" << endl;

	//1.删除(通过iterator实现)
	iter = test1.find(100);
	test1.erase(iter);
	//2.利用key删除
	test1.erase(0);
	cout << "----------" << endl;
	for (it = test1.begin(); it != test1.end(); ++it)
	{
		cout << "key:" << it->first << "value:" << it->second << endl;
	}
	//3.范围删除
	test1.erase(test1.begin(), test1.end());

	multimap<int, string> multi_test;
	multi_test.insert({ 1,"aaa" });
	multi_test.insert({ 1,"bbb" });
	multimap<int, string> ::iterator it1;
	for (it1 = multi_test.begin(); it1 != multi_test.end(); ++it1)
	{
		cout << "key:"<<it1->first <<"value:"<< it1->second << endl;
	}
}