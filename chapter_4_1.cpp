#include "std_lib_facilities.h"


int main()
{
	double x, y;

	while (cin >> x >> y)
	{
		if (abs(x - y) <= 0.01)
		{
			cout << "���� ���� ����" << "\n";
		}
		else if (x < y)
		{
			cout << "�� ū��" << y << "\n";
			cout << "�� ������" << x << "\n";
		}

		else if(x>y)
		{
			cout << "�� ū��" << x << "\n";
			cout << "�� ������" << y << "\n";
			
		}

		cout<<abs(x - y);
	}

	return 0;
}