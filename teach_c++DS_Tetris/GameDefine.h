#pragma once
//��Ϸ����
const TCHAR GameCaption[] = TEXT("����˹����");
//��Ϸ����
const SHORT GameWidth = 38;
//��Ϸ�߶�
const SHORT GameHeight = 21;

//�˶���ʱ����ɫ
const WORD COLOR_MOVE = FOREGROUND_GREEN;

//�̶���ʱ����ɫ
const WORD COLOR_STILL = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY;

//�հ���ɫ
const WORD COLOR_BLANK = 0;

enum KeyValue
{
	KEY_ENTER = 13,
	KEY_F1 = 59,
	KEY_UP = 72,
	KEY_LEFT = 75,
	KEY_RIGHT = 77,
	KEY_DOWN = 80,
	KEY_SPACE = 32,
	KEY_ESC = 27
};

const char FullLine[] = { 1,1,1,1,1,1,1,1,1,1,1 };

const char Diamonds[7][4][4][4]
{ //��������
	{//ͬһ�ַ��鲻ͬ��̬
		{
			//6C00     --   0
			//       --
			{0,1,1,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}},
		{	{1,0,0,0},{1,1,0,0},{0,1,0,0},{0,0,0,0}},
		{	{0,1,1,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}},
		{	{1,0,0,0},{1,1,0,0},{0,1,0,0},{0,0,0,0}
		}
	},
	{
		//	--
		//    --    1
		{{1,1,0,0},{0,1,1,0},{0,0,0,0},{0,0,0,0}},
		{{0,1,0,0},{1,1,0,0},{1,0,0,0},{0,0,0,0}},
		{{1,1,0,0},{0,1,1,0},{0,0,0,0},{0,0,0,0}},
		{{0,1,0,0},{1,1,0,0},{1,0,0,0},{0,0,0,0}}
	},
	{		
		//	---   2
		//	-
		{ { 1,1,1,0 },{ 1,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } },
		{ { 1,0,0,0 },{ 1,0,0,0 },{ 1,1,0,0 },{ 0,0,0,0 } },
		{ { 0,0,1,0 },{ 1,1,1,0 },{ 0,0,0,0 },{ 0,0,0,0 } },
		{ { 1,1,0,0 },{ 0,1,0,0 },{ 0,1,0,0 },{ 0,0,0,0 } }
	},
	{
		//  ---   3
		//    -
		{ { 1,1,1,0 },{ 0,0,1,0 },{ 0,0,0,0 },{ 0,0,0,0 } },
		{ { 1,1,0,0 },{ 1,0,0,0 },{ 1,0,0,0 },{ 0,0,0,0 } },
		{ { 1,0,0,0 },{ 1,1,1,0 },{ 0,0,0,0 },{ 0,0,0,0 } },
		{ { 0,1,0,0 },{ 0,1,0,0 },{ 1,1,0,0 },{ 0,0,0,0 } }
	},
	{  
		// --    4
		// --
		{ { 1,1,0,0 },{ 1,1,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } },
		{ { 1,1,0,0 },{ 1,1,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } },
		{ { 1,1,0,0 },{ 1,1,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } },
		{ { 1,1,0,0 },{ 1,1,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } }
	},
	{
		//  -
		// ---     5
		{ { 0,1,0,0 },{ 1,1,1,0 },{ 0,0,0,0 },{ 0,0,0,0 } },
		{ { 0,1,0,0 },{ 1,1,0,0 },{ 0,1,0,0 },{ 0,0,0,0 } },
		{ { 1,1,1,0 },{ 0,1,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } },
		{ { 1,0,0,0 },{ 1,1,0,0 },{ 1,0,0,0 },{ 0,0,0,0 } }
	},
	{
		// ----    6
		{ { 1,1,1,1 },{ 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } },
		{ { 1,0,0,0 },{ 1,0,0,0 },{ 1,0,0,0 },{ 1,0,0,0 } },
		{ { 1,1,1,1 },{ 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } },
		{ { 1,0,0,0 },{ 1,0,0,0 },{ 1,0,0,0 },{ 1,0,0,0 } }
	}
};

//��Ϸ����
const char Background[]=
"��������������������������������������"
"��                      ����        ��"
"��                      ����        ��"
"��                      ��������������"
"��                      ��            "
"��                      �� �˳�:ESC   "
"��                      ��            "
"��                      �� ��ʼ:�س�  "
"��                      �� ��ͣ:F1    "
"��                      ��            "
"��                      �� ����:��    "
"��                      �� ����:��    "
"��                      �� ����:��    "
"��                      �� ����:��    "
"��                      �� ���:�ո�  "
"��                      ��            "
"��                      ��            "
"��                      �� �ٶ�  �÷� "
"��                      ��������������"
"��                      ����0  00000��"
"��������������������������������������";