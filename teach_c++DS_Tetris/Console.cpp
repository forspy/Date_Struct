#include "Console.h"

void Console::Init(const TCHAR * caption, SHORT GameWidth, SHORT GameHeight)
{
	if(GameWidth <=0 || GameHeight<=0)
	{
		return;
	}
	//��������������
	m_hStdInput = GetStdHandle(STD_INPUT_HANDLE);
	m_hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	if(m_hStdInput == INVALID_HANDLE_VALUE || m_hStdOutput == INVALID_HANDLE_VALUE)
	{
		return;
	}
	//���ع��
	CONSOLE_CURSOR_INFO cci = {25,FALSE};
	SetConsoleCursorInfo(m_hStdOutput, &cci);
	//���ÿ���̨��С
	SMALL_RECT sr = { 0,0,GameWidth - 1,GameHeight - 1 };
	SetConsoleWindowInfo(m_hStdOutput, true, &sr);
	//���û�������С
	m_coord = { GameWidth ,GameHeight };
	SetConsoleScreenBufferSize(m_hStdOutput, m_coord);
	//���ÿ���̨����
	SetConsoleTitle(caption);
}

void Console::Print(const char * str, size_t len, SHORT x, SHORT y, WORD color)
{
	if(x<0 || y<0  || x>m_coord.X || y>m_coord.Y)
	{
		return;
	}
	COORD coord = { x,y };
	DWORD num = 0;
	WORD colorArray[2] = { color,color };
	for (const char* p = str; len != 0 && *p != 0  ;  --len, ++p, ++coord.X)
	{
		//���ֽ�  Ӣ��  ���
		if(*p>0)
		{
			WriteConsoleOutputCharacterA(m_hStdOutput, p, 1, coord, &num);
			if(num !=1)
			{
				return;
			}
			WriteConsoleOutputAttribute(m_hStdOutput, colorArray, 1, coord, &num);
			if (num != 1)
			{
				return;
			}
				
		}
		//˫�ֽ��ַ�  ����  ȫ��
		else
		{
			//���Ȳ������ֽ�  �ڶ����ֽ�Ϊ0 ���λ�ó�������̨
			if (len < 2 || *(p + 1) == 0 || coord.X + 1 >= m_coord.X)
			{
				return;
			}

			WriteConsoleOutputCharacterA(m_hStdOutput, p, 2, coord, &num);
			if (num != 2)
			{
				return;
			}
			WriteConsoleOutputAttribute(m_hStdOutput, colorArray, 2, coord, &num);
			if (num != 2)
			{
				return;
			}
			--len;
			++p;
			++coord.X;
		}
	}
}
