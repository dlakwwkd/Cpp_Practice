#pragma once
class Key
{
public:
	Key();

	void SetUp(int input) { up = input; }
	void SetDown(int input) { down = input; }
	void SetLeft(int input) { left = input; }
	void SetRight(int input) { right = input; }
	void SetZ(int input) { z = input; }
	void SetX(int input) { x = input; }
	void SetC(int input) { c = input; }
	void SetV(int input) { v = input; }
	int GetUp(void) { return up; }
	int GetDown(void) { return down; }
	int GetLeft(void) { return left; }
	int GetRight(void) { return right; }
	int GetZ(void) { return z; }
	int GetX(void) { return x; }
	int GetC(void) { return c; }
	int GetV(void) { return v; }
private:
	int up;
	int down;
	int left;
	int right;
	int z;
	int x;
	int c;
	int v;
};

