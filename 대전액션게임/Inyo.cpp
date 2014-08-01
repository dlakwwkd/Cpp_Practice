#include "stdafx.h"


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