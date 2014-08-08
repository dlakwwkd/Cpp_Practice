#pragma once
enum PlayerType
{
	COMPUTER,
	PLAYER_1,
	PLAYER_2,
};
struct POINT_D
{
	DOUBLE  x;
	DOUBLE  y;
};

class Unit
{
public:
	Unit();
	Unit(std::string m_Name, std::string m_Shape, double m_Speed, int m_Hp, int m_Mp, int m_Damage);
	Unit(const Unit &pc);
	~Unit();

	POINT NowPos(void) { return m_Pos; }
	bool DeadCheck(void) { return m_IsDead; }

	void SetPlayerType(int type);
	void SetTeamType(int type);
	int CheckPlayerType(void);
	int CheckTeamType(void);

	bool UseMp(int need_mp);
	int Attack(void);
	void ShowPos(void);
	void Ai(int reduce);
	void MoveType(void);
	void MoveAction(POINT_D &move);
	void BeAttacked(int damage_earn, int attack_player);
protected:
	PlayerType m_Owner;
	POINT m_Pos;
	POINT m_ToPos;
	POINT_D m_Move;
	POINT_D m_MovePower;
	static POINT_D m_PublicMove;

	std::string m_Name;
	std::string m_Shape;

	double m_Speed;
	int m_Hp;
	int m_Mp;
	int m_Damage;
	bool m_IsDead;
};