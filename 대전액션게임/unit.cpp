#include "stdafx.h"
#include "console.h"
#include "setting.h"
#include "Print.h"

POINT_D Unit::m_PublicMove = { 0, 0 };

Unit::Unit() :
m_Owner(PlayerType(COMPUTER)), m_Pos({ 0, 0 }), m_ToPos({ 0, 0 }), m_Move({ 0, 0 }), m_MovePower({ 0, 0 }),
m_Name("unit"), m_Shape("><"), m_Speed(10), m_Hp(20), m_Mp(10), m_Damage(5), m_IsDead(false){}

Unit::Unit(std::string m_Name, std::string m_Shape, double m_Speed, int m_Hp, int m_Mp, int m_Damage) :
m_Owner(PlayerType(COMPUTER)), m_Pos({ 0, 0 }), m_ToPos({ 0, 0 }), m_Move({ 0, 0 }), m_MovePower({ 0, 0 }),
m_Name(m_Name), m_Shape(m_Shape), m_Speed(m_Speed), m_Hp(m_Hp), m_Mp(m_Mp), m_Damage(m_Damage), m_IsDead(false){}

Unit::Unit(const Unit &pc) :
m_Owner(PlayerType(COMPUTER)), m_Pos(pc.m_Pos), m_ToPos(pc.m_ToPos), m_Move(pc.m_Move), m_MovePower(pc.m_MovePower),
m_Name(pc.m_Name), m_Shape(pc.m_Shape), m_Speed(pc.m_Speed), m_Hp(pc.m_Hp), m_Mp(pc.m_Mp), m_Damage(pc.m_Damage), m_IsDead(pc.m_IsDead){}

Unit::~Unit()
{
}

void Unit::SetPlayerType(int type)
{
	m_Owner = PlayerType(type);
}

int Unit::CheckPlayerType(void)
{
	return m_Owner;
}

bool Unit::UseMp(int need_mp)
{
	if (m_Mp > need_mp)
	{
		m_Mp -= need_mp;
		return true;
	}
	else
	{
		m_Mp = 0;
		return false;
	}
}
int Unit::Attack(void)
{
	return m_Damage;
}
void Unit::ShowPos(void)
{
	if (m_IsDead) return;
	Print::get().InText(m_Pos.x, m_Pos.y, m_Shape);
}
void Unit::Ai(int reduce)
{
	if (rand() % (7 - gameLevel) == 0)
	{
		if (rand() % playerNum == 0)
			m_ToPos = hero[PLAYER_1].NowPos();
		else
			m_ToPos = hero[PLAYER_2].NowPos();
	}
	else
	{
		m_ToPos.x = rand() % PLAY_COLS;
		m_ToPos.y = rand() % PLAY_LINES;
	}
	m_MovePower.x = (m_ToPos.x - m_Pos.x) * m_Speed / reduce;
	m_MovePower.y = (m_ToPos.y - m_Pos.y) * m_Speed / reduce;
}
void Unit::MoveType(void)
{
	switch (gameMode)
	{
	case MobMoveForm(SCATTER):
		MoveAction(m_Move);
		break;
	case MobMoveForm(MASS):
		MoveAction(m_PublicMove);
		break;
	}
}
void Unit::MoveAction(POINT_D &move)
{
	if (m_MovePower.x > 1 || m_MovePower.x < -1) m_MovePower.x -= m_MovePower.x * (deltaTime / 300);
	else m_MovePower.x = 0;

	if (m_MovePower.y > 1 || m_MovePower.y < -1) m_MovePower.y -= m_MovePower.y * (deltaTime / 300);
	else m_MovePower.y = 0;

	if (m_MovePower.x)
	{
		m_Move.x += m_MovePower.x * (deltaTime / 200);

		if (m_Move.x < 0)
			m_Move.x = 0;
		else if (m_Move.x > PLAY_COLS)
			m_Move.x = PLAY_COLS;
	}
	if (m_MovePower.y)
	{
		m_Move.y += m_MovePower.y * (deltaTime / 200);

		if (m_Move.y < 0)
			m_Move.y = 0;
		else if (m_Move.y > PLAY_LINES)
			m_Move.y = PLAY_LINES;
	}
	m_Pos = { (LONG)m_Move.x, (LONG)m_Move.y };
}
void Unit::BeAttacked(int damage_earn, int attack_player)
{
	if (m_Hp > damage_earn) m_Hp -= damage_earn;
	else m_Hp = 0;
	hitColor.push_back({ m_Pos.x, m_Pos.y });
	if (m_Hp <= 0)
	{
		deathColor.push_back({ m_Pos.x, m_Pos.y });
		Print::get().InText(m_Pos.x, m_Pos.y, "00");
		m_IsDead = true;

		if (attack_player != PlayerType(COMPUTER))
			hero[attack_player].LevelUp();
	}
}