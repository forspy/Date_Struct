#pragma once
#include<iostream>
#include<string>
using namespace std;
struct DoubNode
{
	DoubNode* prior;//ǰָ��
	string name;
	DoubNode* next;//��ָ��
};
//��Ϊ��˫���������Լ���ͷβָ�������
typedef DoubNode* DoubHeadNode;
typedef DoubNode* DoubRearNode;
//˫��ѭ������:��ѭ�������е�����һ���ڵ�λ�ö������ҵ������ڵ�

/*
ǰָ��priorָ��ǰһ���ڵ㣬��ָ��nextָ���һ���ڵ�
Ҫ�����нڵ��������޽ڵ�������1�нڵ��������ĸ�����2.�޽ڵ���������������
��ָ��λ�ò���ʱҪ��������˳��
*/
//��ѭ��˫��������ͷ�ڵ�ģʽ

//����һ���½ڵ�
DoubNode* CreatNewNode(const string& str);
//ͷ������ڵ�
void InsertHead(DoubHeadNode& head, DoubRearNode& rear,const string& str);
//β������һ���ڵ�
void InsertRear(DoubHeadNode& head, DoubRearNode& rear, const string& str);
//ָ��λ�ò���
void InsertPos(DoubHeadNode& head, int pos, const string& str);//�����ͷָ���λ��
//ָ��λ��ɾ��
void DelPos(DoubHeadNode& head, int pos);//�����ͷָ���λ��
//����ָ��λ�õĽڵ���Ϣ
void FindDoubList(DoubHeadNode& head, int pos);
//�ı�ָ��λ�õĽڵ���Ϣ
void ChangeNode(DoubHeadNode& head, int pos,const string& str);
//��ʾ���нڵ�
void ShowAll(DoubHeadNode& head);