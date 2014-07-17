// ai.cpp : 인공지능을 구성하는 함수들을 정의합니다.
//

#include "stdafx.h"

void moveAi(void)
{
	static unsigned int i;
	
	for (i = 0; i < mob.size(); i++)
	{
		if (rand() % 20 == 1)
			mob.at(i).ai();
		mob.at(i).move();
		mob.at(i).show_pos();
	}
}
void moveAiBoss(void)
{
	static unsigned int i;

	i = rand() % mob.size();
	mob.at(i).ai_boss();

	for (i = 0; i < mob.size(); i++)
	{
		if (rand() % 10 == 1)
			mob.at(i).move_boss();
		mob.at(i).show_pos();
	}
}