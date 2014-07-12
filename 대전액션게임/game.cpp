// game.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <time.h>

#define LINES 30
#define COLS 118



void gotoxy(int x, int y);
void setcolor(int color, int bgcolor);

//void mouse_input(int& x, int& y);

class Unit
{
protected:
	static int x_left;
	static int x_right;
	static int y_up;
	static int y_down;

	std::string name;
	std::string shape;
	COORD pos_unit;

	double move_speed;
	int hp;
	int damage;
	bool is_dead;

public:
	static int mob_num;

	Unit();
	Unit(int x, int y);
	Unit(const Unit &pc);
	~Unit();


	void move(int x, int y);
	void ai(int &x, int &y);
	void release(void);

	int attack();
	void be_attacked(int damage_earn);
	int hit(void);
	void show_pos();
	void delete_pos();

};
int Unit::mob_num = 0;
int Unit::x_left = 0;
int Unit::x_right = 0;
int Unit::y_up = 0;
int Unit::y_down = 0;

Unit::Unit() : name("unit"), shape("◎"), pos_unit({ 0, 0 }), move_speed(10), hp(100), damage(10), is_dead(false){ mob_num++; }
Unit::Unit(int x, int y) : name("unit"), shape("◎"), pos_unit({ x, y }), move_speed(10), hp(100), damage(10), is_dead(false){ mob_num++; }
Unit::Unit(const Unit &pc)
{
	name = pc.name;
	shape = pc.shape;
	pos_unit = pc.pos_unit;
	move_speed = pc.move_speed;
	hp = pc.hp;
	damage = pc.damage;
	is_dead = pc.is_dead;
	mob_num++;
}
Unit::~Unit()
{
	mob_num--;
}



class Hero: public Unit
{
protected:
	int skill_z_on;
	double to_x, to_y;

public:
	Hero();
	Hero(int x, int y);
	~Hero();

	void move_input(int input_key);
	void move_action(void);
	void skill_z(Unit*mob[]);
	void skill_on(int skill);

};

Hero::Hero() : Unit()
{
	name = "Hero";
	shape = "◆";
	pos_unit = { 0, 0 };
	move_speed = 12;
	hp = 200;
	damage = 20;
	is_dead = false;

	skill_z_on = 0;
	to_x = to_y = 0;
	mob_num--;
}

Hero::Hero(int x, int y) : Unit()
{
	name = "Hero";
	shape = "◆";
	pos_unit = { x, y };
	move_speed = 12;
	hp = 200;
	damage = 20;
	is_dead = false;

	skill_z_on = 0;
	to_x = to_y = 0;
	mob_num--;
}


Hero::~Hero()
{
}





int _tmain(int argc, _TCHAR* argv[])
{
	argc;
	argv;

	int game_play = 1;

	int to_x2[20] = { 0, };
	int to_y2[20] = { 0, };


	srand((int)time(NULL));

	system("mode con: lines=40 cols=120");

	Hero a;
	Unit* mob[100];
	
	for (int i = 0; i < 20; i++){
		mob[i] = new Unit();
	}

	int i;



	while (game_play)
	{
		//mouse_input(to_x, to_y);
		
		if (_kbhit())
		{
			int input_key = _getch();

			switch (input_key)
			{
			case 13:
				for (int i = 0; i < 20; i++){
					mob[i]->release();
				}
				break;
			case 224:
				input_key = _getch();
				a.move_input(input_key);
				break;
			case 'z':
				a.skill_on('z');



			}




		}

		a.move_action();
		a.skill_z(mob);
		

		Sleep(10);

		
		
		i = rand() % 20;
		mob[i]->ai(to_x2[i], to_y2[i]);


		for (i = 0; i < 20; i++)
		{
			mob[i]->delete_pos();
			if (rand() % 5 == 1) mob[i]->move(to_x2[i], to_y2[i]);
			mob[i]->show_pos();
		}
		
		
		

	}


	for (int i = 0; i < 20; i++)
	{
		delete mob[i];
	}








	return 0;
}




void Unit::move(int x, int y)
{

	if (pos_unit.X < x)
	{
		pos_unit.X += 2;
	}
	else if (pos_unit.X > x)
	{
		pos_unit.X -= 2;
	}
	if (pos_unit.Y < y)
	{
		pos_unit.Y++;
	}
	else if (pos_unit.Y > y)
	{
		pos_unit.Y--;
	}
}
void Unit::ai(int &x, int &y)
{
	x = rand() % COLS;
	y = rand() % LINES;
}
int Unit::attack()
{
	return damage;
}
void Unit::be_attacked(int damage_earn)
{
	hp -= damage_earn;
	if (hp <= 0)
		is_dead = true;
}
int Unit::hit(void)
{
	if (pos_unit.X > x_left - 1 && pos_unit.X < x_right + 1 &&
		pos_unit.Y > y_up - 2 && pos_unit.Y < y_down + 2) return 1;
	else return 0;
}
void Unit::release(void)
{
	is_dead = false;
}


