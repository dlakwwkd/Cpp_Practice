/*
	2014.07.09
*/

#include <iostream>

int main()
{
	/* new �� delete �� ��� */
	int* p = new int;	//int ũ���� ������ �Ҵ��Ͽ� �� �ּҰ��� p�� ����(T* pointer = new T;)
	*p = 10;

	std::cout << *p << std::endl;	//������ using namespace�� ���� �ʴ°� �߼���

	delete p;			//�Ҵ�� ���� ����(���� �Ҵ��� ������ ����)



	/* new �� �迭 �Ҵ��ϱ� */
	int arr_size;

	std::cout << "array size: ";
	std::cin >> arr_size;

	int *list = new int[arr_size];

	for (int i = 0; i < arr_size; i++)
	{
		std::cin >> list[i];
	}
	for (int i = 0; i < arr_size; i++)
	{
		std::cout << i << "th element of list: " << list[i] << std::endl;
	}

	delete[]list;



	/* C++ ������ ��𼭳� ���� ������ ����������, ����� �߰�ȣ{}�� ��� ���������� �Ҹ�� */
	int a = 1;
	{
		std::cout << a << std::endl;
		int a = 2;
		std::cout << a << std::endl;
	}
	std::cout << a << std::endl;

	if (1)
	{
		int a = 3;
	}
	std::cout << a << std::endl;

	return 0;
}