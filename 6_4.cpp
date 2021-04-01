#include "std_lib_facilities.h"

class Name_value
{
public:
	Name_value(string s, int n) 
		: names(s), numbers(n) {}

	string names;
	int numbers;

};

int main()
{
	vector <Name_value> name_value;
	string s;
	int n;
	while (cin >> s >> n)
	{
		for (int i = 0; i < name_value.size(); i++)
		{
			if (s == name_value[i].names)
			{
				simple_error("중복된 이름");
			}
		}

		Name_value temp(s,n);
		name_value.push_back(temp);
	}

	for (int i = 0; i < name_value.size(); i++)
	{
		cout << name_value[i].names << " " <<name_value[i].numbers <<"\n";
	}

	return 0;
}