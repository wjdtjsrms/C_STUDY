#include "std_lib_facilities.h"

int main()
{
	char ch;
	double val;

	cin >> ch;
	// ���ۿ� �ٽ� �÷� ���´�.
	cin.putback(ch);
	cin >> val;

	return 0;
}