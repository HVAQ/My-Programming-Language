/**
 * 测试指针指向超出数组值后的返回情况
 * 即
 * 指针指向位置超出数组初始值后
 * 程序会不会正常停止
 */
#include <iostream>

int main ()
{
	using namespace std;
	const char ca[] = {'h', 'e', 'l', 'l', 'o'};
	const char *cp = ca;

	while (*cp)
	{
		cout << *cp << endl;
		++cp;
	}

	return 0;
}
/**
 * 根据运行情况
 * 程序正常停止
 * 可以判断
 * 指向char类型的指针cp始终指向ca
 * 当cp的增量运算使cp指向的范围超出ca所在范围时
 * 循环便会终止
 * 程序正常退出
 */
