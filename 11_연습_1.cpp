#include "std_lib_facilities.h"

void tolower(string & s)
{	
	for (int i = 0; i < s.size(); i++)
	{
		s[i] = tolower(s[i]);
	}
}


int main()
{
	string filename = "11_1_input.txt";
	string filename2 = "11_1_output.txt";
	ifstream is(filename);
	ofstream os(filename2);
	if (!is) error("�Է� ������ ã�� ���߽��ϴ�.");
	if (!os) error("��� ������ ã�� ���߽��ϴ�.");

	string fileStr;
	vector<string> fileData;

	while (is >> fileStr)
	{
		tolower(fileStr);
		fileData.push_back(fileStr);
	}

	for (string s : fileData)
	{
		os << s << " ";
	}


	return 0;
}