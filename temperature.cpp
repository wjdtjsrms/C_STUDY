#include "std_lib_facilities.h"

constexpr int not_a_reading = -7777;
constexpr int not_a_month = -1;
constexpr int implausible_min = -200;
constexpr int implausible_max = 200;

struct Day
{
	int not_a_day = -1;
	vector<double> hour{ vector<double>(24,not_a_reading) };
};
struct Month
{
	int month{ not_a_month };
	vector<Day> day{ 32 };
};
struct Year
{
	int year;
	vector<Month> month {12};
};

struct Reading
{
	int day;
	int hour;
	double temperature;
};

vector<string> month_tbl = {
	"jan","feb","mar","apr","may","jun",
	"jul","aug","sep","oct","nov","dec"
};

int month_to_int(string s)
{
	for (int i = 0; i < 12; i++)
	{
		if(month_tbl[i] == s)
			return i;
	}
	return -1;
}

string int_to_month(int i)
{
	if (i < 0 || 12 <= i)
		error("�߸��� ���� �ε���");

	return month_tbl[i];
}


bool is_vaild(const Reading& r)
{
	if (r.day < 1 || 31 < r.day) return false;
	if (r.hour < 0 || 23 < r.hour) return false;
	if (r.temperature < implausible_min || implausible_max < r.temperature) return false;
	return true;
}

void end_of_loop(istream& ist, char term, const string& message)
{
	if (ist.fail())
	{
		ist.clear();
		char ch;
		if (ist >> ch && ch == term)
			return; // ������ ����
		error(message);
	}
}


// (3 4 9.7) ������ �µ� ����ġ�� r�� ����
istream& operator >>(istream& is, Reading& r)
{
	char ch1;
	if (is >> ch1 && ch1 != '(')
	{
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}

	char ch2;
	int d;
	int h;
	double t;

	is >> d >> h >> t >> ch2;
	if (!is || ch2 != ')')
		error("�߸��� ����ġ");

	r.day = d;
	r.hour = h;
	r.temperature = t;

	return is;
}

// { month feb ... } ������ �����͸� m�� ����
istream& operator >>(istream& is, Month& m)
{
	char ch1;
	if (is >> ch1 && ch1 != '{')
	{
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}

	string month_maker;
	string mm;
	is >> month_maker >> mm;

	if (!is || month_maker != "month")
		error("���� ������ ���� �κ� ����");
	m.month = month_to_int(mm);

	int duplicates = 0;
	int invalids = 0;

	for (Reading r; is >> r;)
	{
		if (is_vaild(r))
		{
			// �ѹ��̶� ���� ���� �ִٸ�
			if (m.day[r.day].hour[r.hour] != not_a_reading)
				++duplicates;
			m.day[r.day].hour[r.hour] = r.temperature;
			m.day[r.day].not_a_day = 1;
		}
		else
		{
			++invalids;
		}
	}
	
	if (invalids) error("���� �����Ͱ� ��ȿ���� ���� ����ġ ����", invalids);
	if (duplicates) error("���� �����Ͱ� �ߺ��� ����ġ ����", duplicates);
	end_of_loop(is, '}', "���� ������ �� �κ� ����");
	return is;
}

istream& operator >> (istream& is, Year& y)
{
	char ch1;
	is >> ch1;
	if (ch1 != '{')
	{
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}

	string year_maker;
	int yy;
	is >> year_maker >> yy;
	if (!is || year_maker != "year")
		error("���� ������ ���� �κ� ����");
	y.year = yy;
	while (true)
	{
		Month m;
		if (!(is >> m))
			break;
		y.month[m.month] = m;
	}

	end_of_loop(is, '}', "���� ������ �� �κ� ����");
	return is;
}


void print_year(ofstream& ofs, Year& year)
{
	ofs <<"year: "<<year.year <<" ";

	// ���� ǥ��
	for (Month& m : year.month)
	{
		if (m.month != not_a_month)
		{
			ofs << "{ month " << int_to_month(m.month) <<" ";

			// �ϰ� ǥ��
			for (int i = 0; i < m.day.size(); i++)
			{
				if (m.day[i].not_a_day != -1)
				{
					ofs << "( " << i << "�� ";

					// �ð��� �µ� ǥ��
					for (int j = 0; j < m.day[i].hour.size(); j++)
					{
						if (m.day[i].hour[j] != not_a_reading)
						{
							ofs << j << "�� ";
							ofs << m.day[i].hour[j] << "�� ";
						}
					}
					ofs << ")";
				}
			}
			ofs << "}\n";
		}
	}

	ofs << "\n";
}




int main()
{
	string iname = "temperature.txt";
	string iname2 = "temperature2.txt";
	ifstream ist(iname);
	ofstream ofs(iname2);
	if(!ist) error("�Է� ������ �� �� ����");
	if (!ofs) error("��� ������ �� �� ����");

	//ist.exceptions(ist.exceptions() || ios_base::badbit);

	vector <Year> ys;
	while (true)
	{
		Year y;
		if (!(ist >> y)) break;
		ys.push_back(y);
	}

	cout <<"���� ����ġ ����: "<< ys.size() <<"\n";
	for (Year& y : ys)
	{
		print_year(ofs, y);
	}
	return 0;
}