// ui.cpp : ���α׷��� UI�� �����ϴ� �Լ����� �����մϴ�.
//

#include "stdafx.h"

std::string mainMenuList[]
=
{
	"[ �̱� �÷��� ]",
	"[ ��Ƽ �÷��� ]",
	" [ ���� ���� ]",
	" [ ���� ���� ]"
};
std::string modeMenuList[]
=
{
	"[ ���潺 ��� ]",
	" [ ���� ��� ]",
	" [ ���� ȭ�� ]",
};
std::string heroList[]
=
{
	"[ ������ �׿��� ]",
	"  [ ���� ȭ�� ]",
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