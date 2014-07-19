#include <iostream>
#include <windows.h>

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main(void)
{
	RECT rt = { 5, 5, 50, 25 };
	POINT pt = { 25, 15 };

	for (int j = rt.top; j < rt.bottom; j++)
	{
		gotoxy(rt.left, j);
		for (int i = rt.left; i < rt.right; i++){
			printf("#");
		}
	}
	


	if (PtInRect(&rt, pt)){
		gotoxy(pt.x, pt.y);
		printf(" ");
	}

	while (1);

	return 0;
}