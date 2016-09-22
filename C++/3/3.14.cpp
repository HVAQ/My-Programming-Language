#include <iostream>
#include <vector>
#include <string>
#include <cctype>

int main ()
{
	using namespace std;

	string str;
	vector<string> v1;

	cout << "Please enter a string." << endl;
	while (cin >> str)
		v1.push_back(str);
	for (vector<string>::size_type ix = 0; ix != v1.size(); ++ix)
	{
		for (string::size_type iy = 0; iy != str.size(); ++iy)
			v1[ix][iy] = toupper(v1[ix][iy]);
		cout << v1[ix];
		if (ix % 8 == 7)
			cout << endl;
		else
			cout << ' ';
	}
	cout << endl;

	return 0;
}
