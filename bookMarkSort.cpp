#include "std_lib_facilities.h"

struct bookMarkData
{
	string link;
	string addDate;
	string icon;
	string name;
};

bool compare(const bookMarkData& b1, const bookMarkData& b2 )
{
	int b = b1.name.compare(b2.name);
	
	if (b >= 0)
	{
		return false;
	}
	return true;
}


class BookMark
{
public:
	BookMark();
	~BookMark();
	void addBookMark(string& str) { strData.push_back(str); };
	void getString();
	void divideLine(bookMarkData&, const string&);
	void printDivStr(ofstream&);

private:
	vector<string> strData;
	vector<bookMarkData> bookData;
};


void BookMark::printDivStr(ofstream& os)
{
	sort(bookData.begin(), bookData.end(), compare);

	for (size_t i = 0; i < bookData.size(); ++i)
	{
		cout << bookData[i].name << endl;
		if (bookData[i].icon == "")
		{
			os << "            <DT><A HREF=\"" << bookData[i].link << "\" " << " ADD_DATE=\"" << bookData[i].addDate << "\">" << bookData[i].name << "</A>"<<"\n";
		}
		else
		{
			os << "            <DT><A HREF=\"" << bookData[i].link << "\" " << " ADD_DATE=\"" << bookData[i].addDate << "\" ICON=\"" << bookData[i].icon << "\">" << bookData[i].name << "</A>" << "\n";;
		}
		
	}
}

void BookMark::getString()
{
	bookMarkData temp;
	bookData.assign(strData.size(),temp);
	for (size_t i = 0; i < strData.size(); ++i)
	{
		divideLine(bookData[i], strData[i]);
	}
}

void BookMark::divideLine(bookMarkData& data, const string& str)
{
	const char * c = str.c_str();
	vector<int> index;
	for(size_t i = 0; i < str.size(); ++i)
	{
		if (c[i] == 34)
		{
			index.push_back(i);
		}
	}
	if (index.size() > 4)
	{
		index.push_back(index[5]+1);
		index.push_back(str.find("</A>"));
		
		data.link = str.substr(index[0]+1, index[1]- index[0]-1);
		data.addDate = str.substr(index[2]+1, index[3]- index[2]-1);
		data.icon = str.substr(index[4]+1, index[5]- index[4]-1);
		data.name = str.substr(index[6] + 1, index[7] - index[6] - 1);
	}
	else
	{
		index.push_back(index[3] + 1);
		index.push_back(str.find("</A>"));

		data.link = str.substr(index[0]+1, index[1]- index[0]-1);
		data.addDate = str.substr(index[2]+1, index[3]- index[2]-1);
		data.name = str.substr(index[4] + 1, index[5] - index[4] - 1);
	}
}

BookMark::BookMark()
{
}

BookMark::~BookMark()
{
}


int main()
{
	string fileName = "bookmarks.txt";
	string fileName2 = "sortbookmarks.txt";
	ifstream is(fileName);
	ofstream os(fileName2);
	if (!is) error("입력 파일을 열 수 없습니다");
	if (!os) error("입력 파일을 열 수 없습니다");


	BookMark bookmark;

	int index = 0;
	bool on = false;

	string getStr;
	while (getline(is, getStr))
	{
		if (getStr == "        </DL><p>")
		{
			on = false;
		}
		if (on)
		{
			bookmark.addBookMark(getStr);
		}
		if (getStr == "        <DL><p>")
		{
			++index;
			on = true;
		}
	}
	bookmark.getString();
	bookmark.printDivStr(os);
	return 0;
}