#include "stdafx.h"
#include "console.h"
#include "setting.h"
#include "Print.h"
#include "Frame.h"

Hero::Hero() : Unit()
{
	m_Pos = { 20, 20 };
	m_Move = { 20, 20 };

	m_Delay = 0;
	m_Heart = 3;
	m_MaxHp = m_Hp;
	m_MaxMp = m_Mp;
}
Hero::Hero(POINT pc) : Unit()
{
	m_Pos = pc;
	m_Move.x = (LONG)m_Pos.x;
	m_Move.y = (LONG)m_Pos.y;

	m_Delay = 0;
	m_Heart = 3;
	m_MaxHp = m_Hp;
	m_MaxMp = m_Mp;
}
Hero::~Hero()
{
}

bool Hero::DeadCheck(void)
{
	return m_IsDead;
}
void Hero::ShowPos(void)
{
	if (m_IsDead) return;
	if (!lowSpecMode)
		Print::get().InColor(m_Pos.x, m_Pos.y, HERO);
	Print::get().InText(m_Pos.x, m_Pos.y, m_Shape);
}
void Hero::HitCheck(int mob_num)
{
	if (m_Delay == 0 &&
		m_Pos.x > mob.at(mob_num)->NowPos().x - 2 &&
		m_Pos.x < mob.at(mob_num)->NowPos().x + 2 &&
		m_Pos.y == mob.at(mob_num)->NowPos().y)
	{
		AddDelay();
		BeAttacked(mob.at(mob_num)->Attack(), PlayerType(COMPUTER));
		Print::get().PrintBottom();
	}
}

