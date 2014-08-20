#include "stdafx.h"
#include "Menu.h"
#include "console.h"
#include "setting.h"
#include "GameManager.h"
#include "Print.h"
#include "ui.h"

Menu::Menu() : m_GM(nullptr), m_MenuType(MAIN), m_Input(SCAN_CODE), m_Menu(1), m_PlayerCount(1), m_On(TRUE)
{
	static std::string mainMenuList[]
		=
	{
		"[  싱글 플레이  ]",
		"[  멀티 플레이  ]",
		"[   게임 설정   ]",
		"[   게임 종료   ]"
	};
	static std::string gameOptionList[]
		=
	{
		"[   게임 속도   ]",
		"[  저사양 모드  ]",
		"[   이전 화면   ]",
	};
	static std::string playerList[]
		=
	{
		"[   1P 플레이   ]",
		"[   2P 플레이   ]",
		"[   이전 화면   ]"
	};
	static std::string heroList[]
		=
	{
		"[ 빛나는 잉여군 ]",
		"[   이전 화면   ]",
	};
	static 	std::string modeMenuList[]
		=
	{
		"[   매우 쉬움   ]",
		"[     쉬움      ]",
		"[     보통      ]",
		"[    어려움     ]",
		"[  매우 어려움  ]",
		"[     HELL      ]",
		"[   이전 화면   ]",
	};
	static std::string pauseOptionList[]
		=
	{
		"[   계속 하기   ]",
		"[   게임 설정   ]",
		"[   처음 으로   ]",
	};
	static std::string gameOverList[]
		=
	{
		"[   이어 하기   ]",
		"[   처음 으로   ]",
	};
	static std::string gameSpeedList[]
		=
	{
		"[   매우 느림   ]",
		"[     느림      ]",
		"[     보통      ]",
		"[     빠름      ]",
		"[   매우 빠름   ]",
		"[   제한 없음   ]",
	};
	static std::string lowSpecList[]
		=
	{
		"[     끄기      ]",
		"[     켜기      ]",
	};

	m_MenuList[MAIN]			= mainMenuList;
	m_MenuList[OPTION]			= gameOptionList;
	m_MenuList[SELECT_PLAYER]	= playerList;
	m_MenuList[SELECT_HERO]		= heroList;
	m_MenuList[SELECT_MODE]		= modeMenuList;
	m_MenuList[PAUSE]			= pauseOptionList;
	m_MenuList[GAME_OVER]		= gameOverList;
	m_MenuList[GAME_SPEED]		= gameSpeedList;
	m_MenuList[LOW_SPEC]		= lowSpecList;

	m_MenuNum[MAIN]				= _countof(mainMenuList);
	m_MenuNum[OPTION]			= _countof(gameOptionList);
	m_MenuNum[SELECT_PLAYER]	= _countof(playerList);
	m_MenuNum[SELECT_HERO]		= _countof(heroList);
	m_MenuNum[SELECT_MODE]		= _countof(modeMenuList);
	m_MenuNum[PAUSE]			= _countof(pauseOptionList);
	m_MenuNum[GAME_OVER]		= _countof(gameOverList);
	m_MenuNum[GAME_SPEED]		= _countof(gameSpeedList);
	m_MenuNum[LOW_SPEC]			= _countof(lowSpecList);

	m_SideMenuType[1]			= MenuType(GAME_SPEED);
	m_SideMenuType[2]			= MenuType(LOW_SPEC);
	m_SideMenu[1]				= GameSpeed(MODERATE);
	m_SideMenu[2]				= OnOff(OFF);
}

void Menu::MenuPlatform(void)
{
	while (m_On)
	{
		MenuPrint();
		m_Input = (InputKey)_getch();

		if (m_Input == SCAN_CODE)
		{
			m_Input = (InputKey)_getch();
			switch (m_Input)
			{
			case UP:
				if (m_Menu > 1) --m_Menu;
				else m_Menu = m_MenuNum[m_MenuType];
				break;
			case DOWN:
				if (m_Menu < m_MenuNum[m_MenuType]) ++m_Menu;
				else m_Menu = 1;
				break;
			}
		}
		else
		{
			switch (m_Input)
			{
			case 'z':
			case ENTER:
				MenuIn();
				break;
			case 'x':
			case ESC:
				MenuOut();
				break;
			}
		}
	}
}

