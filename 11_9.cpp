#include "std_lib_facilities.h"

int main()
{
	double x = 23457.891234;

	// �ε��Ҽ����� ���е��� �����Ѵ�.
	cout << setprecision(10);

	cout << defaultfloat << x << '\n'
		<< fixed << x << '\n'
		<< scientific << x << '\n';

	return 0;
}