// console.cpp : 콘솔 창을 제어하는 함수들을 정의합니다.
//

#include "stdafx.h"

void initConsole(void)
{
	system("mode con: lines=41 cols=120");
}

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void setcolor(int color, int bgcolor)
{
	color &= 0xf;
	bgcolor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}