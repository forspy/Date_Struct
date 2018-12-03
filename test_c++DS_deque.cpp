//deque˫�˶���
//Vector�Ĳ����鷳��List�Ĳ�ѯ�鷳
/*
  �п���list     vector
        |__|---->|__|__|__|__|__|__|__|
        |__|---->|__|__|__|__|__|__|__|
        |__|---->|__|__|__|__|__|__|__|
        |__|---->|__|__|__|__|__|__|__|
iterator:node     first   cur       last
*/
//�п�����list��-->����vector
//deque���������˲���ɾ��
//�������Ƚϣ�
/*
vector��deque������֧���������㣬listֻ֧��++��--
vector�ĵ��������ȶ� ��vector���ݵ�ʱ�� ���ؿ��ڴ� ��û�н�iterator����ָ��
����ÿ�����ݵ�ʱ��ԭ����iterator��ʧЧ����Ҫ���µ���iterator
*/
/*
vector vs list vs deque
1.��Ч���� ���ں�����ɾ��Ч�� ��vector
2.��Ҫ��������ɾ���������ķ��� ��list
3.��Ҫ���� ҲҪ���ǲ���ɾ��Ч�� ��deque
*/
#include<iostream>
#include<deque>
using namespace std;
//using std::deque;
int main()
{
	deque<int> deque1;
	deque1.push_back(1);
	deque1.push_back(2);
	deque1.push_back(3);
	deque1.pop_front();//ǰ���ܵ���
	for (deque<int>::iterator iter = deque1.begin(); iter != deque1.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
	for (deque<int>::reverse_iterator it = deque1.rbegin(); it != deque1.rend(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}