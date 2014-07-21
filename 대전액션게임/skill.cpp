// skill.cpp : skill 클래스와 그 자식 클래스들을 정의합니다.
//

#include "stdafx.h"

Skill::Skill() : name("skill"), rect({ 0, 0, 0, 0 }), damage(0), need_mana(0), cooldown(1){}

Skill::Skill(std::string nm, RECT rt, int dm, int mana, int cool) :
name(nm), rect(rt), damage(dm), need_mana(mana), cooldown(cool){}

Skill::Skill(const Skill &pc) :
name(pc.name), rect(pc.rect), damage(pc.damage), need_mana(pc.need_mana), cooldown(pc.cooldown){}

void Skill::skill_effect(int effect_color)
{
	cooldown--;

	if (player.at(0).use_mp(need_mana))
	{
		int i, j;
		for (j = rect.top; j <= rect.bottom; j++)
		{
			if (j == rect.top || j == rect.bottom)
			{
				gotoxy(rect.left + 3, j);
				setcolor(effect_color);
				for (i = rect.left + 3; i <= rect.right - 3; i++)
				{
					_putch('#');
				}
				setcolor(DEF_COLOR(SCREEN));
			}
			else if (j == rect.top + 1 || j == rect.bottom - 1)
			{
				gotoxy(rect.left + 1, j);
				setcolor(effect_color);
				for (i = rect.left + 1; i <= rect.right - 1; i++)
				{
					_putch('#');
				}
				setcolor(DEF_COLOR(SCREEN));
			}
			else
			{
				gotoxy(rect.left, j);
				setcolor(effect_color);
				for (i = rect.left; i <= rect.right; i++)
				{
					_putch('#');
				}
				setcolor(DEF_COLOR(SCREEN));
			}
		}
		Sleep(gameSpeed*10/(1+lowSpecMode));

		if (!mob.empty())
		{
			for (unsigned int i = 0; i < mob.size(); i++)
			{
				if (PtInRect(&rect, mob.at(i).now_pos()))
					mob.at(i).be_attacked(damage);
			}
		}
		
		rect.top -= cooldown;
		rect.bottom += cooldown;
		rect.left -= 2 * cooldown;
		rect.right += 2 * cooldown;
	}
}
void Skill::skill_use(void)
{
	if (name == "Z")
		skill_effect(SKILL_EFFECT(SKY_BLUE));
	else if (name == "C")
	{
		cooldown--;

		Skill c_dummy("C_dummy",
		{ dummy.back().now_pos().x - 4, dummy.back().now_pos().y - 1,
		dummy.back().now_pos().x + 5, dummy.back().now_pos().y + 3 },
		12, 6, 2);
		skill.push(c_dummy);

		if (cooldown < 1){
			while (!dummy.empty())
			{
				dummy.pop();
			}
		}
	}
	else if (name == "C_dummy")
	{
		skill_effect(SKILL_EFFECT(RED_YELLO));
	}

	if (cooldown < 1)
		skill.pop();
}