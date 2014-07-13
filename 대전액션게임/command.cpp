// command.cpp : 각종 명령 처리 함수들을 정의합니다.
//

#include "stdafx.h"

void inputKey(int input)
{
	switch (input)
	{
	case ENTER_KEY:
		for (int i = 0; i < mob.size(); i++){
			mob.at(i).release();
		}
		break;
	case SCAN_CODE:
		input = _getch();
		player.at(0).move_input(input);
		break;
	case 'z':
		player.at(0).skill_on('z');

	}
}

