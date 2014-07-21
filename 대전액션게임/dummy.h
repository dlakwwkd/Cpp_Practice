// dumy.h : Dumy 클래스와 그 자식 클래스들을 선언합니다.
//

#ifndef __DUMMY_H
#define __DUMMY_H

#include "stdafx.h"

class Dummy : public Hero
{
public:
	Dummy();
	Dummy(POINT pc);
	~Dummy();

	void show_pos(void);
	void ai(int reduce);
};

#endif