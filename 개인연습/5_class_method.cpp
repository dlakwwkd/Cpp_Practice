/*
	2014.07.10
	���� ����, �Ҹ� (Ŭ����)
*/
// ��� ��� �Լ�
// �ڱ� �ڽ��� ����Ű�� ������ this

#include <iostream>
#include <string.h>

class Marine
{
	static int total_marine_num;
	const static int i = 0;

	int hp;		// ���� ü��
	int coord_x, coord_y;	// ���� ��ġ
	bool is_dead;

	const int default_damage;	// �⺻ ���ݷ�

public:
	Marine();	// �⺻ ������
	Marine(int x, int y);	// x, y ��ǥ�� ���� ����
	Marine(int x, int y, int default_damage);

	int attack() const;	// ������ ����
	Marine& be_attacked(int damage_earn);	//�Դ� ������
	void move(int x, int y);	//���ο� ��ġ

	void show_status();	// ���¸� �����ش�.
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

	std::cout << std::endl << "���� 1�� ���� 2�� �� �� ����! " << std::endl;
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
	std::cout << "��ü ���� ��: " << total_marine_num << std::endl;
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
	std::cout << "���� �� ���� ��: " << total_marine_num << std::endl;
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
	std::cout << "���� ������ ȣ��! " << std::endl;
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