#pragma once
class Key
{
public:
	Key();
	~Key();

	void setUp(int input);
	void setDown(int input);
	void setLeft(int input);
	void setRight(int input);
	void setZ(int input);
	void setX(int input);
	void setC(int input);
	void setV(int input);
	int getUp(void);
	int getDown(void);
	int getLeft(void);
	int getRight(void);
	int getZ(void);
	int getX(void);
	int getC(void);
	int getV(void);
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

