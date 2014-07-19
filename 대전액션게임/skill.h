// skill.h : skill 클래스와 그 자식 클래스들을 선언합니다.
//

#ifndef __SKILL_H
#define __SKILL_H

#include "stdafx.h"

class Skill
{
protected:
	RECT rect;
	int damage;
	int use_mana;
public:
	Skill();
	Skill(std::string nm, RECT rt, int dm, int mana, int cool);
	Skill(const Skill &pc);

	std::string name;
	int cooldown;

	void skill_z(void);
	void skill_c(void);
};


#endif