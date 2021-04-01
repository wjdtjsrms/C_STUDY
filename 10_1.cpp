#include "std_lib_facilities.h"

int main()
{
	string file_name = "10_1.txt";
	ifstream is(file_name);
	int x=0;
	while (is >> x)
	{
		cout << x << " ";
		x += x;
	}
	cout <<"\n"<< x << "\n";
	return 0;
}