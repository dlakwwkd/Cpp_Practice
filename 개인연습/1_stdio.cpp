/*
	2014.07.08
*/

#include <iostream>		// C++�� ǥ�� ������� ��� �⺻ ���
using namespace std;	// std��� �̸������� ����ϰڴٴ� ����

int main()
{
	cout << "Hello, World!!" << endl;				// �⺻���� ��� ����
	std::cout << "Hello, World!!" << std::endl;		// using namespace�� ���� �ʾ��� ���
	
	cout << "1" << "2" << "3" << "4" << endl;		// �̷� ���·� ���޾� ��� ����
	cout << endl;									// ���� (printf("\n"), puts("")�� ���� �ǹ�)

	
	int input;							// C++���� ���� ������ �߰��� �ص� ������
	char str[20];
	char ch;

	cout << "�Է�: ";					// �������� ���� �� endl�� ���� ��
	cin >> input;						// �⺻���� �Է� ���� (%������, &������ ���� �ʿ����)
	cin >> str;
	cin >> ch;
	cout << "��: " << input << str << ch << endl;		// ���� ��� ���� (%�����ڰ� �ʿ����)

	return 0;
}