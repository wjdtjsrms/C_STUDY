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
			cout <<"�ܾ� ��ȣ "<< number_of_words << "\n"
				 << "�ݺ��� �ܾ� " << current << "\n";
		}
		pervious = current;
	}

	return 0;
}