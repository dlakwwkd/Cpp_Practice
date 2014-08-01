#include "stdafx.h"


Team::Team() : team_type(TeamType(MOB))
{
}

Team::~Team()
{
}

void Team::setTeam(int type)
{
	team_type = type;
}

int Team::checkTeam(void)
{
	return team_type;
}
