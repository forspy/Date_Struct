#pragma once
#include <windows.h>

//����̨��
class Console
{
public:
	//��ʼ��  ����̨�ı��� ��С
	void Init(const TCHAR* caption, SHORT GameWidth, SHORT GameHeight);
	//��ӡ  Ҫ��ӡ���ַ� �ַ������� ��ӡλ�� ��ӡ��ɫ
	void Print(const char* str, size_t len, SHORT x, SHORT y, WORD color);
private:
	HANDLE m_hStdOutput;
	HANDLE m_hStdInput;
	COORD m_coord;
};

