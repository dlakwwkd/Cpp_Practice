// ai.cpp : 인공지능을 구성하는 함수들을 정의합니다.
//

#include "stdafx.h"

static int to_x2[20] = { 0, };
static int to_y2[20] = { 0, };


void moveAi(void)
{
	static int i;
	i = rand() % mob.size();
	mob.at(i).ai(to_x2[i], to_y2[i]);

	for (i = 0; i < mob.size(); i++)
	{
		mob.at(i).delete_pos();
		if (rand() % 5 == 1) mob.at(i).move(to_x2[i], to_y2[i]);
		mob.at(i).show_pos();
	}
}