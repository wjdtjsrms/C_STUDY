#include "std_lib_facilities.h"

enum class Genre
{
	fiction = 1, nonfiction, periodical,biography,children
};

///////////////////////////
//////////Book/////////////
///////////////////////////

class Book
{
public:
	Book() {}
	Book(string,string,string,bool,Genre);
	~Book() {}

	string const getISBN() { return isbn; }
	string const getTitle() { return title; }
	string const getWriter() { return writer; }
	Genre getGenre() { return genre; }
	bool const getOut() { return out; }
	void const bookOut() { out = true; }
	void const bookIn() { out = false; }

private:
	string isbn;
	string title;
	string writer;
	bool out;
	Genre genre;;

};

void setIsbn(string& isbn)
{
	istringstream ss(isbn);
	string stringBuffer;
	vector<string> x;
	x.clear();
	
	while (getline(ss, stringBuffer, '-'))
	{
		x.push_back(stringBuffer);
	}
	
	for (int i = 0; i < 3; i++)
	{
		if (atoi(x[i].data()) == 0)
		{
			simple_error("ISBN 형식 오류");
		}
	}

}


Book::Book(string isbn, string title, string writer, bool out , Genre genre)
	: isbn(isbn), title(title), writer(writer), out(out), genre(genre)
{
	setIsbn(isbn);
}

// book class help code

bool operator == (Book& a, Book&  b)
{
	return a.getISBN() == b.getISBN();
}
bool operator != (Book&  a, Book&  b)
{
	return a.getISBN() != b.getISBN();
}
ostream& operator << (ostream& os, Book& b)
{
	return os << "제목: " << b.getTitle() << "\n"
	<< "저자: " << b.getWriter() << "\n"
	<< "ISBN: " << b.getISBN() << "\n";
} 

///////////////////////////
/////////Patron////////////
///////////////////////////

class Patron
{
public:
	Patron() {}
	Patron(string,int,int);
	~Patron() {};
	string getUsrName() { return usr_name; }
	int getUsrNumber() { return usr_number; }
	int getUsrDebt() { return usr_debt; }
private:
	string usr_name;
	int usr_number;
	int usr_debt = -1;
};

Patron::Patron(string name,int number,int debt)
	:usr_name(name),usr_number(number),usr_debt(debt)
{}

// Patron class help code

bool getPatronDebt(Patron& patron)
{
	if (patron.getUsrDebt() == -1)
		return false;
	else
		return true;
	
}

///////////////////////////
/////////Library///////////
///////////////////////////


class Library
{
public:
	Library() {}
	~Library() {}
	void addBook(string, string, string, bool, Genre);
	void addPatron(string, int, int);
	void Borrow(string,string);
	vector<string> debtUsr();


private:
	struct Transaction
	{
		Book b;
		Patron p;
	};
private:
	vector<Book> library_Book;
	vector<Patron> library_Patron;
	vector<Transaction> library_Transaction;
};

void Library::addBook(string isbn, string title, string writer, bool out, Genre genre)
{
	Book newbook(isbn,title,writer,out, genre);
	library_Book.push_back(newbook);
}

void Library::addPatron(string name, int number, int debt= -1)
{
	Patron newPatron(name,number,debt);
	library_Patron.push_back(newPatron);
}

bool findBook(vector<Book>& b, string title,int& index)
{
	for (size_t i = 0; i < b.size(); i++)
	{
		if (title == b[i].getTitle())
		{
			index = i;
			return true;
		}
			
	}
	return false;

}
bool findName(vector<Patron>& p, string name, int& index)
{
	for (size_t i = 0; i < p.size(); i++)
	{
		if (name == p[i].getUsrName())
		{
			index = i;
			return true;
		}
			
	}
	return false;
}


void Library::Borrow(string name, string title)
{
	int index = 0;
	Transaction newTransaction;

	if (!findName(library_Patron, name,index))
	{
		cout<< name <<" 사용자를 찾지 못했습니다.\n";
		return;
	}

	// 대출자 연체료 확인
	if (library_Patron[index].getUsrDebt() != -1)
	{
		cout << library_Patron[index].getUsrDebt()<<"원 만큼의 연체료가 있습니다.\n";
		return;
	}

	// 대출자 정보 대입
	newTransaction.p = library_Patron[index];

	if (!findBook(library_Book, title, index))
	{
		cout<< title << " 책을 찾지 못했습니다.\n";
		return;
	}

	// 대출 되는 책 정보 대입
	newTransaction.b = library_Book[index];

	// 대출 정보 생성
	library_Transaction.push_back(newTransaction);

	cout << newTransaction.b.getTitle() << " 책을 " << newTransaction.p.getUsrName() << " 사용자께서 빌려갑니다.\n";
}

vector<string> Library::debtUsr()
{
	vector<string> debtusr;

	for (size_t i = 0; i < library_Patron.size(); i++)
	{
		if (library_Patron[i].getUsrDebt() != -1)
		{
			debtusr.push_back(library_Patron[i].getUsrName());
		}
	}
	return debtusr;
}

void printDebtUsr(Library& library)
{
	vector<string> debtusr = library.debtUsr();

	cout << "연체료 멤버: ";
	for (size_t i = 0; i < debtusr.size(); i++)
	{
		cout << debtusr[i] << " ";
	}
	cout << "\n";
}



int main()
{
	Library library;

	library.addBook("1234-567-8910-test", "title", "writer", false, Genre::fiction);
	library.addBook("4321-756-1098-test2", "title2", "writer2", false, Genre::nonfiction);
	library.addBook("1111-2222-3333-test3", "title3", "writer3", false, Genre::children);

	library.addPatron("wjdtjsrms", 12);
	library.addPatron("tjsrms", 25,5000);
	library.addPatron("dyddnr", 52,6000);
	
	library.Borrow("wjdtjsrms", "title2");
	printDebtUsr(library);

	return 0;
}