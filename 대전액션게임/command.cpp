// command.cpp : 각종 명령 처리 함수들을 정의합니다.
//

#include "stdafx.h"

void inputKey(int input)
{
	Print::get().printTop();
	Print::get().printBottom();
	switch (input)
	{
	case ESC_KEY:
		player.clear();
		mob.clear();
		system("cls");
		gamePlay = OFF;
		break;
	case ENTER_KEY:
		if (!mob.size())
		{
			gameStage++;
			mobNumber += 5;
			respawne();
		}
		break;
	case SCAN_CODE:
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
	case ESC_KEY:
		dummy.pop();
		designateMode = OFF;
		break;
	case SCAN_CODE:
		input = _getch();
		dummy.front().move_input(input);
		break;
	case 'z':
	case 'c':
		player.at(0).skill_on(input);
		break;
	}
}
