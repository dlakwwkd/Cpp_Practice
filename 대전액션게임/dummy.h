// dumy.h : Dumy Ŭ������ �� �ڽ� Ŭ�������� �����մϴ�.
//

#ifndef __DUMMY_H
#define __DUMMY_H

#include "stdafx.h"

class Dummy : public Hero
{
protected:

public:
	Dummy();
	Dummy(POINT pc);
	~Dummy();

	void ai(int reduce);

};

#endif