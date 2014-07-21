// setting.h : 게임 모드, 영웅 선택 등 게임 셋팅에 관련된 함수들을 선언합니다.
//

#ifndef __SETTING_H
#define __SETTING_H

#include "stdafx.h"

enum SWITCH{ OFF, ON };
enum MOB_MOVE_FORM{ SCATTER, MASS };
enum HERO_TYPE{ INYO = 1 };
enum GAME_LEVEL{ VERY_EASY, EASY, NOMAL, HARD, VERY_HARD, CRAZY };
enum GAME_SPEED{ VERY_SLOW, SLOW, MODERATE, FAST, VERY_FAST, NO_LIMIT };

extern int gameSpeed;
extern int gameStage;
extern int gameLevel;
extern int gameFrame;
extern int gameMode;
extern int heroType;
extern int mobNumber;
extern bool gameRun;
extern bool gamePlay;
extern bool lowSpecMode;
extern bool designateMode;
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