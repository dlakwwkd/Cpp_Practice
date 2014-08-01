#pragma once

enum PlayerType
{
	COMPUTER,
	PLAYER_1,
	PLAYER_2,
};

class Player
{
public:
	Player();
	~Player();

	void setPlayerType(int type);
	void setTeamType(int type);
	int checkPlayerType(void);
	int checkTeamType(void);

private:
	int player_type;
	Team* player_team;
};

