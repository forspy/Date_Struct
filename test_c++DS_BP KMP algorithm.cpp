#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
//实现如果一行中有这个字符串，则输出这行
int strindex(char source[], char searchfor[]);
char line[] = "would you please";
char pattern[] = "you";

int main()
{
	//printf("%s", line);
	if (strindex(line, pattern) >= 0)
	{
		printf("%s\n", line);
	}
	//当然使用string类中的find方法也能找到（KMP方法）
	string a = "would you please";
	cout << a.find("you") << endl;//返回位置，如果没有查到，返回0
}
//一段相当经典的BP算法
int strindex(char source[], char searchfor[])
{
	int i, j, k;
	for (i = 0; source[i] != '\0'; i++)//i用于在源字符串中遍历
	{
		//j用于在从i位开始遍历源字符串，k用于反复从头开始遍历要搜索的字符串
		for (j = i, k = 0; source[j] == searchfor[k] && searchfor[k] != '\0'; j++, k++)
			;
		if (searchfor[k] == '\0'&&k > 0)//如果发现在退出for循环的时候K字符串到达了尾部，说明匹配成功
		{
			printf("从第%d个起匹配成功\n",i);
			return i;//相当于跳出/
		}
	}
	printf("没有匹配到\n");
	return -1;
	
}