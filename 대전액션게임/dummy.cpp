#include "stdafx.h"
#include "setting.h"
#include "Print.h"

Dummy::Dummy() : Hero()
{
	m_Name = "dumy";
	m_Shape = "+";
	m_Speed = 5;
}
Dummy::Dummy(POINT pc) : Hero()
{
	m_Pos = pc;
	m_Move.x = (LONG)m_Pos.x;
	m_Move.y = (LONG)m_Pos.y;

	m_Name = "dumy";
	m_Shape = "+";
	m_Speed = 5;
}
Dummy::~Dummy(){}

void Dummy::ShowPos(void)
{
	if (m_IsDead) return;
	if (!lowSpecMode)
		Print::get().InColor(m_Pos.x, m_Pos.y, SCORP);
	Print::get().InText(m_Pos.x, m_Pos.y, m_Shape);
}
void Dummy::Ai(int reduce)
{
	m_ToPos = dummy[m_Owner].front()->m_Pos;

	m_MovePower.x = (m_ToPos.x - m_Pos.x) * m_Speed / reduce;
	m_MovePower.y = (m_ToPos.y - m_Pos.y) * m_Speed / reduce;
}