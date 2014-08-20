#pragma once
class Frame
{
public:
	static Frame& get()
	{
		static Frame instance;
		return instance;
	}
	double	GetDeltaTime(void) { return m_deltaTime; }
	void	SetDeltaTime(void);
	void	FrameCheck(void);
private:
	Frame();
	DWORD		 m_PrevTime;
	DWORD		 m_NowTime;
	double		 m_deltaTime;
	int			 m_Frame;
	unsigned int m_Time;
};

