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
		cout << x <<" �� "<<y<<" �� ���� = "<< x + y<<" �Դϴ�.\n";
		break;
	}
	case '-':
	{
		cout << x << " �� " << y << " �� ���� = " << x - y << " �Դϴ�.\n";
		break;
	}
	case '*':
	{
		cout << x << " �� " << y << " �� ���� = " << x * y << " �Դϴ�.\n";
		break;
	}

	case '/':
	{
		cout << x << " �� " << y << " �� ������� = " << x / y << " �Դϴ�.\n";
		break;
	}

	default:
		cout << "�� �� ���� ��ȣ�Դϴ�.\n";
		break;
	}

	return 0;
}