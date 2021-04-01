#include "std_lib_facilities.h"

void divbase(string& input)
{
	int i = 0;
	std::stringstream ssInt;
	ssInt << input;


	if (input[0] == '0' && input[1] == 'x')
	{
		ssInt >> hex >> i;
		cout << input << "\t" << "hexadecimal" <<"\t"<<"converts to " ;
		cout <<  dec << i <<" decimal\n";
	}
	else if (input[0] == '0')
	{
		ssInt >> oct >> i;
		cout << input << "\t" << "octal" << "\t\t" << "converts to ";
		cout << dec << i << " decimal\n";
	}
	else
	{
		ssInt >> dec >> i;
		cout << input << "\t" << "decimal" << "\t\t" << "converts to ";
		cout << dec << i << " decimal\n";
	}
}



int main()
{
	string input;
	while (cin >> input)
	{
		divbase(input);
	}

	




	return 0;
}