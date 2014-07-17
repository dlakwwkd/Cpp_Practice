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

	static double move_x_public;
	static double move_y_public;
	int pos_x, pos_y;
	int to_x, to_y;
	double move_x, move_y;
	double to_x_power, to_y_power;

	std::string name;
	std::string shape;

	double move_speed;
	int hp;
	int damage;
	bool is_dead;

public:
	Unit();
	Unit(int x, int y);
	Unit(const Unit &pc);
	~Unit();

	void print(void);
	void move(void);
	void move_boss(void);
	void ai(void);
	void ai_boss(void);
	void release(void);
	int attack();
	void be_attacked(int damage_earn);
	int hit(void);
	void show_pos();
};

class Hero : public Unit
{
protected:
	int skill_z_on;

public:
	Hero();
	Hero(int x, int y);
	~Hero();

	void hp_status(void);
	void move_input(int input_key);
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

