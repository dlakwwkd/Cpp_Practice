// print.h : 화면 출력을 위한 print 클래스를 선언합니다.
//

#ifndef __PRINT_H
#define __PRINT_H

#include "stdafx.h"

class Print
{
public:
	static Print& get()
	{
		static Print instance;
		return instance;
	}

	int colorBuffer[CONSOLE_LINES + 1][CONSOLE_COLS + 1];
	char screenBuffer[CONSOLE_LINES + 1][CONSOLE_COLS + 1];

	void inColor(int x, int y, int color);
	void inText(int x, int y, std::string text);
	void init(void);
	void printText(void);
	void printTop(void);
	void printBottom(void);

	void frameCheck(void);

private:
	Print();
};



#endif