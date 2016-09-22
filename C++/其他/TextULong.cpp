#include <iostream>
#include <string>

int main ()
{
	using namespace std;

	string str ("10010");
	bitset<5> bit(str);
	unsigned long ulong = bit.to_ulong();

	cout << "bit is " << ulong << "." << endl;

	return 0;
}
