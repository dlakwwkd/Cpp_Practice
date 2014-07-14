// print.cpp : 화면 출력을 위한 print 클래스를 정의합니다.
//

#include "stdafx.h"

Print::Print()
{
	int x, y;

	for (y = 0; y < CONSOLE_LINES; y++)
	{
		for (x = 0; x < CONSOLE_COLS; x++)
		{
			colorBuffer[y][x] = 0;
			screenBuffer[y][x] = ' ';
		}
		colorBuffer[y][x] = 0;
		screenBuffer[y][x] = '\0';
	}
}

Print::~Print()
{

}

void Print::inColor(int x, int y, int color)
{
	colorBuffer[y][x] = color;
	if (color) colorBuffer[y][CONSOLE_COLS] = 1;
	else colorBuffer[y][CONSOLE_COLS] = 0;
}

void Print::inText(int x, int y, std::string text)
{
	for (int i = x; i < x + text.length(); i++)
	{
		screenBuffer[y][i] = text[i - x];
	}
}

void Print::init()
{
	int x, y;

	for (y = 0; y < CONSOLE_LINES; y++)
	{
		for (x = 0; x < CONSOLE_COLS; x++)
		{
			colorBuffer[y][x] = 0;
			screenBuffer[y][x] = ' ';
		}
		colorBuffer[y][x] = 0;
		screenBuffer[y][x] = '\0';
	}
}

void Print::printText()
{
	int y;
	
	gotoxy(0, 0);
	
	for (y = 0; y < CONSOLE_LINES; y++)
	{
		if (colorBuffer[y][CONSOLE_COLS] == 1)
		{
			setcolor(14, 5);
			printf("%s", screenBuffer[y]);
			setcolor(15, 0);
		}
		else printf("%s", screenBuffer[y]);
	}
}