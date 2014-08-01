#pragma once
#include "Hero.h"
class Dummy : public Hero
{
public:
	Dummy();
	Dummy(POINT pc);
	~Dummy();

	void showPos(void);
	void ai(int reduce);
};