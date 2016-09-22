// 测试string操作符
#include <iostream>
#include <string>

int main ()
{
	using std::string;
	using std::cout;
	using std::endl;

	string s1 ("zhong");
	string s2 ("zhongguo");

	if (s1 > s2)
		cout << "zhong > zhongguo" << endl;
	else
		cout << "zhong < zhongguo" << endl;

	return 0;
}
