#include "stdafx.h"
#include "console.h"
#include "setting.h"
#include "Print.h"

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
			m_ScreenBuffer[y][x] = ' ';
		m_ScreenBuffer[y][x] = '\0';
	}
}

void Print::InText(int x, int y, std::string text)
{
	if (x < 0 || y < 0 || x > CONSOLE_COLS || y > PLAY_LINES) return;
	for (unsigned int i = x; i < x + text.length(); i++)
		m_ScreenBuffer[y][i] = text[i - x];
}

void Print::Init()
{
	int x, y;
	for (y = 0; y <= PLAY_LINES; y++)
	{
		for (x = 0; x < CONSOLE_COLS; x++)
			m_ScreenBuffer[y][x] = ' ';
		m_ScreenBuffer[y][x] = '\0';
	}
	Setcolor(DefColor(SCREEN));
}

void Print::PrintText()
{
	Gotoxy(0, 1);
	for (int y = 0; y <= PLAY_LINES; y++)
		printf("%s", m_ScreenBuffer[y]);
}

void Print::PrintColor(void)
{
	if (!heroColor.empty())
	{
		Setcolor(14);
		while (!heroColor.empty())
		{
			Gotoxy(heroColor.back().x, heroColor.back().y + 1);
			_putch(m_ScreenBuffer[heroColor.back().y][heroColor.back().x]);
			_putch(m_ScreenBuffer[heroColor.back().y][heroColor.back().x + 1]);
			heroColor.pop_back();
		}
	}
	if (!scopeColor.empty())
	{
		Setcolor(11);
		while (!scopeColor.empty())
		{
			Gotoxy(scopeColor.back().x, scopeColor.back().y + 1);
			_putch(m_ScreenBuffer[scopeColor.back().y][scopeColor.back().x]);
			scopeColor.pop_back();
		}
	}
	if (!hitColor.empty())
	{
		Setcolor(218);
		while (!hitColor.empty())
		{
			Gotoxy(hitColor.back().x, hitColor.back().y + 1);
			_putch(m_ScreenBuffer[hitColor.back().y][hitColor.back().x]);
			_putch(m_ScreenBuffer[hitColor.back().y][hitColor.back().x + 1]);
			hitColor.pop_back();
		}
	}
	if (!deathColor.empty())
	{
		Setcolor(76);
		while (!deathColor.empty())
		{
			Gotoxy(deathColor.back().x, deathColor.back().y + 1);
			_putch(m_ScreenBuffer[deathColor.back().y][deathColor.back().x]);
			_putch(m_ScreenBuffer[deathColor.back().y][deathColor.back().x + 1]);
			deathColor.pop_back();
		}
	}
	Sleep(20 / (1 + lowSpecMode));
}

void Print::PrintTop()
{
	Gotoxy(0, 0);
	Setcolor(DefColor(TOP_BAR));
	if (hero.empty())
		printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
	else
	{
		if (playerNum == 1)
			printf(" \t  Stage%4d   \t\t\t    ENTER: 다음 라운드         ESC: 처음으로   \t\t\t\t     남은 생명: %d  \t      ",
			gameStage, hero[PLAYER_1].HavingHeart());
		else
			printf(" \t  Stage%4d   \t\t\t   ENTER: 다음 라운드      ESC: 처음으로   \t\t\t   1P 생명: %d      2P 생명: %d      ",
			gameStage, hero[PLAYER_1].HavingHeart(), hero[PLAYER_2].HavingHeart());
	}
}

void Print::PrintBottom()
{
	Gotoxy(0, PLAY_LINES + 2);
	Setcolor(DefColor(BOTTOM));
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
	Setcolor(DefColor(STATUS_BAR));
	if (hero.empty())
	{
		printf("\t\t\t\t     확인: Enter Key or Z key  \t\t    취소: ESC key or X key  \t\t\t\t\t");
		printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
	}
	else
	{
		hero[PLAYER_1].HpStatus();
		printf("   ");
		if (playerNum > 1)
			hero[PLAYER_2].HpStatus();
		else
			printf(" \t\t 공격 : Z key    조준 : X key   \t\t\t");
		hero[PLAYER_1].MpStatus();
		printf("   ");
		if (playerNum > 1)
			hero[PLAYER_2].MpStatus();
		else
			printf(" \t\t 스킬1: X -> Z   스킬2: X -> C  \t\t\t");
	}
	Setcolor(DefColor(BOTTOM));
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
	Setcolor(DefColor(SCREEN));
}

void Print::FrameCheck()
{
	gameFrame++;
	if (time(NULL) - gameTime >= 1){
		PrintTop();
		PrintBottom();
		Gotoxy(0, CONSOLE_LINES);
		Setcolor(15);
		printf("Frame: %d   mob:%5d\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t   ", gameFrame, mob.size());
		gameTime = (unsigned int)time(NULL);
		gameFrame = 0;
	}
}
