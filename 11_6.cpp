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

int main()
{
	Punct_stream ps{ cin };
	ps.whitespace(".;,?-'");
	ps.case_sensitive(true);
	// "- don't use the as-if rule."
	vector<string> vs;
	for (string word; ps >> word;)
	{
		vs.push_back(word);
	}

	for (string word : vs)
	{
		cout << word << " ";
	}



	return 0;
}