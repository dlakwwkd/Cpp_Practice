/*
	2014.07.09
	간단한 동물 관리 프로그램 만들어보기 (구조체 이용)
*/

#include <iostream>

typedef struct Animal
{
	char name[30];	//이름
	int age;		//나이
	int health;		//체력
	int food;		//포만도
	int clean;		//청결도
} Animal;

void create_animal(Animal *animal)
{
	std::cout << "동물의 이름? ";
	std::cin >> animal->name;

	std::cout << "동물의 나이? ";
	std::cin >> animal->age;

	animal->health = 100;
	animal->food = 100;
	animal->clean = 100;
}

void play(Animal *animal)
{
	animal->health += 10;
	animal->food -= 20;
	animal->clean -= 30;
}

void one_day_pass(Animal *animal)
{
	animal->health -= 10;
	animal->food -= 30;
	animal->clean -= 20;
}

void show_stat(Animal *animal)
{
	std::cout << std::endl;
	std::cout << "[ " << animal->name << "의 상태 ]" << std::endl;
	std::cout << "체력\t: " << animal->health << std::endl;
	std::cout << "배부름\t: " << animal->food << std::endl;
	std::cout << "청결\t: " << animal->clean << std::endl;
	std::cout << std::endl;
}

int main()
{
	Animal* list[30];
	int animal_num = 0;

	std::cout << "< 동물 키우기 프로그램 >" << std::endl;

	for (;;)
	{
		std::cout << std::endl;
		std::cout << "1. 동물 추가하기" << std::endl;
		std::cout << "2. 놀기" << std::endl;
		std::cout << "3. 상태 보기" << std::endl;
		std::cout << "4. 종료" << std::endl;
		std::cout << "입력: ";

		int input;
		std::cin >> input;

		if (input == 4) break;

		switch (input)
		{
			int play_with;
		case 1:
			list[animal_num] = new Animal;
			create_animal(list[animal_num]);

			animal_num++;
			break;
		case 2:
			std::cout << "누구랑 놀게? ";
			std::cin >> play_with;

			if (play_with < animal_num)
				play(list[play_with]);
			else
				std::cout << "그런 애 없어!" << std::endl;
			break;
		case 3:
			std::cout << "누구껄 보게? ";
			std::cin >> play_with;
			if (play_with < animal_num)
				show_stat(list[play_with]);
			else
				std::cout << "그런 애 없어!" << std::endl;
			break;
		}
	}
	for (int i = 0; i != animal_num; i++)
	{
		delete list[i];
	}

	return 0;
}