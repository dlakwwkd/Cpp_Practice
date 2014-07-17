// console.cpp : �ܼ� â�� �����ϴ� �Լ����� �����մϴ�.
//

#include "stdafx.h"

void initConsole(void)
{
	system("mode con: lines=45 cols=120");
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