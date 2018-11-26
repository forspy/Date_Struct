#pragma once
struct SqListStack
{
private:
	int* base;//栈底指针
	int* top;//栈顶指针
	int StackSize;//栈可使用的最大容量
public:
	bool IsEmpty();//判断栈空
	bool IsFull();//判断栈满
	void Push(int data);//压入
	int Pop();//弹出
	void StackClear();//清空栈内的所有元素
	void DestroyStack();//释放整个栈所占用的空间
	SqListStack(int Size=100);
};