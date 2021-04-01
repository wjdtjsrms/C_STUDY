#include "std_lib_facilities.h"

class Punct_stream
{
public:
	Punct_stream(istream& is)
		:source{ is }, sensitive{ true } {}
	~Punct_stream() {};
	void whitespace(const string& s) { white = s; }
	void add_white(char c) { white += c; }
	bool is_whitespace(char c);

	void case_sensitive(bool b) { sensitive = b; }
	bool is_case_sensitive() { return sensitive; }

	Punct_stream& operator >> (string& s);
	operator bool();
	void getString(string& s);

private:
	istream & source;
	istringstream buffer;
	string white;
	bool sensitive;

};

bool Punct_stream::is_whitespace(char c)
{
	for (char w : white)
		if (c == w) return true;
	return false;
}

Punct_stream::operator bool()
{
	return !(source.fail() || source.bad()) && source.good();
}


Punct_stream&  Punct_stream::operator>> (string& s)
{
	while (!(buffer >> s))
	{
		if (buffer.bad() || !source.good()) return *this;
		buffer.clear();

		string line;
		getline(source, line);
		for (char& ch : line)
		{
			if (is_whitespace(ch))
				ch = ' ';
			else if (!sensitive)
				ch = tolower(ch);

			buffer.str(line); //문자열을 스트림에 넣기
		}
	}

	return *this;
}

void Punct_stream::getString(string & s)
{
	vector<string> strVec;

	while (!(buffer >> s))
	{
		if (buffer.bad() || !source.good()) return;
		buffer.clear();

		string line;
		getline(source, line);
		for (char& ch : line)
		{
			if (is_whitespace(ch))
				ch = ' ';
			else if (!sensitive)
				ch = tolower(ch);

			buffer.str(line); //문자열을 스트림에 넣기
		}
	}

	return;
}



vector <string> split(string& s,const string& w)
{
	vector<string> strVec;
	Punct_stream ps { cin };
	ps.whitespace(w);
	ps.case_sensitive(true);
	
	for (string word; ps.operator>>(word);)
	{
		strVec.push_back(word);
	}
	return strVec;
}


int main()
{
	string s = " don't use the as-if Rule .";
	vector<string> strVec;

	strVec = split(s, "-");

	for (string s : strVec)
	{
		cout << s << " ";
	}

	cout << "end\n";
	return 0;
}

