// console.h : 콘솔 창을 제어하는 함수들을 선언합니다.
//

#ifndef __CONSOLE_H
#define __CONSOLE_H

#include "stdafx.h"

#define CONSOLE_LINES 44
#define CONSOLE_COLS 135
#define PLAY_LINES (CONSOLE_LINES-6)
#define PLAY_COLS (CONSOLE_COLS-2)

enum DefColor
{
	TOP_BAR = 63,
	BOTTOM = 63,
	SCREEN = 10,
	STATUS_BAR = 249,
};

void InitConsole(void);
void Gotoxy(int x, int y);
void Setcolor(int color);

#endif