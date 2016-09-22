/**
 * 不能对迭代器的end()进行增量操作
 * 因为会使其指向一个无任何元素(无效)的位置
 * 故而这一操作是非法的
 */
#include <iostream>
#include <vector>
#include <string>

int main ()
{
	using namespace std;

	string str ("hello world");
	vector<string> v1 (5, str);
	vector<string>::iterator mid = v1.begin() + v1.end() / 2;

	cout << *mid << endl;

	return 0;
}
