/*
	2014.07.10
	유닛 생성, 소멸 (클래스)
*/
// 상수 멤버 함수
// 자기 자신을 가리키는 포인터 this

#include <iostream>
#include <string.h>

class Marine
{
	static int total_marine_num;
	const static int i = 0;

	int hp;		// 마린 체력
	int coord_x, coord_y;	// 마린 위치
	bool is_dead;

	const int default_damage;	// 기본 공격력

public:
	Marine();	// 기본 생성자
	Marine(int x, int y);	// x, y 좌표에 마린 생성
	Marine(int x, int y, int default_damage);

	int attack() const;	// 데미지 리턴
	Marine& be_attacked(int damage_earn);	//입는 데미지
	void move(int x, int y);	//새로운 위치

	void show_status();	// 상태를 보여준다.
	static void show_total_marine();
	~Marine() { total_marine_num--; }
};

class Photon_Cannon
{
	int hp, shield;
	int coord_x, coord_y;
	int damage;

	char *name;

public:
	Photon_Cannon(int x, int y);
	Photon_Cannon(int x, int y, char *cannon_name);
	Photon_Cannon(const Photon_Cannon &pc);
	~Photon_Cannon();

	void show_status();
};


int main()
{
	Marine marine1(2, 3, 5);
	marine1.show_status();

	Marine marine2(3, 5, 10);
	marine2.show_status();

	std::cout << std::endl << "마린 1이 마린 2를 두 번 공격! " << std::endl;
	marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());

	marine1.show_status();
	marine2.show_status();

	std::cout << std::endl << std::endl;

	Photon_Cannon pc1(3, 3, "Cannon");
	Photon_Cannon pc2 = pc1;

	pc1.show_status();
	pc2.show_status();

	return 0;
}


int Marine::total_marine_num = 0;
void Marine::show_total_marine()
{
	std::cout << "전체 마린 수: " << total_marine_num << std::endl;
}
Marine::Marine() : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false)
{
	total_marine_num++;
}
Marine::Marine(int x, int y) : hp(50), coord_x(x), coord_y(y), default_damage(default_damage), is_dead(false)
{
	total_marine_num++;
}
Marine::Marine(int x, int y, int default_damage) : coord_x(x), coord_y(y), hp(50), default_damage(default_damage), is_dead(false)
{
	total_marine_num++;
}
void Marine::move(int x, int y)
{
	coord_x = x;
	coord_y = y;
}
int Marine::attack() const
{
	return default_damage;
}
Marine& Marine::be_attacked(int damage_earn)
{
	hp -= damage_earn;
	if (hp <= 0)
		is_dead = true;
	return *this;
}
void Marine::show_status()
{
	std::cout << "*** marine ***" << std::endl;
	std::cout << "Location: (" << coord_x << ", " << coord_y << ") " << std::endl;
	std::cout << "HP: " << hp << std::endl;
	std::cout << "현재 총 마린 수: " << total_marine_num << std::endl;
}

Photon_Cannon::Photon_Cannon(int x, int y)
{
	hp = shield = 100;
	coord_x = x;
	coord_y = y;
	damage = 20;

	name = NULL;
}
Photon_Cannon::Photon_Cannon(const Photon_Cannon &pc)
{
	std::cout << "복사 생성자 호출! " << std::endl;
	hp = pc.hp;
	shield = pc.shield;
	coord_x = pc.coord_x;
	coord_y = pc.coord_y;
	damage = pc.damage;

	name = new char[strlen(pc.name) + 1];
	strcpy_s(name, strlen(pc.name)+1, pc.name);
}
Photon_Cannon::Photon_Cannon(int x, int y, char *cannon_name)
{
	hp = shield = 100;
	coord_x = x;
	coord_y = y;
	damage = 20;

	name = new char[strlen(cannon_name) + 1];
	strcpy_s(name, strlen(cannon_name)+1, cannon_name);
}
Photon_Cannon::~Photon_Cannon()
{
	if (name)
		delete[]name;
}
void Photon_Cannon::show_status()
{
	std::cout << "Photon Cannon : " << name << std::endl;
	std::cout << " Location: (" << coord_x << ", " << coord_y << ") " << std::endl;
	std::cout << " HP: " << hp << std::endl;
}