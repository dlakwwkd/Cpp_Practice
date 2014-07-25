// ai.cpp : 인공지능을 구성하는 함수들을 정의합니다.
//

#include "stdafx.h"

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
		mob.at(i).ai(30);
		break;
	}

	for (i = 0; i < mob.size(); i++)
	{
		switch (gameMode)
		{
		case MobMoveForm(SCATTER):
			if (rand() % 20 - gameLevel*3 == 0)
				mob.at(i).ai(20);
			mob.at(i).moveType();
			break;
		case MobMoveForm(MASS):
			if (rand() % 10 - gameLevel/2 == 0)
				mob.at(i).moveType();
			break;
		}
		mob.at(i).showPos();

		player.at(0).hitCheck(i);

		if (mob.at(i).deadCheck()) mob.erase(mob.begin() + i);
	}
}