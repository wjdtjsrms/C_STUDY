#include "std_lib_facilities.h"


int factorial(int a)
{
	if (a < 0)
	{
		simple_error("팩토리얼의 인자가 0보다 작습니다");
	}

	int x = 1;
	if (a == 0)
	{
		return 1;
	}
	for (int i = 1; i <= a; i++)
	{
		x *= i;
	}
	return x;
}

int permutation(int a, int b)
{
	return factorial(a) / factorial(a - b);
}

int combination(int a, int b)
{
	return permutation(a, b) / factorial(b);
}

int main()
{
	int a, b;
	char c;
	cout << "숫자 두 개를 입력해주세요.\n";
	cin >> a >> b;
	cout << "순열과 조합 중 선택해주세요. (P = 순열, C = 조합)\n";
	cin >> c;

	if (c == 'P')
	{
		cout <<"순열의 값: " << permutation(a, b) <<"\n";
	}
	else if (c == 'C')
	{
		cout <<"조합의 값: " << combination(a, b) << "\n";
	}
	else
	{
		cerr << "잘못된 입력\n";
	}
	return 0;
}