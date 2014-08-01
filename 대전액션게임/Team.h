#pragma once

enum TeamType
{
	MOB,
	A,
	B,
};

class Team
{
public:
	Team();
	~Team();

	void setTeam(int type);
	int checkTeam(void);
private:
	int team_type;
};
