/**
 * 测试vector是否能对数组赋值
 * 通过编译
 * 数组初始化必须为一个初始化列表
 * vector初始化不能为一个列表
 * 可以得出
 * 不能将vector赋值给数组
 */
#include <iostream>
#include <vector>

int main ()
{
	using namespace std;

	vector<int> v1(3, 6);
	int ia[] = {6, 6, 6};

	for (vector<int>::size_type index = 0; index != v1.size(); ++index)
		cout << ia[index] << ' ';
	cout << endl;

	return 0;
}
