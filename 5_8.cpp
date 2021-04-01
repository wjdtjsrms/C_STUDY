#include "std_lib_facilities.h"

int main()
{
	int n, input;
	int sum = 0;
	vector<int> v1;

	cout << "함계를 구할 숫자의 개수를 입력하자!\n";
	cin >> n;
	cout << "정수를 입력하자!\n";
	while (cin >> input)
	{
		v1.push_back(input);
	}

	cout << "앞 숫자 " << n << " 개 ";
	for (int i = 0; i < n; i++)
	{
		cout << v1[i]<<" ";
	}
	cout << "의 합은 ";
	for (int i = 0; i < n; i++)
	{
		sum += v1[i];
	}
	cout << sum << " 입니다.\n";

	return 0;
}