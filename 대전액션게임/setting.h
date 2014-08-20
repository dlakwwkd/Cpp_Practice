#pragma once
#include "stdafx.h"
#include "Dummy.h"
#include "Skill.h"

#define MAX_PLAYER_NUM 3
#define MAX_MOB_NUM 1000

extern int gameSpeed;
extern int gameStage;
extern int gameLevel;
extern int gameMode;
extern int mobNumber;
extern int playerNum;
extern int lowSpecMode;
extern bool scopeMode[MAX_PLAYER_NUM];

extern std::map<int, Hero*>	hero;
extern std::vector<Unit*>	mob;
extern std::queue<Skill*>	skill[MAX_PLAYER_NUM];
extern std::queue<Dummy*>	dummy[MAX_PLAYER_NUM];
