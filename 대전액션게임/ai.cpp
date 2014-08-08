// ai.cpp : 인공지능을 구성하는 함수들을 정의합니다.
//

#include "stdafx.h"
#include "setting.h"
#include "ai.h"

void MoveAi(void)
{
	if (mob.size() == 0) return;
	static unsigned int i;
	
	switch (gameMode)
	{
	case MobMoveForm(SCATTER):
		break;
	case MobMoveForm(MASS):
		i = rand() % mob.size();
		mob.at(i).Ai(30);
		break;
	}

	for (i = 0; i < mob.size(); i++)
	{
		switch (gameMode)
		{
		case MobMoveForm(SCATTER):
			if (rand() % 20 - gameLevel*3 == 0)
				mob.at(i).Ai(20);
			mob.at(i).MoveType();
			break;
		case MobMoveForm(MASS):
			if (rand() % 10 - gameLevel/2 == 0)
				mob.at(i).MoveType();
			break;
		}
		mob.at(i).ShowPos();

		if (playerNum > 0)
			hero[PLAYER_1].HitCheck(i);
		if (playerNum > 1)
			hero[PLAYER_2].HitCheck(i);

		if (mob.at(i).DeadCheck()) mob.erase(mob.begin() + i);
	}
}