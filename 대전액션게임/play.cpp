// play.cpp : ���� ���࿡ �ʿ��� �Լ����� �����մϴ�.
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
	initPlay();
	respawne();
	while (gamePlay)
	{
		Print::get().printText();
		Print::get().init();
		Print::get().frameCheck();

		if (_kbhit())
		{
			inputKey(_getch());
		}
		player.at(0).move();
		player.at(0).show_pos();
		player.at(0).skill_z();

		moveAiBoss();

	}
}