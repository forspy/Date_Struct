#include"Tree.h"
#include<string>
using namespace std;
int main()
{
/*
	    A
	  /  
     /    
    B - C - D
   /    
  /     
 E ---  F
*/
	Tree<string> T1;
	T1.insert("A", "A");//��һ��A��ʾҪ��A���ڶ���A��ʾҪ����A���ֵ��Ĭ��false�ڱ��㿪�ڵ㣬AΪ���ڵ�
	T1.insert("A", "B", true);//��A�ڵ���±߿�һ���ӽڵ㣬true
	//�ڱ��㿪�ֵܽڵ㶼���ڱ����һ���ڵ�Ѱ��
	T1.insert("B", "C");//��B�ӽڵ���Ա߿�һ���ֵܽڵ�C
	T1.insert("B", "D");//��B�������һ���ֵܽڵ�D
	//B��������¿�һ��
	T1.insert("B", "E", true);
	T1.insert("E", "F");//E�㿪�ֵܽڵ�
}