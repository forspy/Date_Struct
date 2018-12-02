#pragma once
#include<iostream>
using namespace std;
template <typename T>
class Vector
{
private:
	T* pbuff;//��̬�����׵�ַ
	int nSize;//��̬����Ԫ�ظ���,ע���Ǹ�����1��ʼ
	int nCapacity;//��̬������󳤶�
public://ע����main����Ҫʹ�ã�������Ҫ������public����
	typedef T* iterator;//����������Ԫ��ָ��
	typedef const T* const_iterator;//������������Ӧ��Ԫ�غͳ�����
	//��������Ա����(����)
	iterator begin() { return pbuff; }//&pbuff[0]Ҳ����
	iterator end() { return pbuff + nSize; }//���һ��Ԫ�صĺ�һ��Ԫ��λ��
	const_iterator begin()const{ return pbuff; }
	const_iterator end()const{ return pbuff + nSize; }
public:
	explicit Vector(int size = 0);//��ֹ=��ʽת��
	//���ع��캯��
	Vector(int size,const T&elem);//��������Ϊ�˷�ֹ��T�������͵�ʱ������������죬����ֱ��������ǡ��
	//��������
	Vector(const Vector<T>& that);
	~Vector();
	//���������----
	Vector<T>& operator=(const Vector<T>& that);//=����
	//�߼��ж�
	bool operator==(const Vector<T>&that);//==�ж�
	bool operator!=(const Vector<T>&that);//!=�ж�
	bool empty();//�п�
	T& operator[](int index);//�����±�λ�õ�ֵ��������Խ��
	//-------
	//vector����
	void assgin(int n, const T& elem);//�������ø�����Ԫ��
	void swap(Vector<T>& that);
	int size();//����VectorԪ�ظ�����ʵ��������
	int capacity();//����Vector������������������
	void reserve(int n);//���ݵ�n����ָ����capacity��
	void resize(int n);//���ݵ�n��
	void resize(int n, const T& elem);//����Ϊsize��ԭ����Ԫ�ز��䣬�����ݵ�Ԫ�ر�Ϊelem
	void clear();//��ʱdestroy Vector��������
	T& at(int index);//�����±�λ�õ�ֵ������Խ�磬���Խ����׳�Out_of_range
	T& front();//���ص�һ��Ԫ��
	T& back();//�������һ��Ԫ��
	void push_back(const T&elem);//β�巨
	void pop_back();//�������һ��Ԫ��

	//��Ԫ����
	friend void swap(Vector<T>&v1, Vector<T>&v2) { v1.swap(v2) };
};
//���ι���
template<typename T>
inline Vector<T>::Vector(int size)
{
	pbuff = new T[size];
	memset(pbuff, 0, sizeof(T)*size);
	nSize = size;
	nCapacity = size;//��size�����˲�ȥ����Ϊ1.5��
}
//˫�ι���
template<typename T>
Vector<T>::Vector(int size,const T& elem)
{
	pbuff = new T[size];
	for (int i = 0; i < size; i++)
	{
		pbuff[i] = elem;
	}
	nSize = size;
	nCapacity = size;//��size�����˲�ȥ����Ϊ1.5��
}
//��������
template<typename T>
inline Vector<T>::Vector(const Vector<T>& that)
{
	pbuff = new T[that.nSize];
	if (that.nCapacity != 0)
		memcpy(pbuff, that.pbuff, sizeof(T)*that.nCapacity);
	else
		pbuff = nullptr;
	nSize = that.nSize;
	nCapacity = that.nCapacity;
}
//��������
template<typename T>
inline Vector<T>::~Vector()
{
	delete[] pbuff;
}
//����=
template<typename T>
inline Vector<T>& Vector<T>::operator=(const Vector<T>& that)
{
	//1.�ж������
	if (this != &that)
	{
		//2.�ͷž���Դ
		delete[] pbuff;
		//3.�������ڴ�
		pbuff = new T[that.nCapacity];
		memcpy(pbuff, that.pbuff, sizeof(T)*nSize);
		nSize = that.nSize;
		nCapacity = that.nCapacity;
	}
	return *this;
}
//�����߼��ж�==,�ж�����ÿ��Ԫ�ض����
template<typename T>
inline bool Vector<T>::operator==(const Vector<T>& that)
{
	int flag = 1;
	if (nSize == that.nSize)
	{
		for (int i = o; i < nSize; i++)
		{
			if (pbuff[i] != that.pbuff[i])
			{
				flag = 0;
				break;
			}
		}
	}
	else
	{
		flag = 0;
	}
	return flag == 1;
}

