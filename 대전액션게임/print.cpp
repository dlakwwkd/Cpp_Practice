#include "stdafx.h"
#include "Print.h"
#include "setting.h"

Print::Print()
{
	m_HeroColor.reserve(MAX_PLAYER_NUM);
	m_SopeColor.reserve(MAX_PLAYER_NUM);
	m_HitColor.reserve(MAX_MOB_NUM);
	m_DeathColor.reserve(MAX_MOB_NUM);

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

void Print::InColor(int x, int y, Color type)
{
	switch (type)
	{
	case HERO:
		m_HeroColor.push_back({ x, y });
		break;
	case SCORP:
		m_SopeColor.push_back({ x, y });
		break;
	case HIT:
		m_HitColor.push_back({ x, y });
		break;
	case DEATH:
		m_DeathColor.push_back({ x, y });
		break;
	default:
		break;
	}
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
	Setcolor(Color(SCREEN));
}

void Print::PrintText()
{
	Gotoxy(0, 1);
	for (int y = 0; y <= PLAY_LINES; y++)
		printf("%s", m_ScreenBuffer[y]);
}

void Print::PrintColor()
{
	if (!m_HeroColor.empty())
	{
		Setcolor(Color(HERO));
		while (!m_HeroColor.empty())
		{
			Gotoxy(m_HeroColor.back().x, m_HeroColor.back().y + 1);
			_putch(m_ScreenBuffer[m_HeroColor.back().y][m_HeroColor.back().x]);
			_putch(m_ScreenBuffer[m_HeroColor.back().y][m_HeroColor.back().x + 1]);
			m_HeroColor.pop_back();
		}
	}
	if (!m_SopeColor.empty())
	{
		Setcolor(Color(SCORP));
		while (!m_SopeColor.empty())
		{
			Gotoxy(m_SopeColor.back().x, m_SopeColor.back().y + 1);
			_putch(m_ScreenBuffer[m_SopeColor.back().y][m_SopeColor.back().x]);
			m_SopeColor.pop_back();
		}
	}
	if (!m_HitColor.empty())
	{
		Setcolor(Color(HIT));
		while (!m_HitColor.empty())
		{
			Gotoxy(m_HitColor.back().x, m_HitColor.back().y + 1);
			_putch(m_ScreenBuffer[m_HitColor.back().y][m_HitColor.back().x]);
			_putch(m_ScreenBuffer[m_HitColor.back().y][m_HitColor.back().x + 1]);
			m_HitColor.pop_back();
		}
	}
	if (!m_DeathColor.empty())
	{
		Setcolor(Color(DEATH));
		while (!m_DeathColor.empty())
		{
			Gotoxy(m_DeathColor.back().x, m_DeathColor.back().y + 1);
			_putch(m_ScreenBuffer[m_DeathColor.back().y][m_DeathColor.back().x]);
			_putch(m_ScreenBuffer[m_DeathColor.back().y][m_DeathColor.back().x + 1]);
			m_DeathColor.pop_back();
		}
	}
	Sleep(20 / (1 + lowSpecMode));
}

void Print::PrintTop()
{
	Gotoxy(0, 0);
	Setcolor(Color(TOP_BAR));
	if (hero.empty())
		printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
	else
	{
		if (playerNum == 1)
			printf(" \t  Stage%4d   \t\t\t    ENTER: 다음 라운드         ESC: 처음으로   \t\t\t\t     남은 생명: %d  \t      ",
			gameStage, hero[PLAYER_1]->HavingHeart());
		else
			printf(" \t  Stage%4d   \t\t\t   ENTER: 다음 라운드      ESC: 처음으로   \t\t\t   1P 생명: %d      2P 생명: %d      ",
			gameStage, hero[PLAYER_1]->HavingHeart(), hero[PLAYER_2]->HavingHeart());
	}
}

void Print::PrintBottom()
{
	Gotoxy(0, PLAY_LINES + 2);
	Setcolor(Color(BOTTOM));
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
	if (hero.empty())
	{
		Setcolor(Color(STATUS_BAR));
		printf("\t\t\t\t     확인: Enter Key or Z key  \t\t    취소: ESC key or X key  \t\t\t\t\t");
		printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
	}
	else
	{
		Setcolor(Color(HP_BAR));
		hero[PLAYER_1]->HpStatus();
		printf("   ");
		if (playerNum > 1)
			hero[PLAYER_2]->HpStatus();
		else
			printf(" \t\t 공격 : Z key    조준 : X key   \t\t\t");
		Setcolor(Color(MP_BAR));
		hero[PLAYER_1]->MpStatus();
		printf("   ");
		if (playerNum > 1)
			hero[PLAYER_2]->MpStatus();
		else
			printf(" \t\t 스킬1: X -> Z   스킬2: X -> C  \t\t\t");
	}
	Setcolor(Color(BOTTOM));
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
	Setcolor(Color(SCREEN));
}
