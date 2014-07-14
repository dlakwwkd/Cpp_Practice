// ai.cpp : 인공지능을 구성하는 함수들을 정의합니다.
//

#include "stdafx.h"

static int to_x2[100] = { 0, };
static int to_y2[100] = { 0, };


void moveAi(void)
{
	static int i;
	
	i = rand() % mob.size();
	mob.at(i).ai(to_x2[i], to_y2[i]);

	for (i = 0; i < mob.size(); i++)
	{
		if (rand() % 10 == 1) mob.at(i).move();
		mob.at(i).show_pos();
	}
}