void Menu::MenuIn(void)
{
	switch (m_MenuType)
	{
	case MAIN:
		if (m_Menu == m_MenuNum[m_MenuType])
		{
			m_GM->SetGameRun(OFF);
			m_GM->SetGamePlay(OFF);
			m_On = FALSE;
		}
		else if (m_Menu == 1) m_MenuType = SELECT_PLAYER;
		else if (m_Menu == 3) m_MenuType = OPTION;
		else
		{
			Gotoxy(0, PLAY_LINES);
			printf("아직 준비되지 않은 메뉴입니다.");
			Sleep(500);
		}
		break;
	case OPTION:
		if (m_Menu == m_MenuNum[m_MenuType])
		{
			if (m_GM->GetGamePlay() == ON)
				m_MenuType = PAUSE;
			else
				m_MenuType = MAIN;
		}
		else
		{
			switch (m_SideMenuType[m_Menu])
			{
			case MenuType(GAME_SPEED):
				if (m_SideMenu[m_Menu] < m_MenuNum[GAME_SPEED])
				{
					m_SideMenu[m_Menu]++;
					gameSpeed = m_SideMenu[m_Menu];
				}
				else
				{
					m_SideMenu[m_Menu] = 1;
					gameSpeed = m_SideMenu[m_Menu];
				}
				break;
			case MenuType(LOW_SPEC):
				if (m_SideMenu[m_Menu] < m_MenuNum[LOW_SPEC])
				{
					m_SideMenu[m_Menu]++;
					lowSpecMode = m_SideMenu[m_Menu];
				}
				else
				{
					m_SideMenu[m_Menu] = 1;
					lowSpecMode = m_SideMenu[m_Menu];
				}
				break;
			}
		}
		break;
	case SELECT_PLAYER:
		if (m_Menu == m_MenuNum[m_MenuType])
		{
			m_MenuType = MAIN;
		}
		else
		{
			playerNum = m_Menu;
			m_MenuType = SELECT_MODE;
			m_PlayerCount = 1;
		}
		break;
	case SELECT_MODE:
		if (m_Menu == m_MenuNum[m_MenuType])
		{
			m_MenuType = SELECT_PLAYER;
		}
		else
		{
			gameLevel = m_Menu;
			m_MenuType = SELECT_HERO;
		};
		break;
	case SELECT_HERO:
		if (m_Menu == m_MenuNum[m_MenuType])
		{
			m_GM->DeleteVestige();
			m_MenuType = SELECT_MODE;
			m_PlayerCount = 1;
		}
		else
		{
			m_GM->HeroCreate(m_PlayerCount);
			if (m_PlayerCount < playerNum)
				m_PlayerCount++;
			else
			{
				m_GM->SetGamePlay(ON);
				m_On = FALSE;
			}
		};
		break;
	case PAUSE:
		if (m_Menu == m_MenuNum[m_MenuType])
		{
			m_GM->DeleteVestige();
			m_GM->SetGamePlay(OFF);
			m_MenuType = MAIN;
			m_On = FALSE;
		}
		else if (m_Menu == 1)
			m_On = FALSE;
		else if (m_Menu == 2)
			m_MenuType = OPTION;
		break;
	case GAME_OVER:
		if (m_Menu == m_MenuNum[m_MenuType])
		{
			m_GM->DeleteVestige();
			m_GM->SetGamePlay(OFF);
			m_MenuType = MAIN;
			m_On = FALSE;
		}
		if (hero[m_PlayerCount]->HavingHeart() > 0)
		{
			hero[m_PlayerCount]->Revive();
			m_On = FALSE;
		}
		else{
			Gotoxy(CONSOLE_COLS / 3 + 8, CONSOLE_LINES / 3 + 8);
			Setcolor(15);
			printf(" 더 이상 생명이 없습니다. ");
			Sleep(500);
		}
		break;
	}
	m_Menu = 1;
}

