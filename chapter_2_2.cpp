#include"std_lib_facilities.h"

int main()
{
	cout << "부동 소수점 값 입력\n";
	double n;
	cin >> n;

	cout << "n == " << n
		<< "\nn+1 == " << n + 1
		<< "\n3 곱하기 n == " << n * 3
		<< "\nn의 두 배 == " << n + n
		<< "\nn 제곱 == " << n * n
		<< "\nn 나누기 2 == " << n / 2
		<< "\nn의 제곱근 == " << sqrt(n)
		<< "\n";

	return 0;
}