#include"std_lib_facilities.h"

int main()
{
	cout << "�ε� �Ҽ��� �� �Է�\n";
	double n;
	cin >> n;

	cout << "n == " << n
		<< "\nn+1 == " << n + 1
		<< "\n3 ���ϱ� n == " << n * 3
		<< "\nn�� �� �� == " << n + n
		<< "\nn ���� == " << n * n
		<< "\nn ������ 2 == " << n / 2
		<< "\nn�� ������ == " << sqrt(n)
		<< "\n";

	return 0;
}