void Hero::Revive(void)
{
	m_Hp = m_MaxHp;
	m_Mp = m_MaxMp;
	Print::get().PrintBottom();
	m_IsDead = false;
	m_Heart--;
}
void Hero::LevelUp(void)
{
	m_MaxHp += 2;
	m_Hp += 1;
	m_MaxMp += 1;
}
void Hero::HpStatus(void)
{
	double now_hp = (double)m_Hp * 50 / m_MaxHp;

	printf("  HP ");
	Setcolor(206);
	for (int i = 0; i < (int)now_hp; i++)
		printf(" ");
	Setcolor(252);
	printf(" %4d/%4d ", m_Hp, m_MaxHp);
	for (int i = 50; i >(int)now_hp; i--)
		printf(" ");

	if (m_Hp < m_MaxHp)
		m_Hp += 2 + m_MaxHp / 200;
	else m_Hp = m_MaxHp;
	if (m_Hp > m_MaxHp)
		m_Hp = m_MaxHp;
}
void Hero::MpStatus(void)
{
	double now_mp = (double)m_Mp * 50 / m_MaxMp;

	printf("  MP ");
	Setcolor(158);
	for (int i = 0; i < (int)now_mp; i++)
		printf(" ");
	Setcolor(249);
	printf(" %4d/%4d ", m_Mp, m_MaxMp);
	for (int i = 50; i >(int)now_mp; i--)
		printf(" ");

	if (m_Mp < m_MaxMp)
		m_Mp += 10 + m_MaxMp / 200;
	else m_Mp = m_MaxMp;
	if (m_Mp > m_MaxMp)
		m_Mp = m_MaxMp;
}
void Hero::InitDelay(void)
{
	if (m_Delay > 0)
		m_Delay -= Frame::get().GetDeltaTime();
	if (m_Delay <= 0) m_Delay = 0;
}
void Hero::AddDelay(void)
{
	m_Delay += 2 * Frame::get().GetDeltaTime();
}
void Hero::MoveInput(int input)
{
	switch (input)
	{
	case InputKey(UP):
		if (m_MovePower.y > -(50 + (Frame::get().GetDeltaTime() / 30)))
			m_MovePower.y -= m_Speed / 2 * (Frame::get().GetDeltaTime() / 30);
		break;
	case InputKey(DOWN):
		if (m_MovePower.y < (50 + (Frame::get().GetDeltaTime() / 30)))
			m_MovePower.y += m_Speed / 2 * (Frame::get().GetDeltaTime() / 30);
		break;
	case InputKey(LEFT):
		if (m_MovePower.x > -(50 + (Frame::get().GetDeltaTime() / 30)))
			m_MovePower.x -= m_Speed * (Frame::get().GetDeltaTime() / 30);
		break;
	case InputKey(RIGHT):
		if (m_MovePower.x < (50 + (Frame::get().GetDeltaTime() / 30)))
			m_MovePower.x += m_Speed * (Frame::get().GetDeltaTime() / 30);
		break;
	}
}
void Hero::MoveAction(void)
{
	if (m_MovePower.x > 0.5 || m_MovePower.x < -0.5) m_MovePower.x -= m_MovePower.x * (Frame::get().GetDeltaTime() / 300);
	else m_MovePower.x = 0;

	if (m_MovePower.y > 0.5 || m_MovePower.y < -0.5) m_MovePower.y -= m_MovePower.y * (Frame::get().GetDeltaTime() / 300);
	else m_MovePower.y = 0;

	if (m_MovePower.x)
	{
		m_Move.x += m_MovePower.x * (Frame::get().GetDeltaTime() / 300);

		if (m_Move.x < 0)
			m_Move.x = 0;
		else if (m_Move.x > PLAY_COLS)
			m_Move.x = PLAY_COLS;
	}
	if (m_MovePower.y)
	{
		m_Move.y += m_MovePower.y * (Frame::get().GetDeltaTime() / 300);

		if (m_Move.y < 0)
			m_Move.y = 0;
		else if (m_Move.y > PLAY_LINES)
			m_Move.y = PLAY_LINES;
	}
	m_Pos = { (LONG)m_Move.x, (LONG)m_Move.y };
}
void Hero::SkillOn(int skill_type)
{
	if (scopeMode[m_Owner])
	{
		if (skill_type == 'z')
		{
			Skill* z = new Skill("Z",
			{ dummy[m_Owner].front()->m_Pos.x - 4, dummy[m_Owner].front()->m_Pos.y - 1,
			dummy[m_Owner].front()->m_Pos.x + 5, dummy[m_Owner].front()->m_Pos.y + 3 },
			15, 5, 3);
			skill[m_Owner].push(z);
			skill[m_Owner].back()->SetPlayerType(m_Owner);
			if (!dummy[m_Owner].empty())
			{
				delete dummy[m_Owner].front();
				dummy[m_Owner].pop();
			}
			scopeMode[m_Owner] = OFF;
		}
		else if (skill_type == 'c')
		{
			Dummy* dumy2 = new Dummy(m_Pos);
			dummy[m_Owner].push(dumy2);
			dummy[m_Owner].back()->SetPlayerType(m_Owner);
			dummy[m_Owner].back()->Ai(3);

			Skill* c = new Skill("C", { 0, 0, 0, 0 }, 0, 0, 15);
			skill[m_Owner].push(c);
			skill[m_Owner].back()->SetPlayerType(m_Owner);
			scopeMode[m_Owner] = OFF;
		}
	}
	else{
		if (skill_type == 'z')
		{
			Skill* z = new Skill("Z",
			{ m_Pos.x - 4, m_Pos.y - 1,
			m_Pos.x + 5, m_Pos.y + 3 },
			10, 1, 2);
			skill[m_Owner].push(z);
			skill[m_Owner].back()->SetPlayerType(m_Owner);
		}
		else if (skill_type == 'x')
		{
			scopeMode[m_Owner] = ON;
			Dummy* dumy = new Dummy(m_Pos);
			dummy[m_Owner].push(dumy);
			dummy[m_Owner].back()->SetPlayerType(m_Owner);
		}
		else if (skill_type == 'v')
		{
			for (unsigned int i = 0; i < mob.size(); i++)
			{
				mob.at(i)->BeAttacked(100, m_Owner);
			}
		}
	}
}
void Hero::SkillCheck(void)
{
	if (!skill[m_Owner].empty())
	{
		skill[m_Owner].front()->SkillUse();
		if (skill[m_Owner].front()->CheckCooldown() < 1)
		{
			delete skill[m_Owner].front();
			skill[m_Owner].pop();
		}
	}
}