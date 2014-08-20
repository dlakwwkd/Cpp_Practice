// main.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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