// setting.cpp : ���� ���, ���� ���� �� ���� ���ÿ� ���õ� �Լ����� �����մϴ�.
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

