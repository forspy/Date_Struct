//�Ѵ�����
#include <iostream>
#include <assert.h>
#include <math.h>
#include "xcept.h"

using namespace std;

//Type ���ͱ�����key��Ա�������������������������������㣡
template <class Type>
class MinPQ
{
public:
	virtual int Insert(const Type &) = 0;
	virtual int RemoveMin(Type &) = 0;
};

template <class Type>
class MinHeap :public MinPQ<Type>
{
public:
	MinHeap(int maxsize = DefaultSize);
	MinHeap(Type arr[], int n);
	MinHeap(const MinHeap<Type> &R);
	~MinHeap(){ delete[]heap; }
	void operator =(const MinHeap<Type> &R);
	int Insert(const Type &x);
	int RemoveMin(Type &x);
	int IsEmpty() const { return currentsize == 0; }
	int IsFull() const { return currentsize == maxheapsize; }
	void MakeEmpty(){ currentsize = 0; }
	void Display();//����ʱʹ��
private:
	enum { DefaultSize = 10 };
	Type *heap;
	int currentsize;
	int maxheapsize;
	void FilterDown(const int start, const int endofheap);    //��i��m���½��е�����Ϊ��С��
	void FilterUp(int start);                               //��i��m�Ե����Ͻ��е�����Ϊ��С�� 
};

template <class Type>
MinHeap<Type>::MinHeap(int maxsize)
{
	maxheapsize = DefaultSize<maxsize ? maxsize : DefaultSize;
	heap = new Type[maxheapsize];
	assert(heap);
	currentsize = 0;
}

template <class Type>
MinHeap<Type>::MinHeap(Type arr[], int n)
{
	maxheapsize = DefaultSize<n ? n : DefaultSize;
	heap = new Type[maxheapsize];
	assert(heap);
	for (int i = 0; i<n; i++)
		heap[i] = arr[i];
	currentsize = n;
	int currentpos = (currentsize - 2) / 2;
	while (currentpos >= 0)
	{
		FilterDown(currentpos, currentsize - 1);
		currentpos--;
	}
}

template <class Type>
MinHeap<Type>::MinHeap(const MinHeap<Type> &R)
{
	heap = new Type[1];
	*this = R;
}

template <class Type>
void MinHeap<Type>::operator =(const MinHeap<Type> &R)
{
	maxheapsize = R.maxheapsize;
	delete[]heap;
	heap = new Type[maxheapsize];
	assert(heap);
	currentsize = R.currentsize;
	for (int i = 0; i<currentsize; i++)
		heap[i] = R.heap[i];
	return;
}
template <class Type>
void MinHeap<Type>::FilterDown(const int start, const int endofheap)
{
	int i = start, j = 2 * i + 1;
	Type temp = heap[i];
	while (j <= endofheap)
	{
		if (j<endofheap&&heap[j].key>heap[j + 1].key)
			j++;                    // heap[].key �ؼ���
		if (temp.key <= heap[j].key)
			break;
		else
		{
			heap[i] = heap[j];
			i = j;
			j = 2 * i + 1;
		}
		heap[i] = temp;
	}
}

template <class Type>
void MinHeap<Type>::FilterUp(int start)
{
	int j = start, i = (j - 1) / 2;
	Type temp = heap[j];
	while (j>0)
	{
		if (heap[i].key<temp.key)        // heap[].key �ؼ��룬
			break;
		else
		{
			heap[j] = heap[i];
			j = i;
			i = (j - 1) / 2;
		}
	}
	heap[j] = temp;
}

template <class Type>
int MinHeap<Type>::Insert(const Type &x)
{
	if (currentsize == maxheapsize)
	{

		cerr << "������!\n";
		return 0;
	}
	heap[currentsize] = x;
	FilterUp(currentsize);
	currentsize++;
	return 1;
}

template <class Type>
int MinHeap<Type>::RemoveMin(Type &x)
{
	if (!currentsize)
	{
		//throw OutOfBounds();
		cerr << "�ѿ�!\n";
		return 0;
	}
	x = heap[0];
	heap[0] = heap[currentsize - 1];
	currentsize--;
	FilterDown(0, currentsize - 1);
	return 1;
}
template <class Type>
void MinHeap<Type>::Display()
{
	for (int i = 0; i<currentsize; i++)
		cout << heap[i] << ' ';
	cout << endl;
}



