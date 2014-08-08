// console.cpp : 콘솔 창을 제어하는 함수들을 정의합니다.
//

#include "stdafx.h"
#include "command.h"
#include "console.h"
#include "Unit.h"
#include "Key.h"

std::map<int, Key> keySet;

void InitConsole(void)
{
	system("mode con: lines=45 cols=135");
	Key p1, p2;
	keySet[PLAYER_1] = p1;
	keySet[PLAYER_2] = p2;
	keySet[PLAYER_2].SetUp(VKey(VK_R));
	keySet[PLAYER_2].SetDown(VKey(VK_F));
	keySet[PLAYER_2].SetLeft(VKey(VK_D));
	keySet[PLAYER_2].SetRight(VKey(VK_G));
	keySet[PLAYER_2].SetZ(VKey(VK_OEM_3));
	keySet[PLAYER_2].SetX(VKey(VK_1));
	keySet[PLAYER_2].SetC(VKey(VK_2));
	keySet[PLAYER_2].SetV(VKey(VK_3));
}

void Gotoxy(int x, int y)
{
	COORD m_Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_Pos);
}

void Setcolor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}