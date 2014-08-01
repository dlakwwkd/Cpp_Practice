#include <iostream>

int yame_atoi(char* input)
{
	int temp = 0;
	for (int i = 0; input[i] != '\0'; i++)
	{
		if (input[i] >= '0' && input[i] <= '9')
		{
			temp *= 10;
			temp += (input[i] - '0');
		}
	}
	return temp;
}

int main()
{
	char str[50];
	std::cin >> str;
	int strint = yame_atoi(str);
	std::cout << strint;
	while(getchar() != '\n');
	return 0;
}