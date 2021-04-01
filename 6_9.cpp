#include "std_lib_facilities.h"

int main()
{
	char ch;
	double val;

	cin >> ch;
	// 버퍼에 다시 올려 놓는다.
	cin.putback(ch);
	cin >> val;

	return 0;
}