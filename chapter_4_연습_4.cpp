#include "std_lib_facilities.h"

int main()
{
	vector<string> names;
	vector<int> numbers;
	string name ="";
	int number = 0;

	while (cin >> name >> number)
	{		
		for (string n : names)
		{
			if (name == n)
			{
				simple_error("�ߺ��� �̸�");
			}
		}
		names.push_back(name);
		numbers.push_back(number);

	}

	for (int i = 0; i < names.size(); i++)
	{
		cout <<"name: "<< names[i] << "\n";
		cout << "number: " << numbers[i] << "\n";
	}

	return 0;
}