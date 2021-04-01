#include "std_lib_facilities.h"

int main()
{
	double x = 23457.891234;

	// 부동소수점의 정밀도를 설정한다.
	cout << setprecision(10);

	cout << defaultfloat << x << '\n'
		<< fixed << x << '\n'
		<< scientific << x << '\n';

	return 0;
}