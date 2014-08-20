#include "stdafx.h"
#include "GameManager.h"
#include "setting.h"
#include "Print.h"
#include "Frame.h"
#include "Menu.h"
#include "Inyo.h"
#include "Key.h"
#include "ai.h"
#include "ui.h"


GameManager::GameManager()
{
	m_GameRun		= ON;
	m_GamePlay		= OFF;
	m_HeroType		= 1;
}


GameManager::~GameManager()
{
}


void GameManager::InitPlay(void)
{
	srand((unsigned int)time(NULL));
	gameStage = 1;
	scopeMode[0] = OFF;
	scopeMode[1] = OFF;

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
	mob.reserve(MAX_MOB_NUM);
	Respawne();
	Print::get().PrintTop();
	Print::get().PrintBottom();
}

void GameManager::HeroCreate(int player_num)
{
	switch (m_HeroType)
	{
	case HeroType(INYO):
		Inyo* inyo = new Inyo;
		hero[player_num] = inyo;
		hero[player_num]->SetPlayerType(PlayerType(player_num));
		break;
	}
}

void GameManager::Respawne(void)
{
	if (gameStage % 5 == 0) gameMode = MobMoveForm(MASS);
	else gameMode = MobMoveForm(SCATTER);

	if (gameStage % 3 != 0)
	{
		for (int i = 0; i < mobNumber * gameMode; i++)
		{
			Unit* m = new Unit("mob", "()", 8 + gameLevel * 2 + (double)gameStage / 4,	//이속
				10 + gameStage * (2 + gameLevel), 5 + gameStage * gameLevel,		//체력, 마나
				3 + gameStage * (1 + gameLevel / 2));									//데미지
			mob.push_back(m);
		}
	}
	else
	{
		for (int i = 0; i < mobNumber * gameMode; i++)
		{
			Unit* m = new Unit("mob", "><", 12 + gameLevel * 2 + (double)gameStage / 3,
				10 + gameStage * (1 + gameLevel), 5 + gameStage * gameLevel,
				3 + gameStage * (2 + gameLevel / 2));
			mob.push_back(m);
		}
	}

}

void GameManager::GameRunLoop(void)
{
	while (m_GameRun)
	{
		Print::get().PrintTop();
		Print::get().PrintBottom();
		Menu::get().SetMenuType(MAIN);
		Menu::get().SetOn(ON);
		Menu::get().MenuPlatform();
		if (playerNum == 1)	//임시 설정
		{
			keySet[PLAYER_1]->SetZ(VKey(VK_Z));
			keySet[PLAYER_1]->SetX(VKey(VK_X));
			keySet[PLAYER_1]->SetC(VKey(VK_C));
			keySet[PLAYER_1]->SetV(VKey(VK_V));
		}
		else
		{
			keySet[PLAYER_1]->SetZ(VKey(VK_I));
			keySet[PLAYER_1]->SetX(VKey(VK_O));
			keySet[PLAYER_1]->SetC(VKey(VK_P));
			keySet[PLAYER_1]->SetV(VKey(VK_OEM_4));
		}
		GamePlayLoop();
	}
}

void GameManager::GamePlayLoop(void)
{
	InitPlay();
	while (m_GamePlay)
	{
		Print::get().PrintText();
		Print::get().PrintColor();
		Print::get().Init();
		Frame::get().SetDeltaTime();
		Frame::get().FrameCheck();

		MoveAi();

		if (playerNum > 0)
			PlayerAction(PLAYER_1);
		if (playerNum > 1)
			PlayerAction(PLAYER_2);
	}
	DeleteVestige();
}

void GameManager::PlayerAction(int player_num)
{
	if (!m_GamePlay) return;

	hero[player_num]->MoveAction();
	hero[player_num]->ShowPos();
	hero[player_num]->InitDelay();
	hero[player_num]->SkillCheck();

	InputCommand(player_num);

	if (!hero.empty())
	{
		if (hero[player_num]->DeadCheck())
			GameOver(player_num);
	}
}

void GameManager::PauseOption(void)
{
	PausePrint();
	while (getchar() != '\n');

	Menu::get().SetOn(ON);
	Menu::get().SetMenuType(PAUSE);
	Menu::get().MenuPlatform();
}

void GameManager::GameOver(int player_num)
{
	GameOverPrint();
	while (getchar() != '\n');

	Menu::get().SetOn(ON);
	Menu::get().SetMenuType(GAME_OVER);
	Menu::get().MenuPlatform();
}

void GameManager::DeleteVestige(void)
{
	if (!hero.empty())
	{
		std::map<int, Hero*>::iterator p;
		for (p = hero.begin(); p != hero.end(); ++p)
		{
			delete p->second;
		}
		hero.clear();
	}
	if (!mob.empty())
	{
		for (auto& p : mob)
		{
			delete p;
		}
		mob.clear();
	}
	for (int i = 0; i < MAX_PLAYER_NUM; ++i)
	{
		while (!dummy[i].empty())
		{
			delete dummy[i].front();
			dummy[i].pop();
		}
		while (!skill[i].empty())
		{
			delete skill[i].front();
			skill[i].pop();
		}
	}
	system("cls");
}



