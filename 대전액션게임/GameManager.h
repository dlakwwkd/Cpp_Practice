#pragma once
class GameManager
{
public:
	GameManager();
	~GameManager();

	void SetGameRun(bool set) { m_GameRun = set; }
	void SetGamePlay(bool set) { m_GamePlay = set; }
	void SetHeroType(int set) { m_HeroType = set; }

	bool GetGameRun(void) { return m_GameRun; }
	bool GetGamePlay(void) { return m_GamePlay; }
	int GetHeroType(void) { return m_HeroType; }

	void InitPlay(void);
	void Respawne(void);
	void HeroCreate(int player_num);
	void GameRunLoop(void);
	void GamePlayLoop(void);
	void PlayerAction(int player_num);
	void PauseOption(void);
	void GameOver(int player_num);
	void DeleteVestige(void);
	void InputCommand(int player_num);

private:
	bool m_GameRun;
	bool m_GamePlay;
	int m_HeroType;
};

