#pragma once
#include<memory>//allocator池化操作
using namespace  std;
//声明list节点
template<typename T>
struct Node
{
	Node* prev;
	Node* next;
	T     data;
};

//list迭代器,支持一些运算,封装了指向节点的指针head
template<typename T>
class Iterator
{
public:
	//typedef Iterator<T> self;
	//typedef Node<T>* link_type;//表示指向节点类型
	//link_type node;//表示是一个头指针，因为是环状的所以不需要尾指针 
	Node<T>* head;//表示是一个头指针，因为是环状的所以不需要尾指针 
	Iterator(Node<T>* p=nullptr):head(p){ }
	Iterator(const Iterator<T>& that):head(that.head){ }//拷贝构造	
	//迭代器的运算符重载
	bool operator==(const Iterator<T>& that);
	bool operator!=(const Iterator<T>& that);
	T& operator*();//解引用,注意是对this迭代器对象的解引用
	T* operator->();//取地址
	Iterator<T>& operator++();//前++
	Iterator<T> operator++(int);//后++,哑元
	Iterator<T>& operator--();//前--
	Iterator<T> operator--(int);//后--
};

template<typename T>
class List
{
protected:
	typedef Node<T> list_node;
	typedef Node<T>* link_type;
	typedef T* pointer;
	typedef T value_type;
	
	//这里使用空间配置器来生成节点
	/*
	空间适配器使用（池化操作） 内存池实现小块内存的分配机制
	内存池是分配好的一块大内存，如果需要就建立链接，不需要就断开链接
	实现原理：
	一级空间配置器  直接封装了malloc free 对于需要空间较小
	二级空间配机器  调用内存池 自由链表 （对于用户申请内存超过128字节采用二级空间配置器）
	设计模式： 适配器模式 单例模式 享元模式
	*/
	allocator<Node<T>> node_allocator;
protected://写在protected里面可以被公有继承的派生类访问
	//只要一个节点指针可以表示整个list
	Node<T>* head;
	//空间配置器生成节点的方法CraatNewNode
	Node<T>* AllocNode() { return node_allocator.allocate(sizeof(Node<T>)); }
	//生成一个节点并赋值
	Node<T>* AllocNodeElem(const T& value)
	{
		//分配节点空间
		Node<T>* p = AllocNode();
		//构造节点内容
		node_allocator.construct(&(p->data), value);
		return p;
	}
	//释放一个节点 ,断开链接
	void DeAllocNode(Node<T>* p) { node_allocator.deallocate(p); }//
	//释放节点并节点里面数据域的元素
	void DestroyNode(Node<T>* p)
	{
		node_allocator.destroy(p->data);
		DeAllocNode(p);
	}
	void EmptyInit()//空的时候初始化
	{
		head = AllocNode();
		head->next = head;
		head->prev = head;
	}
public:
	typedef Iterator<T> iterator;
	List() { EmptyInit(); }
	
	//迭代器操作
	Iterator<T> begin() { return head->next; }//头节点的下一个节点（有头节点模式） 
	//（利用了构造函数的隐式转换 比如 A a=10; 其实是A a=A（10）; 这里return的时候会隐式转换,利用Iterator构造函数Iterator(head->next)）
	Iterator<T> begin()const { return head->next; }//头节点的下一个节点（有头节点模式）
	Iterator<T> end() { return head; }
	Iterator<T> end()const { return head; }
	bool Empty(){ return head->next == head; }
	void insert(Iterator<T> pos, const T& value)//指定位置插入
	{
		//先创建一个节点
		Node<T>* temp = AllocNodeElem(value);
		//寻找位置插入pos位置之前插入，前插
		temp->next = pos.head;
		temp->prev = pos.head->prev;
		pos.head->prev->next = temp;
		pos.head->prev = temp;
	}
	void push_back(const T& value)//尾插
	{
		insert(end(), value);
	}
};

//运算符重载
template<typename T>
inline bool Iterator<T>::operator==(const Iterator<T>& that)
{
	return head == that.head;
}

template<typename T>
inline bool Iterator<T>::operator!=(const Iterator<T>& that)
{
	return head != that.head;
}
//解引用
template<typename T>
inline T& Iterator<T>::operator*()//尽量返回&类型，避免T类型可能出现的浅拷贝
{
	return this->head->data;
}

template<typename T>
inline T * Iterator<T>::operator->()
{
	return &(operator*());//取得数据域的地址 
}
//前++
template<typename T>
inline Iterator<T>& Iterator<T>::operator++()
{
	//指向下一个节点
	head = head->next;
	return *this;
}
//后++	
template<typename T>
inline Iterator<T> Iterator<T>::operator++(int)//返回的是一个局部变量，所以不能引用
{
	Iterator<T> temp;
	temp = *this;
	++(*this);//实际是++了的
	return temp;//返回的是没++的
}
//前--
template<typename T>
inline Iterator<T>& Iterator<T>::operator--()
{
	head = head->prev;//指向前一个节点
	return *this;
}
//后--
template<typename T>
inline Iterator<T> Iterator<T>::operator--(int)
{
	Iterator<T> temp;
	temp = *this;
	--(*this);
	return temp;
}

