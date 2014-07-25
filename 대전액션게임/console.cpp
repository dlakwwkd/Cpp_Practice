// console.cpp : 콘솔 창을 제어하는 함수들을 정의합니다.
//

#include "stdafx.h"

void InitConsole(void)
{
	system("mode con: lines=45 cols=135");
}

void Gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Setcolor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}