#pragma once
#include "Hero.h"
class Dummy : public Hero
{
public:
	Dummy();
	Dummy(POINT pc);
	~Dummy();

	void ShowPos(void);
	void Ai(int reduce);
};