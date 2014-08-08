// play.cpp : 게임 진행에 필요한 함수들을 정의합니다.
//

#include "stdafx.h"
#include "command.h"
#include "console.h"
#include "setting.h"
#include "Print.h"
#include "play.h"
#include "Key.h"
#include "ai.h"
#pragma comment(lib, "winmm.lib")


void GameRunLoop(void)
{
	while (gameRun)
	{
		Print::get().PrintTop();
		Print::get().PrintBottom();
		MainMenu();
		if (playerNum == 1)	//임시 설정
		{
			keySet[PLAYER_1].SetZ(VKey(VK_Z));
			keySet[PLAYER_1].SetX(VKey(VK_X));
			keySet[PLAYER_1].SetC(VKey(VK_C));
			keySet[PLAYER_1].SetV(VKey(VK_V));
		}
		else
		{
			keySet[PLAYER_1].SetZ(VKey(VK_I));
			keySet[PLAYER_1].SetX(VKey(VK_O));
			keySet[PLAYER_1].SetC(VKey(VK_P));
			keySet[PLAYER_1].SetV(VKey(VK_OEM_4));
		}
		GamePlayLoop();
	}
}

void GamePlayLoop(void)
{
	InitPlay();
	DWORD prevTime = timeGetTime();
	while (gamePlay)
	{
		DWORD nowTime = timeGetTime();
		deltaTime = nowTime - prevTime;
		prevTime = nowTime;

		Print::get().PrintText();
		Print::get().PrintColor();
		Print::get().FrameCheck();
		Print::get().Init();

		MoveAi();

		if (playerNum > 0)
			PlayerAction(PLAYER_1);
		if (playerNum > 1)
			PlayerAction(PLAYER_2);
	}
}

void PlayerAction(int player_num)
{
	hero[player_num].MoveAction();
	hero[player_num].ShowPos();
	hero[player_num].InitDelay();
	hero[player_num].SkillCheck();

	InputCommand(player_num);

	if (!hero.empty())
		hero[player_num].DeadCheck();
}