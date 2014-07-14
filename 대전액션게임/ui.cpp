// ui.cpp : 프로그램의 UI를 구성하는 함수들을 정의합니다.
//

#include "stdafx.h"

std::string mainMenuList[]
=
{
	"[ 싱글 플레이 ]",
	"[ 멀티 플레이 ]",
	" [ 게임 설정 ]",
	" [ 게임 종료 ]"
};
std::string modeMenuList[]
=
{
	"[ 디펜스 모드 ]",
	" [ 대전 모드 ]",
	" [ 이전 화면 ]",
};
std::string heroList[]
=
{
	"[ 빛나는 잉여군 ]",
	"  [ 이전 화면 ]",
};

int a = sizeof(mainMenuList) / sizeof(std::string);
int b = sizeof(modeMenuList) / sizeof(std::string);
int c = sizeof(heroList) / sizeof(std::string);


void mainMenuPrint(int menu)
{
	Print::get().init();
	for (int i = 0; i < mainMenuNum; i++)
	{
		if (menu == i + 1) Print::get().inColor(CONSOLE_COLS / 5 * 2, CONSOLE_LINES / 5 * 2 + i, 10);
		else Print::get().inColor(CONSOLE_COLS / 5 * 2, CONSOLE_LINES / 5 * 2 + i, 0);
		Print::get().inText(CONSOLE_COLS / 5 * 2, CONSOLE_LINES / 5 * 2 + i, mainMenuList[i]);
	}
	Print::get().printText();
}

void modeMenuPrint(int menu)
{
	Print::get().init();
	for (int i = 0; i < modeMenuNum; i++)
	{
		if (menu == i + 1) Print::get().inColor(CONSOLE_COLS / 5 * 2, CONSOLE_LINES / 5 * 2 + i, 10);
		else Print::get().inColor(CONSOLE_COLS / 5 * 2, CONSOLE_LINES / 5 * 2 + i, 0);
		Print::get().inText(CONSOLE_COLS / 5 * 2, CONSOLE_LINES / 5 * 2 + i, modeMenuList[i]);
	}
	Print::get().printText();
}

void heroListPrint(int menu)
{
	Print::get().init();
	for (int i = 0; i < heroListNum; i++)
	{
		if (menu == i + 1) Print::get().inColor(CONSOLE_COLS / 5 * 2, CONSOLE_LINES / 5 * 2 + i, 10);
		else Print::get().inColor(CONSOLE_COLS / 5 * 2, CONSOLE_LINES / 5 * 2 + i, 0);
		Print::get().inText(CONSOLE_COLS / 5 * 2, CONSOLE_LINES / 5 * 2 + i, heroList[i]);
	}
	Print::get().printText();
}

void closeMessage(void)
{
	system("cls");
	std::cout << "Good Bye ~" << std::endl;
}