#include<list>//ѭ��˫������	
#include<iostream>
using namespace std;
int foo(int a);
//��״˫������prv next data
//����Ĳ����Vector��һЩ����Ϊlist�������ɵ�����ڵ㣬
//��Vector��nSize=nCapacity��ʱ��β��������Ҫ���ݣ���ʱ�����Ҫmemcpy������������һЩ�������м�����������Ҫ�����ƶ�
//Vector�Ĳ�ѯ��һЩ����Ϊ���Ը����±꣬����ʱ����O(1)����ģ�list��������һ����O(n)����
int main()
{
	list<int> L1;
	list<int> L2(5);//����5���ڵ������ÿ��Ԫ�ض�Ϊ0
	list<int> L3(2, 3);//����2���ڵ㣬ÿ��Ԫ��Ϊ3
	list<int> L4(L3);//L4ʹ��L3����������
	list<int> L5 = L4;//=��ֵ����
	L1.push_back(1);//ĩβ����
	L1.push_back(2);
	L1.push_front(3);//list֧��ͷ�������ɾ��
	L1.pop_back();//ĩβɾ��
	L1.push_back(4);
	L1.sort();//list֧�ֻ����������� ��ps��vectorû��sort()��Ա������ʹ�õ����㷨���е�sort��
	//list֧������ϲ�merge 
	L1.clear();
	L1.push_back(1);
	L1.push_back(6);
	L2.assign(1,2);//��������L2
	L2.push_back(4);
	L1.merge(L2);//��������ϲ�������
	L1.remove(6);//���ָ����Ԫ��ֵ
	L1.remove_if(foo);//���뺯��ָ����У����ָ��������Ԫ��
	L1.remove_if([](int x) {return x == 1; });//c++11,Ҳ����ʹ����������
	for (int i = 0; i < 10; i++)
		L1.push_back(i);
	//splice��Դ�б���ɾ��Ԫ�ز�������뵽Ŀ���б��С�
	L1.push_back(9);
	L1.unique();//ɾ���ظ�ֵ
	for (list<int>::iterator it = L1.begin(); it != L1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	for (auto& i : L1)//c++11 &i��ʾ���ñ�����list������ʵ�����޸�list�����ֵ
		i++;
	for (auto& i : L1)
		cout << i << " ";
	cout << endl;
}
//��������
int foo(int a)
{
	return a % 2 == 0;
}
