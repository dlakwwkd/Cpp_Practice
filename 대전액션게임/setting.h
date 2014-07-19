// setting.h : 게임 모드, 영웅 선택 등 게임 셋팅에 관련된 함수들을 선언합니다.
//

#ifndef __SETTING_H
#define __SETTING_H

#include "stdafx.h"

#define ON 1
#define OFF 0

#define MODE1 1
#define MODE2 2

#define TYPE1 1
#define TYPE2 2

#define LEVEL1 1
#define LEVEL2 2

extern int gameStage;
extern int gameLevel;
extern int gameFrame;
extern int gameRun;
extern int gamePlay;
extern int gameMode;
extern int heroType;
extern int mobNumber;
extern int designateMode;
extern unsigned int gameTime;

extern std::vector<Hero> player;
extern std::vector<Unit> mob;
extern std::queue<Skill> skill;
extern std::queue<Dummy> dummy;

void heroCreate(void);
void respawne(void);

void initPlay(void);
void mainMenu(void);
void selectMode(int input);
void selectHero(void);
void gameOver(void);


#endif