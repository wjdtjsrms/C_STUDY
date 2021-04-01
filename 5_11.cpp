#include "std_lib_facilities.h"

int main()
{
	vector<int> pibo = { 1,1 };
	int i = 2;
	int n = 0;
		while (true)
		{ 
			try {
				n = pibo[i - 1] + pibo[i - 2];
				if (n < 0)
					throw 1;
			}
			catch (int)
			{
				for (int x : pibo)
				{
					cout << x << "\n";
				}
				return 0;
			}
			
			pibo.push_back(n);
			++i;
		}
	
	return 0;
}