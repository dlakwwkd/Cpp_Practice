#include "stdafx.h"


POINT_D Unit::public_move = { 0, 0 };

Unit::Unit() :
owner(NULL), pos({ 0, 0 }), to_pos({ 0, 0 }), move({ 0, 0 }), move_power({ 0, 0 }),
name("unit"), shape("><"), speed(10), hp(20), mp(10), damage(5), is_dead(false){}

Unit::Unit(std::string name, std::string shape, double speed, int hp, int mp, int damage) :
owner(NULL), pos({ 0, 0 }), to_pos({ 0, 0 }), move({ 0, 0 }), move_power({ 0, 0 }),
name(name), shape(shape), speed(speed), hp(hp), mp(mp), damage(damage), is_dead(false){}

Unit::Unit(const Unit &pc) :
owner(NULL), pos(pc.pos), to_pos(pc.to_pos), move(pc.move), move_power(pc.move_power),
name(pc.name), shape(pc.shape), speed(pc.speed), hp(pc.hp), mp(pc.mp), damage(pc.damage), is_dead(pc.is_dead){}

Unit::~Unit()
{
	if (owner != NULL)
		delete owner;
}

void Unit::setPlayerType(int type)
{
	if (owner == NULL)
		owner = new Player;
	owner->setPlayerType(type);
}

void Unit::setTeamType(int type)
{
	if (owner == NULL)
		owner = new Player;
	owner->setTeamType(type);
}

int Unit::checkPlayerType(void)
{
	if (owner == NULL)
		return -1;
	return owner->checkPlayerType();
}

int Unit::checkTeamType(void)
{
	if (owner == NULL)
		return -1;
	return owner->checkTeamType();
}


bool Unit::useMp(int need_mp)
{
	if (mp > need_mp)
	{
		mp -= need_mp;
		return true;
	}
	else
	{
		mp = 0;
		return false;
	}
}
int Unit::attack(void)
{
	return damage;
}
void Unit::showPos(void)
{
	if (is_dead) return;
	Print::get().inText(pos.x, pos.y, shape);
}
void Unit::ai(int reduce)
{
	if (rand() % (7 - gameLevel) == 0)
	{
		if (rand() % playerNum == 0)
			to_pos = player[PLAYER_1].nowPos();
		else
			to_pos = player[PLAYER_2].nowPos();
	}
	else
	{
		to_pos.x = rand() % PLAY_COLS;
		to_pos.y = rand() % PLAY_LINES;
	}
	move_power.x = (to_pos.x - pos.x) * speed / reduce;
	move_power.y = (to_pos.y - pos.y) * speed / reduce;
}
void Unit::moveType(void)
{
	switch (gameMode)
	{
	case MobMoveForm(SCATTER):
		moveAction(move);
		break;
	case MobMoveForm(MASS):
		moveAction(public_move);
		break;
	}
}
void Unit::moveAction(POINT_D &move)
{
	if (move_power.x > 1 || move_power.x < -1) move_power.x -= move_power.x / 8;
	else move_power.x = 0;

	if (move_power.y > 1 || move_power.y < -1) move_power.y -= move_power.y / 8;
	else move_power.y = 0;

	if (move_power.x)
	{
		move.x += move_power.x / 6;

		if (move.x < 0)
			move.x = 0;
		else if (move.x > PLAY_COLS)
			move.x = PLAY_COLS;
	}
	if (move_power.y)
	{
		move.y += move_power.y / 6;

		if (move.y < 0)
			move.y = 0;
		else if (move.y > PLAY_LINES)
			move.y = PLAY_LINES;
	}
	pos = { (LONG)move.x, (LONG)move.y };
}
void Unit::beAttacked(int damage_earn, int attack_player)
{
	if (hp > damage_earn) hp -= damage_earn;
	else hp = 0;
	hitColor.push_back({ pos.x, pos.y });
	if (hp <= 0)
	{
		deathColor.push_back({ pos.x, pos.y });
		Print::get().inText(pos.x, pos.y, "00");
		is_dead = true;

		if (attack_player != PlayerType(MOB))
			player[attack_player].levelUp();
	}
}