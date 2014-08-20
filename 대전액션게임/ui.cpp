// ui.cpp : 프로그램의 UI를 구성하는 함수들을 정의합니다.
//

#include "stdafx.h"
#include "console.h"
#include "setting.h"
#include "Print.h"
#include "Key.h"
#include "ui.h"

void PausePrint(void)
{
	Gotoxy(0, CONSOLE_LINES / 3 - 1);
	Setcolor(11);
	for (int i = 0; i <= CONSOLE_COLS; i++)
	{
		printf("=");
		Gotoxy(CONSOLE_COLS - i, CONSOLE_LINES / 2 + 5);
		printf("=");
		Gotoxy(i, CONSOLE_LINES / 3 - 1);
	}

	Gotoxy(CONSOLE_COLS / 5 * 2 + 2, CONSOLE_LINES / 3 + 4);
	Setcolor(15);
	printf("== [ 일시 정지 ] ==");
	Gotoxy(CONSOLE_COLS / 5 * 2 + 3, CONSOLE_LINES / 3 + 6);
	Setcolor(14);
	printf("Press Enter Key...");
	Setcolor(0);
}

void GameOverPrint(void)
{
	Gotoxy(0, CONSOLE_LINES / 3 - 1);
	Setcolor(11);
	for (int i = 0; i <= CONSOLE_COLS; i++)
	{
		printf("-");
		Gotoxy(CONSOLE_COLS - i, CONSOLE_LINES / 2 + 5);
		printf("-");
		Gotoxy(i, CONSOLE_LINES / 3 - 1);
		Sleep(1);
	}

	Gotoxy(CONSOLE_COLS / 5 * 2 + 2, CONSOLE_LINES / 3 + 3);
	Setcolor(12);
	printf("== [ Game Over ] ==");
	Gotoxy(CONSOLE_COLS / 5 * 2 + 3, CONSOLE_LINES / 3 + 5);
	Setcolor(15);
	printf("   남은 생명: %d ", hero[PLAYER_1]->HavingHeart());
	Gotoxy(CONSOLE_COLS / 5 * 2 + 3, CONSOLE_LINES / 3 + 7);
	Setcolor(14);
	printf("Press Enter Key...");
	Setcolor(0);
}

void CloseMessage(void)
{
	system("cls");
	std::cout << "Good Bye ~" << std::endl;
	
	if (!keySet.empty())
	{
		std::map<int, Key*>::iterator p;
		for (p = keySet.begin(); p != keySet.end(); ++p)
		{
			delete p->second;
		}
		keySet.clear();
	}
	
	getchar();
}