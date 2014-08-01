// ui.cpp : ���α׷��� UI�� �����ϴ� �Լ����� �����մϴ�.
//

#include "stdafx.h"

std::string MainMenuList[]
=
{
	"[  �̱� �÷���  ]",
	"[  ��Ƽ �÷���  ]",
	"[   ���� ����   ]",
	"[   ���� ����   ]"
};
std::string playerList[]
=
{
	"[   1P �÷���   ]",
	"[   2P �÷���   ]",
	"[   ���� ȭ��   ]"
};
std::string modeMenuList[]
=
{
	"[   �ſ� ����   ]",
	"[     ����      ]",
	"[     ����      ]",
	"[    �����     ]",
	"[  �ſ� �����  ]",
	"[     HELL      ]",
	"[   ���� ȭ��   ]",
};
std::string heroList[]
=
{
	"[ ������ �׿��� ]",
	"[   ���� ȭ��   ]",
};
std::string GameOverList[]
=
{
	"[   �̾� �ϱ�   ]",
	"[   ó�� ����   ]",
};
std::string suspensionOptionList[]
=
{
	"[   ��� �ϱ�   ]",
	"[   ���� ����   ]",
	"[   ó�� ����   ]",
};
std::string gameOptionList[]
=
{
	"[   ���� �ӵ�   ]",
	"[  ����� ���  ]",
	"[   ���� ȭ��   ]",
};
std::string gameSpeedList[]
=
{
	"[   �ſ� ����   ]",
	"[     ����      ]",
	"[     ����      ]",
	"[     ����      ]",
	"[   �ſ� ����   ]",
	"[   ���� ����   ]",
};
std::string lowSpecList[]
=
{
	"[     ����      ]",
	"[     �ѱ�      ]",
};

int mainMenuNum = _countof(MainMenuList);
int playerListNum = _countof(playerList);
int modeMenuNum = _countof(modeMenuList);
int heroListNum = _countof(heroList);
int gameOverListNum = _countof(GameOverList);
int gameOptionListNum = _countof(gameOptionList);
int gameSpeedListNum = _countof(gameSpeedList);
int suspensionOptionListNum = _countof(suspensionOptionList);

void MainMenuPrint(int menu)
{
	Print::get().init();
	for (int i = 0; i < mainMenuNum; i++)
	{
		if (menu == i + 1)
		{
			Print::get().inText(CONSOLE_COLS / 5 * 2, CONSOLE_LINES / 5 * 2 + i, "��");
		}
		Print::get().inText(CONSOLE_COLS / 5 * 2 + 3, CONSOLE_LINES / 5 * 2 + i, MainMenuList[i]);
	}
	Print::get().printText();
}

void PlayerListPrint(int menu)
{
	Print::get().init();
	for (int i = 0; i < playerListNum; i++)
	{
		if (menu == i + 1)
		{
			Print::get().inText(CONSOLE_COLS / 5 * 2, CONSOLE_LINES / 5 * 2 + i, "��");
		}
		Print::get().inText(CONSOLE_COLS / 5 * 2 + 3, CONSOLE_LINES / 5 * 2 + i, playerList[i]);
	}
	Print::get().printText();
}

void OptionMenuPrint(int menu, int menu2, int menu3)
{
	Print::get().init();
	for (int i = 0; i < gameOptionListNum; i++)
	{
		if (menu == i + 1)
		{
			Print::get().inText(CONSOLE_COLS / 3, CONSOLE_LINES / 5 * 2 + i, "��");
		}
		Print::get().inText(CONSOLE_COLS / 3 + 3, CONSOLE_LINES / 5 * 2 + i, gameOptionList[i]);
	}
	Print::get().inText(CONSOLE_COLS / 2, CONSOLE_LINES / 5 * 2, gameSpeedList[menu2 - 1]);
	Print::get().inText(CONSOLE_COLS / 2, CONSOLE_LINES / 5 * 2 + 1, lowSpecList[menu3 - 1]);
	Print::get().printText();
	gameSpeed = menu2;
	lowSpecMode = menu3 - 1;
}

void ModeMenuPrint(int menu)
{
	Print::get().init();
	for (int i = 0; i < modeMenuNum; i++)
	{
		if (menu == i + 1)
		{
			Print::get().inText(CONSOLE_COLS / 5 * 2, CONSOLE_LINES / 5 * 2 + i, "��");
		}
		Print::get().inText(CONSOLE_COLS / 5 * 2 + 3, CONSOLE_LINES / 5 * 2 + i, modeMenuList[i]);
	}
	Print::get().printText();
}

void HeroListPrint(int menu)
{
	Print::get().init();
	for (int i = 0; i < heroListNum; i++)
	{
		if (menu == i + 1)
		{
			Print::get().inText(CONSOLE_COLS / 5 * 2, CONSOLE_LINES / 5 * 2 + i, "��");
		}
		Print::get().inText(CONSOLE_COLS / 5 * 2 + 3, CONSOLE_LINES / 5 * 2 + i, heroList[i]);
	}
	Print::get().printText();
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
	printf("   ���� ����: %d ", player[PLAYER_1].havingHeart());
	Gotoxy(CONSOLE_COLS / 5 * 2 + 3, CONSOLE_LINES / 3 + 7);
	Setcolor(14);
	printf("Press Enter Key...");
	Setcolor(0);
}

void GameOverListPrint(int menu)
{
	Print::get().init();
	Print::get().inText(CONSOLE_COLS / 5 * 2 + 2, CONSOLE_LINES / 3 + 2, "== [ Game Over ] ==");
	for (int i = 0; i < gameOverListNum; i++)
	{
		if (menu == i + 1)
		{
			Print::get().inText(CONSOLE_COLS / 5 * 2, CONSOLE_LINES / 3 + 4 + i, "��");
		}
		Print::get().inText(CONSOLE_COLS / 5 * 2 + 3, CONSOLE_LINES / 3 + 4 + i, GameOverList[i]);
	}
	Print::get().printText();
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
	printf("== [ �Ͻ� ���� ] ==");
	Gotoxy(CONSOLE_COLS / 5 * 2 + 3, CONSOLE_LINES / 3 + 6);
	Setcolor(14);
	printf("Press Enter Key...");
	Setcolor(0);
}

void suspensionOptionListPrint(int menu)
{
	Print::get().init();
	Print::get().inText(CONSOLE_COLS / 5 * 2 + 2, CONSOLE_LINES / 3 + 2, "== [ Game Otion ] ==");
	for (int i = 0; i < suspensionOptionListNum; i++)
	{
		if (menu == i + 1)
		{
			Print::get().inText(CONSOLE_COLS / 5 * 2, CONSOLE_LINES / 3 + 4 + i, "��");
		}
		Print::get().inText(CONSOLE_COLS / 5 * 2 + 3, CONSOLE_LINES / 3 + 4 + i, suspensionOptionList[i]);
	}
	Print::get().printText();
}

void CloseMessage(void)
{
	system("cls");
	std::cout << "Good Bye ~" << std::endl;
	getchar();
}