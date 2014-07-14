// unit.h : Unit 클래스와 그 자식 클래스들을 선언합니다.
//

#ifndef __UNIT_H
#define __UNIT_H

#include "stdafx.h"

class Unit
{
protected:
	static int x_left;
	static int x_right;
	static int y_up;
	static int y_down;

	double to_x, to_y;
	std::string name;
	std::string shape;
	COORD pos_unit;

	double move_speed;
	int hp;
	int damage;
	bool is_dead;

public:
	static int mob_num;

	Unit();
	Unit(int x, int y);
	Unit(const Unit &pc);
	~Unit();

	void move(void);
	void ai(int &x, int &y);
	void release(void);
	int attack();
	void be_attacked(int damage_earn);
	int hit(void);
	void show_pos();
	void delete_pos();
};

class Hero : public Unit
{
protected:
	int skill_z_on;
	double to_x, to_y;

public:
	Hero();
	Hero(int x, int y);
	~Hero();

	void move_input(int input_key);
	void move_action(void);
	void skill_z(void);
	void skill_on(int skill);
};

class Inyo : public Hero
{
protected:

public:
	Inyo();
	Inyo(int x, int y);
	~Inyo();
};


#endif

