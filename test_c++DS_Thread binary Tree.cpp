//����һ����֯���ݵķ�ʽ
//���磺�ļ���->���ļ���->�ļ�
//���磺������
//   ���ڵ�T_node
//    /  \
//   /    \
//�ӽڵ�A  �ӽڵ�B
//ͨ�����νṹ��ƣ�������
/* __________
|        |
|  ����  |
|        |
|________|
| ���ڵ� |
|________|
*/
//ÿһ����������һ���ڵ� ���ڵ�û��ǰ����Ҷ�ӽڵ�û�к��
//���������ڵ�Ķ�С�ڵ���2
//Ӧ�ã���������������ѹ��111 110 11 10
//���ö���������ʽ��ֵ��a+b*��c-d��-e/f��
//·�����е�·�ɱ��õ�һ�����������õ�·�ɽڵ�����·��
//�������������뼼��
//ƽ��������˶���������һ���Ĳ������ֱ��Ӧ�ĸ��ռ䣬�ռ��˶���Ӧ�˲���
//STL�õ���������ֲ�ʽ�õ�B������B+��
//��Դ���������ļ���չ��
//�ڵ�Ķȣ��ý��ӵ�е���������Ŀ����Ϊ0��ΪҶ�ӽڵ㣬��Ϊ��0�Ľڵ��Ϊ��֧�ڵ�
//���Ķȣ����нڵ�ȵ����ֵ
//��ȣ������
//ɭ�֣����ཻ�����ļ���
//���������ڵ�����������
//�������������Ҷ���
//��ȫ����������������ڵ��Ϊ��ȫ������
//���������ʣ�
//��������i��Ľڵ������һ�ŷǿն������ĵ�i�������2^(i-1)���ڵ㣬i>=1
//����n���ڵ����ȫ�����������Ϊh=(log2n)+1;

//��ȫ��������˳��洢�ṹ
/*
       A(1)
	  /   \
	B(2)  C(3)
	/ \    /
  D(4)E(5)F(6)
��ȫ�������������˳���Ӧ��[A,B,C,D,E,F]�����Կ��԰�һ������ת������ȫ������
       A(1)
    /       \
   B(2)      C(3)
  / \        / \
D(4)NULL(5)NULL(6)E(5)
һ���������[A,B,C,D,NULL,NULL,E],ת������ȫ��������û�е�Ҷ�ӽڵ㲹�գ���ڵ㣩�������Ϊ��ȫ������
*/ 
/*
�����������ݽṹ��
|*lchild|data|*rchild|*parent|
*/
//�������ı���
//һ�Ŷ���������ɣ����ڵ㣬��������������
/*
�����������������
����������󣬸�����
������������ң���
*/
/*
      A
    /   \
   B     C
  / \    /
 D   E  F
���������A BDE CF
���������DBE A FC
���������DEB FC A
*/
//�ڵݹ������ʱ����������򵥵�ģ��һ������Ķ�����
/*�������������ڶ������Ļ�����������ָ��ýڵ��ǰ�����Ǻ�̣��������
ltag����ʾָ��ǰ������0 lchildָʾ�ڵ������ 1 lchildָʾ�ڵ��ֱ��ǰ��   û�����ӣ�����ltag=1��child�ڵ�ָ����ڵ� �����Ӿ�ֱ������ ltag=0
rtag����ʾָ���̣���0 rchildָʾ�ڵ���Һ��� 1 rchildָʾ�ڵ��ֱ�Ӻ��
|ltag|lchild|data|rchild|rtag|
*/
/*
ǰ���ڵ㣺���������������ɺ������ڵ����ڵ�ǰ��Ľڵ�Ϊ�ýڵ��ǰ���ڵ�
��̽ڵ㣺���������������ɺ������ڵ����ڵĺ���Ľڵ�Ϊ�ýڵ�ĺ�̽ڵ�
     A
   /   \
  B     C
 / \    /
D   E  F
���������DBE A FC   
E��ǰ��ΪB��E�ĺ��ΪA
B��ǰ��ΪD��B�ĺ��ΪE
https://blog.csdn.net/qq_40938077/article/details/80463299  ���ıȽ�������������ϵĺܶ���ܵĲ����
https://blog.csdn.net/I_love_blog/article/details/60343787
������
ǰ���ڵ㣺
1.�����ǰ�ڵ��������������ô�õ��ǰ���ڵ�Ϊ�õ������������ҵĽڵ㣨����A��     
2.��һ���ڵ�û������������ô�жϸýڵ���丸�ڵ�Ĺ�ϵ 
a.���ýڵ����丸�ڵ���ұߺ��ӣ���ô�ýڵ��ǰ����㼴Ϊ�丸�ڵ㡣 ������E��
b.���ýڵ����丸�ڵ����ߺ��ӣ���ô��Ҫ�����丸�׽ڵ�һֱ�����Ķ���Ѱ�ң��ӱ��ڵ㿪ʼ����ֱ���ҵ�һ���ڵ�P��������F��
P�ڵ����丸�ڵ�Q���ұߺ��ӣ���ôQ���Ǹýڵ��ǰ���ڵ�

��̽ڵ㣺
1.��һ���ڵ�������������ô�ýڵ�ĺ�̽ڵ�����������������Ľڵ㣨����A��
2.��һ���ڵ�û������������ô�жϸýڵ���丸�ڵ�Ĺ�ϵ 
a.���ýڵ����丸�ڵ����ߺ��ӣ���ô�ýڵ�ĺ�̽�㼴Ϊ�丸�ڵ㡣 ������D��
b.���ýڵ����丸�ڵ���ұߺ��ӣ���ô��Ҫ�����丸�׽ڵ�һֱ�����Ķ���Ѱ�ң�ֱ���ҵ�һ���ڵ�P��(����E)
P�ڵ����丸�ڵ�Q����ߺ��ӣ���ôQ���Ǹýڵ�ĺ�̽ڵ�
*/

