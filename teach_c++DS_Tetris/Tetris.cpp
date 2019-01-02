#include "Tetris.h"
#include "ctime"
#include <conio.h>
#include <iostream>
Tetris::Tetris()
{
	m_console.Init(GameCaption, GameWidth, GameHeight);
}

void Tetris::Init()
{
	m_bOver = false;
	m_bPause = true;
	m_nScore = 0;
	m_nSpeed = 0;
	memset(m_cData, 0, sizeof(m_cData));

	srand(time(NULL));
	m_nNext = rand() % 7;

	m_x = 4;
	m_y = 2;
	m_nCurrent = -1;
	m_mCurDir = 0;


	//������
	for (int i = 0; i < 21; ++i)
	{
		m_console.Print(Background + GameWidth * i, GameWidth, 0, i, COLOR_STILL);
	}
	//����һ��
	PaintNext();
}

void Tetris::GetCmd()
{
	while (true)
	{
		Sleep(200 / (m_nSpeed + 1));
		if (_kbhit())
		{
			switch (_getch())
			{
			case KEY_ENTER:
				Start();
				continue;
			case KEY_SPACE:
				FallBottom();
				continue;
			case KEY_ESC:
				exit(0);

				//����ȡ���ܼ��ͷ����ʱ _getch()��������ֵ
				//��һ�η���0 ����0xe0 ����Ƿ񰴵ù��ܼ��ͷ����   �ڶ��η���ʵ�ʵ�ֵ
	/*		case 0:
			case 0xE0:
				switch (_getch())*/
				{
				case KEY_F1:
					Pause();
					continue;
				case KEY_UP:
					Rotate();
					continue;
				case KEY_LEFT:
					MoveLeft();
					continue;
				case KEY_RIGHT:
					MoveRight();
					continue;
				case KEY_DOWN:
					MoveDown();
					continue;
				}
			}
		}
		if (IsRun() && m_nSpeed <= 10)
		{
			MoveDown();
		}
	}

}

bool Tetris::Start()
{
	//��Ϸ�Ƿ���� ���¿�ʼ
	if (m_bOver)
	{
		Init();
		return true;
	}
	//��Ϸ��ͣ ���¿�ʼ	//������ʼ
	if (m_bPause)
	{
		m_bPause = false;
		if (m_nCurrent == -1)
		{
			m_nCurrent = m_nNext;
			m_nNext = rand() % 7;
			PaintNext();
		}
		return true;
	}
	return false;
}

void Tetris::Pause()
{
	m_bPause = true;
}

void Tetris::Rotate()
{
	if (IsOk(m_x, m_y, m_nCurrent, (m_mCurDir + 1) % 4))
	{
		//��ԭ���ķ������
		PaintCurrent(COLOR_BLANK);
		m_mCurDir = (m_mCurDir + 1) % 4;
		//����÷���֮��ķ���
		PaintCurrent(COLOR_MOVE);
	}
}

void Tetris::MoveLeft()
{
	if (IsOk(m_x - 1, m_y, m_nCurrent, m_mCurDir))
	{
		//��ԭ���ķ������
		PaintCurrent(COLOR_BLANK);
		--m_x;
		PaintCurrent(COLOR_MOVE);
	}
}

void Tetris::MoveRight()
{
	if (IsOk(m_x + 1, m_y, m_nCurrent, m_mCurDir))
	{
		//��ԭ���ķ������
		PaintCurrent(COLOR_BLANK);
		++m_x;
		PaintCurrent(COLOR_MOVE);
	}
}

