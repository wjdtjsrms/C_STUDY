#include "std_lib_facilities.h"

int main()
{
	int birth_year = 1999;

	// ���λ縦 ���̰� �Ѵ�.
	cout << showbase;

	cout << "10����:\t"<< dec << birth_year <<"\n"
		<< "16����:\t" << hex << birth_year <<"\n"
		<< "8����:\t"  << oct << birth_year <<"\n";

	return 0;
}