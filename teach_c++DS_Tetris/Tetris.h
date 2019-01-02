#pragma once
#include "Console.h"
#include "GameDefine.h"
class Tetris
{
	bool m_bOver;//��Ϸ�Ƿ����
	bool m_bPause;//��Ϸ�Ƿ���ͣ
	int m_nScore;//����
	int m_nSpeed;//�ٶ�

	char m_cData[21][13];  //��Ϸ�����з��������
	int m_nNext;//��һ�����������
	int m_x, m_y;     //��ǰ����λ��
	int m_nCurrent;   //��ǰ����
	int m_mCurDir;    //��ǰ���鷽��
	Console m_console;


public:
	Tetris();
	
	void Init();
	void GetCmd();//��ð���ָ�����
	bool IsRun();   //�ж��Ƿ�����Ϸ��
	int GetSpeed() const; //����ٶ�


	bool Start(); //��Ϸ��ʼ ����Enter
	void Pause(); //��Ϸ��ͣ	����F1
	void Rotate();//������ת ���¡�
	void MoveLeft();//���� ���¡�
	void MoveRight();//���� ���¡�
	int MoveDown(); //���� ���¡�
	void FallBottom();//�䵽���� ���¿ո�
private:



	void PaintCurrent(WORD color);//����ǰ�ķ���
	void PaintNext(); //����һ������
	void ShowScore();//��ʾ�÷�
	bool IsOk(int x,int y,int kind,int dir);	//�жϿ���
	void Eliminate();//����



	void GameOver();//��Ϸ����
};

