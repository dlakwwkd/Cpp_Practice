// console.h : �ܼ� â�� �����ϴ� �Լ����� �����մϴ�.
//

#ifndef __CONSOLE_H
#define __CONSOLE_H

#include "stdafx.h"

#define CONSOLE_LINES 40
#define CONSOLE_COLS 120

#define PLAY_LINES (CONSOLE_LINES-10)
#define PLAY_COLS (CONSOLE_COLS-2)


void initConsole(void);

void gotoxy(int x, int y);
void setcolor(int color, int bgcolor);
//void mouse_input(int& x, int& y);

#endif