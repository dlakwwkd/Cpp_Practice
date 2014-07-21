// command.cpp : 각종 명령 처리 함수들을 정의합니다.
//

#include "stdafx.h"

void inputKey(int input)
{
	Print::get().printTop();
	Print::get().printBottom();
	switch (input)
	{
	case INPUT_KEY(ESC):
		player.clear();
		mob.clear();
		system("cls");
		gamePlay = OFF;
		break;
	case INPUT_KEY(ENTER):
		if (!mob.size())
		{
			gameStage++;
			mobNumber += 5;
			respawne();
		}
		break;
	case INPUT_KEY(SCAN_CODE):
		input = _getch();
		player.at(0).move_input(input);
		break;
	case 'x':
	case 'z':
	case 'c':
	case 'v':
		if (dummy.empty())
			player.at(0).skill_on(input);
		break;
	}
}

void inputKey2(int input)
{
	Print::get().printTop();
	Print::get().printBottom();
	switch (input)
	{
	case 'x':
	case INPUT_KEY(ESC):
		dummy.pop();
		designateMode = OFF;
		break;
	case INPUT_KEY(SCAN_CODE):
		input = _getch();
		dummy.front().move_input(input);
		break;
	case 'z':
	case 'c':
		player.at(0).skill_on(input);
		break;
	}
}
