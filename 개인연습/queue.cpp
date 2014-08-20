#include <windows.h>
#include <iostream>
#include <queue>


int main()
{
	std::queue<int> a;

	std::cout << a.size() << std::endl;


	for (int i = 0; i < 10; ++i)
	{
		a.push(i);
		std::cout << a.front() << ", " << a.back() << ", " << a.size() << std::endl;
	}

	for (int i = 0; i < 10; ++i)
	{
		a.pop();
		if (a.size() == 0) break;
		std::cout << a.front() << ", " << a.back() << ", " << a.size() << std::endl;
	}
	std::cout << a.size() << std::endl;
	getchar();
	return 0;
}