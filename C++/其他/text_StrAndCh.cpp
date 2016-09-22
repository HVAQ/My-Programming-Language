/**
 * 通过输出
 * ch_hello = 6;
 * st_hello = 24;
 * st.size = 5;
 * 可基本得出:
 * 在2015版MacBook pro
 * (系统为mac os x 10.11.6)中
 * 数组存储字符串方式与string类类型存储字符串方式不同
 * (可能是string存储所占空间更大)
 * 可以论证的一点是字符串字面值与string类类型不同
 */
#include <iostream>
#include <string.h>

int main ()
{
	using std::cout;
	using std::string;
	using std::endl;

	char ch[] = "hello";
	string st = "hello";

	cout << "ch_hello = " << sizeof (ch) << endl;
	cout << "hello = " << sizeof ("hello") << endl;
	cout << "st_hello = " << sizeof (st) << endl;
	cout << "st.size() = " << st.size() << endl;

	return 0;
}
