#include "std_lib_facilities.h"


int main()
{
	double x, y;

	while (cin >> x >> y)
	{
		if (abs(x - y) <= 0.01)
		{
			cout << "둘이 거의 같음" << "\n";
		}
		else if (x < y)
		{
			cout << "더 큰값" << y << "\n";
			cout << "더 작은값" << x << "\n";
		}

		else if(x>y)
		{
			cout << "더 큰값" << x << "\n";
			cout << "더 작은값" << y << "\n";
			
		}

		cout<<abs(x - y);
	}

	return 0;
}