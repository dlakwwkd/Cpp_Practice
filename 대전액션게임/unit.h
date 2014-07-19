// unit.h : Unit 클래스를 선언합니다.
//

#ifndef __UNIT_H
#define __UNIT_H

#include "stdafx.h"

typedef struct POINT_D
{
	DOUBLE  x;
	DOUBLE  y;
} POINT_D;


class Unit
{
protected:
	POINT to_pos;
	POINT_D move_power;

	std::string name;
	std::string shape;

	double speed;
	int hp;
	int damage;
public:
	Unit();
	Unit(std::string name, std::string shape, double speed, int hp, int mp, int damage);
	Unit(const Unit &pc);
	~Unit();

	static POINT_D public_move;
	POINT_D move;
	POINT pos;
	bool is_dead;
	int mp;

	void show_pos();
	void ai(int reduce);
	void move_action(POINT_D &move);
	void be_attacked(int damage_earn);
	int attack();
};

#endif