int Tetris::MoveDown()
{
	//����Ҫ��
	if (IsOk(m_x, m_y + 1, m_nCurrent, m_mCurDir))
	{
		//��ԭ���ķ������
		PaintCurrent(COLOR_BLANK);
		++m_y;
		PaintCurrent(COLOR_MOVE);
		return 1;
	}
	//�Ƿ񵽴�ײ�
	if (m_y != -2)
	{
		PaintCurrent(COLOR_STILL);
		for (int i = 0; i < 4; i++)
		{
			if (m_y + i < 0)
			{
				continue;
			}
			for (int j = 0; j < 4; j++)
			{
				if (Diamonds[m_nCurrent][m_mCurDir][i][j] == 1)
				{
					m_cData[m_y + i][m_x + j] = 1;
				}
			}
		}
		//�Ƿ�Ҫ����
		Eliminate();

		m_x = 4;
		m_y = -2;
		m_mCurDir = 0;
		m_nCurrent = m_nNext;


		m_nNext = rand() % 7;
		PaintNext();
		return -1;
	}
	//��Ϸ����
	
	GameOver();
	return 0;

}

void Tetris::FallBottom()
{
	int res = MoveDown();
	while (res == 1)
	{
		res = MoveDown();
	}
}

bool Tetris::IsRun()
{
	return !m_bOver && !m_bPause;
}

int Tetris::GetSpeed() const
{
	return m_nSpeed;
}

void Tetris::GameOver()
{
	m_bOver = true;
	m_console.Print("��Ϸ����", 8, 28, 1, COLOR_STILL);
	for (int i = 0; i < 4; i++)
	{
		m_console.Print(" ", 2, 28 + 2 * i, 2, COLOR_STILL);
	}
}

void Tetris::PaintCurrent(WORD color)
{
	for (int i = 0; i < 4; i++)
	{
		if (m_y + i < 0 || m_y + i >= 21 - 2)
		{
			continue;
		}
		for (int j = 0; j < 4; j++)
		{
			if (Diamonds[m_nCurrent][m_mCurDir][i][j] == 1)
			{
				m_console.Print("��", 2, (2 + m_x * 2 + j * 2), (1 + m_y + i), color);
			}
		}
	}
}

void Tetris::PaintNext()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			const char* c = Diamonds[m_nNext][0][i][j] == 0 ? "  " : "��";
			m_console.Print(c, 2, 28 + 2 * j, 1 + i, COLOR_STILL);
		}
	}
}

void Tetris::ShowScore()
{
	char str[6];
	sprintf(str, "%ld", m_nSpeed);
	m_console.Print(str, 1, 28, 19, COLOR_STILL);
	sprintf(str, "%05d", m_nScore);
	m_console.Print(str, 5, 31, 19, COLOR_STILL);
}

bool Tetris::IsOk(int x, int y, int kind, int dir)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (Diamonds[kind][dir][i][j] == 1)
			{
				if ((y + i) < 0)
				{
					continue;
				}
				if ((y + i) >= (21 - 2) || (x + j) < 0 || (x + j) >= (13 - 2) || m_cData[y + i][x + j] == 1)
				{
					return false;
				}
			}
		}
	}
	return true;
}

void Tetris::Eliminate()
{
	int lineCount = 0;
	for (int i = 0; i < (21 - 2); i++)
	{
		//��Ϸ������ĳһ��ȫΪ1(����) 
		if (memcmp(m_cData[i], FullLine, (13 - 2)) == 0)
		{
			++lineCount;
			for (int m = 0; m < (13 - 2); ++m)
			{
				for (int n = i; n > 1; --n)
				{
					m_cData[n][m] = m_cData[n - 1][m];
					WORD color = m_cData[n][m] == 1 ? COLOR_STILL : COLOR_BLANK;
					m_console.Print("��", 2, 2 + m * 2, n + 1, color);
				}
				//���������һ�б�Ϊ�ո�
				m_cData[0][m] = 0;
				m_console.Print("��", 2, 2 + m * 2, 1, COLOR_BLANK);
			}
		}
	}
	if (lineCount == 0) 
	{
		return;
	}
	int scrore = 0;
	switch (lineCount)
	{
	case 1:
		scrore += 100;
		break;
	case 2:
		scrore += 300;
		break;
	case 3:
		scrore += 800;
		break;
	case 4:
		scrore += 1500;
		break;
	}
	m_nScore += scrore;

	if (m_nScore > 99999) //��߷�
	{
		m_nScore = 99999;
	}
	m_nSpeed = m_nScore / 10000; //ÿһ��ּ���
	ShowScore();
}


