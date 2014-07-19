// play.cpp : 게임 진행에 필요한 함수들을 정의합니다.
//

#include "stdafx.h"

void gameRunLoop(void)
{
	while (gameRun)
	{
		Print::get().printTop();
		Print::get().printBottom();
		mainMenu();
		gamePlayLoop();
	}
}

void gamePlayLoop(void)
{
	initPlay();
	while (gamePlay)
	{
		Print::get().printText();
		Print::get().init();
		Print::get().frameCheck();

		player.at(0).move_action(player.at(0).move);
		player.at(0).show_pos();
		player.at(0).init_delay();
		player.at(0).skill_use();
		player.at(0).dead_check();

		moveAi();

		if (designateMode){
			dummy.front().show_pos();
			dummy.front().move_action(dummy.front().move);
			if (_kbhit())
			{
				inputKey2(_getch());
			}
		}
		else{
			if (!dummy.empty())
				dummy.back().move_action(dummy.back().move);

			if (_kbhit())
			{
				inputKey(_getch());
			}
		}
	}
}