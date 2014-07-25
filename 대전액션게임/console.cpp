// console.cpp : �ܼ� â�� �����ϴ� �Լ����� �����մϴ�.
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