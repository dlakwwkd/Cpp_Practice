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
public:
	Unit();
	Unit(std::string name, std::string shape, double speed, int hp, int mp, int damage);
	Unit(const Unit &pc);
	~Unit();

	POINT nowPos(void);
	void showPos(void);
	void ai(int reduce);
	void moveType(void);
	void moveAction(POINT_D &move);
	void beAttacked(int damage_earn);
	bool useMp(int need_mp);
	bool deadCheck(void);
	int attack(void);
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
};

#endif