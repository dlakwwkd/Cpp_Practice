// command.h : ���� ��� ó�� �Լ����� �����մϴ�.
//

#ifndef __COMMAND_H
#define __COMMAND_H

#include "stdafx.h"

enum INPUT_KEY
{
	SCAN_CODE = 224,
	ENTER = 13,
	ESC = 27,
	UP = 72,
	DOWN = 80,
	LEFT = 75,
	RIGHT = 77
};

void inputKey(int input);
void inputKey2(int input);

#endif