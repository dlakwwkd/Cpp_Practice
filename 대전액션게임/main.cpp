// main.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	argc; argv;

	gameRun = ON;
	gameSpeed = GameSpeed(MODERATE);
	lowSpecMode = OFF;

	InitConsole();
	GameRunLoop();
	CloseMessage();
	return 0;
}