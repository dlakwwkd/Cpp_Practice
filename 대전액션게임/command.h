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

enum VKey
{
	VK_0 = 0x30,
	VK_1 = 0x31,
	VK_2 = 0x32,
	VK_3 = 0x33,
	VK_4 = 0x34,
	VK_5 = 0x35,
	VK_6 = 0x36,
	VK_7 = 0x37,
	VK_8 = 0x38,
	VK_9 = 0x39,
	VK_A = 0x41,
	VK_B = 0x42,
	VK_C = 0x43,
	VK_D = 0x44,
	VK_E = 0x45,
	VK_F = 0x46,
	VK_G = 0x47,
	VK_H = 0x48,
	VK_I = 0x49,
	VK_J = 0x4A,
	VK_K = 0x4B,
	VK_L = 0x4C,
	VK_N = 0x4D,
	VK_M = 0x4E,
	VK_O = 0x4F,
	VK_P = 0x50,
	VK_Q = 0x51,
	VK_R = 0x52,
	VK_S = 0x53,
	VK_T = 0x54,
	VK_U = 0x55,
	VK_V = 0x56,
	VK_W = 0x57,
	VK_X = 0x58,
	VK_Y = 0x59,
	VK_Z = 0x5A,
};

void InputCommand(int player_num);

#endif

// #define VK_OEM_1          0xBA   // ';:' for US
// #define VK_OEM_PLUS       0xBB   // '+' any country
// #define VK_OEM_COMMA      0xBC   // ',' any country
// #define VK_OEM_MINUS      0xBD   // '-' any country
// #define VK_OEM_PERIOD     0xBE   // '.' any country
// #define VK_OEM_2          0xBF   // '/?' for US
// #define VK_OEM_3          0xC0   // '`~' for US
// #define VK_OEM_4          0xDB  //  '[{' for US
// #define VK_OEM_5          0xDC  //  '\|' for US
// #define VK_OEM_6          0xDD  //  ']}' for US
// #define VK_OEM_7          0xDE  //  ''"' for US