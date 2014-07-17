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
	for (unsigned int i = x; i < x + text.length(); i++)
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
	int x, y;

	gotoxy(0, 0);

	BAR_COLOR;
	printf("%s", screenBuffer[0]);
	DEF_COLOR;

	for (y = 1; y <= PLAY_LINES; y++)
	{
		if (colorBuffer[y][CONSOLE_COLS])
		{
			for (x = 0; x < CONSOLE_COLS; x++)
			{
				if (colorBuffer[y][x])
					setcolor(colorBuffer[y][x]);
				printf("%c", screenBuffer[y][x]);
			}
		}
		else printf("%s", screenBuffer[y]);
	}

	BAR_COLOR;
	printf("%s", screenBuffer[y++]);
	printf("%s", screenBuffer[y++]);
	printf("%s", screenBuffer[y++]);
	printf("%s", screenBuffer[y++]);
	DEF_COLOR;
}

void Print::frameCheck()
{
	gameFrame++;
	if (time(NULL) - gameTime >= 1){
		printf("Frame: %d \t\t\t\t\t\t\t\t\t\t\t\t\t  ", gameFrame);
		gameTime = (unsigned int)time(NULL);
		gameFrame = 0;
	}
	if (gameFrame > 60){
		Sleep(10);
		printf("Frame: %d \t\t\t\t\t\t\t\t\t\t\t\t\t  ", gameFrame);
		gameFrame -= 10; 
	}
}