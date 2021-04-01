#include "std_lib_facilities.h"


int main()
{
	double x, y;
	char sym;

	cin >> x >> y >> sym;

	switch (sym)
	{

	case '+':
	{
		cout << x <<" 와 "<<y<<" 의 합은 = "<< x + y<<" 입니다.\n";
		break;
	}
	case '-':
	{
		cout << x << " 와 " << y << " 의 차는 = " << x - y << " 입니다.\n";
		break;
	}
	case '*':
	{
		cout << x << " 와 " << y << " 의 곱은 = " << x * y << " 입니다.\n";
		break;
	}

	case '/':
	{
		cout << x << " 와 " << y << " 의 나누기는 = " << x / y << " 입니다.\n";
		break;
	}

	default:
		cout << "알 수 없는 기호입니다.\n";
		break;
	}

	return 0;
}