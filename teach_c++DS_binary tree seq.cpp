//�������Ķ�Ϊ2
/*
��������Ҷ�Ӹ���Ϊn0����Ϊ2�Ľڵ����n2��n0=n2+1

��ȫ��������ǰ�涼�������������һ�������������


�������������һ��2^(n-1),�ܹ�2^k-1,һ��n���ڵ㣬���h=log2(n+1)
���Ϊi�Ķ������ĸ��׽ڵ�Ϊi/2�����ӽڵ�2i�����ӽڵ�2i+1�����ڵ���Ϊ1��������������ţ���ͨ�������յĵط�����ţ�
��ȫ�������ı�ţ�
       2^k
2^(k+1)  2^(k+1)+1
*/
/*
     A
   /   \
  B     C
 / \    /
D   E  F
*/
/*
������ʽ��
��α�����һ���������������ң�
����������� �� �� A BDE CF
����������� �� �� DBE A FC
����������� �� �� DEB FC A
*/
//��������˳��洢����ʽ�洢
/*
˳��洢��
        A(1)
     /       \
   B(2)      C(3)
  / \        / \
D(4)NULL(5)NULL(6)E(5)
һ���������[A,B,C,D,NULL,NULL,E],ת������ȫ��������û�е�Ҷ�ӽڵ㲹�գ���ڵ㣩�������Ϊ��ȫ������
*/
#include<iostream>
#include<vector>
using namespace std;
template<typename T>
class TreeArr
{
private:
	vector<T> vecBuff;//���飬��Ŵ�0��ʼ
public:
	TreeArr(){ }
	TreeArr(T arr[], int len);
	~TreeArr();//����
	void clear();//��������
	void Init(T arr[], int len);
	bool find(const T& findVal);
	void appendNode(const T& data);
	//������ʽ
	void prePrint(unsigned int index = 0);//ǰ�������index��ʾ��ţ�˳��洢���У�����һ���Ӹ���ʼ����
	void midPrint(unsigned int index = 0);//�������
	void backPrint(unsigned int index = 0);//�������
	void levelPrint();//�㼶�������ǵݹ����
};
//����,����˳��洢��ʽ����
template<typename T>
TreeArr<T>::TreeArr(T arr[], int len)
{
	vecBuff.insert(vecBuff.end(), arr, arr + len);//vector��Χ����
	/*
	vector _Where�ڵ�һԪ�ز����ʸ����λ�ã�_FirstҪ���Ƶ�Ԫ�ط�Χ�еĵ�һ��Ԫ�ص�λ�ã�
	_LastҪ���Ƶ�Ԫ�ط�Χ֮��ĵ�һ��Ԫ�ص�λ��
	*/
}

template<typename T>
TreeArr<T>::~TreeArr()
{
	clear();
}

template<typename T>
void TreeArr<T>::clear()
{
	vecBuff.clear();
}

template<typename T>
void TreeArr<T>::Init(T arr[], int len)//�ֶ�init
{
	vecBuff.clear();
	//���鸴�Ƶ�vecbuff����
	vecBuff.insert(vecBuff.end(), arr, arr + len);//vector��Χ����
}

template<typename T>
bool TreeArr<T>::find(const T & findVal)
{
	auto iter = std::find(vecBuff.begin(), vecBuff.end(), findVal);//find��std����ķ���
	if (iter == vecBuff.end())
		return false;
	else
		return true;
}

template<typename T>
void TreeArr<T>::appendNode(const T & data)
{
	vecBuff.push_back(data);
}
//�������
template<typename T>
void TreeArr<T>::prePrint(unsigned int index)//index��ʾ���
{
	if (index < vecBuff.size() && index >= 0)
	{
		cout << vecBuff[index] << " ";//���ڵ�
		prePrint(2 * index + 1);
		prePrint(2 * index + 2);
	}
	
}

template<typename T>
void TreeArr<T>::midPrint(unsigned int index)
{
	if (index < vecBuff.size() && index >= 0)
	{
		midPrint(2 * index + 1);
		cout << vecBuff[index] << " ";//���ڵ�
		
		midPrint(2 * index + 2);
	}
	
}

template<typename T>
void TreeArr<T>::backPrint(unsigned int index)
{
	if (index < vecBuff.size() && index >= 0)
	{
		
		backPrint(2 * index + 1);
		backPrint(2 * index + 2);
		cout << vecBuff[index] << " ";//���ڵ�
	}
	
}

template<typename T>
void TreeArr<T>::levelPrint()
{
	vector<int>::iterator iter;
	for (iter = vecBuff.begin(); iter != vecBuff.end(); ++iter)
	{
		cout << *iter << " ";
	}
}

int  main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int nSize = sizeof(arr) / sizeof(arr[0]);
	TreeArr<int> tree(arr, nSize);
	bool b = tree.find(9);
	cout << "�������" << endl;
	tree.prePrint();
	cout << endl;
	cout << "�������" << endl;
	tree.midPrint();
	cout << endl;
	cout << "�������" << endl;
	tree.backPrint();
	cout << endl;
	cout << "(�ǵݹ�)�㼶����" << endl;
	tree.levelPrint();
	cout << endl;
}