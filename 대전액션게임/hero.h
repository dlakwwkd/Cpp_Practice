#pragma once
#include "Unit.h"
class Hero : public Unit
{
public:
	Hero();
	Hero(POINT pc);
	~Hero();

	int HavingHeart(void) { return m_Heart; }
	void ShowPos(void);
	void HitCheck(int mob_num);
	void DeadCheck(void);
	void Revive(void);
	void HpStatus(void);
	void MpStatus(void);
	void LevelUp(void);
	void InitDelay(void);
	void AddDelay(void);
	void MoveInput(int input);
	void MoveAction(void);
	void SkillOn(int skill_type);
	void SkillCheck(void);
protected:
	int m_Delay;
	int m_Heart;
	int m_MaxHp;
	int m_MaxMp;
};

