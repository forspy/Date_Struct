#pragma once
#include "Console.h"
#include "GameDefine.h"
class Tetris
{
	bool m_bOver;//游戏是否结束
	bool m_bPause;//游戏是否暂停
	int m_nScore;//分数
	int m_nSpeed;//速度

	char m_cData[21][13];  //游戏中所有方格的数据
	int m_nNext;//下一个方块的索引
	int m_x, m_y;     //当前方块位置
	int m_nCurrent;   //当前方块
	int m_mCurDir;    //当前方块方向
	Console m_console;


public:
	Tetris();
	
	void Init();
	void GetCmd();//获得按键指令并处理
	bool IsRun();   //判断是否在游戏中
	int GetSpeed() const; //获得速度


	bool Start(); //游戏开始 按下Enter
	void Pause(); //游戏暂停	按下F1
	void Rotate();//方块旋转 按下↑
	void MoveLeft();//左移 按下←
	void MoveRight();//右移 按下→
	int MoveDown(); //下移 按下↓
	void FallBottom();//落到地下 按下空格
private:



	void PaintCurrent(WORD color);//画当前的方块
	void PaintNext(); //画下一个方块
	void ShowScore();//显示得分
	bool IsOk(int x,int y,int kind,int dir);	//判断可以
	void Eliminate();//消除



	void GameOver();//游戏结束
};

