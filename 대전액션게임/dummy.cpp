// dummy.cpp : Dummy Ŭ������ �� �ڽ� Ŭ�������� �����մϴ�.
//

#include "stdafx.h"

Dummy::Dummy() : Hero()
{
	name = "dumy";
	shape = "+";
	speed = 12;
}

Dummy::Dummy(POINT pc) : Hero()
{
	pos = pc;
	move.x = (LONG)pos.x;
	move.y = (LONG)pos.y;

	name = "dumy";
	shape = "+";
	speed = 12;
}

Dummy::~Dummy()
{

}

void Dummy::ai(int reduce)
{
	to_pos = dummy.front().pos;

	move_power.x = (to_pos.x - pos.x) * speed / reduce;
	move_power.y = (to_pos.y - pos.y) * speed / reduce;
}