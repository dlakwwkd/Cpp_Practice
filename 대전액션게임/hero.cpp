// hero.cpp : hero 클래스와 그 자식 클래스들을 정의합니다.
//

#include "stdafx.h"

Hero::Hero() : Unit()
{
	pos.y = 10;
	move.y = 10;

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

Inyo::~Inyo()
{
}

void Hero::dead_check(void)
{
	if (is_dead) gameOver();
}
void Hero::revive(void)
{
	hp = 100;
	Print::get().printBottom();
	is_dead = false;
	heart--;
}
void Hero::hp_status()
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
		player.at(0).hp += 1;
}
void Hero::mp_status()
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
		player.at(0).mp += 2;
}
void Hero::init_delay()
{
	if (delay > 0)
		delay--;
	else delay = 0;
}
void Hero::move_input(int input_key)
{
	switch (input_key)
	{
	case UP_KEY:
		move_power.y -= speed / 2;
		break;
	case DOWN_KEY:
		move_power.y += speed / 2;
		break;
	case LEFT_KEY:
		move_power.x -= speed;
		break;
	case RIGHT_KEY:
		move_power.x += speed;
		break;
	}
}
void Hero::skill_on(int skill_type)
{
	if (designateMode)
	{
		if (skill_type == 'z')
		{
			Skill z("Z",
			{ dummy.front().pos.x - 2, dummy.front().pos.y,
			dummy.front().pos.x + 3, dummy.front().pos.y + 2 },
			15, 10, 3);
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
			20, 5, 2);
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
			for (int i = 0; i < mob.size(); i++)
			{
				mob.at(i).be_attacked(100);
			}
		}
	}
}
void Hero::skill_use(void)
{
	if (skill.empty()) return;

	if (skill.front().name == "Z")
		skill.front().skill_z();
	else if (skill.front().name == "C")
	{
		skill.front().cooldown--;

		Skill c_dummy("C_dummy",
		{ dummy.back().pos.x - 6, dummy.back().pos.y - 2,
		dummy.back().pos.x + 7, dummy.back().pos.y + 4 },
		12, 6, 2);
		skill.push(c_dummy);

		if (skill.front().cooldown < 1){
			while (!dummy.empty())
			{
				dummy.pop();
			}
		}
	}
	else if (skill.front().name == "C_dummy")
	{
		skill.front().skill_c();
	}

	if (skill.front().cooldown < 1)
		skill.pop();
}