#pragma once
class Skill
{
public:
	Skill();
	Skill(std::string nm, RECT rt, int dm, int mana, int cool);
	Skill(const Skill &pc);
	~Skill();

	void SetPlayerType(int type);
	void SetTeamType(int type);
	int CheckPlayerType(void);
	int CheckTeamType(void);
	int CheckCooldown(void);

	void SkillEffect(int effect_color);
	void SkillUse(void);
protected:
	PlayerType	 m_Owner;
	RECT		 m_Rect;
	std::string	 m_Name;
	int m_Damage;
	int m_NeedMana;
	int m_Cooldown;
};