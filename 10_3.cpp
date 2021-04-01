#include "std_lib_facilities.h"


istream& operator >> (istream& is, vector<int>& temperature)
{
	char ch1;

	if (is >> ch1 && ch1 != '(')
	{
		is.unget();
		is.clear(ios_base::badbit);
		return is;
	}

	int data;
	int temp;
	char comma1, comma2;
	char ch2;

	is >> data >> comma1 >> data >> comma2 >> temp >> ch2;

	if (!is || comma1 != ',' || comma2 != ',' || ch2 != ')')
	{
		is.clear(ios_base::failbit);
	}

	// 있을 수 없는 온드
	if (temp < -999 || 999 < temp)
	{
		is.clear(ios_base::failbit);
		return is;
	}

	temperature.push_back(temp);
	return is;
}




int main()
{
	string filename = "raw_temps.txt";
	ifstream ifs(filename);
	vector<int> temperature;
	int total = 0, median = 0;

	while (true)
	{
		if (!(ifs >> temperature)) break;
	}

	// 벡터의 값 확인
	cout <<"입력받은 값" << "\n";
	for (int i : temperature)
	{
		cout << i << " ";
	}
	cout << "\n";

	// 평균값 구하기
	for (int i : temperature)
	{
		total += i;
	}
	total /= temperature.size();

	// 중앙값 구하기
	sort(temperature);


	cout << "평균값 : " << total << "\n";
	cout << "중앙값 : " << temperature[temperature.size()/2] << "\n";

	return 0;
}