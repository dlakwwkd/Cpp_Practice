// command.h : 각종 명령 처리 함수들을 선언합니다.
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