#include <stdio.h>
#include <stdlib.h>

typedef char TElemType;

typedef enum PointerTag { Link, Thread };

typedef struct ThrBiNode {
	TElemType data;
	ThrBiNode *lchild, *rchild;  // ���Һ���ָ��
	PointerTag lTag, RTag;    // ����ָʾ
}ThrBiNode, *ThrBiTree;

// ������������������������� �� �ң�
void InThreading(ThrBiTree T, ThrBiTree &pre)
{
	if (T) {
		InThreading(T->lchild, pre);   // ������������

		if (!T->lchild) {
			// ��ǰ��������Ϊ��
			T->lTag = Thread;
			T->lchild = pre;
		}
		else
		{
			T->lTag = Link;
		}

		if (!pre->rchild) {
			// ǰ����������Ϊ��
			pre->RTag = Thread;
			pre->rchild = T;
		}
		else
		{
			pre->RTag = Link;
		}
		pre = T;
		InThreading(T->rchild, pre);   // ������������
	}
}

// �������������T��������������������Thrtָ��ͷ���
void InOrderThreading(ThrBiTree T, ThrBiTree &Thrt)
{
	// ��ʼ����������Ϊ����һ��ͷ���
	Thrt = (ThrBiTree)malloc(sizeof(ThrBiNode));
	Thrt->lTag = Link;
	Thrt->RTag = Thread;
	if (!T)    // ���������Ϊ��������Thrt->lchildָ���ָ
	{
		Thrt->lchild = Thrt;
		Thrt->rchild = Thrt;
	}
	else
	{
		Thrt->lchild = T;
		ThrBiNode *pre = Thrt;   // preָ����ָ��ǰ����ǰ�����
		InThreading(T, pre);
		// ����Ϊ���һ������������
		pre->RTag = Thread;
		pre->rchild = Thrt;// ���һ������rchild��ָ���ָ
		Thrt->rchild = pre;  // ͷ����rchild��ָ��ָ�����һ�����
	}
}

// ���������ӡ����������T���ǵݹ��㷨��,Tָ��ͷ��㣬ͷ����lchild����ָ��������ĸ����
void InOrderTraversePrint(ThrBiTree T)
{
	ThrBiNode *p = T->lchild;  // pָ������
	while (p != T)  // ���� ��������� p==t
	{
		while (p->lTag == Link)
			p = p->lchild;

		// ��ʱpָ������������еĵ�һ����㣨�����µĽ�㣩
		printf("%c ", p->data);  // ��ӡ��������Ϊ�յĽ��

		while (p->RTag == Thread && p->rchild != T)
		{
			p = p->rchild;
			printf("%c ", p->data);   // ���ʺ������
		}
		p = p->rchild;

	}
	printf("\n");
}

// �����������н���һ�Ŷ��� ����'.'�������
// �������ݣ�abc..de.g..f...#
void CreateBiTreePreOrder(ThrBiTree &T)
{
	char ch;
	scanf("%c", &ch);
	if (ch != '#')
	{
		if (ch == '.') {
			T = NULL;
		}
		else
		{
			T = (ThrBiNode*)malloc(sizeof(ThrBiNode));
			T->data = ch;
			CreateBiTreePreOrder(T->lchild);
			CreateBiTreePreOrder(T->rchild);
		}
	}
}

int main()
{
	ThrBiTree T;
	printf("�밴�������������������ڵ��ֵ���Կո��ʾ��������#�Ž���:\n");
	CreateBiTreePreOrder(T);  // ����������

	ThrBiTree Thrt;
	InOrderThreading(T, Thrt); // ��������T����������

							   // �����������������
	InOrderTraversePrint(Thrt);

	return 0;
}