// print.cpp : 화면 출력을 위한 print 클래스를 정의합니다.
//

#include "stdafx.h"

std::vector<POINT> hitColor;
std::vector<POINT> deathColor;
std::vector<POINT> heroColor;
std::vector<POINT> scopeColor;

Print::Print()
{
	int x, y;
	for (y = 0; y <= PLAY_LINES; y++)
	{
		for (x = 0; x < CONSOLE_COLS; x++)
			screenBuffer[y][x] = ' ';
		screenBuffer[y][x] = '\0';
	}
}

void Print::inText(int x, int y, std::string text)
{
	for (unsigned int i = x; i < x + text.length(); i++)
		screenBuffer[y][i] = text[i - x];
}

void Print::init()
{
	int x, y;
	for (y = 0; y <= PLAY_LINES; y++)
	{
		for (x = 0; x < CONSOLE_COLS; x++)
			screenBuffer[y][x] = ' ';
		screenBuffer[y][x] = '\0';
	}
	Setcolor(DefColor(SCREEN));
}

void Print::printText()
{
	Gotoxy(0, 1);
	for (int y = 0; y <= PLAY_LINES; y++)
		printf("%s", screenBuffer[y]);
}

void Print::printColor(void)
{
	if (!heroColor.empty())
	{
		Setcolor(14);
		while (!heroColor.empty())
		{
			Gotoxy(heroColor.back().x, heroColor.back().y + 1);
			_putch(screenBuffer[heroColor.back().y][heroColor.back().x]);
			_putch(screenBuffer[heroColor.back().y][heroColor.back().x + 1]);
			heroColor.pop_back();
		}
	}
	if (!scopeColor.empty())
	{
		Setcolor(11);
		while (!scopeColor.empty())
		{
			Gotoxy(scopeColor.back().x, scopeColor.back().y + 1);
			_putch(screenBuffer[scopeColor.back().y][scopeColor.back().x]);
			scopeColor.pop_back();
		}
	}
	if (!hitColor.empty())
	{
		Setcolor(218);
		while (!hitColor.empty())
		{
			Gotoxy(hitColor.back().x, hitColor.back().y + 1);
			_putch(screenBuffer[hitColor.back().y][hitColor.back().x]);
			_putch(screenBuffer[hitColor.back().y][hitColor.back().x + 1]);
			hitColor.pop_back();
		}
	}
	if (!deathColor.empty())
	{
		Setcolor(76);
		while (!deathColor.empty())
		{
			Gotoxy(deathColor.back().x, deathColor.back().y + 1);
			_putch(screenBuffer[deathColor.back().y][deathColor.back().x]);
			_putch(screenBuffer[deathColor.back().y][deathColor.back().x + 1]);
			deathColor.pop_back();
		}
	}
	Sleep(gameSpeed * 5 / (1 + lowSpecMode));
}

void Print::printTop()
{
	Gotoxy(0, 0);
	Setcolor(DefColor(TOP_BAR));
	if (player.empty())
		printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
	else
	{
		printf(" \t  Stage%4d   \t\t\t    ENTER: 다음 라운드         ESC: 처음으로   \t\t\t\t     남은 생명: %d  \t      ",
			gameStage, player.at(0).havingHeart());
	}
}

void Print::printBottom()
{
	Gotoxy(0, PLAY_LINES + 2);
	Setcolor(DefColor(BOTTOM));
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
	Setcolor(DefColor(STATUS_BAR));
	if (player.empty())
	{
		printf("\t\t\t\t     확인: Enter Key or Z key  \t\t    취소: ESC key or X key  \t\t\t\t\t");
		printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
	}
	else
	{
		player.at(0).hpStatus();
		player.at(0).mpStatus();
	}
	Setcolor(DefColor(BOTTOM));
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
	Setcolor(DefColor(SCREEN));
}

void Print::frameCheck()
{
	gameFrame++;
	if (time(NULL) - gameTime >= 1){
		printTop();
		printBottom();
		Gotoxy(0, CONSOLE_LINES);
		Setcolor(15);
		printf("Frame: %d   mob:%5d\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t   ", gameFrame, mob.size());
		gameTime = (unsigned int)time(NULL);
		gameFrame = 0;
	}
}
