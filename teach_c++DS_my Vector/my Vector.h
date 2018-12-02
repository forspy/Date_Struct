#pragma once
#include<iostream>
using namespace std;
template <typename T>
class Vector
{
private:
	T* pbuff;//动态数组首地址
	int nSize;//动态数组元素个数,注意是个数从1开始
	int nCapacity;//动态数组最大长度
public://注意在main里面要使用，所以需要声明在public里面
	typedef T* iterator;//迭代器就是元素指针
	typedef const T* const_iterator;//常迭代器，对应常元素和常对象
	//迭代器成员函数(方法)
	iterator begin() { return pbuff; }//&pbuff[0]也可以
	iterator end() { return pbuff + nSize; }//最后一个元素的后一个元素位置
	const_iterator begin()const{ return pbuff; }
	const_iterator end()const{ return pbuff + nSize; }
public:
	explicit Vector(int size = 0);//防止=隐式转换
	//重载构造函数
	Vector(int size,const T&elem);//加引用是为了防止当T是类类型的时候产生拷贝构造，所以直接引用最恰当
	//拷贝构造
	Vector(const Vector<T>& that);
	~Vector();
	//运算符重载----
	Vector<T>& operator=(const Vector<T>& that);//=重载
	//逻辑判断
	bool operator==(const Vector<T>&that);//==判断
	bool operator!=(const Vector<T>&that);//!=判断
	bool empty();//判空
	T& operator[](int index);//返回下标位置的值，不会检查越界
	//-------
	//vector方法
	void assgin(int n, const T& elem);//重新设置个数和元素
	void swap(Vector<T>& that);
	int size();//返回Vector元素个数（实际容量）
	int capacity();//返回Vector最大容量（最大容量）
	void reserve(int n);//扩容到n个（指的是capacity）
	void resize(int n);//扩容到n个
	void resize(int n, const T& elem);//扩容为size，原来的元素不变，新扩容的元素变为elem
	void clear();//随时destroy Vector容器数组
	T& at(int index);//返回下标位置的值，会检查越界，如果越界会抛出Out_of_range
	T& front();//返回第一个元素
	T& back();//返回最后一个元素
	void push_back(const T&elem);//尾插法
	void pop_back();//弹出最后一个元素

	//友元函数
	friend void swap(Vector<T>&v1, Vector<T>&v2) { v1.swap(v2) };
};
//单参构造
template<typename T>
inline Vector<T>::Vector(int size)
{
	pbuff = new T[size];
	memset(pbuff, 0, sizeof(T)*size);
	nSize = size;
	nCapacity = size;//是size不够了才去扩充为1.5倍
}
//双参构造
template<typename T>
Vector<T>::Vector(int size,const T& elem)
{
	pbuff = new T[size];
	for (int i = 0; i < size; i++)
	{
		pbuff[i] = elem;
	}
	nSize = size;
	nCapacity = size;//是size不够了才去扩充为1.5倍
}
//拷贝构造
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
//析构函数
template<typename T>
inline Vector<T>::~Vector()
{
	delete[] pbuff;
}
//重载=
template<typename T>
inline Vector<T>& Vector<T>::operator=(const Vector<T>& that)
{
	//1.判断自相等
	if (this != &that)
	{
		//2.释放旧资源
		delete[] pbuff;
		//3.开辟新内存
		pbuff = new T[that.nCapacity];
		memcpy(pbuff, that.pbuff, sizeof(T)*nSize);
		nSize = that.nSize;
		nCapacity = that.nCapacity;
	}
	return *this;
}
//重载逻辑判断==,判断数组每个元素都相等
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
	return pbuff[index];//不检查越界
}
//手动释放
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
//返回数组的第一个元素
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
//尾部压入
template<typename T>
inline void Vector<T>::push_back(const T & elem)
{
	if (nSize == nCapacity)
	{
		reserve(int(1.5*nCapacity) + 1);//先扩容,+1是防止nCapacity为0
		pbuff[nSize] = elem;
		nSize++;
	}
	else
	{
		pbuff[nSize] = elem;
		nSize++;
	}
}
//弹出
template<typename T>
inline void Vector<T>::pop_back()
{
	if (!empty())
		nSize--;
}

//重新设置Vector的大小和里面的数组元素
template<typename T>
inline void Vector<T>::assgin(int n, const T & elem)
{
	clear();//先调用释放
	pbuff = new T[n];
	for (int i = 0; i < n; i++)
	{
		pbuff[i] = elem;
	}
	nSize = n;
	nCapacity = n;
}
//方法：交换
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
	//代码复用，适合成员变量较多的类
	Vector<T> temp;
	temp = *this;
	*this = that;
	that = temp;
}
//返回元素个数
template<typename T>
inline int Vector<T>::size()
{
	return nSize;
}
//返回容量
template<typename T>
inline int Vector<T>::capacity()
{
	return nCapacity;
}

//扩容：只能往大了扩
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
//扩容：可改大也可改小
template<typename T>
inline void Vector<T>::resize(int n)
{
	if (n > nSize)
	{
		reserve(n);
		memset(&pbuff[nSize], 0, sizeof(T)*(n - nSize));//可写可不写，主要是了解memset的初始化方式
	}
	else
	{
		nSize = n;//这样可读取的元素就被限制住了，但这样写会留下隐患，待优化
	}
}
//扩容，原来的值不变，增加的容量为新值
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
