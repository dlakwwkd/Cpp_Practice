// setting.cpp : 게임 모드, 영웅 선택 등 게임 셋팅에 관련된 함수들을 정의합니다.
//

#include "stdafx.h"

int gameRun;
int gamePlay;
int gameMode;
int heroType;

std::vector<Hero> player;
std::vector<Unit> mob;

void initPlay(void)
{
	srand((int)time(NULL));
	gameRun = ON;
}

void mainMenu(void)
{
	int input;
	int menu = 1;
	while (1)
	{
		mainMenuPrint(menu);
		input = _getch();

		if (input == SCAN_CODE)
		{
			input = _getch();
			switch (input)
			{
			case UP_KEY:
				if (menu > 1) menu--;
				break;
			case DOWN_KEY:
				if (menu < mainMenuNum) menu++;
				break;
			}
		}
		else
		{
			switch (input)
			{
			case ENTER_KEY:
				if (menu == mainMenuNum){
					gameRun = OFF;
					gamePlay = OFF;
					return;
				}
				selectMode(input);
				if (gamePlay) return;
				break;
			case ESC_KEY:
				gameRun = OFF;
				gamePlay = OFF;
				return;
			}
		}
	}
	return;
}

void selectMode(int input)
{
	int menu = 1;
	while (1)
	{
		modeMenuPrint(menu);
		input = _getch();

		if (input == SCAN_CODE)
		{
			input = _getch();
			switch (input)
			{
			case UP_KEY:
				if (menu > 1) menu--;
				break;
			case DOWN_KEY:
				if (menu < modeMenuNum) menu++;
				break;
			}
		}
		else
		{
			switch (input)
			{
			case ENTER_KEY:
				if (menu == modeMenuNum){
					gamePlay = OFF;
					return;
				}
				gameMode = menu;
				selectHero();
				if (gamePlay) return;
				break;
			case ESC_KEY:
				gamePlay = OFF;
				return;
			}
		}
	}
	return;
}


void selectHero(void)
{
	int input;
	int menu = 1;
	while (1)
	{
		heroListPrint(menu);
		input = _getch();

		if (input == SCAN_CODE)
		{
			input = _getch();
			switch (input)
			{
			case UP_KEY:
				if (menu > 1) menu--;
				break;
			case DOWN_KEY:
				if (menu < heroListNum) menu++;
				break;
			}
		}
		else
		{
			switch (input)
			{
			case ENTER_KEY:
				if (menu == heroListNum){
					gamePlay = OFF;
					return;
				}
				heroType = menu;
				heroCreate();
				gamePlay = ON;
				return;
			case ESC_KEY:
				gamePlay = OFF;
				return;
			}
		}
	}
	return;
}

void heroCreate(void)
{
	switch (heroType)
	{
	case TYPE1:
		Inyo inyo;
		player.push_back(inyo);
		break;
	}
}

void respawne(void)
{
	for (int i = 0; i < 20; i++){
		Unit m;
		mob.push_back(m);
	}
}