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
	speed = 12;
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
	speed = 12;
	hp = 100;
	mp = 100;
	damage = 20;
	max_hp = hp;
	max_mp = mp;
}
Inyo::~Inyo(){}

void Hero::show_pos(void)
{
	if (is_dead) return;
	Print::get().inColor(pos.x, pos.y, 14);
	Print::get().inColor(pos.x + 2, pos.y, DEF_COLOR(SCREEN));
	Print::get().inText(pos.x, pos.y, shape);
}
void Hero::hit_check(int mob_num)
{
	if (delay == 0 &&
		pos.x > mob.at(mob_num).now_pos().x -2 &&
		pos.x < mob.at(mob_num).now_pos().x + 2 &&
		pos.y == mob.at(mob_num).now_pos().y)
	{
		be_attacked(mob.at(mob_num).attack());
	}
}
void Hero::dead_check(void)
{
	if (is_dead) gameOver();
}
void Hero::revive(void)
{
	hp = max_hp;
	Print::get().printBottom();
	is_dead = false;
	heart--;
}
void Hero::level_up(void)
{
	max_hp += 1;
	max_mp += 1;
}
void Hero::hp_status(void)
{
	double now_hp = (double)hp * 50 / max_hp;

	setcolor(252); printf("   HP "); setcolor(206);
	for (int i = 0; i < (int)now_hp; i++)
		printf(" ");
	setcolor(252);
	printf(" %4d/%4d", hp, max_hp);
	setcolor(249);
	for (int i = 50; i >(int)now_hp; i--)
		printf(" ");
	printf("  공격 : Z key    조준 : X key    ");

	if (player.at(0).hp < max_hp)
		player.at(0).hp += 1 + max_hp / 300;
}
void Hero::mp_status(void)
{
	double now_mp = (double)mp * 50 / max_mp;

	setcolor(249); printf("   MP "); setcolor(158);
	for (int i = 0; i < (int)now_mp; i++)
		printf(" ");
	setcolor(249);
	printf(" %4d/%4d", mp, max_mp);
	for (int i = 50; i >(int)now_mp; i--)
		printf(" ");
	printf("  스킬1: X -> Z   스킬2: X -> C   ");

	if (player.at(0).mp < max_mp)
		player.at(0).mp += 2 + max_mp / 300;
}
void Hero::init_delay(void)
{
	if (delay > 0)
		delay--;
	else delay = 0;
}
void Hero::add_delay(void)
{
	delay += 2;
}
void Hero::move_input(int input_key)
{
	switch (input_key)
	{
	case INPUT_KEY(UP):
		move_power.y -= speed / 2;
		break;
	case INPUT_KEY(DOWN):
		move_power.y += speed / 2;
		break;
	case INPUT_KEY(LEFT):
		move_power.x -= speed;
		break;
	case INPUT_KEY(RIGHT):
		move_power.x += speed;
		break;
	}
}
void Hero::move_action(void)
{
	if (move_power.x > 1 || move_power.x < -1) move_power.x -= move_power.x / 16;
	else move_power.x = 0;

	if (move_power.y > 1 || move_power.y < -1) move_power.y -= move_power.y / 16;
	else move_power.y = 0;

	if (move_power.x)
	{
		move.x += move_power.x / 8;

		if (move.x < 0)
			move.x = 0;
		else if (move.x > PLAY_COLS)
			move.x = PLAY_COLS;
	}
	if (move_power.y)
	{
		move.y += move_power.y / 8;

		if (move.y < 0)
			move.y = 0;
		else if (move.y > PLAY_LINES)
			move.y = PLAY_LINES;
	}
	pos = { (LONG)move.x, (LONG)move.y };
}
void Hero::skill_on(int skill_type)
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
			dummy.pop();
			designateMode = OFF;
		}
		else if (skill_type == 'c')
		{
			Dummy dumy2(player.at(0).pos);
			dummy.push(dumy2);
			dummy.back().ai(12);

			Skill c("C", { 0, 0, 0, 0 }, 0, 0, 12);
			skill.push(c);
			designateMode = OFF;
		}
	}
	else{
		if (skill_type == 'z')
		{
			Skill z("Z",
			{ player.at(0).pos.x - 2, player.at(0).pos.y,
			player.at(0).pos.x + 3, player.at(0).pos.y + 2 },
			10, 2, 3);
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
				mob.at(i).be_attacked(100);
			}
		}
	}
}
void Hero::skill_check(void)
{
	if (skill.empty()) return;
	else skill.front().skill_use();
}
int Hero::having_heart(void)
{
	return heart;
}