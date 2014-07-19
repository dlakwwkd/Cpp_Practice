// skill.cpp : skill 클래스와 그 자식 클래스들을 정의합니다.
//

#include "stdafx.h"

Skill::Skill() : name("skill"), rect({ 0, 0, 0, 0 }), damage(0), use_mana(0), cooldown(1){}

Skill::Skill(std::string nm, RECT rt, int dm, int mana, int cool) :
name(nm), rect(rt), damage(dm), use_mana(mana), cooldown(cool){}

Skill::Skill(const Skill &pc) :
name(pc.name), rect(pc.rect), damage(pc.damage), use_mana(pc.use_mana), cooldown(pc.cooldown){}

void Skill::skill_z(void)
{
	cooldown--;

	if (player.at(0).mp > use_mana)
	{
		setcolor(191);
		for (int j = rect.top; j <= rect.bottom; j++)
		{
			gotoxy(rect.left, j);
			for (int i = rect.left; i <= rect.right; i++)
				printf("#");
		}
		setcolor(DEF_COLOR);
		Sleep(10);

		if (mob.empty()) return;
		for (unsigned int i = 0; i < mob.size(); i++)
		{
			if (PtInRect(&rect, mob.at(i).pos))
				mob.at(i).be_attacked(damage);
		}
		rect.top -= cooldown;
		rect.bottom += cooldown;
		rect.left -= 2 * cooldown;
		rect.right += 2 * cooldown;
	
		player.at(0).mp -= use_mana;
	}
}
void Skill::skill_c(void)
{
	cooldown--;

	if (player.at(0).mp > use_mana)
	{
		setcolor(206);
		for (int j = rect.top; j <= rect.bottom; j++)
		{
			gotoxy(rect.left, j);
			for (int i = rect.left; i <= rect.right - 7; i++)
				printf("▒");
		}
		setcolor(DEF_COLOR);
		Sleep(10);

		if (mob.empty()) return;
		for (unsigned int i = 0; i < mob.size(); i++)
		{
			if (PtInRect(&rect, mob.at(i).pos))
				mob.at(i).be_attacked(damage);
		}
		rect.top -= cooldown;
		rect.bottom += cooldown;
		rect.left -= 2 * cooldown;

		player.at(0).mp -= use_mana;
	}
}