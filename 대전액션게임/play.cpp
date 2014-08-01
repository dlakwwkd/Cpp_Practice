// play.cpp : 게임 진행에 필요한 함수들을 정의합니다.
//

#include "stdafx.h"

void GameRunLoop(void)
{
	while (gameRun)
	{
		Print::get().printTop();
		Print::get().printBottom();
		MainMenu();
		if (playerNum == 1)	//임시 설정
		{
			keySet[PLAYER_1].setZ(VKey(VK_Z));
			keySet[PLAYER_1].setX(VKey(VK_X));
			keySet[PLAYER_1].setC(VKey(VK_C));
			keySet[PLAYER_1].setV(VKey(VK_V));
		}
		else
		{
			keySet[PLAYER_1].setZ(VKey(VK_I));
			keySet[PLAYER_1].setX(VKey(VK_O));
			keySet[PLAYER_1].setC(VKey(VK_P));
			keySet[PLAYER_1].setV(VKey(VK_OEM_4));
		}
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

			MoveAi();

			if (playerNum > 0)
				PlayerAction(PLAYER_1);
			if (playerNum > 1)
				PlayerAction(PLAYER_2);
		}
	}
}

void PlayerAction(int player_num)
{
	player[player_num].moveAction();
	player[player_num].showPos();
	player[player_num].initDelay();
	player[player_num].skillCheck();

	InputCommand(player_num);

	if (!player.empty())
		player[player_num].deadCheck();
}