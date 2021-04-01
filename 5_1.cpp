#include "std_lib_facilities.h"

double ctok(double c)
{
	if (c < -273.15)
	{
		simple_error("절대 온도 보다 낮은 온도는 없습니다.");
	}
	double k = c + 273.15;
	return k;
}

double ktoc(double k)
{
	double c = k - 273.15;
	return c;
}

int main()
{
	double c = 0;
	char unit;
	cin >> c >> unit;

	if (unit == 'C')
	{
		cout << ctok(c) << "K\n";
	}
	else if (unit == 'k')
	{	
		cout << ktoc(c) << "C\n";
	}
	else
	{
		simple_error("등록되지 않은 기호");
	}

	return 0;
}