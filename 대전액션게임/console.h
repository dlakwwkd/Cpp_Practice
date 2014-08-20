#pragma once
#include "stdafx.h"

#define CONSOLE_LINES 44
#define CONSOLE_COLS 135
#define PLAY_LINES (CONSOLE_LINES-6)
#define PLAY_COLS (CONSOLE_COLS-2)

class Key;

extern std::map<int, Key*> keySet;

void InitConsole(void);
void Gotoxy(int x, int y);
void Setcolor(int color);

