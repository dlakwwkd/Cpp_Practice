// console.h : 콘솔 창을 제어하는 함수들을 선언합니다.
//

#ifndef __CONSOLE_H
#define __CONSOLE_H

#include "stdafx.h"

#define CONSOLE_LINES 44
#define CONSOLE_COLS 120

#define PLAY_LINES (CONSOLE_LINES-5)
#define PLAY_COLS (CONSOLE_COLS-2)

#define DEF_COLOR setcolor(15);
#define BAR_COLOR setcolor(62);


void initConsole(void);

void gotoxy(int x, int y);
void setcolor(int color);

#endif