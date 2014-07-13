// ui.h : 프로그램의 UI를 구성하는 함수들을 선언합니다.
//

#ifndef __UI_H
#define __UI_H

#include "stdafx.h"

extern int a, b, c;

static int mainMenuNum = a;
static int modeMenuNum = b;
static int heroListNum = c;

void mainMenuPrint(int menu);
void modeMenuPrint(int menu);
void heroListPrint(int menu);

void closeMessage(void);

#endif