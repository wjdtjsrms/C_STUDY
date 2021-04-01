#include "std_lib_facilities.h"

int main()
{
	double a, b, c;
	double x = 0;
	double x2 = 0;
	cin >> a >> b >> c;
	
	if ((b*b) - (4 * a*c) < 0)
	{
		simple_error("방정식의 실수해가 없을걸?");
	}
	x = ((-1 * b) + sqrt((b*b) - (4 * a*c))) / (2*a);
	x2 = ((-1 * b) - sqrt((b*b) - (4 * a*c))) / (2 * a);

	cout << x <<" \n";
	cout << x2 << " \n";
	return 0;
}