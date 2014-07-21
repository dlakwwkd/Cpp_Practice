// unit.h : Unit 클래스를 선언합니다.
//

#ifndef __UNIT_H
#define __UNIT_H

#include "stdafx.h"

struct POINT_D
{
	DOUBLE  x;
	DOUBLE  y;
};

class Unit
{
protected:
	POINT pos;
	POINT to_pos;
	POINT_D move;
	POINT_D move_power;
	static POINT_D public_move;

	std::string name;
	std::string shape;

	double speed;
	int hp;
	int mp;
	int damage;
	bool is_dead;
public:
	Unit();
	Unit(std::string name, std::string shape, double speed, int hp, int mp, int damage);
	Unit(const Unit &pc);
	~Unit();

	POINT now_pos(void);
	void show_pos(void);
	void ai(int reduce);
	void move_type(void);
	void move_action(POINT_D &move);
	void be_attacked(int damage_earn);
	bool use_mp(int need_mp);
	bool dead_check(void);
	int attack(void);
};

#endif