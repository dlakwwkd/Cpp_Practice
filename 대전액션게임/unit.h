#pragma once
struct POINT_D
{
	DOUBLE  x;
	DOUBLE  y;
};

class Unit
{
public:
	Unit();
	Unit(std::string name, std::string shape, double speed, int hp, int mp, int damage);
	Unit(const Unit &pc);
	~Unit();

	POINT nowPos(void) { return pos; }
	bool deadCheck(void) { return is_dead; }

	void setPlayerType(int type);
	void setTeamType(int type);
	int checkPlayerType(void);
	int checkTeamType(void);

	bool useMp(int need_mp);
	int attack(void);
	void showPos(void);
	void ai(int reduce);
	void moveType(void);
	void moveAction(POINT_D &move);
	void beAttacked(int damage_earn, int attack_player);
protected:
	Player* owner;
	POINT pos;
	POINT to_pos;
	POINT_D move;
	POINT_D move_power;
	static POINT_D public_move;

	std::string name;
	std::string shape;

	double speed;
	int hp;
	int mp;
	int damage;
	bool is_dead;
};