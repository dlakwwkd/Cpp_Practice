#pragma once
enum SkillEffect
{
	RED_YELLO = 206,
	SKY_BLUE = 191,
	GREEN_YELLO = 174
};

class Skill
{
public:
	Skill();
	Skill(std::string nm, RECT rt, int dm, int mana, int cool);
	Skill(const Skill &pc);
	~Skill();

	void setPlayerType(int type);
	void setTeamType(int type);
	int checkPlayerType(void);
	int checkTeamType(void);

	void skillEffect(int effect_color);
	void skillUse(void);
protected:
	Player* owner;
	RECT rect;
	std::string name;
	int damage;
	int need_mana;
	int cooldown;
};