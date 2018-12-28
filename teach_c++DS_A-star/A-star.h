#pragma once
//A*Ѱ·
/*
A* [1]  ��A-Star)�㷨��һ�־�̬·����������·������Ч��ֱ������������Ҳ�������������ĳ�������ʽ�㷨��
ע�⡪��������Ч��ֱ�������㷨��֮��ӿ���˺ܶ�Ԥ�����㷨����ALT��CH��HL�ȵȣ������߲�ѯЧ����A*�㷨����ǧ�������򱶡�
��ʽ��ʾΪ�� f(n)=g(n)+h(n),
���У� f(n) �Ǵӳ�ʼ״̬����״̬n��Ŀ��״̬�Ĵ��۹��ƣ�
g(n) ����״̬�ռ��дӳ�ʼ״̬��״̬n��ʵ�ʴ��ۣ�
h(n) �Ǵ�״̬n��Ŀ��״̬�����·���Ĺ��ƴ��ۡ�
������·���������⣬״̬����ͼ�еĽڵ㣬���۾��Ǿ��룩
*/
#include<vector>
#include<list>
using namespace std;
struct Point
{
	int row, col;//�������
	int F, G, H;//����ֵ
	Point* parent;//���ĸ���������õ�
	Point(int _row,int _col):row(_row),col(_col),F(0),G(0),H(0),parent(nullptr){ }
};

class Astar
{
private:
	vector<vector<int>> m_map;//����һ����ά�����ʾ��ͼ
	//��Ҫһ���������һ���رձ��������������ң��رձ������޳�Ҫ���ҵĵ㣬����list�������洢�����Ӹ�Ч
	list<Point*> m_openList;
	list<Point*> m_closeList;
	Point* FindPath(Point& startpoint, Point& endpoint);
	int CalcG(Point* current, Point* target);
	int CalcH(Point* point, Point* end);
	int CalcF(Point* point);
	Point* GetMinF();//��ȡ��С��fֵ���ڵĵ�
	bool IsIncloseList(const Point* point);//�ж��Ƿ��ڹرձ�����
	Point* IsInopenList(const Point* point);//�ж��Ƿ��ڿ���������
public:
	Astar(vector<vector<int>>& map);
	void GetPath(Point& startpoint, Point& endpoint);//��ʾ·��
	
	/*~Astar();*/
};