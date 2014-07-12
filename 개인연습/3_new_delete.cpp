/*
	2014.07.09
*/

#include <iostream>

int main()
{
	/* new 와 delete 의 사용 */
	int* p = new int;	//int 크기의 공간을 할당하여 그 주소값을 p에 대입(T* pointer = new T;)
	*p = 10;

	std::cout << *p << std::endl;	//요즘은 using namespace를 쓰지 않는게 추세임

	delete p;			//할당된 공간 해제(동적 할당한 공간만 가능)



	/* new 로 배열 할당하기 */
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



	/* C++ 에서는 어디서나 변수 선언이 가능하지만, 선언된 중괄호{}를 벗어난 지역변수는 소멸됨 */
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