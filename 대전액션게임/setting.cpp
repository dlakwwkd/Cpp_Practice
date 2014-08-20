// setting.cpp : 게임 모드, 영웅 선택 등 게임 셋팅에 관련된 함수들을 정의합니다.
//

#include "stdafx.h"
#include "console.h"
#include "setting.h"
#include "Print.h"
#include "Inyo.h"
#include "Key.h"
#include "ui.h"

int gameSpeed;
int gameStage;
int gameLevel;
int gameMode;
int mobNumber;
int playerNum;
int lowSpecMode;
bool scopeMode[MAX_PLAYER_NUM];

std::map<int, Hero*> hero;
std::vector<Unit*> mob;
std::queue<Skill*> skill[MAX_PLAYER_NUM];
std::queue<Dummy*> dummy[MAX_PLAYER_NUM];

