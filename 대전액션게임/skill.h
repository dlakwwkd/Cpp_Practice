// skill.h : skill Ŭ������ �� �ڽ� Ŭ�������� �����մϴ�.
//

#ifndef __SKILL_H
#define __SKILL_H

#include "stdafx.h"

enum SKILL_EFFECT
{
	RED_YELLO = 206,
	SKY_BLUE = 191,
	GREEN_YELLO = 174
};

class Skill
{
protected:
	RECT rect;
	std::string name;
	int damage;
	int need_mana;
	int cooldown;
public:
	Skill();
	Skill(std::string nm, RECT rt, int dm, int mana, int cool);
	Skill(const Skill &pc);

	void skill_effect(int effect_color);
	void skill_use(void);
};

#endif