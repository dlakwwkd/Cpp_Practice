// setting.h : 게임 모드, 영웅 선택 등 게임 셋팅에 관련된 함수들을 선언합니다.
//

#ifndef __SETTING_H
#define __SETTING_H

#include "stdafx.h"

enum OnOff
{
	OFF,
	ON,
};
enum MobMoveForm
{
	SCATTER = 1,
	MASS,
};
enum HeroType
{
	INYO = 1,
};
enum GameLevel
{
	VERY_EASY = 1,
	EASY,
	NOMAL,
	HARD,
	VERY_HARD,
	CRAZY,
};
enum GameSpeed
{
	VERY_SLOW = 1,
	SLOW,
	MODERATE, 
	FAST,
	VERY_FAST,
	NO_LIMIT, 
};

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

void HeroCreate(void);
void Respawne(void);
void InitPlay(void);

void MainMenu(void);
void OptionMenu(void);
void SelectMode(int input);
void SelectHero(void);
void suspensionOption(void);
void GameOver(void);

#endif