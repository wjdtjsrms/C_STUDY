#include"std_lib_facilities.h"

int main()
{
	int number_of_words = 0;
	string pervious = " ";
	string current;

	while (cin >> current)
	{
		++number_of_words;
		if (pervious == current)
		{
			cout <<"단어 번호 "<< number_of_words << "\n"
				 << "반복된 단어 " << current << "\n";
		}
		pervious = current;
	}

	return 0;
}