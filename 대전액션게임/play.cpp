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
	respawne();
	while (gamePlay)
	{
		//system("cls");
		//mouse_input(to_x, to_y);

		if (_kbhit())
		{
			inputKey(_getch());
		}
		player.at(0).move_action();
		player.at(0).skill_z();

		moveAi();

		Sleep(10);
	}
}