#include "std_lib_facilities.h"

int main()
{
	double x;
	vector <double> value;

	while (cin >> x)
	{
		value.push_back(x);
	}

	sort(value);

	for (double i : value)
	{
		cout << i << "\n";
	}


	return 0;
}