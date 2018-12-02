#include"my Vector.h"
template<typename T>
void Show(const Vector<T>& obj);
int main()
{
	Vector<int> A(5, 1);
	cout << A.at(1) << endl;
	A.push_back(6);
	cout << A[5] << endl;
	Show(A);
	Vector<int> B(2, 3);
	A.swap(B);
	Show(A);
	A.resize(10, 6);
	Show(A);
	A.pop_back();
	Show(A);
	A.assgin(8,8);
	Show(A);
}
//��ʾVector�����Ԫ��
template<typename T>
void Show(const Vector<T>& obj)
{
	Vector<int>::const_iterator it;//��Ϊ�ǳ���������ʹ�ó�������
	for (it = obj.begin(); it != obj.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
