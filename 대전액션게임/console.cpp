// console.cpp : 콘솔 창을 제어하는 함수들을 정의합니다.
//

#include "stdafx.h"

std::map<int, Key> keySet;

void InitConsole(void)
{
	system("mode con: lines=45 cols=135");
	Key p1, p2;
	keySet[PLAYER_1] = p1;
	keySet[PLAYER_2] = p2;
	keySet[PLAYER_2].setUp(VKey(VK_R));
	keySet[PLAYER_2].setDown(VKey(VK_F));
	keySet[PLAYER_2].setLeft(VKey(VK_D));
	keySet[PLAYER_2].setRight(VKey(VK_G));
	keySet[PLAYER_2].setZ(VKey(VK_OEM_3));
	keySet[PLAYER_2].setX(VKey(VK_1));
	keySet[PLAYER_2].setC(VKey(VK_2));
	keySet[PLAYER_2].setV(VKey(VK_3));
}

void Gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Setcolor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}