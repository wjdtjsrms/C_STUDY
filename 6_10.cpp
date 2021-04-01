#include "std_lib_facilities.h"


int factorial(int a)
{
	if (a < 0)
	{
		simple_error("���丮���� ���ڰ� 0���� �۽��ϴ�");
	}

	int x = 1;
	if (a == 0)
	{
		return 1;
	}
	for (int i = 1; i <= a; i++)
	{
		x *= i;
	}
	return x;
}

int permutation(int a, int b)
{
	return factorial(a) / factorial(a - b);
}

int combination(int a, int b)
{
	return permutation(a, b) / factorial(b);
}

int main()
{
	int a, b;
	char c;
	cout << "���� �� ���� �Է����ּ���.\n";
	cin >> a >> b;
	cout << "������ ���� �� �������ּ���. (P = ����, C = ����)\n";
	cin >> c;

	if (c == 'P')
	{
		cout <<"������ ��: " << permutation(a, b) <<"\n";
	}
	else if (c == 'C')
	{
		cout <<"������ ��: " << combination(a, b) << "\n";
	}
	else
	{
		cerr << "�߸��� �Է�\n";
	}
	return 0;
}