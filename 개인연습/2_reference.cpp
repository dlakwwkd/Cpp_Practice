/*
	2014.07.08
*/

#include <iostream>
using namespace std;

int change_val(int *p);
int change_val_ref(int &p);

int main()
{
	int num = 5;

	cout << num << endl;
	
	// 기존 C언어 포인터 형식의 call by reference
	change_val(&num);
	cout << num << endl;
	
	// C++의 새로운 개념 reference(참조자) 도입
	change_val_ref(num);
	cout << num << endl;

	
	int num_2 = 10;

	// 포인터 선언과 초기화
	int *ptr;
	ptr = &num_2;

	// 참조자 선언과 초기화	(레퍼런스는 무조건 선언과 동시에 초기화 해야함)
	int &ref = num_2;

	// 포인터보다 더 편리함 (포인터 연산이 안되는게 단점)
	cout << *ptr << endl;
	cout << ref << endl;

	(*ptr)++;
	cout << *ptr << endl;

	ref++;
	cout << ref << endl;

	cout << *ptr << endl;
	cout << ref << endl;

	/* 레퍼런스는 한 번 초기화 되면 다른 변수의 별명이 될 수 없다.*/
	//포인터는 가능
	int num_3 = 5;
	ptr = &num_3;


	// 참조자 이해하기
	int x;
	int& y = x;
	int& z = y;

	x = 1;
	cout << "x: " << x << " y: " << y << " z: " << z << endl;

	y = 2;
	cout << "x: " << x << " y: " << y << " z: " << z << endl;

	z = 3;
	cout << "x: " << x << " y: " << y << " z: " << z << endl;

	/* y와 z 모두 x의 레퍼런스일 뿐, 레퍼런스의 레퍼런스인 것이 아니다.*/

	/* 참조자의 참조자, 참조자의 배열, 참조자의 포인터 등은 존재할 수 없다.
	-> 참조자는 메모리 상에 존재하지 않기 때문(컴파일시 변환되는 별명 같은 존재)*/

	// 배열의 레퍼런스는 가능(그러나 잘 사용하지는 않는다)
	int arr[3] = { 1, 2, 3 };
	int (&ref_2)[3] = arr;

	ref_2[0] = 2;
	ref_2[1] = 3;
	ref_2[2] = 1;

	cout << arr[0] << ref_2[1] << arr[2] << endl;


	/* 상수는 리터럴이기 때문에 레퍼런스로 참조하려면 const를 붙여주어야 한다.*/
	//int &ref_3 = 4; <- X
	const int &ref_3 = 4;
	
	int a = ref_3;
	cout << a << endl;


	return 0;
}


int change_val(int *p)
{
	*p = 3;
	return 0;
}

int change_val_ref(int &p)
{
	p = 7;
	return 0;
}