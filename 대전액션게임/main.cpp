// main.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	argc;
	argv;

	initConsole();
	initPlay();

	gameRunLoop();

	closeMessage();
	return 0;
}