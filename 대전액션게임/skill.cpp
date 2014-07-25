// skill.cpp : skill 클래스와 그 자식 클래스들을 정의합니다.
//

#include "stdafx.h"

Skill::Skill() : name("skill"), rect({ 0, 0, 0, 0 }), damage(0), need_mana(0), cooldown(1){}

Skill::Skill(std::string nm, RECT rt, int dm, int mana, int cool) :
name(nm), rect(rt), damage(dm), need_mana(mana), cooldown(cool){}

Skill::Skill(const Skill &pc) :
name(pc.name), rect(pc.rect), damage(pc.damage), need_mana(pc.need_mana), cooldown(pc.cooldown){}

void Skill::skillEffect(int effect_color)
{
	cooldown--;

	if (player.at(0).useMp(need_mana))
	{
		int i, j;
		for (j = rect.top; j <= rect.bottom; j++)
		{
			if (j == rect.top || j == rect.bottom)
			{
				Gotoxy(rect.left + 3, j);
				Setcolor(effect_color);
				for (i = rect.left + 3; i <= rect.right - 3; i++)
				{
					_putch('#');
				}
				Setcolor(DefColor(SCREEN));
			}
			else if (j == rect.top + 1 || j == rect.bottom - 1)
			{
				Gotoxy(rect.left + 1, j);
				Setcolor(effect_color);
				for (i = rect.left + 1; i <= rect.right - 1; i++)
				{
					_putch('#');
				}
				Setcolor(DefColor(SCREEN));
			}
			else
			{
				Gotoxy(rect.left, j);
				Setcolor(effect_color);
				for (i = rect.left; i <= rect.right; i++)
				{
					_putch('#');
				}
				Setcolor(DefColor(SCREEN));
			}
		}
		Sleep(gameSpeed*5/(1+lowSpecMode));

		if (!mob.empty())
		{
			for (unsigned int i = 0; i < mob.size(); i++)
			{
				if (PtInRect(&rect, mob.at(i).nowPos()))
					mob.at(i).beAttacked(damage);
			}
		}
		
		rect.top -= cooldown;
		rect.bottom += cooldown;
		rect.left -= 2 * cooldown;
		rect.right += 2 * cooldown;
	}
}
void Skill::skillUse(void)
{
	if (name == "Z")
		skillEffect(SkillEffect(SKY_BLUE));
	else if (name == "C")
	{
		cooldown--;

		Skill c_dummy("C_dummy",
		{ dummy.back().nowPos().x - 6, dummy.back().nowPos().y - 2,
		dummy.back().nowPos().x + 7, dummy.back().nowPos().y + 4 },
		20, 3, 2);
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
		skillEffect(SkillEffect(RED_YELLO));
	}

	if (cooldown < 1)
		skill.pop();
}