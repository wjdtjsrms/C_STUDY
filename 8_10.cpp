#include "std_lib_facilities.h"

struct int_result
{
	int max = 0;
	int min = 0;
	int middle = 0;
};


int_result maxv(vector<int>& vec)
{
	int_result result;
	sort(vec);

	result.min = vec[0];
	result.max = vec[vec.size() - 1];
	result.middle = vec[vec.size() / 2];

	return result;
}


int main()
{
	int_result result;
	vector<int> vec = {10,20,5,60,2,1,35};

	result = maxv(vec);

	cout << "min: " << result.min << "\n";
	cout << "middle: " << result.middle << "\n";
	cout <<"max: "<< result.max <<"\n";

	return 0;
}