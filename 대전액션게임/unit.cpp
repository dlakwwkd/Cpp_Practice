// unit.cpp : Unit 클래스와 그 자식 클래스들을 정의합니다.
//

#include "stdafx.h"

int Unit::mob_num = 0;
int Unit::x_left = 0;
int Unit::x_right = 0;
int Unit::y_up = 0;
int Unit::y_down = 0;

Unit::Unit() : name("unit"), shape("◎"), pos_unit({ 0, 0 }), move_speed(10), hp(100), damage(10), is_dead(false){ mob_num++; }
Unit::Unit(int x, int y) : name("unit"), shape("◎"), pos_unit({ x, y }), move_speed(10), hp(100), damage(10), is_dead(false){ mob_num++; }
Unit::Unit(const Unit &pc)
{
	name = pc.name;
	shape = pc.shape;
	pos_unit = pc.pos_unit;
	move_speed = pc.move_speed;
	hp = pc.hp;
	damage = pc.damage;
	is_dead = pc.is_dead;
	mob_num++;
}
Unit::~Unit()
{
	mob_num--;
}



Hero::Hero() : Unit()
{
	name = "Hero";
	shape = "◆";
	pos_unit = { 0, 0 };
	move_speed = 12;
	hp = 200;
	damage = 20;
	is_dead = false;

	skill_z_on = 0;
	to_x = to_y = 0;
	mob_num--;
}

Hero::Hero(int x, int y) : Unit()
{
	name = "Hero";
	shape = "◆";
	pos_unit = { x, y };
	move_speed = 12;
	hp = 200;
	damage = 20;
	is_dead = false;

	skill_z_on = 0;
	to_x = to_y = 0;
	mob_num--;
}


Hero::~Hero()
{
}



Inyo::Inyo() : Hero()
{
	name = "Inyo";
	shape = "◈";
	pos_unit = { 0, 0 };
	move_speed = 12;
	hp = 200;
	damage = 20;
	is_dead = false;

	skill_z_on = 0;
	to_x = to_y = 0;
	mob_num--;
}

Inyo::Inyo(int x, int y) : Hero()
{
	name = "Inyo";
	shape = "◈";
	pos_unit = { x, y };
	move_speed = 12;
	hp = 200;
	damage = 20;
	is_dead = false;

	skill_z_on = 0;
	to_x = to_y = 0;
	mob_num--;
}


Inyo::~Inyo()
{
}




void Unit::move(int x, int y)
{

	if (pos_unit.X < x)
	{
		pos_unit.X += 2;
	}
	else if (pos_unit.X > x)
	{
		pos_unit.X -= 2;
	}
	if (pos_unit.Y < y)
	{
		pos_unit.Y++;
	}
	else if (pos_unit.Y > y)
	{
		pos_unit.Y--;
	}
}
void Unit::ai(int &x, int &y)
{
	x = rand() % PLAY_COLS;
	y = rand() % PLAY_LINES;
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
	if (pos_unit.X > x_left - 1 && pos_unit.X < x_right + 1 &&
		pos_unit.Y > y_up - 2 && pos_unit.Y < y_down + 2) return 1;
	else return 0;
}
void Unit::release(void)
{
	is_dead = false;
}
void Unit::show_pos()
{
	if (is_dead) return;
	gotoxy(pos_unit.X, pos_unit.Y);
	std::cout << shape;
}
void Unit::delete_pos()
{
	if (is_dead) return;
	gotoxy(pos_unit.X, pos_unit.Y);
	std::cout << "  ";
}



void Hero::move_input(int input_key)
{
	switch (input_key)
	{
	case UP_KEY:
		to_y -= move_speed / 2;
		break;
	case DOWN_KEY:
		to_y += move_speed / 2;
		break;
	case LEFT_KEY:
		to_x -= move_speed;
		break;
	case RIGHT_KEY:
		to_x += move_speed;
		break;
	}
}
void Hero::move_action(void)
{
	static double x = pos_unit.X;
	static double y = pos_unit.Y;

	if (to_x > 1 || to_x < -1) to_x -= to_x / 10;
	else to_x = 0;

	if (to_y > 1 || to_y < -1) to_y -= to_y / 10;
	else to_y = 0;

	if (to_x)
	{
		x += to_x / 5;

		if (x < 0)
			x = 0;
		else if (x > PLAY_COLS)
			x = PLAY_COLS;
	}
	if (to_y)
	{
		y += to_y / 5;

		if (y < 0)
			y = 0;
		else if (y > PLAY_LINES)
			y = PLAY_LINES;
	}

	delete_pos();
	pos_unit.X = (int)x;
	pos_unit.Y = (int)y;
	show_pos();
}
void Hero::skill_z(void)
{
	if (!skill_z_on) return;

	x_left = pos_unit.X - 4;
	x_right = pos_unit.X + 4;
	y_up = pos_unit.Y - 2;
	y_down = pos_unit.Y + 2;

	gotoxy(x_left, y_up + 1); setcolor(12, 0);
	std::cout << "▨▨▨▨▨"; setcolor(15, 0);
	gotoxy(x_left, pos_unit.Y); setcolor(12, 0);
	std::cout << "▨▨▨▨▨"; setcolor(15, 0);
	gotoxy(x_left, y_down - 1); setcolor(12, 0);
	std::cout << "▨▨▨▨▨"; setcolor(15, 0);

	Sleep(50);

	gotoxy(x_left - 1, y_up); setcolor(12, 0);
	std::cout << "  ▒▒▒▒  "; setcolor(15, 0);
	gotoxy(x_left - 1, pos_unit.Y); setcolor(12, 0);
	std::cout << "▒▒※※▒▒"; setcolor(15, 0);
	gotoxy(x_left - 1, y_down); setcolor(12, 0);
	std::cout << "  ▒▒▒▒  "; setcolor(15, 0);

	for (int i = 0; i < mob_num; i++)
	{
		if (mob.at(i).hit()){
			mob.at(i).be_attacked(50);
		}
	}
	Sleep(50);

	gotoxy(x_left - 1, y_up);
	std::cout << "           ";
	gotoxy(x_left - 1, y_up + 1);
	std::cout << "           ";
	gotoxy(x_left - 1, pos_unit.Y);
	std::cout << "           ";
	gotoxy(x_left - 1, y_down - 1);
	std::cout << "           ";
	gotoxy(x_left - 1, y_down);
	std::cout << "           ";


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
