#include <windows.h>
#include <map>

enum SkillIndex
{
	NOMAL_SKILL_START = 301,
	NOMAL_SKILL_END = NOMAL_SKILL_START + 10,
	SPECIAL_SKILL_START = NOMAL_SKILL_END + 1,
	SPECIAL_SKILL_END = SPECIAL_SKILL_START + 10,
};


class Skill
{
private:
	int id;
};

int main()
{
	std::map<int, Skill*> skillList;

	for (int i = NOMAL_SKILL_START; i < NOMAL_SKILL_END; ++i)
	{
		skillList[i] = new Skill();
	}
	for (int i = SPECIAL_SKILL_START; i < SPECIAL_SKILL_END; ++i)
	{
		skillList[i] = new Skill();
	}

	return 0;
}