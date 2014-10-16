#include <stdio.h>
#include <iostream>

#define NUM 1

#if(NUM == 1)
struct Point
{
	int x;
	int y;

	Point operator+(Point param)
	{
		Point temp;
		temp.x = this->x + param.x;
		temp.y = this->y + param.y;
		return temp;
	}
};

int main(void)
{
	Point temp1, temp2;
	temp1 = { 2, 3 };
	temp2 = { 5, 2 };

	Point result1 = temp1 + temp2;
	Point result2 = temp1.operator+(temp2);

	printf(" %d, %d \n %d, %d",
		result1.x, result1.y,
		result2.x, result2.y);
	getchar();
	return 0;
}
#endif

#if(NUM == 2)
class Point
{
public:
	Point(int x, int y) : m_X(x), m_Y(y){}

	bool operator==(Point p)
	{
		if (this->m_X != p.m_X || this->m_Y != p.m_Y)
			return false;
		else
			return true;
	}
private:
	int m_X;
	int m_Y;
};

int main(void)
{
	Point temp1(3, 7), temp2(3, 7), temp3(6, 7);
	
	if (temp1 == temp2) printf("temp1 == temp2\n");
	else				printf("temp1 != temp2\n");

	if (temp1 == temp3) printf("temp1 == temp3\n");
	else				printf("temp1 != temp3\n");

	getchar();
	return 0;
}
#endif

#if(NUM == 3)
class Complex
{
public:
	Complex(int real, int imaginary)
		: m_Real(real), m_Imaginary(imaginary){}

	Complex operator++()	//전치 연산
	{
		this->m_Real++;
		return *this;
	}
	Complex operator++(int)	//후치 연산
	{
		Complex prev(this->m_Real, this->m_Imaginary);
		this->m_Real++;
		return prev;
	}
private:
	int m_Real;
	int m_Imaginary;
};

int main(void)
{
	Complex cl(2, 3), prefix(0,0), postfix(0,0);

	prefix	= ++cl;	// prefix = cl = (3, 3)
	postfix = cl++;	// postfix = (3, 3), cl = (4, 3)

	return 0;
}
#endif

#if(NUM == 4)
class Complex
{
public:
	Complex(int real, int imaginary)
		: m_Real(real), m_Imaginary(imaginary){}

	friend std::ostream& operator<<(std::ostream& o, Complex c);

private:
	int m_Real;
	int m_Imaginary;
};

std::ostream& operator<<(std::ostream& o, Complex c)
{
	o << c.m_Real << std::showpos <<
		c.m_Imaginary << "i" << std::noshowpos;
	return o;
}

int main(void)
{
	Complex cl(5, 3);

	std::cout << cl << std::endl;

	getchar();
	return 0;
}
#endif

#if(NUM == 5)
class Point
{
public:
	Point(int x, int y) : m_X(x), m_Y(y){}

	inline const Point operator+(const Point& p) const
	{
		int x = this->m_X + p.m_X;
		int y = this->m_Y + p.m_Y;
		return Point( x, y );
	}

	inline bool operator==(const Point& p) const
	{
		if (this->m_X != p.m_X || this->m_Y != p.m_Y)
			return false;
		else
			return true;
	}

	inline Point& operator+=(const Point& p)
	{
		this->m_X += p.m_X;
		this->m_Y += p.m_Y;
		return *this;
	}

private:
	int m_X;
	int m_Y;
};

int main(void)
{
	Point temp1(3, 7), temp2(3, 7), temp3(6, 7);

	if (temp1 == temp2) printf("temp1 == temp2\n");
	else				printf("temp1 != temp2\n");

	if (temp1 == temp3) printf("temp1 == temp3\n");
	else				printf("temp1 != temp3\n");

	temp1 = temp1 + temp3;
	temp2 += temp3;

	if (temp1 == temp2) printf("temp1 == temp2\n");
	else				printf("temp1 != temp2\n");

	getchar();
	return 0;
}
#endif
