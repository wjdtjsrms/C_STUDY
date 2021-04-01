#include "std_lib_facilities.h"

template <typename T>
vector<T> vec_reverse(vector<T> vec)
{
	 reverse(vec.begin(), vec.end());

	 return vec;
}

template <typename T>
vector<T> vec_ref_reverse(vector<T> &vec)
{
	reverse(vec.begin(), vec.end());

	return vec;
}



int main()
{
	vector<int> vec = { 1,2,3 };
	vector<string> s_vec = { "HELLO"," NEW ", "WORLD" };
	
	cout << "���� ���� ����: ";
	for (int i : vec_reverse<int>(vec))
	{
		cout << i << " ";
	}


	cout << "\n";

	vec_ref_reverse<string>(s_vec);
	cout << "������ ���� ����: ";
	for (string str : s_vec)
	{
		cout << str << " ";
	}

	cout << "\n";



	return 0;
}