void Menu::MenuOut(void)
{
	switch (m_MenuType)
	{
	case MAIN:
		break;
	case OPTION:
	case SELECT_PLAYER:
		m_MenuType = MAIN;
		break;
	case SELECT_MODE:
		m_MenuType = SELECT_PLAYER;
		break;
	case SELECT_HERO:
		m_GM->DeleteVestige();
		m_MenuType = SELECT_MODE;
		break;
	case PAUSE:
		m_On = FALSE;
		break;
	case GAME_OVER:
		break;
	}
	m_Menu = 1;
}

void Menu::MenuPrint(void)
{
	Print::get().Init();
	if (m_MenuType == OPTION) OptionMenuPrint();
	else if (m_MenuType == PAUSE) PausePrint();
	else if (m_MenuType == GAME_OVER) GameOverListPrint();
	else
	{
		for (int i = 0; i < m_MenuNum[m_MenuType]; i++)
		{
			if (m_Menu == i + 1)
			{
				Print::get().InText(CONSOLE_COLS / 5 * 2, CONSOLE_LINES / 5 * 2 + i, "☞");
			}
			Print::get().InText(CONSOLE_COLS / 5 * 2 + 3, CONSOLE_LINES / 5 * 2 + i, m_MenuList[m_MenuType][i]);
		}
	}
	Print::get().PrintText();
}

void Menu::OptionMenuPrint(void)
{
	for (int i = 0; i < m_MenuNum[m_MenuType]; i++)
	{
		if (m_Menu == i + 1)
		{
			Print::get().InText(CONSOLE_COLS / 3, CONSOLE_LINES / 5 * 2 + i, "☞");
		}
		Print::get().InText(CONSOLE_COLS / 3 + 3, CONSOLE_LINES / 5 * 2 + i, m_MenuList[m_MenuType][i]);
	}

	Print::get().InText(CONSOLE_COLS / 2, CONSOLE_LINES / 5 * 2,
		m_MenuList[GAME_SPEED][m_SideMenu[m_SideMenuType[GAME_SPEED]]]);

	Print::get().InText(CONSOLE_COLS / 2, CONSOLE_LINES / 5 * 2 + 1,
		m_MenuList[LOW_SPEC][m_SideMenu[m_SideMenuType[LOW_SPEC]]]);

	gameSpeed = m_SideMenu[m_SideMenuType[GAME_SPEED]];
	lowSpecMode = m_SideMenu[m_SideMenuType[LOW_SPEC]];
}

void Menu::PausePrint(void)
{
	Print::get().InText(CONSOLE_COLS / 5 * 2 + 2, CONSOLE_LINES / 3 + 2, "== [ Game Pause ] ==");
	for (int i = 0; i < m_MenuNum[m_MenuType]; i++)
	{
		if (m_Menu == i + 1)
		{
			Print::get().InText(CONSOLE_COLS / 5 * 2, CONSOLE_LINES / 3 + 4 + i, "☞");
		}
		Print::get().InText(CONSOLE_COLS / 5 * 2 + 3, CONSOLE_LINES / 3 + 4 + i, m_MenuList[m_MenuType][i]);
	}
}

void Menu::GameOverListPrint(void)
{
	Print::get().InText(CONSOLE_COLS / 5 * 2 + 2, CONSOLE_LINES / 3 + 2, "== [ Game Over ] ==");
	for (int i = 0; i < m_MenuNum[m_MenuType]; i++)
	{
		if (m_Menu == i + 1)
		{
			Print::get().InText(CONSOLE_COLS / 5 * 2, CONSOLE_LINES / 3 + 4 + i, "☞");
		}
		Print::get().InText(CONSOLE_COLS / 5 * 2 + 3, CONSOLE_LINES / 3 + 4 + i, m_MenuList[m_MenuType][i]);
	}
}
