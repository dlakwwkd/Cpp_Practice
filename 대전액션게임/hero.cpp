// hero.cpp : hero 클래스와 그 자식 클래스들을 정의합니다.
//

#include "stdafx.h"

Hero::Hero() : Unit()
{
	pos = { 20 ,20 };
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
Hero::~Hero(){}

Inyo::Inyo() : Hero()
{
	name = "Inyo";
	shape = "[]";
	speed = 5;
	hp = 100;
	mp = 100;
	damage = 20;
	max_hp = hp;
	max_mp = mp;
}
Inyo::Inyo(POINT pc) : Hero()
{
	pos = pc;
	move.x = (LONG)pos.x;
	move.y = (LONG)pos.y;
	name = "Inyo";
	shape = "[]";
	speed = 5;
	hp = 100;
	mp = 100;
	damage = 20;
	max_hp = hp;
	max_mp = mp;
}
Inyo::~Inyo(){}

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
		pos.x > mob.at(mob_num).nowPos().x -2 &&
		pos.x < mob.at(mob_num).nowPos().x + 2 &&
		pos.y == mob.at(mob_num).nowPos().y)
	{
		beAttacked(mob.at(mob_num).attack());
	}
}
void Hero::deadCheck(void)
{
	if (is_dead) GameOver();
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

	Setcolor(252); printf("   HP "); Setcolor(206);
	for (int i = 0; i < (int)now_hp; i++)
		printf(" ");
	Setcolor(252);
	printf(" %5d/%5d", hp, max_hp);
	Setcolor(249);
	for (int i = 50; i >(int)now_hp; i--)
		printf(" ");
	printf(" \t\t 공격 : Z key    조준 : X key   \t\t\t");

	if (player.at(0).hp < max_hp)
		player.at(0).hp += 2 + max_hp / 200;
	else player.at(0).hp = max_hp;
}
void Hero::mpStatus(void)
{
	double now_mp = (double)mp * 50 / max_mp;

	Setcolor(249); printf("   MP "); Setcolor(158);
	for (int i = 0; i < (int)now_mp; i++)
		printf(" ");
	Setcolor(249);
	printf(" %5d/%5d", mp, max_mp);
	for (int i = 50; i >(int)now_mp; i--)
		printf(" ");
	printf(" \t\t 스킬1: X -> Z   스킬2: X -> C  \t\t\t");

	if (player.at(0).mp < max_mp)
		player.at(0).mp += 10 + max_mp / 200;
	else player.at(0).mp = max_mp;
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
	if (designateMode)
	{
		if (skill_type == 'z')
		{
			Skill z("Z",
			{ dummy.front().pos.x - 4, dummy.front().pos.y - 1,
			dummy.front().pos.x + 5, dummy.front().pos.y + 3 },
			15, 5, 3);
			skill.push(z);
			if (!dummy.empty())
				dummy.pop();
			designateMode = OFF;
		}
		else if (skill_type == 'c')
		{
			Dummy dumy2(player.at(0).pos);
			dummy.push(dumy2);
			dummy.back().ai(3);

			Skill c("C", { 0, 0, 0, 0 }, 0, 0, 15);
			skill.push(c);
			designateMode = OFF;
		}
	}
	else{
		if (skill_type == 'z')
		{
			Skill z("Z",
			{ player.at(0).pos.x - 4, player.at(0).pos.y - 1,
			player.at(0).pos.x + 5, player.at(0).pos.y + 3 },
			10, 1, 2);
			skill.push(z);
		}
		else if (skill_type == 'x')
		{
			designateMode = ON;
			Dummy dumy(player.at(0).pos);
			dummy.push(dumy);
		}
		else if (skill_type == 'v')
		{
			for (unsigned int i = 0; i < mob.size(); i++)
			{
				mob.at(i).beAttacked(100);
			}
		}
	}
}
void Hero::skillCheck(void)
{
	if (skill.empty()) return;
	else skill.front().skillUse();
}
int Hero::havingHeart(void)
{
	return heart;
}