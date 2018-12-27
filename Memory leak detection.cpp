//内存泄漏检测：
/*
1.进入VLD把include文件夹下面的两个头文件复制到当前cpp文件夹下。
2.因为我们的开发环境是x86，所以把lib文件夹下的静态库文件复制到当前cpp文件夹下。
3.选择bin/win32/下面的dbghelp.dll、Microsoft.DTfW.DHL.manifest、vld_x86.dll复制到debug文件夹下面(是外层debug)
4.加入头文件
5.vld只在debug模式下有用
*/
#if _DEBUG//在项目-属性-c/c++-预处理器下面定义的宏，
//表示vld只在debug模式下有用
#include "vld.h"
#pragma comment(lib,"vld.lib")//加入静态库
#endif // _DEGUB
#include<iostream>
using namespace std;
//测试一个内存泄漏的案例
void fun()
{
	int* ptr = new int[10];
	// Leak Hash: 0xFEEDB229, Count: 1, Total 40 bytes
	//delete[] ptr;
}

int main()
{
	fun();
	return 0;
}