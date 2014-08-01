#pragma once
#include "Unit.h"
class Hero : public Unit
{
public:
	Hero();
	Hero(POINT pc);
	~Hero();

	int havingHeart(void) { return heart; }
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
protected:
	int delay;
	int heart;
	int max_hp;
	int max_mp;
};

