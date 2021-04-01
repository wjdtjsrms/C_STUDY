#include "std_lib_facilities.h"

double sum(const vector<double>& price, const vector<double>& weight)
{
	double result = 0.0;

	if (price.size() != weight.size())
		simple_error("size error");

	for (size_t i = 0; i < price.size(); i++)
	{
		result += price[i] * weight[i];
	}
	
	return result;
}



int main()
{
	vector<double> price;
	vector<double> weight;
	double input = 0.0;

	cout << "price 값을 입력해주세요: ";
	while (cin >> input)
	{
		price.push_back(input);
	}

	cout << "\n";
	cout << "weight 값을 입력해주세요: ";

	cin.clear();
	cin.ignore();
	while (cin >> input)
	{
		weight.push_back(input);
	}

	cout <<"결과 값: " << sum(price, weight) <<"\n";

	return 0;
}