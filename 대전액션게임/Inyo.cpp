#include "stdafx.h"
#include "Inyo.h"

Inyo::Inyo() : Hero()
{
	m_Name = "Inyo";
	m_Shape = "[]";
	m_Speed = 5;
	m_Hp = 100;
	m_Mp = 100;
	m_Damage = 20;
	m_MaxHp = m_Hp;
	m_MaxMp = m_Mp;
}
Inyo::Inyo(POINT pc) : Hero()
{
	m_Pos = pc;
	m_Move.x = (LONG)m_Pos.x;
	m_Move.y = (LONG)m_Pos.y;
	m_Name = "Inyo";
	m_Shape = "[]";
	m_Speed = 5;
	m_Hp = 100;
	m_Mp = 100;
	m_Damage = 20;
	m_MaxHp = m_Hp;
	m_MaxMp = m_Mp;
}
Inyo::~Inyo(){}