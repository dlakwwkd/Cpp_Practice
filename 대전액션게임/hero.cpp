#include "stdafx.h"


Hero::Hero() : Unit()
{
	pos = { 20, 20 };
	move = { 20, 20 };

	delay = 0;
	heart = 3;
	max_hp = hp;
	max_mp = mp;
}
Hero::Hero(POINT pc) : Unit()
{
	pos = pc;
	move.x = (LONG)pos.x;
	move.y = (LONG)pos.y;

	delay = 0;
	heart = 3;
	max_hp = hp;
	max_mp = mp;
}
Hero::~Hero()
{
}


void Hero::showPos(void)
{
	if (is_dead) return;
	if (!lowSpecMode)
		heroColor.push_back({ pos.x, pos.y });
	Print::get().inText(pos.x, pos.y, shape);
}
void Hero::hitCheck(int mob_num)
{
	if (delay == 0 &&
		pos.x > mob.at(mob_num).nowPos().x - 2 &&
		pos.x < mob.at(mob_num).nowPos().x + 2 &&
		pos.y == mob.at(mob_num).nowPos().y)
	{
		addDelay();
		beAttacked(mob.at(mob_num).attack(), PlayerType(MOB));
		Print::get().printBottom();
	}
}
void Hero::deadCheck(void)
{
	if (is_dead) GameOver(checkPlayerType());
}
void Hero::revive(void)
{
	hp = max_hp;
	mp = max_mp;
	Print::get().printBottom();
	is_dead = false;
	heart--;
}
void Hero::levelUp(void)
{
	max_hp += 2;
	max_mp += 1;
}
void Hero::hpStatus(void)
{
	double now_hp = (double)hp * 50 / max_hp;

	Setcolor(252); printf("  HP "); Setcolor(206);
	for (int i = 0; i < (int)now_hp; i++)
		printf(" ");
	Setcolor(252);
	printf(" %4d/%4d ", hp, max_hp);
	Setcolor(249);
	for (int i = 50; i >(int)now_hp; i--)
		printf(" ");

	if (hp < max_hp)
		hp += 2 + max_hp / 200;
	else hp = max_hp;
	if (hp > max_hp)
		hp = max_hp;
}
void Hero::mpStatus(void)
{
	double now_mp = (double)mp * 50 / max_mp;

	Setcolor(249); printf("  MP "); Setcolor(158);
	for (int i = 0; i < (int)now_mp; i++)
		printf(" ");
	Setcolor(249);
	printf(" %4d/%4d ", mp, max_mp);
	for (int i = 50; i >(int)now_mp; i--)
		printf(" ");

	if (mp < max_mp)
		mp += 10 + max_mp / 200;
	else mp = max_mp;
	if (mp > max_mp)
		mp = max_mp;
}
void Hero::initDelay(void)
{
	if (delay > 0)
		delay--;
	else delay = 0;
}
void Hero::addDelay(void)
{
	delay += 2;
}
void Hero::moveInput(int input)
{
	switch (input)
	{
	case InputKey(UP):
		if (move_power.y > -50)
			move_power.y -= speed / 2;
		break;
	case InputKey(DOWN):
		if (move_power.y < 50)
			move_power.y += speed / 2;
		break;
	case InputKey(LEFT):
		if (move_power.x > -50)
			move_power.x -= speed;
		break;
	case InputKey(RIGHT):
		if (move_power.x < 50)
			move_power.x += speed;
		break;
	}
}
void Hero::moveAction(void)
{
	if (move_power.x > 1 || move_power.x < -1) move_power.x -= move_power.x / 10;
	else move_power.x = 0;

	if (move_power.y > 1 || move_power.y < -1) move_power.y -= move_power.y / 10;
	else move_power.y = 0;

	if (move_power.x)
	{
		move.x += move_power.x / 10;

		if (move.x < 0)
			move.x = 0;
		else if (move.x > PLAY_COLS)
			move.x = PLAY_COLS;
	}
	if (move_power.y)
	{
		move.y += move_power.y / 10;

		if (move.y < 0)
			move.y = 0;
		else if (move.y > PLAY_LINES)
			move.y = PLAY_LINES;
	}
	pos = { (LONG)move.x, (LONG)move.y };
}
void Hero::skillOn(int skill_type)
{
	if (designateMode[checkPlayerType() - 1])
	{
		if (skill_type == 'z')
		{
			Skill z("Z",
			{ dummy.front().pos.x - 4, dummy.front().pos.y - 1,
			dummy.front().pos.x + 5, dummy.front().pos.y + 3 },
			15, 5, 3);
			skill.push(z);
			skill.back().setPlayerType(checkPlayerType());
			skill.back().setTeamType(checkTeamType());
			if (!dummy.empty())
				dummy.pop();
			designateMode[checkPlayerType() - 1] = OFF;
		}
		else if (skill_type == 'c')
		{
			Dummy dumy2(pos);
			dummy.push(dumy2);
			dummy.back().setPlayerType(checkPlayerType());
			dummy.back().setTeamType(checkTeamType());
			dummy.back().ai(3);

			Skill c("C", { 0, 0, 0, 0 }, 0, 0, 15);
			skill.push(c);
			skill.back().setPlayerType(checkPlayerType());
			skill.back().setTeamType(checkTeamType());
			designateMode[checkPlayerType() - 1] = OFF;
		}
	}
	else{
		if (skill_type == 'z')
		{
			Skill z("Z",
			{ pos.x - 4, pos.y - 1,
			pos.x + 5, pos.y + 3 },
			10, 1, 2);
			skill.push(z);
			skill.back().setPlayerType(checkPlayerType());
			skill.back().setTeamType(checkTeamType());
		}
		else if (skill_type == 'x')
		{
			designateMode[checkPlayerType() - 1] = ON;
			Dummy dumy(pos);
			dummy.push(dumy);
			dummy.back().setPlayerType(checkPlayerType());
			dummy.back().setTeamType(checkTeamType());
		}
		else if (skill_type == 'v')
		{
			for (unsigned int i = 0; i < mob.size(); i++)
			{
				mob.at(i).beAttacked(100, checkPlayerType());
			}
		}
	}
}
void Hero::skillCheck(void)
{
	if (skill.empty()) return;
	else skill.front().skillUse();
}