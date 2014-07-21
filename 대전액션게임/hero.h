// hero.h : Hero 클래스와 그 자식 클래스들을 선언합니다.
//

#ifndef __HERO_H
#define __HERO_H

#include "stdafx.h"

class Hero : public Unit
{
protected:
	int delay;
	int heart;
	int max_hp;
	int max_mp;
public:
	Hero();
	Hero(POINT pc);
	~Hero();

	void show_pos(void);
	void hit_check(int mob_num);
	void dead_check(void);
	void revive(void);
	void hp_status(void);
	void mp_status(void);
	void level_up(void);
	void init_delay(void);
	void add_delay(void);
	void move_input(int input_key);
	void move_action(void);
	void skill_on(int skill_type);
	void skill_check(void);
	int having_heart(void);
};

class Inyo : public Hero
{
public:
	Inyo();
	Inyo(POINT pc);
	~Inyo();
};

#endif