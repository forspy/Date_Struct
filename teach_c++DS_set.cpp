//������������set ����
//�ײ����ݽṹ RBTree �����
//key��value һ����ӳ��ϵ
//set �������� key����vaule���൱��y�������ᣩ=x��λ���ᣩ��
//�������ظ�ֵ������Ԫ���Զ����򣬲�����ͨ���������޸�����
#include<set>
#include<iostream>
#include<string>
using namespace std;
int main()
{
	set<int> test1;
	

	test1.insert(5);
	test1.insert(7);
	test1.insert(2);
	test1.insert(3);
	test1.insert(5);//�ظ�Ԫ�ز�����
	for (set<int>::iterator it = test1.begin(); it != test1.end(); it++)//���Զ�����
	{
		cout << *it << " ";
	}
	cout << endl;
	set<int>::iterator iter = test1.find(7);
	test1.erase(iter);
	test1.erase(2);
	for (set<int>::iterator it = test1.begin(); it != test1.end(); it++)//���Զ�����
	{
		cout << *it << " ";
	}
	cout << endl;

	set<string> test2;
	test2.insert("hello");
	test2.insert("world");
	for (set<string>::iterator it = test2.begin(); it != test2.end(); it++)//�ᰴ���ַ���strcmp��ʽ����
	{
		cout << *it << " ";
	}
	cout << endl;
	multiset<int> test3;//�����ظ�
	test3.insert(3);
	test3.insert(3);
	test3.insert(2);
	for (set<int>::iterator it = test3.begin(); it != test3.end(); it++)//���Զ�����
	{
		cout << *it << " ";
	}
	cout << endl;
}