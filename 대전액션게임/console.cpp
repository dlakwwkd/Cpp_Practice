// console.cpp : 콘솔 창을 제어하는 함수들을 정의합니다.
//

#include "stdafx.h"

void initConsole(void)
{
	system("mode con: lines=43 cols=100");
}

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void setcolor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}