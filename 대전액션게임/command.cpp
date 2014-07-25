// command.cpp : 각종 명령 처리 함수들을 정의합니다.
//

#include "stdafx.h"

void InputCommand()
{
	static int inputX = 0;
	static int inputZ = 0;
	static int inputEnter = 0;
	static int inputEsc = 0;

	if (designateMode)
	{
		dummy.front().showPos();
		dummy.front().moveAction();

		if (GetAsyncKeyState(VK_UP) & 0x8000)
			dummy.front().moveInput(InputKey(UP));
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
			dummy.front().moveInput(InputKey(DOWN));
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
			dummy.front().moveInput(InputKey(LEFT));
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
			dummy.front().moveInput(InputKey(RIGHT));

		if (GetAsyncKeyState(InputKey(Z_KEY)) & 0x8000)
		{
			if (inputZ == 0)
			{
				player.at(0).skillOn('z');
				inputZ = 1;
			}
		}
		else inputZ = 0;

		if ((GetAsyncKeyState(InputKey(X_KEY)) & 0x8000))
		{
			if (inputX == 0)
			{
				dummy.pop();
				designateMode = OFF;
				inputX = 1;
			}
		}
		else inputX = 0;

		if (GetAsyncKeyState(InputKey(C_KEY)) & 0x8000)
			player.at(0).skillOn('c');

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
				designateMode = OFF;
				inputEsc = 1;
			}
		}
		else inputEsc = 0;
	}
	else
	{
		if (!dummy.empty())
			dummy.back().moveAction();

		if (GetAsyncKeyState(VK_UP) & 0x8000)
			player.at(0).moveInput(InputKey(UP));
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
			player.at(0).moveInput(InputKey(DOWN));
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
			player.at(0).moveInput(InputKey(LEFT));
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
			player.at(0).moveInput(InputKey(RIGHT));

		if (GetAsyncKeyState(InputKey(Z_KEY)) & 0x8000)
		{
			if (inputZ == 0)
			{
				if (dummy.empty())
					player.at(0).skillOn('z');
				inputZ = 1;
			}
		}
		else inputZ = 0;

		if ((GetAsyncKeyState(InputKey(X_KEY)) & 0x8000))
		{
			if (inputX == 0)
			{
				if (dummy.empty())
					player.at(0).skillOn('x');
				inputX = 1;
			}
		}
		else inputX = 0;

		if (GetAsyncKeyState(InputKey(C_KEY)) & 0x8000)
		{
			if (dummy.empty())
				player.at(0).skillOn('c');
		}

		if (GetAsyncKeyState(InputKey(V_KEY)) & 0x8000)
		{
			if (dummy.empty())
				player.at(0).skillOn('v');
		}

		if (GetAsyncKeyState(VK_RETURN) & 0x8000)
		{
			if (inputEnter == 0)
			{
				while (getchar() != '\n');
				if (!mob.size())
				{
					gameStage++;
					mobNumber += 5;
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