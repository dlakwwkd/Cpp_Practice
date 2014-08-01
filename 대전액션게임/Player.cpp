#include "stdafx.h"


Player::Player() : player_type(PlayerType(COMPUTER)), player_team(NULL)
{
}

Player::~Player()
{
	if (player_team != NULL)
		delete player_team;
}

void Player::setPlayerType(int type)
{
	player_type = type;
}

void Player::setTeamType(int type)
{
	if (player_team == NULL)
		player_team = new Team;
	player_team->setTeam(type);
}

int Player::checkPlayerType(void)
{
	return player_type;
}

int Player::checkTeamType(void)
{
	if (player_team == NULL)
		return -1;
	return player_team->checkTeam();
}
