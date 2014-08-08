#include "stdafx.h"
#include "command.h"
#include "Key.h"

Key::Key() : up(VK_UP), down(VK_DOWN), left(VK_LEFT), right(VK_RIGHT),
z(Z_KEY), x(X_KEY), c(C_KEY), v(V_KEY){}

Key::~Key()
{
}

void Key::SetUp(int input)
{
	up = input;
}
void Key::SetDown(int input)
{
	down = input;
}
void Key::SetLeft(int input)
{
	left = input;
}
void Key::SetRight(int input)
{
	right = input;
}
void Key::SetZ(int input)
{
	z = input;
}
void Key::SetX(int input)
{
	x = input;
}
void Key::SetC(int input)
{
	c = input;
}
void Key::SetV(int input)
{
	v = input;
}
int Key::GetUp(void)
{
	return up;
}
int Key::GetDown(void)
{
	return down;
}
int Key::GetLeft(void)
{
	return left;
}
int Key::GetRight(void)
{
	return 	right;
}
int Key::GetZ(void)
{
	return z;
}
int Key::GetX(void)
{
	return 	x;
}
int Key::GetC(void)
{
	return 	c;
}
int Key::GetV(void)
{
	return 	v;
}
