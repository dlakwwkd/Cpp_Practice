#pragma once
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
	char screenBuffer[PLAY_LINES + 1][CONSOLE_COLS + 1];

	void inText(int x, int y, std::string text);
	void init(void);
	void printText(void);
	void printColor(void);
	void printTop(void);
	void printBottom(void);

	void frameCheck(void);
private:
	Print();
};