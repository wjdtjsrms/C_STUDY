#include "std_lib_facilities.h"

int main()
{
	int n, input;
	int sum = 0;
	vector<int> v1;

	cout << "�԰踦 ���� ������ ������ �Է�����!\n";
	cin >> n;
	cout << "������ �Է�����!\n";
	while (cin >> input)
	{
		v1.push_back(input);
	}

	cout << "�� ���� " << n << " �� ";
	for (int i = 0; i < n; i++)
	{
		cout << v1[i]<<" ";
	}
	cout << "�� ���� ";
	for (int i = 0; i < n; i++)
	{
		sum += v1[i];
	}
	cout << sum << " �Դϴ�.\n";

	return 0;
}