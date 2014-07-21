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
	clock_t delay = CLOCKS_PER_SEC / (30 * gameSpeed);
	clock_t start = clock();
	clock_t start2 = clock();
	while (gamePlay)
	{
		if (clock() - start > delay)
		{
			start = clock();
			if (!lowSpecMode)
			{
				Print::get().printText();
				Print::get().init();
			}
			Print::get().frameCheck();

			player.at(0).move_action();
			player.at(0).show_pos();
			player.at(0).init_delay();
			player.at(0).skill_check();
			player.at(0).dead_check();

			moveAi();

			if (designateMode){
				dummy.front().show_pos();
				dummy.front().move_action();
				if (_kbhit())
				{
					inputKey2(_getch());
				}
			}
			else{
				if (!dummy.empty())
					dummy.back().move_action();
				if (_kbhit())
				{
					inputKey(_getch());
				}
			}
		}
		if (lowSpecMode)
		{
			if (clock() - start2 > delay * 2)
			{
				start2 = clock();
				Print::get().printText();
				Print::get().init();
			}
		}
	}
}