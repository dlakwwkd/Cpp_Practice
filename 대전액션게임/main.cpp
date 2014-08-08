// main.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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