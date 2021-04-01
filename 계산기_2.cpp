#include "std_lib_facilities.h"

//------------------------------------------------------------------------------
const char number = '8';
const char quit = 'q';
const char print = ';';
const string prompt = "> ";
const string result = "= ";
const char name = 'a';
const char let = 'L';
const string declkey = "let";


//------------------------------------------------------------------------------

class Token {
public:
	char kind;        // what kind of token
	double value;     // for numbers: a value 
	string name;
	Token(char ch)    // make a Token from a char
		:kind(ch), value(0) { }
	Token(char ch, double val)     // make a Token from a char and a double
		:kind(ch), value(val) { }
	Token(char ch, string n)     // make a Token from a char and a double
		:kind(ch), name(n) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public:
	Token_stream();   // make a Token_stream that reads from cin
	Token get();      // get a Token (get() is defined elsewhere)
	void putback(Token t);    // put a Token back
	void ignore(char c);
private:
	bool full;        // is there a Token in the buffer?
	Token buffer;     // here is where we keep a Token put back using putback()
};
Token_stream ts;
//------------------------------------------------------------------------------
// 변수용 클래스
class Variable
{
public:
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
	
};
vector <Variable> var_table;
//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
	:full(false), buffer(0)    // no Token in buffer
{
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
	if (full) error("putback() into a full buffer");
	buffer = t;       // copy t to buffer
	full = true;      // buffer is now full
}

//------------------------------------------------------------------------------
void Token_stream::ignore(char c)
{
	if (full && (c == buffer.kind))
	{
		full = false;
		return;
	}

	full = false;

	//찾을때 까지 버퍼를 읽는다.
	char ch = 0;
	while (cin >> ch)
		if (ch == c) return;
}


//------------------------------------------------------------------------------



Token Token_stream::get()
{
	if (full) {       // do we already have a Token ready?
					  // remove token from buffer
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

	switch (ch) {
	case print:  
	case quit:  
	case '(': 
	case ')': 
	case '{': 
	case '}': 
	case '+': 
	case '-': 
	case '*': 
	case '/': 
	case '!': 
	case '%':
	case '=':
		return Token(ch);        
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(ch);         // put digit back into the input stream
		double val;
		cin >> val;              // read a floating-point number
		return Token(number, val);   // let '8' represent "a number"
	}
	default:
		if (isalpha(ch))
		{
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch)  || ch =='_')) s += ch;
			cin.putback(ch);
			if (s == declkey) return Token(let);
			return Token(name, s);
		}
		error("잘못된 토큰");
	}
}

//------------------------------------------------------------------------------
double get_value(string s)
{
	for (const Variable& v : var_table)
		if (v.name == s) return v.value;

	error("get: 정의 되지 않은 변수", s);
	
}

void set_value(string s, double d)
{
	for (Variable& v : var_table)
	{
		if (v.name == s)
		{
			v.value = d;
			return;
		}
	}
	error("set: 정의 되지 않은 변수", s);
}

// var가 var_table 에 이미 있는지 확인
bool is_declared(string var)
{
	for (const Variable& v : var_table)
	{
		if (v.name == var)
			return true;
	}
	return false;
}

double define_name(string var, double val)
{
	if (is_declared(var))
	{
		error(var,"가 재정의됨");
	}
	Variable temp(var, val);
	var_table.push_back(temp);
	return val;
}

//------------------------------------------------------------------------------

double expression(); // declaration so that primary() can call expression()

//------------------------------------------------------------------------------



double declaration()
{
	Token t = ts.get();
	if (t.kind != name) error("선언에는 이름이 필요함");
	string var_name = t.name;

	Token t2 = ts.get();
	if (t2.kind != '=') error("선언에서 =가 빠짐", var_name);

	double d = expression();
	define_name(var_name, d);
	return d;
}




double statement()
{
	Token t = ts.get();
	switch (t.kind)
	{
	case let:
		return declaration();

	default:
		ts.putback(t);
		return expression();
	}

}



double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':    // handle '(' expression ')'
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return d;
	}
	case '{':    // handle '{' expression '}'
	{
		double d = expression();
		t = ts.get();
		if (t.kind != '}') error("'}' expected");
		return d;
	}
	case number:            // we use '8' to represent a number
		return t.value;  // return the number's value
	case name:
		return get_value(t.name);
	case '-':
		return -primary();
	case '+':
		return primary();

	default:
		error("primary가 나와야 합니다.");
	}
}

double factorial()
{
	double left = primary();
	Token t = ts.get();
	switch (t.kind) {
	case '!':
	{
		int x = 1;

		if (left == 0)
			return 1;
		for (int i = 1; i <= left; i++)
			x *= i;

		return x;
	}

	default:
		ts.putback(t);
		return left;
	}
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
	double left = factorial();
	Token t = ts.get();        // get the next token from token stream

	while (true) {
		switch (t.kind) {
		case '*':
			left *= factorial();
			t = ts.get();
			break;
		case '/':
		{
			double d = factorial();
			if (d == 0) error("divide by zero");
			left /= d;
			t = ts.get();
			break;
		}
		case '%':
		{
			int i1 = narrow_cast<int>(left);
			int i2 = narrow_cast<int>(factorial());
			if (i2 == 0)error("영으로 나누자마라");
			left = i1 % i2;
			t = ts.get();
			break;
		}
		default:
			ts.putback(t);     // put t back into the token stream
			return left;
		}
	}
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
	double left = term();      // read and evaluate a Term
	Token t = ts.get();        // get the next token from token stream

	while (true) {
		switch (t.kind) {
		case '+':
			left += term();    // evaluate Term and add
			t = ts.get();
			break;
		case '-':
			left -= term();    // evaluate Term and subtract
			t = ts.get();
			break;
		default:
			ts.putback(t);     // put t back into the token stream
			return left;       // finally: no more + or -: return the answer
		}
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}


void calculate()
{
	while (cin) {
		try {
			cout << prompt;
			Token t = ts.get();
			while (t.kind == print)
			{
				t = ts.get();
			}
			if (t.kind == quit)
			{
				return;
			}
			ts.putback(t);
			cout << result << statement() << "\n";
		}
		catch (exception& e)
		{
			cerr << e.what() << "\n";
			clean_up_mess();
		}
		
	}
}

void define_names()
{
	define_name("pi", 3.1415926535);
	define_name("e", 2.7182818284);
}


//------------------------------------------------------------------------------
int main()
try
{
	define_names();
	calculate();

	keep_window_open();
	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open("~~");
	return 1;
}
catch (...) {
	cerr << "Oops: unknown exception!\n";
	keep_window_open("~~");
	return 2;
}
//------------------------------------------------------------------------------