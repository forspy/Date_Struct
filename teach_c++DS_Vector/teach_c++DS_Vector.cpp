//vector�ɱ��С������
//�����ڴ棺ʵ�ʴ�С+Ԥ����С ���浽���޻�����realloc 1.5���ռ�
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
void vecttest()
{
	vector<int> test;
	int nsize;//
	int ncapacity;
	for (int i = 0; i < 100; i++)
	{
		test.push_back(i);
		nsize = test.size();//Ԫ�ظ���
		ncapacity = test.capacity();//ʵ������
		if (nsize == ncapacity)
		{
			cout << "Ԫ�ظ���:" << nsize << '\t' << "ʵ������:" << ncapacity << endl;
		}
	}
}
int main()
{
	vector<int> vec1;
	vector<int> vec2(5);//����5��Ԫ��
	vector<int> vec3(5, 1);//����5��Ԫ�أ�����ÿ��Ԫ�ظ�ֵΪ1
	vector<int> vec4 = vec3;//�������ֵ
	vector<int> vec5(vec3);//�������

	int arr[5] = { 1,2,3,4,5 };
	vector<int> vec6(arr, arr + 5);
	vector<int> vec7(&arr[0], &arr[5]);

	//ĩβ���Ԫ��
	vec1.push_back(10);
	vec1.push_back(20);
	vec1.push_back(30);
	//10 20 30
	vec1.pop_back();//10 20

	//����������---
	cout << *vec1.begin() << endl;//��ʼ������
	cout << *(vec1.end() - 1) << endl;//ĩβ������ ָ�����һ��Ԫ�ص���һ��λ�� ����Ҫ-1
	//��������
	//vec1.cbegin(); //����Ա.������,������ʾ��vector����ĳ�Ԫ�أ����ܸ�
	//vec1.cend();
	cout << vec1[1] << endl;//�����±���� ������Խ��
	cout << vec1.at(1) << endl;//���÷������ʣ��������
	cout << "------------" << endl;
	//-------------
	//ͨ����Ա��������
	cout << vec1.front() << endl;
	cout << vec1.back() << endl;

	//-------
	int*p = vec1.data();//.data()����һ��ָ��vector�����ָ��

	vec1.clear();//��ղ��ͷ��ڴ�?
	cout << sizeof(vec1) << endl;

	for (int i = 0; i < 10; i++)
	{
		vec1.push_back(i);//��������
	}
	cout << "--------------" << endl;
	//----------
	vector<int>::iterator iter;//����һ��������
	for (iter = vec1.begin(); iter != vec1.end(); iter++)//Ҳ����ʹ��auto iter=vec1.begin() �Զ�����������������
	{
		cout << *iter << endl;
	}
	cout << "Ԫ�ظ���" << vec1.size() << endl;
	//Ԫ�ط�ת
	reverse(vec1.begin(), vec1.end());//�㷨������ĺ���
	for (iter = vec1.begin(); iter != vec1.end(); iter++)//Ҳ����ʹ��auto iter=vec1.begin() �Զ�����������������
	{
		cout << *iter << endl;
	}
	//���ַ�ת
	reverse(vec1.begin(), vec1.begin()+2);//��ʼ�ӵ�0������1����ת
	cout << "-----------" << endl;
	for (iter = vec1.begin(); iter != vec1.end(); iter++)//Ҳ����ʹ��auto iter=vec1.begin() �Զ�����������������
	{
		cout << *iter << endl;
	}
	//����
	sort(vec1.begin(), vec1.end());
	for (auto it : vec1)//c++11
	{
		cout << it << " ";
	}
	cout << endl;

	vec2 = { 10,20,30,40,50 };
	//����
	vec1.swap(vec2);
	for (auto it : vec1)
	{
		cout << it << " ";
	}
	cout << endl;
	vec1.empty();//��Ϊtrue

	//���ݣ�Ĭ��1.5����
	vec3.reserve(10);//vec��5�����ݵ�10����Ҳ����Ԥ��5����Ĭ����Ԥ��7.5-5=2��
	//��������
	vec3.assign(3, 5);//��Ϊ����5
	for (auto it : vec3)
	{
		cout << it << " ";
	}
	cout << endl;
	//���ݲ��޸����ݵ�ֵ
	vec3.resize(10, 8);//ԭ����ֵ���䣬����ı�Ϊ8
	for (auto it : vec3)
	{
		cout << it << " ";
	}
	cout << endl;
	//֤��vector���Զ����ݲ�����֮ǰ��1.5��
	vecttest();
	//vector��Ա�������MSDN����ÿ�Ӣ�ģ�
}