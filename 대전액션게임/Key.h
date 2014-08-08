#pragma once
class Key
{
public:
	Key();
	~Key();

	void SetUp(int input);
	void SetDown(int input);
	void SetLeft(int input);
	void SetRight(int input);
	void SetZ(int input);
	void SetX(int input);
	void SetC(int input);
	void SetV(int input);
	int GetUp(void);
	int GetDown(void);
	int GetLeft(void);
	int GetRight(void);
	int GetZ(void);
	int GetX(void);
	int GetC(void);
	int GetV(void);
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

