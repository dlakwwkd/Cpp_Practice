// main.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	argc; argv;

	gameRun = ON;

	initConsole();
	gameRunLoop();
	closeMessage();
	return 0;
}