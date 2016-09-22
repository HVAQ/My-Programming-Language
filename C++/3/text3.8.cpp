#include <iostream>

int main ()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::string;

	string st;

	cout << "Please enter the string." << endl;
	while (cin >> st)
		cout << st << " ";
	cout << endl;

	return 0;
}
