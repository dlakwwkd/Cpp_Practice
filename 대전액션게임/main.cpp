// main.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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