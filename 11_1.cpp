#include "std_lib_facilities.h"

int main()
{
	int birth_year = 1999;

	// 접두사를 보이게 한다.
	cout << showbase;

	cout << "10진수:\t"<< dec << birth_year <<"\n"
		<< "16진수:\t" << hex << birth_year <<"\n"
		<< "8진수:\t"  << oct << birth_year <<"\n";

	return 0;
}