#pragma once

class GameManager;

class Menu
{
public:
	static Menu& get()
	{
		static Menu instance;
		return instance;
	}
	void SetGM(GameManager* GM) { m_GM = GM; }
	void SetOn(bool on) { m_On = on; }
	void SetMenu(int menu) { m_Menu = menu; }
	void SetMenuType(MenuType type) { m_MenuType = type; }
	void MenuPlatform(void);
	void MenuIn(void);
	void MenuOut(void);
	void MenuPrint(void);
	void OptionMenuPrint(void);
	void GameOverPrint(void);
	void GameOverListPrint(void);
	void PausePrint(void);
	void PauseListPrint(void);

private:
	Menu();
	GameManager*					 m_GM;
	std::map<MenuType, std::string*> m_MenuList;
	std::map<MenuType, int>			 m_MenuNum;
	std::map<int, int>				 m_SideMenuType;
	std::map<int, int>				 m_SideMenu;
	MenuType						 m_MenuType;
	InputKey						 m_Input;
	int								 m_Menu;
	int								 m_PlayerCount;
	bool							 m_On;
};

