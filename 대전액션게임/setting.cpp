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
int playerNum;
int lowSpecMode;
bool gameRun;
bool gamePlay;
bool designateMode[MAX_PLAYER_NUM];
unsigned int gameTime;

std::map<int, Hero> player;
std::vector<Unit> mob;
std::queue<Skill> skill;
std::queue<Dummy> dummy;

void InitPlay(void)
{
	srand((unsigned int)time(NULL));
	gameTime = (unsigned int)time(NULL);
	gameStage = 1;
	gameFrame = 0;
	designateMode[0] = OFF;
	designateMode[1] = OFF;

	switch (gameLevel)
	{
	case GameLevel(VERY_EASY):
		mobNumber = 5;
		break;
	case GameLevel(EASY):
		mobNumber = 20;
		break;
	case GameLevel(NOMAL):
		mobNumber = 10;
		break;
	case GameLevel(HARD):
		mobNumber = 30;
		break;
	case GameLevel(VERY_HARD):
		mobNumber = 10;
		break;
	case GameLevel(CRAZY):
		mobNumber = 50;
		break;
	}
	Respawne();
	Print::get().printTop();
	Print::get().printBottom();
}

void HeroCreate(int player_num)
{
	switch (heroType)
	{
	case HeroType(INYO):
		Inyo inyo;
		player[player_num] = inyo;
		player[player_num].setPlayerType(PlayerType(player_num));
		player[player_num].setTeamType(TeamType(A));
		break;
	}
}

void Respawne(void)
{
	if (gameStage % 5 == 0) gameMode = MobMoveForm(MASS);
	else gameMode = MobMoveForm(SCATTER);

	if (gameStage % 3 != 0)
	{
		for (int i = 0; i < mobNumber * gameMode; i++)
		{
			Unit m("mob", "()", 8 + gameLevel*2 + (double)gameStage / 4,		//이속
				10 + gameStage * (2 + gameLevel), 5 + gameStage * gameLevel,	//체력, 마나
				3 + gameStage * (1 + gameLevel/2));								//데미지
			mob.push_back(m);
			mob.front().setPlayerType(PlayerType(COMPUTER));
			mob.front().setTeamType(TeamType(MOB));
		}
	}
	else
	{
		for (int i = 0; i < mobNumber * gameMode; i++)
		{
			Unit m("mob", "><", 12 + gameLevel*2 + (double)gameStage / 3,
				10 + gameStage * (1 + gameLevel), 5 + gameStage * gameLevel,
				3 + gameStage * (2 + gameLevel/2));
			mob.push_back(m);
			mob.front().setPlayerType(PlayerType(COMPUTER));
			mob.front().setTeamType(TeamType(MOB));
		}
	}

}

