#include "stdafx.h"

Key::Key() : up(VK_UP), down(VK_DOWN), left(VK_LEFT), right(VK_RIGHT),
z(Z_KEY), x(X_KEY), c(C_KEY), v(V_KEY){}

Key::~Key()
{
}

void Key::setUp(int input)
{
	up = input;
}
void Key::setDown(int input)
{
	down = input;
}
void Key::setLeft(int input)
{
	left = input;
}
void Key::setRight(int input)
{
	right = input;
}
void Key::setZ(int input)
{
	z = input;
}
void Key::setX(int input)
{
	x = input;
}
void Key::setC(int input)
{
	c = input;
}
void Key::setV(int input)
{
	v = input;
}
int Key::getUp(void)
{
	return up;
}
int Key::getDown(void)
{
	return down;
}
int Key::getLeft(void)
{
	return left;
}
int Key::getRight(void)
{
	return 	right;
}
int Key::getZ(void)
{
	return z;
}
int Key::getX(void)
{
	return 	x;
}
int Key::getC(void)
{
	return 	c;
}
int Key::getV(void)
{
	return 	v;
}
