#include "std_lib_facilities.h"

vector<int> str_size(const vector<string>& vec)
{
	vector<int> result;

	for (int i = 0; i < vec.size(); i++)
	{
		
		result.push_back(vec[i].size());
	}

	return result;
}


void long_str(vector<int>& int_vec, vector<string>& str_vec)
{
	vector<int> int_temp = int_vec;
	vector<string> str_temp = str_vec;
	sort(int_vec);

	for (int i = 0; i < int_vec.size(); i++)
	{
		for (int j = 0; j < int_temp.size(); j++)
		{
			if (int_vec[i] == int_temp[j])
			{
				str_temp[i] = str_vec[j];
			}
		}
	}


	cout << "가장 짧은 string: " << str_temp[0]<<"\n";
	cout << "가장 긴 string: " << str_temp[str_vec.size()-1] << "\n";
}

void dictionary_str(vector<string>& str_vec)
{
	sort(str_vec);
	cout << "사전순 첫번째 string: " << str_vec[0] << "\n";;
	cout << "사전순 마지막 string: " << str_vec[str_vec.size() - 1] << "\n";;
}



int main()
{
	vector<int> result;
	vector <string> vec = { "abc","abcde", "xyzx","addbcd" };

	result=str_size(vec);

	long_str(result, vec);
	dictionary_str(vec);

	return 0;
}