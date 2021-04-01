#include "std_lib_facilities.h"

int main()
{
	int max = 0;
	int count = 0;

	cout << "max 값을 입력하시오.\n";
	cin >> max;

	vector<int> primes = { 2 };

	for (int i = 3; i <= max; i++)
	{
		count = 0;

		for (int x : primes)
		{
			if (i % x == 0)
			{
				++count;
			}
		}

		if (count == 0)
		{
			primes.push_back(i);
		}
	}

	for (int x : primes)
	{
		cout << x << " ";
	}

	return 0;
}