// setting.cpp : 게임 모드, 영웅 선택 등 게임 셋팅에 관련된 함수들을 정의합니다.
//

#include "stdafx.h"

int gameSpeed;
int gameStage;
int gameLevel;
int gameFrame;
int gameMode;
int heroType;
int mobNumber;
bool gameRun;
bool gamePlay;
bool lowSpecMode;
bool designateMode;
unsigned int gameTime;

std::vector<Hero> player;
std::vector<Unit> mob;
std::queue<Skill> skill;
std::queue<Dummy> dummy;

void initPlay(void)
{
	srand((unsigned int)time(NULL));
	gameTime = (unsigned int)time(NULL);
	gameSpeed = GAME_SPEED(MODERATE);
	gameStage = 1;
	gameFrame = 0;
	lowSpecMode = OFF;
	designateMode = OFF;

	switch (gameLevel)
	{
	case GAME_LEVEL(EASY):
		mobNumber = 10;
		break;
	case GAME_LEVEL(NOMAL):
		mobNumber = 30;
		break;
	case GAME_LEVEL(HARD):
		mobNumber = 10;
		break;
	}
	respawne();
	Print::get().printTop();
	Print::get().printBottom();
}

void heroCreate(void)
{
	switch (heroType)
	{
	case HERO_TYPE(INYO):
		Inyo inyo;
		player.push_back(inyo);
		break;
	}
}

void respawne(void)
{
	if (gameStage % 6 == 0) gameMode = MOB_MOVE_FORM(MASS);
	else gameMode = MOB_MOVE_FORM(SCATTER);

	if (gameStage % 3 != 0)
	{
		for (int i = 0; i < mobNumber; i++)
		{
			Unit m("mob", "()", 3 * gameLevel + (double)gameStage / 3 * gameLevel,
				10 + gameStage * (2 + gameLevel), 5 + gameStage * (gameLevel), 3 + gameStage * (1 + gameLevel));
			mob.push_back(m);
		}
	}
	else
	{
		for (int i = 0; i < mobNumber; i++)
		{
			Unit m("mob", "><", 6 * gameLevel + (double)gameStage / 2 * gameLevel,
				10 + gameStage * gameLevel, 5 + gameStage * (gameLevel), 3 + gameStage * (2 + gameLevel));
			mob.push_back(m);
		}
	}

}

void mainMenu(void)
{
	int input;
	int menu = 1;
	setcolor(15);
	while (1)
	{
		mainMenuPrint(menu);
		input = _getch();

		if (input == INPUT_KEY(SCAN_CODE))
		{
			input = _getch();
			switch (input)
			{
			case INPUT_KEY(UP):
				if (menu > 1) menu--;
				else menu = mainMenuNum;
				break;
			case INPUT_KEY(DOWN):
				if (menu < mainMenuNum) menu++;
				else menu = 1;
				break;
			}
		}
		else
		{
			switch (input)
			{
			case INPUT_KEY(ENTER):
				if (menu == mainMenuNum){
					gameRun = OFF;
					gamePlay = OFF;
					return;
				}
				else if (menu == 1) selectMode(input);
				else{
					gotoxy(0, PLAY_LINES);
					printf("아직 준비되지 않은 메뉴입니다.");
					Sleep(500);
				}
				if (gamePlay) return;
				break;
			case INPUT_KEY(ESC):
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

		if (input == INPUT_KEY(SCAN_CODE))
		{
			input = _getch();
			switch (input)
			{
			case INPUT_KEY(UP):
				if (menu > 1) menu--;
				else menu = modeMenuNum;
				break;
			case INPUT_KEY(DOWN):
				if (menu < modeMenuNum) menu++;
				else menu = 1;
				break;
			}
		}
		else
		{
			switch (input)
			{
			case INPUT_KEY(ENTER):
				if (menu == modeMenuNum){
					gamePlay = OFF;
					return;
				}
				gameLevel = menu;
				selectHero();
				if (gamePlay) return;
				break;
			case INPUT_KEY(ESC):
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

		if (input == INPUT_KEY(SCAN_CODE))
		{
			input = _getch();
			switch (input)
			{
			case INPUT_KEY(UP):
				if (menu > 1) menu--;
				else menu = heroListNum;
				break;
			case INPUT_KEY(DOWN):
				if (menu < heroListNum) menu++;
				else menu = 1;
				break;
			}
		}
		else
		{
			switch (input)
			{
			case INPUT_KEY(ENTER):
				if (menu == heroListNum){
					gamePlay = OFF;
					return;
				}
				heroType = menu;
				heroCreate();
				gamePlay = ON;
				return;
			case INPUT_KEY(ESC):
				gamePlay = OFF;
				return;
			}
		}
	}
	return;
}
void gameOver(void)
{
	int input;
	int menu = 1;
	while (1)
	{
		gameOverListPrint(menu);
		input = _getch();

		if (input == INPUT_KEY(SCAN_CODE))
		{
			input = _getch();
			switch (input)
			{
			case INPUT_KEY(UP):
				if (menu > 1) menu--;
				else menu = gameOverListNum;
				break;
			case INPUT_KEY(DOWN):
				if (menu < gameOverListNum) menu++;
				else menu = 1;
				break;
			}
		}
		else
		{
			switch (input)
			{
			case INPUT_KEY(ENTER):
				if (menu == gameOverListNum)
				{
					player.clear();
					mob.clear();
					system("cls");
					gamePlay = OFF;
					return;
				}
				if (player.at(0).having_heart() > 0)
				{
					player.at(0).revive();
				}
				else{
					gotoxy(CONSOLE_COLS / 3 + 3, CONSOLE_LINES / 4 * 2);
					setcolor(10);
					printf(" 더 이상 생명이 없습니다. ");
					Sleep(500);
				}
				gamePlay = ON;
				return;
			}
		}
	}
	return;
}
