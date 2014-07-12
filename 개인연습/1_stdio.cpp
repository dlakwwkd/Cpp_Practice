/*
	2014.07.08
*/

#include <iostream>		// C++의 표준 입출력이 담긴 기본 헤더
using namespace std;	// std라는 이름공간을 사용하겠다는 선언

int main()
{
	cout << "Hello, World!!" << endl;				// 기본적인 출력 형태
	std::cout << "Hello, World!!" << std::endl;		// using namespace를 하지 않았을 경우
	
	cout << "1" << "2" << "3" << "4" << endl;		// 이런 형태로 연달아 사용 가능
	cout << endl;									// 개행 (printf("\n"), puts("")와 같은 의미)

	
	int input;							// C++에선 변수 선언을 중간에 해도 괜찮음
	char str[20];
	char ch;

	cout << "입력: ";					// 개행하지 않을 땐 endl을 빼면 됨
	cin >> input;						// 기본적인 입력 형태 (%연산자, &연산자 등이 필요없음)
	cin >> str;
	cin >> ch;
	cout << "값: " << input << str << ch << endl;		// 변수 출력 형태 (%연산자가 필요없음)

	return 0;
}