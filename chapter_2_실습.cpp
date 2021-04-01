
#include"std_lib_facilities.h"


int main()
{
	string name ,f_name;
	char f_sex = 'x';
	int age = -1;


	cout << "편지 받을 사람의 이름을 입력하세요.\n";
	cin >> name;
	cout << "편지 받을 사람의 나이를 입력하세요.\n";
	cin >> age;
	if (age <= 0 || age >= 100)
	{
		simple_error("장난치지 마세요!");
	}
	cout << "다른 친구의 이름을 입력해주세요.\n";
	cin >> f_name;
	cout << "친구의 성별을 입력해주세요. (남자 : m  / 여자 : f)\n";
	cin >> f_sex;

	cout << "친애하는 " << name << ","<<"\n";
	cout << "날씨가 많이 추워졌습니다. 잘 지내시죠? 보고싶네요." <<'\n';
	cout << "요즘 " << f_name << "씨 만난 적 있으신가요?" << "\n";
	if (f_sex == 'm')
	{
		cout << f_name << "씨를 보시거든 그에게 저한테 전화해달라고 전해주세요.\n";
	}
	else if (f_sex == 'f')
	{
		cout << f_name << "씨를 보시거든 그녀에게 저한테 전화해달라고 전해주세요.\n";
	}
	else
	{
		cout << f_name << "씨를 보시거든 저한테 전화해달라고 전해주세요.\n";
	}

	if (age == 17)
	{
		cout << "내년에는 투표를 할 수 있겠네요.\n";
	}
	else if (70 < age)
	{
		cout << "은퇴후를 잘 즐기고 계시지요?\n";
	}
	else if (age < 12)
	{
		cout << "내년에는 " << age+1 <<"살이 되겠네요.\n";
	}
	else
	{

	}
	cout << "당신의 친구, 정선근.\n\n";

	keep_window_open();
	return 0;
}

