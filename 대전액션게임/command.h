// command.h : 각종 명령 처리 함수들을 선언합니다.
//

#ifndef __COMMAND_H
#define __COMMAND_H

#include "stdafx.h"

#define SCAN_CODE	224
#define ENTER_KEY	13
#define ESC_KEY		27
#define UP_KEY		72
#define DOWN_KEY	80
#define LEFT_KEY	75
#define RIGHT_KEY	77


void inputKey(int input);
void selectHero(void);


#endif