#include <iostream>
#include <vector>
#include <string>
#include <cctype>

int main ()
{
	using namespace std;

	string str;
	vector<string> v1;
	int index (0);

	cout << "Please enter a string." << endl;
	while (cin >> str)
		v1.push_back(str);
	for (vector<string>::iterator ix = v1.begin(); ix != v1.end(); ++ix, ++index)
	{
		for (string::size_type iy = 0; iy != str.size(); ++iy)
			(*ix)[iy] = toupper((*ix)[iy]);
		cout << *ix;
		if (index % 8 == 7)
			cout << endl;
		else
			cout << ' ';
	}
	if (index % 8 != 0)
		cout << endl;

	return 0;
}
