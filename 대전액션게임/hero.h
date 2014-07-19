// hero.h : Hero Ŭ������ �� �ڽ� Ŭ�������� �����մϴ�.
//

#ifndef __HERO_H
#define __HERO_H

#include "stdafx.h"

class Hero : public Unit
{
protected:

public:
	Hero();
	Hero(POINT pc);
	~Hero();

	int delay;
	int heart;
	int max_hp;
	int max_mp;

	void dead_check(void);
	void revive(void);
	void hp_status(void);
	void mp_status(void);
	void init_delay(void);
	void move_input(int input_key);
	void skill_on(int skill_type);
	void skill_use(void);
};

class Inyo : public Hero
{
protected:

public:
	Inyo();
	Inyo(POINT pc);
	~Inyo();
};

#endif