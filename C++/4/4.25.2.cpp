#include <iostream>
#include <cstring>

int main ()
{
	using namespace std;
	char str1[] = "zello";
	char str2[] = "hello2";
	int num;

	if ((num = strcmp(str1, str2)) == 0)
		cout << str1 << " = " << str2 << endl;
	else if (num < 0)
		cout << str1 << " < " << str2 << endl;
	else
		cout << str1 << " > " << str2 << endl;

	return 0;
}
/*
 * 当是str1为hello
 * str2为hello2时
 * 输出结果为hello < hello2
 * 初步推测
 * strcmp函数比较的是字符的ascii码值
 * 当str1变为zello时
 * 输出结果为zello > hello2
 * 证明上述推测正确
 */