template<typename T>
inline bool Vector<T>::operator!=(const Vector<T>& that)
{
	return !operator==(that);
}
template<typename T>
inline bool Vector<T>::empty()
{
	return nSize == 0;
}
template<typename T>
inline T & Vector<T>::operator[](int index)
{
	return pbuff[index];//�����Խ��
}
//�ֶ��ͷ�
template<typename T>
inline void Vector<T>::clear()
{
	if (pbuff)
		delete[] pbuff;
	pbuff = nullptr;
	nSize = 0;
	nCapacity = 0;
}
template<typename T>
inline T & Vector<T>::at(int index)
{
	if (index >= 0 && index <= nSize)
		return pbuff[index];
	throw "Out of range";
}
//��������ĵ�һ��Ԫ��
template<typename T>
inline T & Vector<T>::front()
{
	if (pbuff)
		return pbuff[0];
	else
	{
		throw "Out_of_range";
	}
}
template<typename T>
inline T & Vector<T>::back()
{
	return buff[nSize - 1];
}
//β��ѹ��
template<typename T>
inline void Vector<T>::push_back(const T & elem)
{
	if (nSize == nCapacity)
	{
		reserve(int(1.5*nCapacity) + 1);//������,+1�Ƿ�ֹnCapacityΪ0
		pbuff[nSize] = elem;
		nSize++;
	}
	else
	{
		pbuff[nSize] = elem;
		nSize++;
	}
}
//����
template<typename T>
inline void Vector<T>::pop_back()
{
	if (!empty())
		nSize--;
}

//��������Vector�Ĵ�С�����������Ԫ��
template<typename T>
inline void Vector<T>::assgin(int n, const T & elem)
{
	clear();//�ȵ����ͷ�
	pbuff = new T[n];
	for (int i = 0; i < n; i++)
	{
		pbuff[i] = elem;
	}
	nSize = n;
	nCapacity = n;
}
//����������
template<typename T>
inline void Vector<T>::swap(Vector<T>& that)
{
	/*
	T* temp_pbuff = pbuff;
	int temp_nSize = nSize;
	int temp_nCapacity = nCapacity;
	pbuff = that.pbuff;
	nSize = that.nSize;
	nCapacity = that.nCapacity;
	//----
	that.pbuff = temp_pbuff;
	that.nSize = temp_nSize;
	that.nCapacity = temp_nCapacity;
	*/
	//���븴�ã��ʺϳ�Ա�����϶����
	Vector<T> temp;
	temp = *this;
	*this = that;
	that = temp;
}
//����Ԫ�ظ���
template<typename T>
inline int Vector<T>::size()
{
	return nSize;
}
//��������
template<typename T>
inline int Vector<T>::capacity()
{
	return nCapacity;
}

//���ݣ�ֻ����������
template<typename T>
inline void Vector<T>::reserve(int n)
{
	if (n > nSize)
	{
		T* tempbuff = new T[n];
		memcpy(tempbuff, pbuff, sizeof(T)*nSize);
		nCapacity = n;
		delete[] pbuff;
		pbuff = tempbuff;
	}
}
//���ݣ��ɸĴ�Ҳ�ɸ�С
template<typename T>
inline void Vector<T>::resize(int n)
{
	if (n > nSize)
	{
		reserve(n);
		memset(&pbuff[nSize], 0, sizeof(T)*(n - nSize));//��д�ɲ�д����Ҫ���˽�memset�ĳ�ʼ����ʽ
	}
	else
	{
		nSize = n;//�����ɶ�ȡ��Ԫ�ؾͱ�����ס�ˣ�������д���������������Ż�
	}
}
//���ݣ�ԭ����ֵ���䣬���ӵ�����Ϊ��ֵ
template<typename T>
inline void Vector<T>::resize(int n, const T & elem)
{
	resize(n);
	for (int i = nSize; i < n; i++)
	{
		pbuff[i] = elem;
	}
	nSize = n;
}
