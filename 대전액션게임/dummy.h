// dumy.h : Dumy Ŭ������ �� �ڽ� Ŭ�������� �����մϴ�.
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