// play.cpp : ���� ���࿡ �ʿ��� �Լ����� �����մϴ�.
//

#include "stdafx.h"

void GameRunLoop(void)
{
	while (gameRun)
	{
		Print::get().printTop();
		Print::get().printBottom();
		MainMenu();
		GamePlayLoop();
	}
}

void GamePlayLoop(void)
{
	InitPlay();
	clock_t start = clock();
	while (gamePlay)
	{
		clock_t delay = CLOCKS_PER_SEC / (10 * gameSpeed);
		if (clock() - start > delay)
		{
			start = clock();
			Print::get().printText();
			Print::get().printColor();
			Print::get().frameCheck();
			Print::get().init();

			player.at(0).moveAction();
			player.at(0).showPos();
			player.at(0).initDelay();
			player.at(0).skillCheck();

			MoveAi();

			InputCommand();

			if (!player.empty())
				player.at(0).deadCheck();
		}
	}
}