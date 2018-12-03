//map key(λ��) value��ֵ��
//һ��key��Ӧһ��value����һ��value���Զ�Ӧ���key  ӳ���ϵ
#include<map>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	map<int, string> test1;//��map
	map<int, string>test2(test1.begin(), test1.end());//��Χ����
	map<int, string>test3 = test2;
	//pairΪmap����Ķ��� ��-ֵ��
	map<int, string>test4(test3);
	map<int, string>test5{ pair<int, string>(1, "aaa"), pair<int, string>(2, "bbb") };//{ pair}��ֵ��������
	map<int, string>test6{ pair<int, string>(1, "aaa") };
	map<int, string>test7{ make_pair<int, string>(1, "aaa") };
	//map<int, string>test6{}
	//1.��������
	test1[100] = "obj100";
	test1[1] = "obj1";
	test1[2] = "obj2";
	//�޸�
	test1[100] = "obj1001";
	map<int, string>::iterator it;
	for (it = test1.begin(); it != test1.end(); ++it)
	{
		cout << "key:" << it->first << "value:" << it->second << endl;
	}
	//2.����ʽ��������insert()
	test1.insert(pair<int, string>(3, "obj3"));
	test1.insert(pair<int, string>(4, "obj4"));
	test1.insert(pair<int, string>(100, "obj**"));//insert�����ظ���key�����value
	test1.insert({ 9,"obj9" });//c++11��׼
	cout << "---------" << endl;
	for (it = test1.begin(); it != test1.end(); ++it)
	{
		cout << "key:" << it->first << "value:" << it->second << endl;
	}
	//3.��insert����value_type
	test1.insert(map<int, string>::value_type(5, "obj5"));
	test1.insert(map<int, string>::value_type(100, "obj**"));//insert�����ظ���key�����value
	test1.insert(map<int, string>::value_type(0, "obj5"));
	cout << "---------" << endl;
	for (it = test1.begin(); it != test1.end(); ++it)
	{
		cout << "key:" << it->first << "value:" << it->second << endl;
	}
	//Ҳ���Է������
	cout << "----------" << endl;
	map<int, string>::reverse_iterator rit;
	for (rit = test1.rbegin(); rit != test1.rend(); ++rit)
	{
		cout << "key:" << rit->first << "value:" << rit->second << endl;
	}
	//���һ�ȡԪ��
	//1.count�жϹؼ��ִ治����
	cout << test1.count(1) << endl;//count()�����key�治���ڣ����ڷ���1 �����ڷ���0��Ҳ������������
	cout << test1.count(99) << endl;

	//2.find ����һ��iterator �ҵ�����ָ�����pair�ĵ�������û�з���end()������
	map<int, string>::iterator iter;
	iter = test1.find(1);
	if (iter != test1.end())
		cout << "�ҵ���" << "key:" << iter->first << "value:" << iter->second << endl;
	else
		cout << "û�ҵ�" << endl;
	iter = test1.lower_bound(50);//��key������ڻ����50�ĵ�һ��Ԫ��,������keyΪ100����
	if (iter != test1.end())
		cout << "�ҵ���" << "key:" << iter->first << "value:" << iter->second << endl;
	else
		cout << "û�ҵ�" << endl;
	iter = test1.upper_bound(1);//��key�������1�ĵ�һ��Ԫ��,������keyΪ100����
	if (iter != test1.end())
		cout << "�ҵ���" << "key:" << iter->first << "value:" << iter->second << endl;
	else
		cout << "û�ҵ�" << endl;

	//1.ɾ��(ͨ��iteratorʵ��)
	iter = test1.find(100);
	test1.erase(iter);
	//2.����keyɾ��
	test1.erase(0);
	cout << "----------" << endl;
	for (it = test1.begin(); it != test1.end(); ++it)
	{
		cout << "key:" << it->first << "value:" << it->second << endl;
	}
	//3.��Χɾ��
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