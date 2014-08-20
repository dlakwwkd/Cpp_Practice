#pragma once
#include "console.h"

class Print
{
public:
	static Print& get()
	{
		static Print instance;
		return instance;
	}
	void InText(int x, int y, std::string text);
	void InColor(int x, int y, Color type);
	void Init(void);
	void PrintText(void);
	void PrintColor(void);
	void PrintTop(void);
	void PrintBottom(void);
private:
	Print();
	std::vector<POINT> m_HitColor;
	std::vector<POINT> m_DeathColor;
	std::vector<POINT> m_HeroColor;
	std::vector<POINT> m_SopeColor;
	char m_ScreenBuffer[PLAY_LINES + 1][CONSOLE_COLS + 1];
};