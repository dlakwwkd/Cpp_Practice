// hero.h : Hero Ŭ������ �� �ڽ� Ŭ�������� �����մϴ�.
//

#ifndef __HERO_H
#define __HERO_H

#include "stdafx.h"

class Hero : public Unit
{
public:
	Hero();
	Hero(POINT pc);
	~Hero();

	void showPos(void);
	void hitCheck(int mob_num);
	void deadCheck(void);
	void revive(void);
	void hpStatus(void);
	void mpStatus(void);
	void levelUp(void);
	void initDelay(void);
	void addDelay(void);
	void moveInput(int input);
	void moveAction(void);
	void skillOn(int skill_type);
	void skillCheck(void);
	int havingHeart(void);
protected:
	int delay;
	int heart;
	int max_hp;
	int max_mp;
};

class Inyo : public Hero
{
public:
	Inyo();
	Inyo(POINT pc);
	~Inyo();
};

#endif