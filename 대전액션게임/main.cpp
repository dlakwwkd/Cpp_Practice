// main.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "GameManager.h"
#include "Menu.h"
#include "console.h"
#include "setting.h"
#include "ui.h"

int _tmain(void)
{
	InitConsole();

	GameManager GM;
	Menu::get().SetGM(&GM);
	GM.GameRunLoop();

	CloseMessage();
	return 0;
}