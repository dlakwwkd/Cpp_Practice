// setting.cpp : ���� ���, ���� ���� �� ���� ���ÿ� ���õ� �Լ����� �����մϴ�.
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

void InitPlay(void)
{
	srand((unsigned int)time(NULL));
	gameTime = (unsigned int)time(NULL);
	gameStage = 1;
	gameFrame = 0;
	designateMode = OFF;

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

void HeroCreate(void)
{
	switch (heroType)
	{
	case HeroType(INYO):
		Inyo inyo;
		player.push_back(inyo);
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
			Unit m("mob", "()", 8 + gameLevel*2 + (double)gameStage / 4,		//�̼�
				10 + gameStage * (2 + gameLevel), 5 + gameStage * gameLevel,	//ü��, ����
				3 + gameStage * (1 + gameLevel/2));								//������
			mob.push_back(m);
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
				else if (menu == 1) SelectMode(input);
				else if (menu == 3) OptionMenu();
				else{
					Gotoxy(0, PLAY_LINES);
					printf("���� �غ���� ���� �޴��Դϴ�.");
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
				SelectHero();
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
void SelectHero(void)
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
				HeroCreate();
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

void GameOver(void)
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
				if (player.at(0).havingHeart() > 0)
				{
					player.at(0).revive();
					gamePlay = ON;
					return;
				}
				else{
					Gotoxy(CONSOLE_COLS / 3 + 8, CONSOLE_LINES / 3 + 8);
					Setcolor(15);
					printf(" �� �̻� ������ �����ϴ�. ");
					Sleep(500);
				}
			}
		}
	}
	return;
}
