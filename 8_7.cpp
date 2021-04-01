#include "std_lib_facilities.h"

int main()
{
	vector<string> name = { "jeong","yong","sock" };
	vector<string> name_temp = name;
	vector<double> age = { 22,25,24 };
	vector<double> age_temp = age;

	for (int i = 0; i < name.size(); i++)
	{
		cout << name[i] << " ";
		cout << age[i] << " ";
	}
	
	sort(name.begin(), name.end());

	for (int i = 0; i < name.size(); i++)
	{
		for (int j = 0; j < name_temp.size(); j++)
		{
			if (name[i] == name_temp[j])
			{
				age_temp[i] = age[j];
			}
		}
	}
	cout << "\n";
	for (int i = 0; i < name.size(); i++)
	{
		cout << name[i] << " ";
		cout << age_temp[i] << " ";
	}
	

	return 0;
}