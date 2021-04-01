#include "std_lib_facilities.h"

class Name_pairs
{
public:
	Name_pairs() {};
	~Name_pairs() {};
	void read_names(string);
	void read_ages(int);
	void const print();
	void name_sort();
private:
	vector<string> name;
	vector<double> age;
};

void Name_pairs::read_names(string s)
{
	for (size_t i = 0; i < name.size(); i++)
		if (name[i] == s)
			simple_error("���� �̸��� �ֽ��ϴ�.");
		
	name.push_back(s);
}
void Name_pairs::read_ages(int n)
{
	if (n < 0) 
		simple_error("���̴� ������ �ɼ� �����ϴ�.");

	age.push_back(n);
}

void const Name_pairs::print()
{
	if (name.size() != age.size())
		simple_error("�̸��� ������ ���� ��ġ ���� �ʽ��ϴ�.");

	for (size_t i = 0; i < name.size(); i++)
		cout << name[i] << " : " << age[i]<<"��"<< "\n";
}

void Name_pairs::name_sort()
{
	vector<string> temp = name;
	vector<double> temp2 = age;
	sort(name);

	for (size_t i = 0; i < name.size(); i++)
	{
		for (size_t j = 0; j < temp.size(); j++)
		{
			if (name[i] == temp[j])
			{
				age[i] = temp2[j];
			}
		}
	}
}



void operator <<(ostream& os, Name_pairs& const n)
{
	return n.print();
}

void input(Name_pairs& name_pair)
{
	string name;
	int age;

	cout << "�̸��� ���̸� �Է����ּ���\n";
	while (cin >> name >> age)
	{
		name_pair.read_names(name);
		name_pair.read_ages(age);
	}
}


int main()
{
	Name_pairs name_pair;	
	input(name_pair);

	name_pair.name_sort();

	cout << name_pair;

	return 0;
}