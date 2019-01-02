#include "Tetris.h"
#include <conio.h>

int main() 
{
	Tetris tetris;
	tetris.Init();
	while (true)
	{
		tetris.GetCmd();
	}
	return 0;
}