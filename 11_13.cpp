#include "std_lib_facilities.h"

int main()
{
	string filename = "11_13.txt";
	vector<string> str;
	ifstream is(filename);
	if (!is) error("입력 파일 열수 없음");

	for (string s ; is >> s;)
	{
		str.push_back(s);
	}

	for (size_t i = 0; i < str.size() / 2; i++)
	{
		swap(str[i], str[str.size() - (i+1)]);
	}

	for (string s : str)
	{
		cout << s << " ";
	}
	cout << "\n";

	return 0;
}