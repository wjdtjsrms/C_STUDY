
#include"std_lib_facilities.h"


int main()
{
	string name;
	double age=0;
	cout << "이름과 나이를 입력해주세요\n";
	cin >> name >> age;
	cout << "안녕하세요. " << name << " (나이 " << age*12 << "개월)\n";
	keep_window_open();
	return 0;
}

