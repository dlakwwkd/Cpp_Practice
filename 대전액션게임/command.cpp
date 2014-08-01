// command.cpp : 각종 명령 처리 함수들을 정의합니다.
//

#include "stdafx.h"

void InputCommand(int player_num)
{
	static int inputX[MAX_PLAYER_NUM] = { 0, };
	static int inputZ[MAX_PLAYER_NUM] = { 0, };
	static int inputEnter = 0;
	static int inputEsc = 0;

	if (designateMode[player_num - 1])
	{
		dummy.front().showPos();
		dummy.front().moveAction();

		if (GetAsyncKeyState(keySet[player_num].getUp()) & 0x8000)
			dummy.front().moveInput(InputKey(UP));
		if (GetAsyncKeyState(keySet[player_num].getDown()) & 0x8000)
			dummy.front().moveInput(InputKey(DOWN));
		if (GetAsyncKeyState(keySet[player_num].getLeft()) & 0x8000)
			dummy.front().moveInput(InputKey(LEFT));
		if (GetAsyncKeyState(keySet[player_num].getRight()) & 0x8000)
			dummy.front().moveInput(InputKey(RIGHT));

		if (GetAsyncKeyState(keySet[player_num].getZ()) & 0x8000)
		{
			if (inputZ[player_num - 1] == 0)
			{
				player[player_num].skillOn('z');
				inputZ[player_num - 1] = 1;
			}
		}
		else inputZ[player_num - 1] = 0;

		if ((GetAsyncKeyState(keySet[player_num].getX()) & 0x8000))
		{
			if (inputX[player_num - 1] == 0)
			{
				dummy.pop();
				designateMode[player_num - 1] = OFF;
				inputX[player_num - 1] = 1;
			}
		}
		else inputX[player_num - 1] = 0;

		if (GetAsyncKeyState(keySet[player_num].getC()) & 0x8000)
			player[player_num].skillOn('c');

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
			dummy.back().moveAction();

		if (GetAsyncKeyState(keySet[player_num].getUp()) & 0x8000)
			player[player_num].moveInput(InputKey(UP));
		if (GetAsyncKeyState(keySet[player_num].getDown()) & 0x8000)
			player[player_num].moveInput(InputKey(DOWN));
		if (GetAsyncKeyState(keySet[player_num].getLeft()) & 0x8000)
			player[player_num].moveInput(InputKey(LEFT));
		if (GetAsyncKeyState(keySet[player_num].getRight()) & 0x8000)
			player[player_num].moveInput(InputKey(RIGHT));

		if (GetAsyncKeyState(keySet[player_num].getZ()) & 0x8000)
		{
			if (inputZ[player_num - 1] == 0)
			{
				if (dummy.empty())
					player[player_num].skillOn('z');
				inputZ[player_num - 1] = 1;
			}
		}
		else inputZ[player_num - 1] = 0;

		if ((GetAsyncKeyState(keySet[player_num].getX()) & 0x8000))
		{
			if (inputX[player_num - 1] == 0)
			{
				if (dummy.empty())
					player[player_num].skillOn('x');
				inputX[player_num - 1] = 1;
			}
		}
		else inputX[player_num - 1] = 0;

		if (GetAsyncKeyState(keySet[player_num].getC()) & 0x8000)
		{
			if (dummy.empty())
				player[player_num].skillOn('c');
		}

		if (GetAsyncKeyState(keySet[player_num].getV()) & 0x8000)
		{
			if (dummy.empty())
				player[player_num].skillOn('v');
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
				suspensionOption();
				inputEsc = 1;
				inputEnter = 1;
			}
		}
		else inputEsc = 0;
	}
}