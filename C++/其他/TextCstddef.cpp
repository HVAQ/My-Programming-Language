#include <iostream>
#include <string>
#include <cstddef>

int main ()
{
	using namespace std;
	string str ("10010");
	bitset<5> bit(str);
	size_t count = bit.count();

	cout << "bit中有 " << count << " 个位为1." << endl;

	return 0;
}