void GameManager::InputCommand(int player_num)
{
	static int inputX[MAX_PLAYER_NUM] = { 0, };
	static int inputZ[MAX_PLAYER_NUM] = { 0, };
	static int inputEnter = 0;
	static int inputEsc = 0;

	if (scopeMode[player_num])
	{
		dummy[player_num].front()->ShowPos();
		dummy[player_num].front()->MoveAction();

		if (GetAsyncKeyState(keySet[player_num]->GetUp()) & 0x8000)
			dummy[player_num].front()->MoveInput(InputKey(UP));
		if (GetAsyncKeyState(keySet[player_num]->GetDown()) & 0x8000)
			dummy[player_num].front()->MoveInput(InputKey(DOWN));
		if (GetAsyncKeyState(keySet[player_num]->GetLeft()) & 0x8000)
			dummy[player_num].front()->MoveInput(InputKey(LEFT));
		if (GetAsyncKeyState(keySet[player_num]->GetRight()) & 0x8000)
			dummy[player_num].front()->MoveInput(InputKey(RIGHT));

		if (GetAsyncKeyState(keySet[player_num]->GetZ()) & 0x8000)
		{
			if (inputZ[player_num] == 0)
			{
				hero[player_num]->SkillOn('z');
				inputZ[player_num] = 1;
			}
		}
		else inputZ[player_num] = 0;

		if ((GetAsyncKeyState(keySet[player_num]->GetX()) & 0x8000))
		{
			if (inputX[player_num] == 0)
			{
				delete dummy[player_num].front();
				dummy[player_num].pop();
				scopeMode[player_num] = OFF;
				inputX[player_num] = 1;
			}
		}
		else inputX[player_num] = 0;

		if (GetAsyncKeyState(keySet[player_num]->GetC()) & 0x8000)
			hero[player_num]->SkillOn('c');

		if (GetAsyncKeyState(VK_RETURN) & 0x8000)
		{
			if (inputEnter == 0)
			{
				while (getchar() != '\n');
				inputEnter = 1;
			}
		}
		else inputEnter = 0;

		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
		{
			if (inputEnter == 0)
			{
				delete dummy[player_num].front();
				dummy[player_num].pop();
				scopeMode[player_num] = OFF;
				inputEsc = 1;
			}
		}
		else inputEsc = 0;
	}
	else
	{
		if (!dummy[player_num].empty())
			dummy[player_num].back()->MoveAction();

		if (GetAsyncKeyState(keySet[player_num]->GetUp()) & 0x8000)
			hero[player_num]->MoveInput(InputKey(UP));
		if (GetAsyncKeyState(keySet[player_num]->GetDown()) & 0x8000)
			hero[player_num]->MoveInput(InputKey(DOWN));
		if (GetAsyncKeyState(keySet[player_num]->GetLeft()) & 0x8000)
			hero[player_num]->MoveInput(InputKey(LEFT));
		if (GetAsyncKeyState(keySet[player_num]->GetRight()) & 0x8000)
			hero[player_num]->MoveInput(InputKey(RIGHT));

		if (GetAsyncKeyState(keySet[player_num]->GetZ()) & 0x8000)
		{
			if (inputZ[player_num] == 0)
			{
				if (dummy[player_num].empty())
					hero[player_num]->SkillOn('z');
				inputZ[player_num] = 1;
			}
		}
		else inputZ[player_num] = 0;

		if ((GetAsyncKeyState(keySet[player_num]->GetX()) & 0x8000))
		{
			if (inputX[player_num] == 0)
			{
				if (dummy[player_num].empty())
					hero[player_num]->SkillOn('x');
				inputX[player_num] = 1;
			}
		}
		else inputX[player_num] = 0;

		if (GetAsyncKeyState(keySet[player_num]->GetC()) & 0x8000)
		{
			if (dummy[player_num].empty())
				hero[player_num]->SkillOn('c');
		}

		if (GetAsyncKeyState(keySet[player_num]->GetV()) & 0x8000)
		{
			if (dummy[player_num].empty())
				hero[player_num]->SkillOn('v');
		}

		if (GetAsyncKeyState(VK_RETURN) & 0x8000)
		{
			if (inputEnter == 0)
			{
				while (getchar() != '\n');
				if (!mob.size())
				{
					gameStage++;
					mobNumber += 4 + gameLevel;
					Respawne();
				}
				inputEnter = 1;
			}
		}
		else inputEnter = 0;

		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
		{
			if (inputEsc == 0)
			{
				PauseOption();
				inputEsc = 1;
				inputEnter = 1;
			}
		}
		else inputEsc = 0;
	}
}