//�ڴ�й©��⣺
/*
1.����VLD��include�ļ������������ͷ�ļ����Ƶ���ǰcpp�ļ����¡�
2.��Ϊ���ǵĿ���������x86�����԰�lib�ļ����µľ�̬���ļ����Ƶ���ǰcpp�ļ����¡�
3.ѡ��bin/win32/�����dbghelp.dll��Microsoft.DTfW.DHL.manifest��vld_x86.dll���Ƶ�debug�ļ�������(�����debug)
4.����ͷ�ļ�
5.vldֻ��debugģʽ������
*/
#if _DEBUG//����Ŀ-����-c/c++-Ԥ���������涨��ĺ꣬
//��ʾvldֻ��debugģʽ������
#include "vld.h"
#pragma comment(lib,"vld.lib")//���뾲̬��
#endif // _DEGUB
#include<iostream>
using namespace std;
//����һ���ڴ�й©�İ���
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