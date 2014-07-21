// ai.cpp : 인공지능을 구성하는 함수들을 정의합니다.
//

#include "stdafx.h"

void moveAi(void)
{
	if (mob.size() == 0) return;
	static unsigned int i;
	
	switch (gameMode)
	{
	case MOB_MOVE_FORM(SCATTER):
		break;
	case MOB_MOVE_FORM(MASS):
		i = rand() % mob.size();
		mob.at(i).ai(50);
		break;
	}

	for (i = 0; i < mob.size(); i++)
	{
		switch (gameMode)
		{
		case MOB_MOVE_FORM(SCATTER):
			if (rand() % 30/gameLevel == 0)
				mob.at(i).ai(20);
			mob.at(i).move_type();
			break;
		case MOB_MOVE_FORM(MASS):
			if (rand() % (mob.size() / 10 / gameLevel + 1) == 0)
				mob.at(i).move_type();
			break;
		}
		mob.at(i).show_pos();

		player.at(0).hit_check(i);

		if (mob.at(i).dead_check()) mob.erase(mob.begin() + i);
	}
}