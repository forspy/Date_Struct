#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
//ʵ�����һ����������ַ��������������
int strindex(char source[], char searchfor[]);
char line[] = "would you please";
char pattern[] = "you";

int main()
{
	//printf("%s", line);
	if (strindex(line, pattern) >= 0)
	{
		printf("%s\n", line);
	}
	//��Ȼʹ��string���е�find����Ҳ���ҵ���KMP������
	string a = "would you please";
	cout << a.find("you") << endl;//����λ�ã����û�в鵽������0
}
//һ���൱�����BP�㷨
int strindex(char source[], char searchfor[])
{
	int i, j, k;
	for (i = 0; source[i] != '\0'; i++)//i������Դ�ַ����б���
	{
		//j�����ڴ�iλ��ʼ����Դ�ַ�����k���ڷ�����ͷ��ʼ����Ҫ�������ַ���
		for (j = i, k = 0; source[j] == searchfor[k] && searchfor[k] != '\0'; j++, k++)
			;
		if (searchfor[k] == '\0'&&k > 0)//����������˳�forѭ����ʱ��K�ַ���������β����˵��ƥ��ɹ�
		{
			printf("�ӵ�%d����ƥ��ɹ�\n",i);
			return i;//�൱������/
		}
	}
	printf("û��ƥ�䵽\n");
	return -1;
	
}