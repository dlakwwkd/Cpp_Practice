/*
	2014.07.09
	������ ���� ���� ���α׷� ������ (����ü �̿�)
*/

#include <iostream>

typedef struct Animal
{
	char name[30];	//�̸�
	int age;		//����
	int health;		//ü��
	int food;		//������
	int clean;		//û�ᵵ
} Animal;

void create_animal(Animal *animal)
{
	std::cout << "������ �̸�? ";
	std::cin >> animal->name;

	std::cout << "������ ����? ";
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
	std::cout << "[ " << animal->name << "�� ���� ]" << std::endl;
	std::cout << "ü��\t: " << animal->health << std::endl;
	std::cout << "��θ�\t: " << animal->food << std::endl;
	std::cout << "û��\t: " << animal->clean << std::endl;
	std::cout << std::endl;
}

int main()
{
	Animal* list[30];
	int animal_num = 0;

	std::cout << "< ���� Ű��� ���α׷� >" << std::endl;

	for (;;)
	{
		std::cout << std::endl;
		std::cout << "1. ���� �߰��ϱ�" << std::endl;
		std::cout << "2. ���" << std::endl;
		std::cout << "3. ���� ����" << std::endl;
		std::cout << "4. ����" << std::endl;
		std::cout << "�Է�: ";

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
			std::cout << "������ ���? ";
			std::cin >> play_with;

			if (play_with < animal_num)
				play(list[play_with]);
			else
				std::cout << "�׷� �� ����!" << std::endl;
			break;
		case 3:
			std::cout << "������ ����? ";
			std::cin >> play_with;
			if (play_with < animal_num)
				show_stat(list[play_with]);
			else
				std::cout << "�׷� �� ����!" << std::endl;
			break;
		}
	}
	for (int i = 0; i != animal_num; i++)
	{
		delete list[i];
	}

	return 0;
}