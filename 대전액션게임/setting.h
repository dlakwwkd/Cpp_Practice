// setting.h : 게임 모드, 영웅 선택 등 게임 셋팅에 관련된 함수들을 선언합니다.
//

#ifndef __SETTING_H
#define __SETTING_H

#include "stdafx.h"
#include "Dummy.h"
#include "Skill.h"

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

#define MAX_PLAYER_NUM 2
#define MAX_MOB_NUM 1000

extern int gameSpeed;
extern int gameStage;
extern int gameLevel;
extern int gameFrame;
extern int gameMode;
extern int heroType;
extern int mobNumber;
extern int playerNum;
extern int lowSpecMode;
extern bool gameRun;
extern bool gamePlay;
extern bool designateMode[MAX_PLAYER_NUM];
extern unsigned int gameTime;
extern double deltaTime;

extern std::map<int, Hero> hero;
extern std::vector<Unit> mob;
extern std::queue<Skill> skill;
extern std::queue<Dummy> dummy;

void HeroCreate(int player_num);
void Respawne(void);
void InitPlay(void);

void MainMenu(void);
void OptionMenu(void);
void PlayerMenu(int input);
void SelectMode(int input);
void SelectHero(int player_num);
void SuspensionOption(void);
void GameOver(int player_num);

#endif