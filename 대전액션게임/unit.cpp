// unit.cpp : Unit 클래스와 그 자식 클래스들을 정의합니다.
//

#include "stdafx.h"

int Unit::x_left = 0;
int Unit::x_right = 0;
int Unit::y_up = 0;
int Unit::y_down = 0;
double Unit::move_x_public = 0;
double Unit::move_y_public = 1;

Unit::Unit() : pos_x(0), pos_y(1), move_x(0), move_y(1), to_x(0), to_y(0), to_x_power(0), to_y_power(0),
	name("unit"), shape("><"), move_speed(10), hp(100), damage(10), is_dead(false){}

Unit::Unit(int x, int y) : pos_x(x), pos_y(y), move_x(0), move_y(1), to_x(0), to_y(0), to_x_power(0), to_y_power(0),
	name("unit"), shape("><"), move_speed(10), hp(100), damage(10), is_dead(false){}

Unit::Unit(const Unit &pc)
{
	pos_x = pc.pos_x;
	pos_y = pc.pos_y;
	move_x = pc.move_x;
	move_y = pc.move_y;
	to_x = pc.to_x;
	to_y = pc.to_y;
	to_x_power = pc.to_x_power;
	to_y_power = pc.to_y_power;
	name = pc.name;
	shape = pc.shape;
	move_speed = pc.move_speed;
	hp = pc.hp;
	damage = pc.damage;
	is_dead = pc.is_dead;
}
Unit::~Unit()
{
}



Hero::Hero() : Unit()
{
	name = "Hero";
	shape = "◆";
	move_speed = 12;
	hp = 200;
	damage = 20;

	skill_z_on = 0;
}

Hero::Hero(int x, int y) : Unit()
{
	name = "Hero";
	shape = "◆";
	pos_x = x;
	pos_y = y;
	move_speed = 12;
	hp = 200;
	damage = 20;

	skill_z_on = 0;
}


Hero::~Hero()
{
}



Inyo::Inyo() : Hero()
{
	name = "Inyo";
	shape = "◈";
	move_speed = 12;
	hp = 200;
	damage = 20;

	skill_z_on = 0;
}

Inyo::Inyo(int x, int y) : Hero()
{
	name = "Inyo";
	shape = "◈";
	pos_x = x;
	pos_y = y;
	move_speed = 12;
	hp = 200;
	damage = 20;

	skill_z_on = 0;
}


Inyo::~Inyo()
{
}


void Unit::print(void)
{
	printf("%d", pos_x);
}

void Unit::move(void)
{
	if (to_x_power > 1 || to_x_power < -1) to_x_power -= to_x_power / 10;
	else to_x_power = 0;

	if (to_y_power > 1 || to_y_power < -1) to_y_power -= to_y_power / 10;
	else to_y_power = 0;

	if (to_x_power)
	{
		move_x += to_x_power / 5;

		if (move_x < 0)
			move_x = 0;
		else if (move_x > PLAY_COLS)
			move_x = PLAY_COLS;
	}
	if (to_y_power)
	{
		move_y += to_y_power / 5;

		if (move_y < 1)
			move_y = 1;
		else if (move_y > PLAY_LINES)
			move_y = PLAY_LINES;
	}
	pos_x = (int)move_x;
	pos_y = (int)move_y;
}
void Unit::move_boss(void)
{
	if (to_x_power > 1 || to_x_power < -1) to_x_power -= to_x_power / 5;
	else to_x_power = 0;

	if (to_y_power > 1 || to_y_power < -1) to_y_power -= to_y_power / 5;
	else to_y_power = 0;

	if (to_x_power)
	{
		move_x_public += to_x_power / 5;

		if (move_x_public < 0)
			move_x_public = 0;
		else if (move_x_public > PLAY_COLS)
			move_x_public = PLAY_COLS;
	}
	if (to_y_power)
	{
		move_y_public += to_y_power / 5;

		if (move_y_public < 1)
			move_y_public = 1;
		else if (move_y_public > PLAY_LINES)
			move_y_public = PLAY_LINES;
	}
	pos_x = (int)move_x_public;
	pos_y = (int)move_y_public;
}
void Unit::ai_boss(void)
{
	to_x = rand() % PLAY_COLS;
	to_y = rand() % PLAY_LINES + 1;

	to_x_power = (to_x - pos_x) * move_speed / 50;
	to_y_power = (to_y - pos_y) * move_speed / 50;
}
void Unit::ai(void)
{
	to_x = rand() % PLAY_COLS;
	to_y = rand() % PLAY_LINES + 1;

	to_x_power = (to_x - pos_x) * move_speed / 20;
	to_y_power = (to_y - pos_y) * move_speed / 20;
}
int Unit::attack()
{
	return damage;
}
void Unit::be_attacked(int damage_earn)
{
	hp -= damage_earn;
	if (hp <= 0)
		is_dead = true;
}
int Unit::hit(void)
{
	if (pos_x > x_left - 1 && pos_x < x_right + 1 &&
		pos_y > y_up - 2 && pos_y < y_down + 2) return 1;
	else return 0;
}
void Unit::release(void)
{
	is_dead = false;
}
void Unit::show_pos()
{
	if (is_dead) return;
	Print::get().inText(pos_x, pos_y, shape);
}


void Hero::hp_status()
{
	static int max_hp = hp;
	double now_hp = (hp / max_hp) * 100;

	//Print::get().inText()
}



void Hero::move_input(int input_key)
{
	switch (input_key)
	{
	case UP_KEY:
		to_y_power -= move_speed / 2;
		break;
	case DOWN_KEY:
		to_y_power += move_speed / 2;
		break;
	case LEFT_KEY:
		to_x_power -= move_speed;
		break;
	case RIGHT_KEY:
		to_x_power += move_speed;
		break;
	}
}
void Hero::skill_z(void)
{
	if (!skill_z_on) return;

	x_left = pos_x - 4;
	x_right = pos_x + 4;
	y_up = pos_y - 2;
	y_down = pos_y + 2;

	gotoxy(x_left, y_up + 1); setcolor(12);
	printf("▨▨▨▨▨"); setcolor(15);
	gotoxy(x_left, pos_y); setcolor(12);
	printf("▨▨▨▨▨"); setcolor(15);
	gotoxy(x_left, y_down - 1); setcolor(12);
	printf("▨▨▨▨▨"); setcolor(15);

	Sleep(10);

	gotoxy(x_left - 1, y_up); setcolor(12);
	printf("  ▒▒▒▒  "); setcolor(15);
	gotoxy(x_left - 1, pos_y); setcolor(12);
	printf("▒▒※※▒▒"); setcolor(15);
	gotoxy(x_left - 1, y_down); setcolor(12);
	printf("  ▒▒▒▒  "); setcolor(15);

	for (unsigned int i = 0; i < mob.size(); i++)
	{
		if (mob.at(i).hit()){
			mob.at(i).be_attacked(50);
		}
	}
	Sleep(10);

	skill_z_on = 0;
}
void Hero::skill_on(int skill)
{
	switch (skill)
	{
	case 'z':
		skill_z_on = 1;
		break;
	}
}
