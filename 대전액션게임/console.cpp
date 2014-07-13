// console.cpp : 콘솔 창을 제어하는 함수들을 정의합니다.
//

#include "stdafx.h"

void initConsole(void)
{
	system("mode con: lines=40 cols=120");
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
