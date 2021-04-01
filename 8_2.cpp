#include "std_lib_facilities.h"

void print(const string& str,const vector<int>& vec) {

	cout << str;
	for (int i: vec)
	{
		cout << i << " ";
	}
	cout << "\n";
}

void fibonacci(int x,int y,vector<int>& v, int n)
{
	v.push_back(x);
	v.push_back(y);

	for (int i = 2; i <= n; i++)
	{
		v.push_back(v[i - 1] + v[i - 2]);	
	}
}



int main()
{
	string str = "pibonacci: ";
	vector<int> vec;

	fibonacci(1, 2, vec, 5);

	print(str, vec);
	return 0;
}