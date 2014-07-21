// ui.cpp : 프로그램의 UI를 구성하는 함수들을 정의합니다.
//

#include "stdafx.h"

std::string mainMenuList[]
=
{
	"[  싱글 플레이  ]",
	"[  멀티 플레이  ]",
	"[   게임 설정   ]",
	"[   게임 종료   ]"
};
std::string modeMenuList[]
=
{
	"[  초급 난이도  ]",
	"[  중급 난이도  ]",
	"[  상급 난이도  ]",
	"[   이전 화면   ]",
};
std::string heroList[]
=
{
	"[ 빛나는 잉여군 ]",
	"[   이전 화면   ]",
};
std::string gameOverList[]
=
{
	"[   이어 하기   ]",
	"[   처음 으로   ]",
};

int mainMenuNum = _countof(mainMenuList);
int modeMenuNum = _countof(modeMenuList);
int heroListNum = _countof(heroList);
int gameOverListNum = _countof(gameOverList);

void mainMenuPrint(int menu)
{
	Print::get().init();
	for (int i = 0; i < mainMenuNum; i++)
	{
		if (menu == i + 1)
		{
			Print::get().inText(CONSOLE_COLS / 5 * 2 - 3, CONSOLE_LINES / 5 * 2 + i, "☞");
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
			Print::get().inText(CONSOLE_COLS / 5 * 2 - 3, CONSOLE_LINES / 5 * 2 + i, "☞");
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
			Print::get().inText(CONSOLE_COLS / 5 * 2 - 3, CONSOLE_LINES / 5 * 2 + i, "☞");
		}
		Print::get().inText(CONSOLE_COLS / 5 * 2, CONSOLE_LINES / 5 * 2 + i, heroList[i]);
	}
	Print::get().printText();
}

void gameOverListPrint(int menu)
{
	Print::get().init();
	Print::get().inColor(CONSOLE_COLS / 5 * 2 - 1, CONSOLE_LINES / 3 - 1, 11);
	Print::get().inText(CONSOLE_COLS / 5 * 2 - 1, CONSOLE_LINES / 3 - 1, "== [ Game Over ] ==");
	for (int i = 0; i < gameOverListNum; i++)
	{
		if (menu == i + 1)
		{
			Print::get().inText(CONSOLE_COLS / 5 * 2 - 3, CONSOLE_LINES / 5 * 2 + i, "☞");
		}
		Print::get().inText(CONSOLE_COLS / 5 * 2, CONSOLE_LINES / 5 * 2 + i, gameOverList[i]);
	}
	Print::get().printText();
}



void closeMessage(void)
{
	system("cls");
	std::cout << "Good Bye ~" << std::endl;
	getchar();
}