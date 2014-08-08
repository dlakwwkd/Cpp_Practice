#pragma once
#include "console.h"
extern std::vector<POINT> hitColor;
extern std::vector<POINT> deathColor;
extern std::vector<POINT> heroColor;
extern std::vector<POINT> scopeColor;

class Print
{
public:
	static Print& get()
	{
		static Print instance;
		return instance;
	}
	char m_ScreenBuffer[PLAY_LINES + 1][CONSOLE_COLS + 1];

	void InText(int x, int y, std::string text);
	void Init(void);
	void PrintText(void);
	void PrintColor(void);
	void PrintTop(void);
	void PrintBottom(void);

	void FrameCheck(void);
private:
	Print();
};