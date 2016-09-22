#include <iostream>
#include <cctype>

int main ()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::string;

	string st;

	cout << "Please enter the string." << endl;
	while (cin >> st)
	{
		for (string::size_type ix = 0; ix != st.size(); ix++)
			if (!ispunct(st[ix]))
				cout << st[ix];
			cout << " ";
	}
	cout << endl;

	return 0;
}