void MainMenu(void)
{
	int input;
	int menu = 1;
	while (1)
	{
		MainMenuPrint(menu);
		input = _getch();

		if (input == InputKey(SCAN_CODE))
		{
			input = _getch();
			switch (input)
			{
			case InputKey(UP):
				if (menu > 1) menu--;
				else menu = mainMenuNum;
				break;
			case InputKey(DOWN):
				if (menu < mainMenuNum) menu++;
				else menu = 1;
				break;
			}
		}
		else
		{
			switch (input)
			{
			case 'z':
			case InputKey(ENTER):
				if (menu == mainMenuNum){
					gameRun = OFF;
					gamePlay = OFF;
					return;
				}
				else if (menu == 1) PlayerMenu(input);
				else if (menu == 3) OptionMenu();
				else{
					Gotoxy(0, PLAY_LINES);
					printf("아직 준비되지 않은 메뉴입니다.");
					Sleep(500);
				}
				if (gamePlay) return;
				break;
			case InputKey(ESC):
				gameRun = OFF;
				gamePlay = OFF;
				return;
			}
		}
	}
	return;
}
void OptionMenu(void)
{
	int input;
	int menu = 1;
	int menu2 = gameSpeed;
	int menu3 = lowSpecMode + 1;
	while (1)
	{
		OptionMenuPrint(menu, menu2, menu3);
		input = _getch();

		if (input == InputKey(SCAN_CODE))
		{
			input = _getch();
			switch (input)
			{
			case InputKey(UP):
				if (menu > 1) menu--;
				else menu = gameOptionListNum;
				break;
			case InputKey(DOWN):
				if (menu < gameOptionListNum) menu++;
				else menu = 1;
				break;
			case InputKey(LEFT):
				if (menu == 1)
				{
					if (menu2 > 1) menu2--;
					else menu2 = gameSpeedListNum;
				}
				else if (menu == 2)
				{
					if (menu3 > 1) menu3--;
					else menu3 = 2;
				}
				break;
			case InputKey(RIGHT):
				if (menu == 1)
				{
					if (menu2 < gameSpeedListNum) menu2++;
					else menu2 = 1;
				}
				else if (menu == 2)
				{
					if (menu3 < 2) menu3++;
					else menu3 = 1;
				}
				break;
			}
		}
		else
		{
			switch (input)
			{
			case 'z':
			case InputKey(ENTER):
				if (menu == gameOptionListNum)
					return;
				else if (menu == 1)
				{
					if (menu2 < gameSpeedListNum) menu2++;
					else menu2 = 1;
				}
				else if (menu == 2)
				{
					if (menu3 < 2) menu3++;
					else menu3 = 1;
				}
				break;
			case 'x':
			case InputKey(ESC):
				return;
			}
		}
	}
	return;
}
void PlayerMenu(int input)
{
	int menu = 1;
	while (1)
	{
		PlayerListPrint(menu);
		input = _getch();

		if (input == InputKey(SCAN_CODE))
		{
			input = _getch();
			switch (input)
			{
			case InputKey(UP):
				if (menu > 1) menu--;
				else menu = playerListNum;
				break;
			case InputKey(DOWN):
				if (menu < playerListNum) menu++;
				else menu = 1;
				break;
			}
		}
		else
		{
			switch (input)
			{
			case 'z':
			case InputKey(ENTER):
				if (menu == playerListNum){
					gamePlay = OFF;
					return;
				}
				playerNum = menu;
				SelectMode(input);
				if (gamePlay) return;
				break;
			case 'x':
			case InputKey(ESC):
				gamePlay = OFF;
				return;
			}
		}
	}
	return;
}
void SelectMode(int input)
{
	int menu = 1;
	while (1)
	{
		ModeMenuPrint(menu);
		input = _getch();

		if (input == InputKey(SCAN_CODE))
		{
			input = _getch();
			switch (input)
			{
			case InputKey(UP):
				if (menu > 1) menu--;
				else menu = modeMenuNum;
				break;
			case InputKey(DOWN):
				if (menu < modeMenuNum) menu++;
				else menu = 1;
				break;
			}
		}
		else
		{
			switch (input)
			{
			case 'z':
			case InputKey(ENTER):
				if (menu == modeMenuNum){
					gamePlay = OFF;
					return;
				}
				gameLevel = menu;
				SelectHero(PLAYER_1);
				if (playerNum > 1)
					SelectHero(PLAYER_2);
				if (gamePlay) return;
				break;
			case 'x':
			case InputKey(ESC):
				gamePlay = OFF;
				return;
			}
		}
	}
	return;
}
void SelectHero(int player_num)
{
	int input;
	int menu = 1;
	while (1)
	{
		HeroListPrint(menu);
		input = _getch();

		if (input == InputKey(SCAN_CODE))
		{
			input = _getch();
			switch (input)
			{
			case InputKey(UP):
				if (menu > 1) menu--;
				else menu = heroListNum;
				break;
			case InputKey(DOWN):
				if (menu < heroListNum) menu++;
				else menu = 1;
				break;
			}
		}
		else
		{
			switch (input)
			{
			case 'z':
			case InputKey(ENTER):
				if (menu == heroListNum){
					gamePlay = OFF;
					return;
				}
				heroType = menu;
				HeroCreate(player_num);
				gamePlay = ON;
				return;
			case 'x':
			case InputKey(ESC):
				gamePlay = OFF;
				return;
			}
		}
	}
	return;
}
void suspensionOption(void)
{
	int input;
	int menu = 1;

	suspensionOptionPrint();
	while (getchar() != '\n');

	while (1)
	{
		suspensionOptionListPrint(menu);
		input = _getch();

		if (input == InputKey(SCAN_CODE))
		{
			input = _getch();
			switch (input)
			{
			case InputKey(UP):
				if (menu > 1) menu--;
				else menu = suspensionOptionListNum;
				break;
			case InputKey(DOWN):
				if (menu < suspensionOptionListNum) menu++;
				else menu = 1;
				break;
			}
		}
		else
		{
			switch (input)
			{
			case 'z':
			case InputKey(ENTER):
				if (menu == suspensionOptionListNum)
				{
					if (!player.empty()) player.clear();
					if (!mob.empty()) mob.clear();
					while (!dummy.empty()) dummy.pop();
					while (!skill.empty()) skill.pop();
					system("cls");
					gamePlay = OFF;
					return;
				}
				else if (menu == 2)
				{
					OptionMenu();
					break;
				}
				else
				{
					gamePlay = ON;
					return;
				}
			}
		}
	}
	return;
}

void GameOver(int player_num)
{
	int input;
	int menu = 1;

	GameOverPrint();
	while (getchar() != '\n');

	while (1)
	{
		GameOverListPrint(menu);
		input = _getch();

		if (input == InputKey(SCAN_CODE))
		{
			input = _getch();
			switch (input)
			{
			case InputKey(UP):
				if (menu > 1) menu--;
				else menu = gameOverListNum;
				break;
			case InputKey(DOWN):
				if (menu < gameOverListNum) menu++;
				else menu = 1;
				break;
			}
		}
		else
		{
			switch (input)
			{
			case 'z':
			case InputKey(ENTER):
				if (menu == gameOverListNum)
				{
					if (!player.empty()) player.clear();
					if (!mob.empty()) mob.clear();
					while (!dummy.empty()) dummy.pop();
					while (!skill.empty()) skill.pop();
					system("cls");
					gamePlay = OFF;
					return;
				}
				if (player[player_num].havingHeart() > 0)
				{
					player[player_num].revive();
					gamePlay = ON;
					return;
				}
				else{
					Gotoxy(CONSOLE_COLS / 3 + 8, CONSOLE_LINES / 3 + 8);
					Setcolor(15);
					printf(" 더 이상 생명이 없습니다. ");
					Sleep(500);
				}
			}
		}
	}
	return;
}
