/**
 * 通过程序输出
 * 可基本分析
 * 迭代器的比较
 * 比较的是迭代器指向容器中位置
 * 而不是对该位置的值进行比较
 */
#include <iostream>
#include <string>
#include <vector>

int main ()
{
	using namespace std;

	string ch("hello");
	vector<string> str(2, ch);
	vector<string>::iterator one, two;
	
	one = str.begin();
	two = one + 1;

	if (one == two)
		cout << *one << " = " << *two << endl;
	else
		cout << *one << " != " << *two << endl;

	return 0;
}
