// console.h : 콘솔 창을 제어하는 함수들을 선언합니다.
//

#ifndef __CONSOLE_H
#define __CONSOLE_H

#include "stdafx.h"

#define CONSOLE_LINES 42
#define CONSOLE_COLS 100
#define PLAY_LINES (CONSOLE_LINES-6)
#define PLAY_COLS (CONSOLE_COLS-2)

enum DEF_COLOR
{
	TOP_BAR = 63,
	BOTTOM = 63,
	SCREEN = 10
};

void initConsole(void);
void gotoxy(int x, int y);
void setcolor(int color);

#endif