#include "std_lib_facilities.h"

struct point
{
	double x, y;
};



istream& operator >>(istream& is, point& p)
{

	char ch1;
	
	if (is >> ch1 && ch1 != '(')
	{
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}

	char ch2;
	char comma;
	double x,y;

	is >> x >> comma >> y >> ch2;
	if (!is || ch2 != ')' || comma != ',')
		is.clear(ios_base::failbit);
	
	p.x = x;
	p.y = y;

	return is;
}

ostream& operator <<(ostream& os, point& p)
{
	return os << '(' << p.x << ',' << p.y << ')';
}


//함수로 만들어야 유효 범위를 벗어나면서 버퍼를 flush 함
int main()
{
	string file_name = "mydata.txt";

	ofstream ost(file_name);
	if (!ost) error("출력 파일을 열 수 없음");

	ifstream ist(file_name);
	if (!ist) error("입력 파일을 열 수 없음");


	vector<point> original_points;
	vector<point> processed_points;
	point input;



	cout << "(x,y) 형식의 point 값을 입력해주세요.\n";
	for (int i = 0; i < 2; i++)
	{
		cout << "input : ";
		cin >> input;
		original_points.push_back(input);
		cout << "\n";
	}


	for (point p : original_points)
	{
		ost << p ;
	}
	ost.close();
	point p;
	while (ist >> p)
	{
		processed_points.push_back(p);
	}

	cout << "original_points:";
	for (point p : original_points)
	{
		cout << p;
	}

	cout << "\nprocessed_points:";
	for (point p : processed_points)
	{
		cout << p;
	}


	return 0;
}