void Unit::show_pos()
{
	if (is_dead) return;
	gotoxy(pos_unit.X, pos_unit.Y);
	std::cout << shape;
}
void Unit::delete_pos()
{
	if (is_dead) return;
	gotoxy(pos_unit.X, pos_unit.Y);
	std::cout << "  ";
}



void Hero::move_input(int input_key)
{
	switch (input_key)
	{
	case 72:	//up
		to_y -= move_speed / 2;
		break;
	case 80:	//down
		to_y += move_speed / 2;

		break;
	case 75:	//left
		to_x -= move_speed;
		break;
	case 77:	//right
		to_x += move_speed;
		break;
	}
}

void Hero::move_action(void)
{
	static double x = pos_unit.X;
	static double y = pos_unit.Y;

	if (to_x > 1 || to_x < -1) to_x -= to_x / 10;
	else to_x = 0;

	if (to_y > 1 || to_y < -1) to_y -= to_y / 10;
	else to_y = 0;

	if (to_x)
	{
		x += to_x/5;

		if (x < 0)
			x = 0;
		else if (x > COLS)
			x = COLS;
	}
	if (to_y)
	{
		y += to_y/5;

		if (y < 0)
			y = 0;
		else if (y > LINES)
			y = LINES;
	}

	delete_pos();
	pos_unit.X = (int)x;
	pos_unit.Y = (int)y;
	show_pos();
}

void Hero::skill_z(Unit*mob[])
{
	if (!skill_z_on) return;
	
	x_left = pos_unit.X - 4;
	x_right = pos_unit.X + 4;
	y_up = pos_unit.Y - 2;
	y_down = pos_unit.Y + 2;

	gotoxy(x_left, y_up + 1); setcolor(12, 0);
	std::cout << "▒▒▒▒▒"; setcolor(15, 0);
	gotoxy(x_left, pos_unit.Y); setcolor(12, 0);
	std::cout << "▒▒▒▒▒"; setcolor(15, 0);
	gotoxy(x_left, y_down - 1); setcolor(12, 0);
	std::cout << "▒▒▒▒▒"; setcolor(15, 0);

	Sleep(50);

	gotoxy(x_left - 1, y_up); setcolor(12, 0);
	std::cout << "▒▒▒▒▒▒"; setcolor(15, 0);
	gotoxy(x_left - 1, pos_unit.Y); setcolor(12, 0);
	std::cout << "▒▒    ▒▒"; setcolor(15, 0);
	gotoxy(x_left - 1, y_down); setcolor(12, 0);
	std::cout << "▒▒▒▒▒▒"; setcolor(15, 0);
	
	for (int i = 0; i < mob_num; i++)
	{
		if (mob[i]->hit()){
			mob[i]->be_attacked(50);
		}
	}
	Sleep(50);

	gotoxy(x_left - 1, y_up);
	std::cout << "           ";
	gotoxy(x_left - 1, y_up + 1);
	std::cout << "           ";
	gotoxy(x_left - 1, pos_unit.Y);
	std::cout << "           ";
	gotoxy(x_left - 1, y_down - 1);
	std::cout << "           ";
	gotoxy(x_left - 1, y_down);
	std::cout << "           ";


	skill_z_on = 0;
}

void Hero::skill_on(int skill)
{
	switch (skill)
	{
	case 'z':
		skill_z_on = 1;
		break;
	}
}








void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void setcolor(int color, int bgcolor)
{
	color &= 0xf;
	bgcolor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}








//void mouse_input(int& x, int& y)
//{
//	INPUT_RECORD rec;
//	DWORD dwRead;
//
//	HANDLE hCout = GetStdHandle(STD_OUTPUT_HANDLE);
//	HANDLE hCin = GetStdHandle(STD_INPUT_HANDLE);
//	
//	while (ReadConsoleInput(hCin, &rec, 1, &dwRead)) {
//		// 만약 Mouse Event가 발생하여 
//		if (rec.EventType == MOUSE_EVENT) {
//			// Mouse Click일 경우엔 별을 찍는다 
//			if (rec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
//				// 우선 커서 위치를 마우스가 클릭된 곳으로 이동
//				SetConsoleCursorPosition(hCout, rec.Event.MouseEvent.dwMousePosition);
//				std::cout << '*';
//			}
//			else if (rec.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED){
//				x = rec.Event.MouseEvent.dwMousePosition.X;
//				y = rec.Event.MouseEvent.dwMousePosition.Y;
//			}
//			else break;
//		}
//		else break;
//	}
//}
