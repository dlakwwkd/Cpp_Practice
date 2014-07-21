// print.cpp : 화면 출력을 위한 print 클래스를 정의합니다.
//

#include "stdafx.h"

Print::Print()
{
	int x, y;

	for (y = 0; y <= PLAY_LINES; y++)
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

void Print::inColor(int x, int y, int color)
{
	colorBuffer[y][x] = color;
	colorBuffer[y][CONSOLE_COLS] = 1;
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

	for (y = 0; y <= PLAY_LINES; y++)
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

	gotoxy(0, 1);

	for (y = 0; y <= PLAY_LINES; y++)
	{
		if (colorBuffer[y][CONSOLE_COLS])
		{
			for (x = 0; x < CONSOLE_COLS; x++)
			{
				if (colorBuffer[y][x])
					setcolor(colorBuffer[y][x]);
				_putch(screenBuffer[y][x]);
			}
			setcolor(DEF_COLOR(SCREEN));
		}
		else printf("%s", screenBuffer[y]);
	}
}

void Print::printTop()
{
	gotoxy(0, 0);
	setcolor(DEF_COLOR(TOP_BAR));
	if (player.empty())
		printf("\t\t\t\t\t\t\t\t\t\t\t\t\t");
	else
	{
		printf("   Stage%4d   \t\t    ENTER: 다음 라운드         ESC: 처음으로   \t\t     남은 생명: %d   ",
			gameStage, player.at(0).having_heart());
	}
	setcolor(DEF_COLOR(SCREEN));
	
}

void Print::printBottom()
{
	gotoxy(0, PLAY_LINES + 2);
	setcolor(DEF_COLOR(BOTTOM));
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t");
	setcolor(249);
	if (player.empty())
	{
		printf("\t\t\t\t\t\t\t\t\t\t\t\t\t");
		printf("\t\t\t\t\t\t\t\t\t\t\t\t\t");
	}
	else
	{
		player.at(0).hp_status();
		player.at(0).mp_status();
	}
	setcolor(DEF_COLOR(BOTTOM));
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t");
	setcolor(DEF_COLOR(SCREEN));
}

void Print::frameCheck()
{
	gameFrame++;
	if (time(NULL) - gameTime >= 1){
		printTop();
		printBottom();
		gotoxy(0, CONSOLE_LINES);
		setcolor(15);
		printf("Frame: %d   mob:%5d\t\t\t\t\t\t\t\t\t\t   ", gameFrame, mob.size());
		setcolor(DEF_COLOR(SCREEN));
		gameTime = (unsigned int)time(NULL);
		gameFrame = 0;
	}
}