#pragma once
#include<memory>//allocator�ػ�����
using namespace  std;
//����list�ڵ�
template<typename T>
struct Node
{
	Node* prev;
	Node* next;
	T     data;
};

//list������,֧��һЩ����,��װ��ָ��ڵ��ָ��head
template<typename T>
class Iterator
{
public:
	//typedef Iterator<T> self;
	//typedef Node<T>* link_type;//��ʾָ��ڵ�����
	//link_type node;//��ʾ��һ��ͷָ�룬��Ϊ�ǻ�״�����Բ���Ҫβָ�� 
	Node<T>* head;//��ʾ��һ��ͷָ�룬��Ϊ�ǻ�״�����Բ���Ҫβָ�� 
	Iterator(Node<T>* p=nullptr):head(p){ }
	Iterator(const Iterator<T>& that):head(that.head){ }//��������	
	//�����������������
	bool operator==(const Iterator<T>& that);
	bool operator!=(const Iterator<T>& that);
	T& operator*();//������,ע���Ƕ�this����������Ľ�����
	T* operator->();//ȡ��ַ
	Iterator<T>& operator++();//ǰ++
	Iterator<T> operator++(int);//��++,��Ԫ
	Iterator<T>& operator--();//ǰ--
	Iterator<T> operator--(int);//��--
};

template<typename T>
class List
{
protected:
	typedef Node<T> list_node;
	typedef Node<T>* link_type;
	typedef T* pointer;
	typedef T value_type;
	
	//����ʹ�ÿռ������������ɽڵ�
	/*
	�ռ�������ʹ�ã��ػ������� �ڴ��ʵ��С���ڴ�ķ������
	�ڴ���Ƿ���õ�һ����ڴ棬�����Ҫ�ͽ������ӣ�����Ҫ�ͶϿ�����
	ʵ��ԭ��
	һ���ռ�������  ֱ�ӷ�װ��malloc free ������Ҫ�ռ��С
	�����ռ������  �����ڴ�� �������� �������û������ڴ泬��128�ֽڲ��ö����ռ���������
	���ģʽ�� ������ģʽ ����ģʽ ��Ԫģʽ
	*/
	allocator<Node<T>> node_allocator;
protected://д��protected������Ա����м̳е����������
	//ֻҪһ���ڵ�ָ����Ա�ʾ����list
	Node<T>* head;
	//�ռ����������ɽڵ�ķ���CraatNewNode
	Node<T>* AllocNode() { return node_allocator.allocate(sizeof(Node<T>)); }
	//����һ���ڵ㲢��ֵ
	Node<T>* AllocNodeElem(const T& value)
	{
		//����ڵ�ռ�
		Node<T>* p = AllocNode();
		//����ڵ�����
		node_allocator.construct(&(p->data), value);
		return p;
	}
	//�ͷ�һ���ڵ� ,�Ͽ�����
	void DeAllocNode(Node<T>* p) { node_allocator.deallocate(p); }//
	//�ͷŽڵ㲢�ڵ������������Ԫ��
	void DestroyNode(Node<T>* p)
	{
		node_allocator.destroy(p->data);
		DeAllocNode(p);
	}
	void EmptyInit()//�յ�ʱ���ʼ��
	{
		head = AllocNode();
		head->next = head;
		head->prev = head;
	}
public:
	typedef Iterator<T> iterator;
	List() { EmptyInit(); }
	
	//����������
	Iterator<T> begin() { return head->next; }//ͷ�ڵ����һ���ڵ㣨��ͷ�ڵ�ģʽ�� 
	//�������˹��캯������ʽת�� ���� A a=10; ��ʵ��A a=A��10��; ����return��ʱ�����ʽת��,����Iterator���캯��Iterator(head->next)��
	Iterator<T> begin()const { return head->next; }//ͷ�ڵ����һ���ڵ㣨��ͷ�ڵ�ģʽ��
	Iterator<T> end() { return head; }
	Iterator<T> end()const { return head; }
	bool Empty(){ return head->next == head; }
	void insert(Iterator<T> pos, const T& value)//ָ��λ�ò���
	{
		//�ȴ���һ���ڵ�
		Node<T>* temp = AllocNodeElem(value);
		//Ѱ��λ�ò���posλ��֮ǰ���룬ǰ��
		temp->next = pos.head;
		temp->prev = pos.head->prev;
		pos.head->prev->next = temp;
		pos.head->prev = temp;
	}
	void push_back(const T& value)//β��
	{
		insert(end(), value);
	}
};

//���������
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
//������
template<typename T>
inline T& Iterator<T>::operator*()//��������&���ͣ�����T���Ϳ��ܳ��ֵ�ǳ����
{
	return this->head->data;
}

template<typename T>
inline T * Iterator<T>::operator->()
{
	return &(operator*());//ȡ��������ĵ�ַ 
}
//ǰ++
template<typename T>
inline Iterator<T>& Iterator<T>::operator++()
{
	//ָ����һ���ڵ�
	head = head->next;
	return *this;
}
//��++	
template<typename T>
inline Iterator<T> Iterator<T>::operator++(int)//���ص���һ���ֲ����������Բ�������
{
	Iterator<T> temp;
	temp = *this;
	++(*this);//ʵ����++�˵�
	return temp;//���ص���û++��
}
//ǰ--
template<typename T>
inline Iterator<T>& Iterator<T>::operator--()
{
	head = head->prev;//ָ��ǰһ���ڵ�
	return *this;
}
//��--
template<typename T>
inline Iterator<T> Iterator<T>::operator--(int)
{
	Iterator<T> temp;
	temp = *this;
	--(*this);
	return temp;
}

