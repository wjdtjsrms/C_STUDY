#include "std_lib_facilities.h"

int main()
{
	string filename = "11_12.txt";
	fstream fs(filename);
	if (!fs) error("���� �б� ����");

	char ch;
	string s;
	while (fs >> ch)
	{
		s += ch;
	}

	reverse(s.begin(), s.end());
	cout << s << "\n";
	

	return 0;
}