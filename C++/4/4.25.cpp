/**
 * 比较两个string类型字符串
 */
#include <iostream>
#include <string>

int main ()
{
	using namespace std;
	string str1("hello"), str2("hello2"), str3("hello");

	if (str1 == str2)
		cout << str1 << " = " << str2 << endl;
	else if (str1 > str2)
		cout << str1 << " > " << str2 << endl;
	else
		cout << str1 << " > " << str2 << endl;

	if (str1 == str3)
		cout << "string 类型比较的是字符串的实际值." << endl;
	else
		cout << "string 类型比较的是字符串所在的地址." << endl;

	return 0;
}
/**
 * 通过输出明确
 * hello > hello2
 * string 类型比较的是字符串的实际值
 * 可以初步推测的是
 * 当str1为zello，hello0等是
 * 输出依旧为str1 > str2
 * 可以初步推测
 * string类型比较不是按照字符的ascii码进行比较
 */
