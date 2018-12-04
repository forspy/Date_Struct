//deque双端队列
//Vector的插入麻烦而List的查询麻烦
/*
  中控器list     vector
        |__|---->|__|__|__|__|__|__|__|
        |__|---->|__|__|__|__|__|__|__|
        |__|---->|__|__|__|__|__|__|__|
        |__|---->|__|__|__|__|__|__|__|
iterator:node     first   cur       last
*/
//中控器（list）-->各个vector
//deque可以在两端插入删除
//迭代器比较：
/*
vector和deque迭代器支持算术运算，list只支持++，--
vector的迭代器不稳定 在vector扩容的时候 会重开内存 但没有将iterator重新指向，
所以每次扩容的时候原来的iterator会失效，需要重新调整iterator
*/
/*
vector vs list vs deque
1.高效访问 不在乎插入删除效率 用vector
2.需要大量插入删除，不关心访问 用list
3.需要访问 也要考虑插入删除效率 用deque
*/
#include<iostream>
#include<deque>
using namespace std;
//using std::deque;
int main()
{
	deque<int> deque1;
	deque1.push_back(1);
	deque1.push_back(2);
	deque1.push_back(3);
	deque1.pop_front();//前后都能弹出
	for (deque<int>::iterator iter = deque1.begin(); iter != deque1.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
	for (deque<int>::reverse_iterator it = deque1.rbegin(); it != deque1.rend(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}