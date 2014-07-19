// unit.cpp : Unit 클래스를 정의합니다.
//

#include "stdafx.h"

POINT_D Unit::public_move = { 0, 0 };

Unit::Unit() : pos({ 0, 0 }), to_pos({ 0, 0 }), move({ 0, 0 }), move_power({ 0, 0 }),
name("unit"), shape("><"), speed(10), hp(20), mp(10), damage(5), is_dead(false){}

Unit::Unit(std::string name, std::string shape, double speed, int hp, int mp, int damage) : 
pos({ 0, 0 }), to_pos({ 0, 0 }), move({ 0, 0 }), move_power({ 0, 0 }),
name(name), shape(shape), speed(speed), hp(hp), mp(mp), damage(damage), is_dead(false){}

Unit::Unit(const Unit &pc) : pos(pc.pos), to_pos(pc.to_pos), move(pc.move), move_power(pc.move_power),
name(pc.name), shape(pc.shape), speed(pc.speed), hp(pc.hp), mp(pc.mp), damage(pc.damage), is_dead(pc.is_dead){}

Unit::~Unit()
{
}

void Unit::show_pos()
{
	if (is_dead) return;
	if (name == "Inyo")
	{
		Print::get().inColor(pos.x, pos.y, 14);
		Print::get().inColor(pos.x + 2, pos.y, DEF_COLOR);
	}
	else if (shape == "+")
	{
		Print::get().inColor(pos.x, pos.y, 11);
		Print::get().inColor(pos.x + 1, pos.y, DEF_COLOR);
	}
	Print::get().inText(pos.x, pos.y, shape);
}
void Unit::ai(int reduce)
{
	to_pos.x = rand() % PLAY_COLS;
	to_pos.y = rand() % PLAY_LINES;

	move_power.x = (to_pos.x - pos.x) * speed / reduce;
	move_power.y = (to_pos.y - pos.y) * speed / reduce;
}
void Unit::move_action(POINT_D &move)
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
void Unit::be_attacked(int damage_earn)
{
	hp -= damage_earn;
	if (hp <= 0){
		Print::get().inColor(pos.x, pos.y, 12);
		Print::get().inColor(pos.x + 2, pos.y, DEF_COLOR);
		Print::get().inText(pos.x, pos.y, "@@");
		is_dead = true;

		player.at(0).max_hp += 2;
		player.at(0).max_mp += 1;
	}
}
int Unit::attack()
{
	if (player.at(0).pos.x == pos.x && player.at(0).pos.y == pos.y){
		player.at(0).delay ++;
		Print::get().printBottom();
		return damage;
	}
	else return 0;
}