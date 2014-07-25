// command.h : 각종 명령 처리 함수들을 선언합니다.
//

#ifndef __COMMAND_H
#define __COMMAND_H

#include "stdafx.h"

enum InputKey
{
	SCAN_CODE = 224,
	ENTER = 13,
	ESC = 27,
	UP = 72,
	DOWN = 80,
	LEFT = 75,
	RIGHT = 77,
	Z_KEY = 0x5A,
	X_KEY = 0x58,
	C_KEY = 0x43,
	V_KEY = 0x56
};

void InputCommand();

#endif