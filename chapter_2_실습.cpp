
#include"std_lib_facilities.h"


int main()
{
	string name ,f_name;
	char f_sex = 'x';
	int age = -1;


	cout << "���� ���� ����� �̸��� �Է��ϼ���.\n";
	cin >> name;
	cout << "���� ���� ����� ���̸� �Է��ϼ���.\n";
	cin >> age;
	if (age <= 0 || age >= 100)
	{
		simple_error("�峭ġ�� ������!");
	}
	cout << "�ٸ� ģ���� �̸��� �Է����ּ���.\n";
	cin >> f_name;
	cout << "ģ���� ������ �Է����ּ���. (���� : m  / ���� : f)\n";
	cin >> f_sex;

	cout << "ģ���ϴ� " << name << ","<<"\n";
	cout << "������ ���� �߿������ϴ�. �� ��������? ����ͳ׿�." <<'\n';
	cout << "���� " << f_name << "�� ���� �� �����Ű���?" << "\n";
	if (f_sex == 'm')
	{
		cout << f_name << "���� ���ðŵ� �׿��� ������ ��ȭ�ش޶�� �����ּ���.\n";
	}
	else if (f_sex == 'f')
	{
		cout << f_name << "���� ���ðŵ� �׳࿡�� ������ ��ȭ�ش޶�� �����ּ���.\n";
	}
	else
	{
		cout << f_name << "���� ���ðŵ� ������ ��ȭ�ش޶�� �����ּ���.\n";
	}

	if (age == 17)
	{
		cout << "���⿡�� ��ǥ�� �� �� �ְڳ׿�.\n";
	}
	else if (70 < age)
	{
		cout << "�����ĸ� �� ���� �������?\n";
	}
	else if (age < 12)
	{
		cout << "���⿡�� " << age+1 <<"���� �ǰڳ׿�.\n";
	}
	else
	{

	}
	cout << "����� ģ��, ������.\n\n";

	keep_window_open();
	return 0;
}

