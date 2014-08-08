// ui.cpp : 프로그램의 UI를 구성하는 함수들을 정의합니다.
//

#include "stdafx.h"
#include "console.h"
#include "setting.h"
#include "Print.h"
#include "ui.h"

std::string mainMenuList[]
=
{
	"[  싱글 플레이  ]",
	"[  멀티 플레이  ]",
	"[   게임 설정   ]",
	"[   게임 종료   ]"
};
std::string playerList[]
=
{
	"[   1P 플레이   ]",
	"[   2P 플레이   ]",
	"[   이전 화면   ]"
};
std::string modeMenuList[]
=
{
	"[   매우 쉬움   ]",
	"[     쉬움      ]",
	"[     보통      ]",
	"[    어려움     ]",
	"[  매우 어려움  ]",
	"[     HELL      ]",
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
std::string suspensionOptionList[]
=
{
	"[   계속 하기   ]",
	"[   게임 설정   ]",
	"[   처음 으로   ]",
};
std::string gameOptionList[]
=
{
	"[   게임 속도   ]",
	"[  저사양 모드  ]",
	"[   이전 화면   ]",
};
std::string gamem_SpeedList[]
=
{
	"[   매우 느림   ]",
	"[     느림      ]",
	"[     보통      ]",
	"[     빠름      ]",
	"[   매우 빠름   ]",
	"[   제한 없음   ]",
};
std::string lowSpecList[]
=
{
	"[     끄기      ]",
	"[     켜기      ]",
};

int mainMenuNum = _countof(mainMenuList);
int playerListNum = _countof(playerList);
int modeMenuNum = _countof(modeMenuList);
int heroListNum = _countof(heroList);
int gameOverListNum = _countof(gameOverList);
int gameOptionListNum = _countof(gameOptionList);
int gamem_SpeedListNum = _countof(gamem_SpeedList);
int suspensionOptionListNum = _countof(suspensionOptionList);

void MainMenuPrint(int menu)
{
	Print::get().Init();
	for (int i = 0; i < mainMenuNum; i++)
	{
		if (menu == i + 1)
		{
			Print::get().InText(CONSOLE_COLS / 5 * 2, CONSOLE_LINES / 5 * 2 + i, "☞");
		}
		Print::get().InText(CONSOLE_COLS / 5 * 2 + 3, CONSOLE_LINES / 5 * 2 + i, mainMenuList[i]);
	}
	Print::get().PrintText();
}

void PlayerListPrint(int menu)
{
	Print::get().Init();
	for (int i = 0; i < playerListNum; i++)
	{
		if (menu == i + 1)
		{
			Print::get().InText(CONSOLE_COLS / 5 * 2, CONSOLE_LINES / 5 * 2 + i, "☞");
		}
		Print::get().InText(CONSOLE_COLS / 5 * 2 + 3, CONSOLE_LINES / 5 * 2 + i, playerList[i]);
	}
	Print::get().PrintText();
}

void OptionMenuPrint(int menu, int menu2, int menu3)
{
	Print::get().Init();
	for (int i = 0; i < gameOptionListNum; i++)
	{
		if (menu == i + 1)
		{
			Print::get().InText(CONSOLE_COLS / 3, CONSOLE_LINES / 5 * 2 + i, "☞");
		}
		Print::get().InText(CONSOLE_COLS / 3 + 3, CONSOLE_LINES / 5 * 2 + i, gameOptionList[i]);
	}
	Print::get().InText(CONSOLE_COLS / 2, CONSOLE_LINES / 5 * 2, gamem_SpeedList[menu2 - 1]);
	Print::get().InText(CONSOLE_COLS / 2, CONSOLE_LINES / 5 * 2 + 1, lowSpecList[menu3 - 1]);
	Print::get().PrintText();
	gameSpeed = menu2;
	lowSpecMode = menu3 - 1;
}

void ModeMenuPrint(int menu)
{
	Print::get().Init();
	for (int i = 0; i < modeMenuNum; i++)
	{
		if (menu == i + 1)
		{
			Print::get().InText(CONSOLE_COLS / 5 * 2, CONSOLE_LINES / 5 * 2 + i, "☞");
		}
		Print::get().InText(CONSOLE_COLS / 5 * 2 + 3, CONSOLE_LINES / 5 * 2 + i, modeMenuList[i]);
	}
	Print::get().PrintText();
}

void HeroListPrint(int menu)
{
	Print::get().Init();
	for (int i = 0; i < heroListNum; i++)
	{
		if (menu == i + 1)
		{
			Print::get().InText(CONSOLE_COLS / 5 * 2, CONSOLE_LINES / 5 * 2 + i, "☞");
		}
		Print::get().InText(CONSOLE_COLS / 5 * 2 + 3, CONSOLE_LINES / 5 * 2 + i, heroList[i]);
	}
	Print::get().PrintText();
}

void GameOverPrint(void)
{
	Gotoxy(0, CONSOLE_LINES / 3 - 1);
	Setcolor(11);
	for (int i = 0; i <= CONSOLE_COLS; i++)
	{
		printf("-");
		Gotoxy(CONSOLE_COLS - i, CONSOLE_LINES / 2 + 5);
		printf("-");
		Gotoxy(i, CONSOLE_LINES / 3 - 1);
		Sleep(1);
	}

	Gotoxy(CONSOLE_COLS / 5 * 2 + 2, CONSOLE_LINES / 3 + 3);
	Setcolor(12);
	printf("== [ Game Over ] ==");
	Gotoxy(CONSOLE_COLS / 5 * 2 + 3, CONSOLE_LINES / 3 + 5);
	Setcolor(15);
	printf("   남은 생명: %d ", hero[PLAYER_1].HavingHeart());
	Gotoxy(CONSOLE_COLS / 5 * 2 + 3, CONSOLE_LINES / 3 + 7);
	Setcolor(14);
	printf("Press Enter Key...");
	Setcolor(0);
}

void GameOverListPrint(int menu)
{
	Print::get().Init();
	Print::get().InText(CONSOLE_COLS / 5 * 2 + 2, CONSOLE_LINES / 3 + 2, "== [ Game Over ] ==");
	for (int i = 0; i < gameOverListNum; i++)
	{
		if (menu == i + 1)
		{
			Print::get().InText(CONSOLE_COLS / 5 * 2, CONSOLE_LINES / 3 + 4 + i, "☞");
		}
		Print::get().InText(CONSOLE_COLS / 5 * 2 + 3, CONSOLE_LINES / 3 + 4 + i, gameOverList[i]);
	}
	Print::get().PrintText();
}

void suspensionOptionPrint(void)
{
	Gotoxy(0, CONSOLE_LINES / 3 - 1);
	Setcolor(11);
	for (int i = 0; i <= CONSOLE_COLS; i++)
	{
		printf("=");
		Gotoxy(CONSOLE_COLS - i, CONSOLE_LINES / 2 + 5);
		printf("=");
		Gotoxy(i, CONSOLE_LINES / 3 - 1);
	}

	Gotoxy(CONSOLE_COLS / 5 * 2 + 2, CONSOLE_LINES / 3 + 4);
	Setcolor(15);
	printf("== [ 일시 정지 ] ==");
	Gotoxy(CONSOLE_COLS / 5 * 2 + 3, CONSOLE_LINES / 3 + 6);
	Setcolor(14);
	printf("Press Enter Key...");
	Setcolor(0);
}

void suspensionOptionListPrint(int menu)
{
	Print::get().Init();
	Print::get().InText(CONSOLE_COLS / 5 * 2 + 2, CONSOLE_LINES / 3 + 2, "== [ Game Otion ] ==");
	for (int i = 0; i < suspensionOptionListNum; i++)
	{
		if (menu == i + 1)
		{
			Print::get().InText(CONSOLE_COLS / 5 * 2, CONSOLE_LINES / 3 + 4 + i, "☞");
		}
		Print::get().InText(CONSOLE_COLS / 5 * 2 + 3, CONSOLE_LINES / 3 + 4 + i, suspensionOptionList[i]);
	}
	Print::get().PrintText();
}

void CloseMessage(void)
{
	system("cls");
	std::cout << "Good Bye ~" << std::endl;
	getchar();
}