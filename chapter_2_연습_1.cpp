#include"std_lib_facilities.h"

int main()
{
	int length;
	cout << "mile 단위로 거리를 입력해주세요\n";
	cin >> length;

	cout << "mile : " << length << " mile\n";
	cout << "-> km : " << length * 1.609 << " km\n";
	return 0;
}