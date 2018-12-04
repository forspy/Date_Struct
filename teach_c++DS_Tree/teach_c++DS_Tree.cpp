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
	T1.insert("A", "A");//第一个A表示要找A，第二个A表示要插入A这个值，默认false在本层开节点，A为根节点
	T1.insert("A", "B", true);//在A节点的下边开一个子节点，true
	//在本层开兄弟节点都是在本层第一个节点寻找
	T1.insert("B", "C");//在B子节点的旁边开一个兄弟节点C
	T1.insert("B", "D");//在B层继续开一个兄弟节点D
	//B层的下面新开一层
	T1.insert("B", "E", true);
	T1.insert("E", "F");//E层开兄弟节点
}