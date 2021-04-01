#include "std_lib_facilities.h"
// 가장 많이 중복된 숫자 찾기

int main()
{
	vector<int> value;
	int input;
	int count = 0, max = 0;
	int mode = 0;

	while (cin >> input)
	{
		value.push_back(input);
	}
	
	sort(value);

	for (int i = value.size() - 1; i > 0; i--)
	{
		if (value[i] == value[i - 1])
		{
			++count;
		}
		else if(value[i] != value[i - 1] || i==1)
		{
			if (max < count)
			{
				mode = value[i];
				max = count;
			}
			count = 0;
		}

	}

	cout <<"mode : "<< mode << "\n";

	return 0;
}