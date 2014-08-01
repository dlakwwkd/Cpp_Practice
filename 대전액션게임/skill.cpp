#include "stdafx.h"


Skill::Skill() : owner(NULL), name("skill"), rect({ 0, 0, 0, 0 }), damage(0), need_mana(0), cooldown(1){}

Skill::Skill(std::string nm, RECT rt, int dm, int mana, int cool) :
owner(NULL), name(nm), rect(rt), damage(dm), need_mana(mana), cooldown(cool){}

Skill::Skill(const Skill &pc) :
owner(NULL), name(pc.name), rect(pc.rect), damage(pc.damage), need_mana(pc.need_mana), cooldown(pc.cooldown){}

Skill::~Skill()
{
	if (owner != NULL)
		delete owner;
}

void Skill::setPlayerType(int type)
{
	if (owner == NULL)
		owner = new Player;
	owner->setPlayerType(type);
}

void Skill::setTeamType(int type)
{
	if (owner == NULL)
		owner = new Player;
	owner->setTeamType(type);
}

int Skill::checkPlayerType(void)
{
	if (owner == NULL)
		return -1;
	return owner->checkPlayerType();
}

int Skill::checkTeamType(void)
{
	if (owner == NULL)
		return -1;
	return owner->checkTeamType();
}

void Skill::skillEffect(int effect_color)
{
	cooldown--;

	if (rect.top < 1)
	{
		rect.bottom += 1 - rect.top;
		rect.top += 1 - rect.top;
	}
	if (rect.bottom > PLAY_LINES + 1)
	{
		rect.top += (PLAY_LINES + 1) - rect.bottom;
		rect.bottom += (PLAY_LINES + 1) - rect.bottom;
	}
	if (rect.left < 0)
	{
		rect.right += 0 - rect.left;
		rect.left += 0 - rect.left;
	}
	if (rect.right > PLAY_COLS + 1)
	{
		rect.left += (PLAY_COLS + 1) - rect.right;
		rect.right += (PLAY_COLS + 1) - rect.right;
	}

	if (player[this->checkPlayerType()].useMp(need_mana))
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

		if (!mob.empty())
		{
			for (unsigned int i = 0; i < mob.size(); i++)
			{
				if (PtInRect(&rect, mob.at(i).nowPos()))
					mob.at(i).beAttacked(damage, this->checkPlayerType());
			}
		}
		//임시 구현
		if (this->checkPlayerType() == PLAYER_1)
		{
			if (PtInRect(&rect, player[PLAYER_2].nowPos()))
			{
				player[PLAYER_2].beAttacked(damage, this->checkPlayerType());
				Print::get().printBottom();
			}
			else
				Sleep(gameSpeed * 5 / (1 + lowSpecMode));
		}
		else if (this->checkPlayerType() == PLAYER_2)
		{
			if (PtInRect(&rect, player[PLAYER_1].nowPos()))
			{
				player[PLAYER_1].beAttacked(damage, this->checkPlayerType());
				Print::get().printBottom();
			}
			else
				Sleep(gameSpeed * 5 / (1 + lowSpecMode));
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
		skill.back().setPlayerType(this->checkPlayerType());
		skill.back().setTeamType(this->checkTeamType());

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
	{
		if (!skill.empty())
			skill.pop();
	}
}