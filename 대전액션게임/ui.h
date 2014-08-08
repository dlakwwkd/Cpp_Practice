// ui.h : ���α׷��� UI�� �����ϴ� �Լ����� �����մϴ�.
//

#ifndef __UI_H
#define __UI_H

#include "stdafx.h"

extern int mainMenuNum, playerListNum, modeMenuNum, heroListNum, gameOverListNum, gameOptionListNum,
gamem_SpeedListNum, suspensionOptionListNum;

void MainMenuPrint(int menu);
void PlayerListPrint(int menu);
void OptionMenuPrint(int menu, int menu2, int menu3);
void ModeMenuPrint(int menu);
void HeroListPrint(int menu);
void GameOverPrint(void);
void GameOverListPrint(int menu);
void suspensionOptionPrint(void);
void suspensionOptionListPrint(int menu);

void CloseMessage(void);

#endif