#include "stdafx.h"
#include "Frame.h"
#include "Print.h"
#include "setting.h"
#pragma comment(lib, "winmm.lib")

Frame::Frame() : m_PrevTime(0), m_NowTime(0), m_deltaTime(0), m_Frame(0), m_Time(0) {}

void Frame::SetDeltaTime(void)
{
	m_NowTime = timeGetTime();
	m_deltaTime = m_NowTime - m_PrevTime;
	m_PrevTime = m_NowTime;
}

void Frame::FrameCheck(void)
{
	m_Frame++;
	if (time(NULL) - m_Time >= 1){
		Print::get().PrintTop();
		Print::get().PrintBottom();
		Gotoxy(0, CONSOLE_LINES);
		Setcolor(Color(FRAME_STATUS));
		printf("Frame: %d   mob:%5d\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t   ", m_Frame, mob.size());
		m_Time = (unsigned int)time(NULL);
		m_Frame = 0;
		Setcolor(Color(SCREEN));
	}
}
