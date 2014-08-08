// command.cpp : 각종 명령 처리 함수들을 정의합니다.
//

#include "stdafx.h"
#include "command.h"
#include "console.h"
#include "setting.h"
#include "Key.h"

void InputCommand(int player_num)
{
	static int inputX[MAX_PLAYER_NUM] = { 0, };
	static int inputZ[MAX_PLAYER_NUM] = { 0, };
	static int inputEnter = 0;
	static int inputEsc = 0;

	if (designateMode[player_num - 1])
	{
		dummy.front().ShowPos();
		dummy.front().MoveAction();

		if (GetAsyncKeyState(keySet[player_num].GetUp()) & 0x8000)
			dummy.front().MoveInput(InputKey(UP));
		if (GetAsyncKeyState(keySet[player_num].GetDown()) & 0x8000)
			dummy.front().MoveInput(InputKey(DOWN));
		if (GetAsyncKeyState(keySet[player_num].GetLeft()) & 0x8000)
			dummy.front().MoveInput(InputKey(LEFT));
		if (GetAsyncKeyState(keySet[player_num].GetRight()) & 0x8000)
			dummy.front().MoveInput(InputKey(RIGHT));

		if (GetAsyncKeyState(keySet[player_num].GetZ()) & 0x8000)
		{
			if (inputZ[player_num - 1] == 0)
			{
				hero[player_num].SkillOn('z');
				inputZ[player_num - 1] = 1;
			}
		}
		else inputZ[player_num - 1] = 0;

		if ((GetAsyncKeyState(keySet[player_num].GetX()) & 0x8000))
		{
			if (inputX[player_num - 1] == 0)
			{
				dummy.pop();
				designateMode[player_num - 1] = OFF;
				inputX[player_num - 1] = 1;
			}
		}
		else inputX[player_num - 1] = 0;

		if (GetAsyncKeyState(keySet[player_num].GetC()) & 0x8000)
			hero[player_num].SkillOn('c');

		if (GetAsyncKeyState(VK_RETURN) & 0x8000)
		{
			if (inputEnter == 0)
			{
				while (getchar() != '\n');
				inputEnter = 1;
			}
		}
		else inputEnter = 0;

		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
		{
			if (inputEnter == 0)
			{
				dummy.pop();
				designateMode[player_num - 1] = OFF;
				inputEsc = 1;
			}
		}
		else inputEsc = 0;
	}
	else
	{
		if (!dummy.empty())
			dummy.back().MoveAction();

		if (GetAsyncKeyState(keySet[player_num].GetUp()) & 0x8000)
			hero[player_num].MoveInput(InputKey(UP));
		if (GetAsyncKeyState(keySet[player_num].GetDown()) & 0x8000)
			hero[player_num].MoveInput(InputKey(DOWN));
		if (GetAsyncKeyState(keySet[player_num].GetLeft()) & 0x8000)
			hero[player_num].MoveInput(InputKey(LEFT));
		if (GetAsyncKeyState(keySet[player_num].GetRight()) & 0x8000)
			hero[player_num].MoveInput(InputKey(RIGHT));

		if (GetAsyncKeyState(keySet[player_num].GetZ()) & 0x8000)
		{
			if (inputZ[player_num - 1] == 0)
			{
				if (dummy.empty())
					hero[player_num].SkillOn('z');
				inputZ[player_num - 1] = 1;
			}
		}
		else inputZ[player_num - 1] = 0;

		if ((GetAsyncKeyState(keySet[player_num].GetX()) & 0x8000))
		{
			if (inputX[player_num - 1] == 0)
			{
				if (dummy.empty())
					hero[player_num].SkillOn('x');
				inputX[player_num - 1] = 1;
			}
		}
		else inputX[player_num - 1] = 0;

		if (GetAsyncKeyState(keySet[player_num].GetC()) & 0x8000)
		{
			if (dummy.empty())
				hero[player_num].SkillOn('c');
		}

		if (GetAsyncKeyState(keySet[player_num].GetV()) & 0x8000)
		{
			if (dummy.empty())
				hero[player_num].SkillOn('v');
		}

		if (GetAsyncKeyState(VK_RETURN) & 0x8000)
		{
			if (inputEnter == 0)
			{
				while (getchar() != '\n');
				if (!mob.size())
				{
					gameStage++;
					mobNumber += 4 + gameLevel;
					Respawne();
				}
				inputEnter = 1;
			}
		}
		else inputEnter = 0;

		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
		{
			if (inputEsc == 0)
			{
				SuspensionOption();
				inputEsc = 1;
				inputEnter = 1;
			}
		}
		else inputEsc = 0;
	}
}