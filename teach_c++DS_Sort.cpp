#include<iostream>
#include<vector>
#include<algorithm>//min,max头文件
#include<ctime>
using namespace std;
void PrintArr(int arr[], int Size);
void BubbleSort(int arr[], int size);
void BubbleSort_optimization(int arr[], int size);
void qsort(int arr[], int left, int right);//快速排序
void qsort_optimization(int* arr, int left, int right);//效率更高的快速排序
void BucketSort(int* arr, int Size);//桶排序
void InsertSort(int* arr, int Size);//插入排序
void ShellSort(int* arr, int Size);//希尔排序，插入排序的改进版，选择长度的分组插入排序
void SelectSort(int* arr, int Size);//选择排序
void MergeSort(int* arr, int left, int right);//归并排序
void Merge(int* arr, int left, int mid, int right);//合并，归并排序辅助函数
//函数指针来使用多个函数
typedef void(*funName)(int*, int);
void SortTime(int* arr, int Size, funName func);
typedef void(*funName1)(int*, int, int);
void SortTime(int* arr, int left, int right, funName1 func);//重载
int main()
{
	int arr[] = { 0,4,5,3,7,2,1,9,8,6 };
	int Size = sizeof(arr) / sizeof(arr[0]);
	//BubbleSort(arr, Size);
	//BubbleSort_optimization(arr, Size);
	//qsort(arr, 0, Size-1);//注意传入的是左右下标值，指向left和right
	//qsort_optimization(arr, 0, Size - 1);
	//BucketSort(arr, Size);  
	//InsertSort(arr, Size);
	//ShellSort(arr, Size);
	//SelectSort(arr, Size);
	//MergeSort(arr, 0, Size - 1);
	//PrintArr(arr, Size);
	const int len = 20000;
	int testArr[9][len] = { 0 };
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < len; j++)
		{
			testArr[i][j] = rand() % 1000;
		}
	}	
	cout << "qsort：";
	SortTime(testArr[0], 0, len - 1, qsort);//传入二维数组对应行数下标就相当于传入这一行的地址
	cout << "qsort_optimization:";
	SortTime(testArr[8], 0, len - 1, qsort_optimization);
	cout << "MergeSort：";
	SortTime(testArr[1], 0, len - 1, MergeSort);
	SortTime(testArr[2], len, BubbleSort);
	SortTime(testArr[3], len, BubbleSort_optimization);
	SortTime(testArr[4], len, BucketSort);
	SortTime(testArr[5], len, InsertSort);
	SortTime(testArr[6], len, ShellSort);
	SortTime(testArr[7], len, SelectSort);
	/*运行结果：
	qsort：21
	qsort_optimization:2
	MergeSort：256
	BubbleSort:9476
	BubbleSort_optimization:9428
	BucketSort:19
	InsertSort:236
	ShellSort:4
	SelectSort:1376
	*/
}
void PrintArr(int arr[],int Size)
{
	for (int i = 0; i < Size; i++)
		cout << arr[i] << " ";
	cout << endl;
}
//冒泡排序
//时间复杂度为O(n ^ 2）
void BubbleSort(int arr[],int size)
{
	for (int i = 0; i < size - 1; i++)//0-9
	{
		for (int j = 0; j < size - 1 - i; j++)//排过的就不用排了
		{
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
	cout << __func__ << ":";//用于打印这个函数的名字
}
//优化的冒泡排序O(n^2)
void BubbleSort_optimization(int arr[], int size)
{
	bool flag;
	for (int i = 0; i < size - 1; i++)//两个排一次就够了
	{
		flag = true;//对于已经排好序的就不用排了
		for (int j = 0; j < size - 1 - i; j++)//排过的就不用排了
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				flag = false;//交换了就说明还存在无序情况
			}
		}
		if (flag)//都有序了就跳过
			break;
	}
	cout << __func__ << ":";//用于打印这个函数的名字
}
//快速排序O(nlog2n)
void qsort(int arr[], int left, int right)//left和right为要排的范围
{
	int i, last;//i负责检索数组，Last负责指向最后一个有序的元素
	if (left < right)//两个要排，一个就不用排了
	{
		last = left;//设置头一个为标准
		for (i = left + 1; i <= right; i++)//注意这里要取到right
		{
			if (arr[i] < arr[left])//last表示当前有序的后面一个,这样就把后面一个也排为有序了
			{
				last++;//先让Last移动到有序的后一位准备交换
				swap(arr[last], arr[i]);//last指向要大于中间值的那些数，让他们和小于中间值的数交换位置
			}
		}
		swap(arr[left], arr[last]);//将Left与Last对换得到一组有序的数，中间为Last，而Last的左边都比Last小，Last的右边都比Last大，
								   //接下来递归对[left,Last-1]和[Last+1，right]递归即可
		qsort(arr, left, last - 1);
		qsort(arr, last + 1, right);
	}
	//cout << __func__ << ":";//用于打印这个函数的名字,递归的不能打印名字
}
//效率更高的快速排序，避免了交换产生的时间
//时间复杂度为O(nlog2n)
void qsort_optimization(int * arr, int left, int right)
{
	if (left < right)
	{
		int i, j, p;
		i = left;
		j = right;
		p = arr[i];//选取第一个元素作为基准值，并保存

		while (i < j)//只要两个指示没相遇就继续寻找
		{
			while (i<j&&arr[j]>p)//从右往左找，要么相遇，要么找到第一个小于基准的数
			{
				j--;//符合要求继续搜索
			}
			if (i < j)
			{
				arr[i] = arr[j];//把小于基准的数放在左边
				i++;//然后左边标向右移动一位
			}
			while (i<j&&arr[i]<p)//找到一个右边就换左边，找到一个左边就换右边这样连续的换就能形成有序
			{
				i++;
			}
			if (i < j)
			{
				arr[j] = arr[i];
				j--;//然后右边标向左移动一位准备换右边比较
			}
		}
		arr[i] = p;//相遇了，把基准值赋进去
		qsort_optimization(arr, left, i - 1);
		qsort_optimization(arr, i + 1, right);
	}
}
//O(n+k)
void BucketSort(int * arr, int Size)
{
	vector<int> v(Size, 0);//创建Size个元素为0的数组Vector
	//遍历数组
	for (int i = 0; i < Size ; i++)
	{
		v[arr[i]]++;
	}
	//因为已经排好序了，输出vector里元素次数的下标
	for (int i = 0,j=0; i < Size; i++)
	{
		while (v[i]--)
		{
			arr[j] = i;
			j++;
		}	
	}
	cout << __func__ << ":";//用于打印这个函数的名字
}
//插入排序，将待排的元素依次插入已经排好的序列中
//时间复杂度为O(n^2)
void InsertSort(int * arr, int Size)//O(n^2)
{
	int temp;
	int j;
	for (int i = 1; i < Size; i++)
	{
		temp = arr[i];
		j = i - 1;//表示排好序的最后一位
		while (j >= 0 && arr[j] > temp)
		{
			arr[j + 1] = arr[j];
			j--;//指向前移
		}
		arr[j + 1] = temp;
	}
	cout << __func__ << ":";//用于打印这个函数的名字
}
//希尔排序O(n^1.3)
void ShellSort(int * arr, int Size)
{
	int temp;
	int j;
	//gap为步长,步长逐渐缩小，先排较远的，快速减少无序情况
	for (int gap = Size / 2; gap > 0; gap /= 2)//每次隔着gap个比较	
	{
		for (int i = gap; i < Size; i++)//排gap组
		{
			temp = arr[i];
			j = i - gap;//表示排好序隔着gap个的最后一位
			while (j >= 0 && arr[j] > temp)
			{
				arr[j + gap] = arr[j];
				j-=gap;//指向前移
			}
			arr[j + gap] = temp;
		}
	}
	cout << __func__ << ":";//用于打印这个函数的名字
}
//选择排序，选择最小的一个数插入到数组尾部
//时间复杂度为O(n^2）
void SelectSort(int * arr, int Size)
{
	for (int i = 0; i < Size; i++)//有序区
	{
		for (int j = i + 1; j < Size; j++)//这样内循环保证在无序区找到一个最小的换给i
		{
			if (arr[i] > arr[j])
				swap(arr[i], arr[j]);
		}
	}
	cout << __func__ << ":";//用于打印这个函数的名字
}
//归并排序O(nlog2n)
void MergeSort(int * arr, int left, int right)
{
	if (left < right)//递归分割
	{
		int mid = (left + right) / 2;//分割
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		Merge(arr, left, mid, right);
	}
	
}
//合并（有序的才能合并，所以对于归并排序，必须拆分到最小）
void Merge(int * arr, int left, int mid, int right)
{
	int low = left;//左半部分起始
	int hight = mid + 1;//右半部分起始
	int lenght = right - left + 1;
	vector<int> temp(lenght);//另开一个数组，用于存放
	int index = 0;//辅助数组的下标
	while (low <= mid&&hight <= right)
	{
		//挑选两部分中最小的元素放到temp数组中
		if (arr[low] < arr[hight])
		{
			temp[index++] = arr[low++];
		}
		else
		{
			temp[index++] = arr[hight++];
		}
	}
	//如果有剩余部分，把剩余部分放进temp数组
	while (low <= mid)//如果左边有剩余
		temp[index++] = arr[low++];
	while (hight <= right)//如果右边有剩余
		temp[index++] = arr[hight++];
	//更新原来的数组
	for (int i = 0; i < lenght; i++)
	{
		arr[left + i] = temp[i];
	}
}
//使用函数指针来调用多个函数,比较各个排序算法的运行时间
void SortTime(int * arr, int Size, funName func)
{
	clock_t start, end;
	start = clock();
	func(arr, Size);
	end = clock();
	cout << (end - start) << endl;
}

void SortTime(int * arr, int left, int right, funName1 func)
{
	clock_t start, end;
	start = clock();
	func(arr, left,right);
	end = clock();
	cout << (end - start) << endl;
}
