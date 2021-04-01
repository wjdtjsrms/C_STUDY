#include "std_lib_facilities.h"


istream& operator >> (istream& is, vector<int>& temperature)
{
	char ch1;

	if (is >> ch1 && ch1 != '(')
	{
		is.unget();
		is.clear(ios_base::badbit);
		return is;
	}

	int data;
	int temp;
	char comma1, comma2;
	char ch2;

	is >> data >> comma1 >> data >> comma2 >> temp >> ch2;

	if (!is || comma1 != ',' || comma2 != ',' || ch2 != ')')
	{
		is.clear(ios_base::failbit);
	}

	// ���� �� ���� �µ�
	if (temp < -999 || 999 < temp)
	{
		is.clear(ios_base::failbit);
		return is;
	}

	temperature.push_back(temp);
	return is;
}




int main()
{
	string filename = "raw_temps.txt";
	ifstream ifs(filename);
	vector<int> temperature;
	int total = 0, median = 0;

	while (true)
	{
		if (!(ifs >> temperature)) break;
	}

	// ������ �� Ȯ��
	cout <<"�Է¹��� ��" << "\n";
	for (int i : temperature)
	{
		cout << i << " ";
	}
	cout << "\n";

	// ��հ� ���ϱ�
	for (int i : temperature)
	{
		total += i;
	}
	total /= temperature.size();

	// �߾Ӱ� ���ϱ�
	sort(temperature);


	cout << "��հ� : " << total << "\n";
	cout << "�߾Ӱ� : " << temperature[temperature.size()/2] << "\n";

	return 0;
}