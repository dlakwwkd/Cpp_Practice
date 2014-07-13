// console.cpp : �ܼ� â�� �����ϴ� �Լ����� �����մϴ�.
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
//		// ���� Mouse Event�� �߻��Ͽ� 
//		if (rec.EventType == MOUSE_EVENT) {
//			// Mouse Click�� ��쿣 ���� ��´� 
//			if (rec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
//				// �켱 Ŀ�� ��ġ�� ���콺�� Ŭ���� ������ �̵�
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
