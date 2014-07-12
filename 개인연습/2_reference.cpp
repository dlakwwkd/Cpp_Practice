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
	
	// ���� C��� ������ ������ call by reference
	change_val(&num);
	cout << num << endl;
	
	// C++�� ���ο� ���� reference(������) ����
	change_val_ref(num);
	cout << num << endl;

	
	int num_2 = 10;

	// ������ ����� �ʱ�ȭ
	int *ptr;
	ptr = &num_2;

	// ������ ����� �ʱ�ȭ	(���۷����� ������ ����� ���ÿ� �ʱ�ȭ �ؾ���)
	int &ref = num_2;

	// �����ͺ��� �� ���� (������ ������ �ȵǴ°� ����)
	cout << *ptr << endl;
	cout << ref << endl;

	(*ptr)++;
	cout << *ptr << endl;

	ref++;
	cout << ref << endl;

	cout << *ptr << endl;
	cout << ref << endl;

	/* ���۷����� �� �� �ʱ�ȭ �Ǹ� �ٸ� ������ ������ �� �� ����.*/
	//�����ʹ� ����
	int num_3 = 5;
	ptr = &num_3;


	// ������ �����ϱ�
	int x;
	int& y = x;
	int& z = y;

	x = 1;
	cout << "x: " << x << " y: " << y << " z: " << z << endl;

	y = 2;
	cout << "x: " << x << " y: " << y << " z: " << z << endl;

	z = 3;
	cout << "x: " << x << " y: " << y << " z: " << z << endl;

	/* y�� z ��� x�� ���۷����� ��, ���۷����� ���۷����� ���� �ƴϴ�.*/

	/* �������� ������, �������� �迭, �������� ������ ���� ������ �� ����.
	-> �����ڴ� �޸� �� �������� �ʱ� ����(�����Ͻ� ��ȯ�Ǵ� ���� ���� ����)*/

	// �迭�� ���۷����� ����(�׷��� �� ��������� �ʴ´�)
	int arr[3] = { 1, 2, 3 };
	int (&ref_2)[3] = arr;

	ref_2[0] = 2;
	ref_2[1] = 3;
	ref_2[2] = 1;

	cout << arr[0] << ref_2[1] << arr[2] << endl;


	/* ����� ���ͷ��̱� ������ ���۷����� �����Ϸ��� const�� �ٿ��־�� �Ѵ�.*/
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