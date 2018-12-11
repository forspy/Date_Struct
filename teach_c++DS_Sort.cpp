#include<iostream>
#include<vector>
#include<algorithm>//min,maxͷ�ļ�
#include<ctime>
using namespace std;
void PrintArr(int arr[], int Size);
void BubbleSort(int arr[], int size);
void BubbleSort_optimization(int arr[], int size);
void qsort(int arr[], int left, int right);//��������
void qsort_optimization(int* arr, int left, int right);//Ч�ʸ��ߵĿ�������
void BucketSort(int* arr, int Size);//Ͱ����
void InsertSort(int* arr, int Size);//��������
void ShellSort(int* arr, int Size);//ϣ�����򣬲�������ĸĽ��棬ѡ�񳤶ȵķ����������
void SelectSort(int* arr, int Size);//ѡ������
void MergeSort(int* arr, int left, int right);//�鲢����
void Merge(int* arr, int left, int mid, int right);//�ϲ����鲢����������
//����ָ����ʹ�ö������
typedef void(*funName)(int*, int);
void SortTime(int* arr, int Size, funName func);
typedef void(*funName1)(int*, int, int);
void SortTime(int* arr, int left, int right, funName1 func);//����
int main()
{
	int arr[] = { 0,4,5,3,7,2,1,9,8,6 };
	int Size = sizeof(arr) / sizeof(arr[0]);
	//BubbleSort(arr, Size);
	//BubbleSort_optimization(arr, Size);
	//qsort(arr, 0, Size-1);//ע�⴫����������±�ֵ��ָ��left��right
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
	cout << "qsort��";
	SortTime(testArr[0], 0, len - 1, qsort);//�����ά�����Ӧ�����±���൱�ڴ�����һ�еĵ�ַ
	cout << "qsort_optimization:";
	SortTime(testArr[8], 0, len - 1, qsort_optimization);
	cout << "MergeSort��";
	SortTime(testArr[1], 0, len - 1, MergeSort);
	SortTime(testArr[2], len, BubbleSort);
	SortTime(testArr[3], len, BubbleSort_optimization);
	SortTime(testArr[4], len, BucketSort);
	SortTime(testArr[5], len, InsertSort);
	SortTime(testArr[6], len, ShellSort);
	SortTime(testArr[7], len, SelectSort);
	/*���н����
	qsort��21
	qsort_optimization:2
	MergeSort��256
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
//ð������
void BubbleSort(int arr[],int size)
{
	for (int i = 0; i < size - 1; i++)//0-9
	{
		for (int j = 0; j < size - 1 - i; j++)//�Ź��ľͲ�������
		{
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
	cout << __func__ << ":";//���ڴ�ӡ�������������
}
//�Ż���ð������
void BubbleSort_optimization(int arr[], int size)
{
	bool flag;
	for (int i = 0; i < size - 1; i++)//������һ�ξ͹���
	{
		flag = true;//�����Ѿ��ź���ľͲ�������
		for (int j = 0; j < size - 1 - i; j++)//�Ź��ľͲ�������
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				flag = false;//�����˾�˵���������������
			}
		}
		if (flag)//�������˾�����
			break;
	}
	cout << __func__ << ":";//���ڴ�ӡ�������������
}
//��������
void qsort(int arr[], int left, int right)//left��rightΪҪ�ŵķ�Χ
{
	int i, last;//i����������飬Last����ָ�����һ�������Ԫ��
	if (left < right)//����Ҫ�ţ�һ���Ͳ�������
	{
		last = left;//����ͷһ��Ϊ��׼
		for (i = left + 1; i <= right; i++)//ע������Ҫȡ��right
		{
			if (arr[i] < arr[left])//last��ʾ��ǰ����ĺ���һ��,�����ͰѺ���һ��Ҳ��Ϊ������
			{
				last++;//����Last�ƶ�������ĺ�һλ׼������
				swap(arr[last], arr[i]);//lastָ��Ҫ�����м�ֵ����Щ���������Ǻ�С���м�ֵ��������λ��
			}
		}
		swap(arr[left], arr[last]);//��Left��Last�Ի��õ�һ������������м�ΪLast����Last����߶���LastС��Last���ұ߶���Last��
								   //�������ݹ��[left,Last-1]��[Last+1��right]�ݹ鼴��
		qsort(arr, left, last - 1);
		qsort(arr, last + 1, right);
	}
	//cout << __func__ << ":";//���ڴ�ӡ�������������,�ݹ�Ĳ��ܴ�ӡ����
}
//Ч�ʸ��ߵĿ������򣬱����˽���������ʱ��
void qsort_optimization(int * arr, int left, int right)
{
	if (left < right)
	{
		int i, j, p;
		i = left;
		j = right;
		p = arr[i];//ѡȡ��һ��Ԫ����Ϊ��׼ֵ��������

		while (i < j)//ֻҪ����ָʾû�����ͼ���Ѱ��
		{
			while (i<j&&arr[j]>p)//���������ң�Ҫô������Ҫô�ҵ���һ��С�ڻ�׼����
			{
				j--;//����Ҫ���������
			}
			if (i < j)
			{
				arr[i] = arr[j];//��С�ڻ�׼�����������
				i++;//Ȼ����߱������ƶ�һλ
			}
			while (i<j&&arr[i]<p)//�ҵ�һ���ұ߾ͻ���ߣ��ҵ�һ����߾ͻ��ұ����������Ļ������γ�����
			{
				i++;
			}
			if (i < j)
			{
				arr[j] = arr[i];
				j--;//Ȼ���ұ߱������ƶ�һλ׼�����ұ߱Ƚ�
			}
		}
		arr[i] = p;//�����ˣ��ѻ�׼ֵ����ȥ
		qsort_optimization(arr, left, i - 1);
		qsort_optimization(arr, i + 1, right);
	}
}

void BucketSort(int * arr, int Size)
{
	vector<int> v(Size, 0);//����Size��Ԫ��Ϊ0������Vector
	//��������
	for (int i = 0; i < Size ; i++)
	{
		v[arr[i]]++;
	}
	//��Ϊ�Ѿ��ź����ˣ����vector��Ԫ�ش������±�
	for (int i = 0,j=0; i < Size; i++)
	{
		while (v[i]--)
		{
			arr[j] = i;
			j++;
		}	
	}
	cout << __func__ << ":";//���ڴ�ӡ�������������
}
//�������򣬽����ŵ�Ԫ�����β����Ѿ��źõ�������
void InsertSort(int * arr, int Size)//O(n^2)
{
	int temp;
	int j;
	for (int i = 1; i < Size; i++)
	{
		temp = arr[i];
		j = i - 1;//��ʾ�ź�������һλ
		while (j >= 0 && arr[j] > temp)
		{
			arr[j + 1] = arr[j];
			j--;//ָ��ǰ��
		}
		arr[j + 1] = temp;
	}
	cout << __func__ << ":";//���ڴ�ӡ�������������
}
//ϣ������
void ShellSort(int * arr, int Size)
{
	int temp;
	int j;
	//gapΪ����,��������С�����Ž�Զ�ģ����ټ����������
	for (int gap = Size / 2; gap > 0; gap /= 2)//ÿ�θ���gap���Ƚ�	
	{
		for (int i = gap; i < Size; i++)//��gap��
		{
			temp = arr[i];
			j = i - gap;//��ʾ�ź������gap�������һλ
			while (j >= 0 && arr[j] > temp)
			{
				arr[j + gap] = arr[j];
				j-=gap;//ָ��ǰ��
			}
			arr[j + gap] = temp;
		}
	}
	cout << __func__ << ":";//���ڴ�ӡ�������������
}
//ѡ������ѡ����С��һ�������뵽����β��
void SelectSort(int * arr, int Size)
{
	for (int i = 0; i < Size; i++)//������
	{
		for (int j = i + 1; j < Size; j++)//������ѭ����֤���������ҵ�һ����С�Ļ���i
		{
			if (arr[i] > arr[j])
				swap(arr[i], arr[j]);
		}
	}
	cout << __func__ << ":";//���ڴ�ӡ�������������
}
//�鲢����
void MergeSort(int * arr, int left, int right)
{
	if (left < right)//�ݹ�ָ�
	{
		int mid = (left + right) / 2;//�ָ�
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		Merge(arr, left, mid, right);
	}
	
}
//�ϲ�������Ĳ��ܺϲ������Զ��ڹ鲢���򣬱����ֵ���С��
void Merge(int * arr, int left, int mid, int right)
{
	int low = left;//��벿����ʼ
	int hight = mid + 1;//�Ұ벿����ʼ
	int lenght = right - left + 1;
	vector<int> temp(lenght);//��һ�����飬���ڴ��
	int index = 0;//����������±�
	while (low <= mid&&hight <= right)
	{
		//��ѡ����������С��Ԫ�طŵ�temp������
		if (arr[low] < arr[hight])
		{
			temp[index++] = arr[low++];
		}
		else
		{
			temp[index++] = arr[hight++];
		}
	}
	//�����ʣ�ಿ�֣���ʣ�ಿ�ַŽ�temp����
	while (low <= mid)//��������ʣ��
		temp[index++] = arr[low++];
	while (hight <= right)//����ұ���ʣ��
		temp[index++] = arr[hight++];
	//����ԭ��������
	for (int i = 0; i < lenght; i++)
	{
		arr[left + i] = temp[i];
	}
}
//ʹ�ú���ָ�������ö������,�Ƚϸ��������㷨������ʱ��
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
