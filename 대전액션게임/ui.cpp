// ui.cpp : 프로그램의 UI를 구성하는 함수들을 정의합니다.
//

#include "stdafx.h"

std::string mainMenuList[]
=
{
	"[ 싱글 플레이 ]",
	"[ 멀티 플레이 ]",
	" [ 게임 설정 ]",
	" [ 게임 종료 ]"
};
std::string modeMenuList[]
=
{
	"[ 디펜스 모드 ]",
	" [ 대전 모드 ]",
	" [ 이전 화면 ]",
};
std::string heroList[]
=
{
	"[ 빛나는 잉여군 ]",
	"  [ 이전 화면 ]",
};

int a = sizeof(mainMenuList) / sizeof(std::string);
int b = sizeof(modeMenuList) / sizeof(std::string);
int c = sizeof(heroList) / sizeof(std::string);


void mainMenuPrint(int menu)
{
	system("cls");
	for (int i = 0; i < mainMenuNum; i++)
	{
		gotoxy(CONSOLE_COLS / 5 * 2, CONSOLE_LINES / 5 * 2 + i);
		if (menu == i + 1){
			setcolor(10, 0);
			std::cout << mainMenuList[i] << std::endl;
			setcolor(15, 0);
		}
		else std::cout << mainMenuList[i] << std::endl;
	}
}

void modeMenuPrint(int menu)
{
	system("cls");
	for (int i = 0; i < modeMenuNum; i++)
	{
		gotoxy(CONSOLE_COLS / 5 * 2, CONSOLE_LINES / 5 * 2 + i);
		if (menu == i + 1){
			setcolor(10, 0);
			std::cout << modeMenuList[i] << std::endl;
			setcolor(15, 0);
		}
		else std::cout << modeMenuList[i] << std::endl;
	}
}

void heroListPrint(int menu)
{
	system("cls");
	for (int i = 0; i < heroListNum; i++)
	{
		gotoxy(CONSOLE_COLS / 5 * 2, CONSOLE_LINES / 5 * 2 + i);
		if (menu == i + 1){
			setcolor(10, 0);
			std::cout << heroList[i] << std::endl;
			setcolor(15, 0);
		}
		else std::cout << heroList[i] << std::endl;
	}
}

void closeMessage(void)
{
	system("cls");
	std::cout << "Good Bye ~" << std::endl;
}