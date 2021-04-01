#include "std_lib_facilities.h"

bool findWord(vector<string>& words , string& findWord)
{
	for (string s : words)
	{
		if (s == findWord)
		{
			return true;
		}
	}

	return false;
}


int main()
{
	// 데이터 초기화
	string fileName = "11_2.txt";
	ifstream is(fileName);
	if (!is) error("입력 파일을 열 수 없습니다");

	int strNum = 1;
	string getStr;

	string find_Word;
	cin >> find_Word;

	while (getline(is, getStr))
	{
		stringstream ss{ getStr };
		vector<string> words;

		for (string s; ss >> s;)
			words.push_back(s);

		if (findWord(words, find_Word))
		{
			cout << strNum <<": "<< getStr << "\n";
		}

		++strNum;
	}

	cout << "\n";
	return 0;
}