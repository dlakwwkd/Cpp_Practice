// ui.cpp : ���α׷��� UI�� �����ϴ� �Լ����� �����մϴ�.
//

#include "stdafx.h"

std::string mainMenuList[]
=
{
	"[ �̱� �÷��� ]",
	"[ ��Ƽ �÷��� ]",
	" [ ���� ���� ] ",
	" [ ���� ���� ] "
};
std::string modeMenuList[]
=
{
	"[ ���潺 ��� ]",
	" [ ���� ��� ] ",
	" [ ���� ȭ�� ] ",
};
std::string heroList[]
=
{
	"[ ������ �׿��� ]",
	"  [ ���� ȭ�� ]  ",
};


int mainMenuNum = _countof(mainMenuList);
int modeMenuNum = _countof(modeMenuList);
int heroListNum = _countof(heroList);


void mainMenuPrint(int menu)
{
	Print::get().init();
	for (int i = 0; i < mainMenuNum; i++)
	{
		if (menu == i + 1)
		{
			Print::get().inColor(CONSOLE_COLS / 5 * 2, CONSOLE_LINES / 5 * 2 + i, 10);
			Print::get().inColor(CONSOLE_COLS / 5 * 2 + mainMenuList[i].length(), CONSOLE_LINES / 5 * 2 + i, 15);
		}
		Print::get().inText(CONSOLE_COLS / 5 * 2, CONSOLE_LINES / 5 * 2 + i, mainMenuList[i]);
	}
	Print::get().printText();
}

void modeMenuPrint(int menu)
{
	Print::get().init();
	for (int i = 0; i < modeMenuNum; i++)
	{
		if (menu == i + 1)
		{
			Print::get().inColor(CONSOLE_COLS / 5 * 2, CONSOLE_LINES / 5 * 2 + i, 10);
			Print::get().inColor(CONSOLE_COLS / 5 * 2 + modeMenuList[i].length(), CONSOLE_LINES / 5 * 2 + i, 15);
		}
		Print::get().inText(CONSOLE_COLS / 5 * 2, CONSOLE_LINES / 5 * 2 + i, modeMenuList[i]);
	}
	Print::get().printText();
}

void heroListPrint(int menu)
{
	Print::get().init();
	for (int i = 0; i < heroListNum; i++)
	{
		if (menu == i + 1)
		{
			Print::get().inColor(CONSOLE_COLS / 5 * 2, CONSOLE_LINES / 5 * 2 + i, 10);
			Print::get().inColor(CONSOLE_COLS / 5 * 2 + heroList[i].length(), CONSOLE_LINES / 5 * 2 + i, 15);
		}
		Print::get().inText(CONSOLE_COLS / 5 * 2, CONSOLE_LINES / 5 * 2 + i, heroList[i]);
	}
	Print::get().printText();
}

void status(void)
{
	Print::get().inColor(3, PLAY_LINES + 1, 60);
	Print::get().inColor(60, PLAY_LINES + 1, 63);

	//player.at(0).

}




void closeMessage(void)
{
	system("cls");
	std::cout << "Good Bye ~" << std::endl;
	getchar();
}