// ai.cpp : 인공지능을 구성하는 함수들을 정의합니다.
//

#include "stdafx.h"

void moveAi(void)
{
	if (mob.size() == 0) return;
	static unsigned int i;
	
	switch (gameMode)
	{
	case MODE1:
		break;
	case MODE2:
		i = rand() % mob.size();
		mob.at(i).ai(50);
		break;
	}

	for (i = 0; i < mob.size(); i++)
	{
		switch (gameMode)
		{
		case MODE1:
			if (rand() % 20 == 0)
				mob.at(i).ai(20);
			mob.at(i).move_action(mob.at(i).move);
			break;
		case MODE2:
			if (rand() % (mob.size() / 10 + 1) == 0)
				mob.at(i).move_action(mob.at(i).public_move);
			break;
		}

		mob.at(i).show_pos();

		if (player.at(0).delay == 0)
			player.at(0).be_attacked(mob.at(i).attack());
		if (mob.at(i).is_dead) mob.erase(mob.begin() + i);
	}
}