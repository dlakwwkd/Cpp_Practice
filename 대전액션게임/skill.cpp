#include "stdafx.h"
#include "console.h"
#include "setting.h"
#include "Print.h"

Skill::Skill() : m_Owner(PlayerType(COMPUTER)), m_Name("skill"), m_Rect({ 0, 0, 0, 0 }), m_Damage(0), m_NeedMana(0), m_Cooldown(1){}

Skill::Skill(std::string nm, RECT rt, int dm, int mana, int cool) :
m_Owner(PlayerType(COMPUTER)), m_Name(nm), m_Rect(rt), m_Damage(dm), m_NeedMana(mana), m_Cooldown(cool){}

Skill::Skill(const Skill &pc) :
m_Owner(PlayerType(COMPUTER)), m_Name(pc.m_Name), m_Rect(pc.m_Rect), m_Damage(pc.m_Damage), m_NeedMana(pc.m_NeedMana), m_Cooldown(pc.m_Cooldown){}

Skill::~Skill()
{
}

void Skill::SetPlayerType(int type)
{
	m_Owner = PlayerType(type);
}

int Skill::CheckPlayerType(void)
{
	return m_Owner;
}

void Skill::SkillEffect(int effect_color)
{
	m_Cooldown--;

	if (m_Rect.top < 1)
	{
		m_Rect.bottom += 1 - m_Rect.top;
		m_Rect.top += 1 - m_Rect.top;
	}
	if (m_Rect.bottom > PLAY_LINES + 1)
	{
		m_Rect.top += (PLAY_LINES + 1) - m_Rect.bottom;
		m_Rect.bottom += (PLAY_LINES + 1) - m_Rect.bottom;
	}
	if (m_Rect.left < 0)
	{
		m_Rect.right += 0 - m_Rect.left;
		m_Rect.left += 0 - m_Rect.left;
	}
	if (m_Rect.right > PLAY_COLS + 1)
	{
		m_Rect.left += (PLAY_COLS + 1) - m_Rect.right;
		m_Rect.right += (PLAY_COLS + 1) - m_Rect.right;
	}

	if (hero[this->CheckPlayerType()].UseMp(m_NeedMana))
	{
		int i, j;
		for (j = m_Rect.top; j <= m_Rect.bottom; j++)
		{
			if (j == m_Rect.top || j == m_Rect.bottom)
			{
				Gotoxy(m_Rect.left + 3, j);
				Setcolor(effect_color);
				for (i = m_Rect.left + 3; i <= m_Rect.right - 3; i++)
				{
					_putch('#');
				}
				Setcolor(DefColor(SCREEN));
			}
			else if (j == m_Rect.top + 1 || j == m_Rect.bottom - 1)
			{
				Gotoxy(m_Rect.left + 1, j);
				Setcolor(effect_color);
				for (i = m_Rect.left + 1; i <= m_Rect.right - 1; i++)
				{
					_putch('#');
				}
				Setcolor(DefColor(SCREEN));
			}
			else
			{
				Gotoxy(m_Rect.left, j);
				Setcolor(effect_color);
				for (i = m_Rect.left; i <= m_Rect.right; i++)
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
				if (PtInRect(&m_Rect, mob.at(i).NowPos()))
					mob.at(i).BeAttacked(m_Damage, this->CheckPlayerType());
			}
		}
		//임시 구현
		if (this->CheckPlayerType() == PLAYER_1)
		{
			if (PtInRect(&m_Rect, hero[PLAYER_2].NowPos()))
			{
				hero[PLAYER_2].BeAttacked(m_Damage, this->CheckPlayerType());
				Print::get().PrintBottom();
			}
			else
				Sleep(gameSpeed * 5 / (1 + lowSpecMode));
		}
		else if (this->CheckPlayerType() == PLAYER_2)
		{
			if (PtInRect(&m_Rect, hero[PLAYER_1].NowPos()))
			{
				hero[PLAYER_1].BeAttacked(m_Damage, this->CheckPlayerType());
				Print::get().PrintBottom();
			}
			else
				Sleep(gameSpeed * 5 / (1 + lowSpecMode));
		}

		m_Rect.top -= m_Cooldown;
		m_Rect.bottom += m_Cooldown;
		m_Rect.left -= 2 * m_Cooldown;
		m_Rect.right += 2 * m_Cooldown;
	}
}
void Skill::SkillUse(void)
{
	if (m_Name == "Z")
		SkillEffect(SkillEffectColor(SKY_BLUE));
	else if (m_Name == "C")
	{
		m_Cooldown--;

		Skill c_dummy("C_dummy",
		{ dummy.back().NowPos().x - 6, dummy.back().NowPos().y - 2,
		dummy.back().NowPos().x + 7, dummy.back().NowPos().y + 4 },
		20, 3, 2);
		skill.push(c_dummy);
		skill.back().SetPlayerType(this->CheckPlayerType());

		if (m_Cooldown < 1){
			while (!dummy.empty())
			{
				dummy.pop();
			}
		}
	}
	else if (m_Name == "C_dummy")
	{
		SkillEffect(SkillEffectColor(RED_YELLO));
	}

	if (m_Cooldown < 1)
	{
		if (!skill.empty())
			skill.pop();
	}
}