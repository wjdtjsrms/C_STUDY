#include "std_lib_facilities.h"
#include <random>
struct Reading
{
	int day;
	int hour;
	int temperature;
};

ostream& operator << (ostream& os, Reading& read)
{
	return os << '(' << read.day << ',' << read.hour << ',' << read.temperature << ')';
}


int main()
{
	string filename = "raw_temps.txt";
	ofstream os(filename);

	// 난수 생성
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 30);

	for (int i = 0; i < 30; i++)
	{
		Reading read{ (i % 30) + 1 ,(i % 24) + 1, dis(gen) };
		os << read;
	}

	return 0;
}