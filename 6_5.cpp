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
	
	cout << "값에 의한 전달: ";
	for (int i : vec_reverse<int>(vec))
	{
		cout << i << " ";
	}


	cout << "\n";

	vec_ref_reverse<string>(s_vec);
	cout << "참조에 의한 전달: ";
	for (string str : s_vec)
	{
		cout << str << " ";
	}

	cout << "\n";



	return 0;
}