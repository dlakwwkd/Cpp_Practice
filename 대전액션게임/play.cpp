// play.cpp : 게임 진행에 필요한 함수들을 정의합니다.
//

#include "stdafx.h"

void gameRunLoop(void)
{
	while (gameRun)
	{
		mainMenu();
		gamePlayLoop();
	}
}

void gamePlayLoop(void)
{
	respawne();
	while (gamePlay)
	{
		Print::get().printText();
		Print::get().init();

		if (_kbhit())
		{
			inputKey(_getch());
		}
		player.at(0).move_action();
		player.at(0).skill_z();

		moveAi();

	}
}