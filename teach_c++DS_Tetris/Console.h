#pragma once
#include <windows.h>

//控制台类
class Console
{
public:
	//初始化  控制台的标题 大小
	void Init(const TCHAR* caption, SHORT GameWidth, SHORT GameHeight);
	//打印  要打印的字符 字符串长度 打印位置 打印颜色
	void Print(const char* str, size_t len, SHORT x, SHORT y, WORD color);
private:
	HANDLE m_hStdOutput;
	HANDLE m_hStdInput;
	COORD m_coord;
};

