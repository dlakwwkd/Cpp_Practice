// ui.h : ���α׷��� UI�� �����ϴ� �Լ����� �����մϴ�.
//

#ifndef __UI_H
#define __UI_H

#include "stdafx.h"

extern int mainMenuNum, modeMenuNum, heroListNum;

void mainMenuPrint(int menu);
void modeMenuPrint(int menu);
void heroListPrint(int menu);

void status(void);


void closeMessage(void);

#endif