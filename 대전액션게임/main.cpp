// main.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "console.h"
#include "setting.h"
#include "play.h"
#include "ui.h"

int _tmain(int argc, _TCHAR* argv[])
{
	argc; argv;

	playerNum = 0;
	gameRun = ON;
	gameSpeed = GameSpeed(MODERATE);
	lowSpecMode = OFF;

	InitConsole();
	GameRunLoop();
	CloseMessage();
	return 0;
}