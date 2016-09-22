// Text vector
#include <iostream>
#include <vector>

int main ()
{
	using std::vector;
	using std::endl;
	using std::cout;

	char ch = '*';
	int num(6);
	int size;
	vector<char> v1(8, ch);
	vector<int> v2(3, num);

	if (v1.size() > v2.size())
	{
		size = (v1.size() - v2.size()) / 2;	
		if ((v1.size() - v2.size()) % 2 != 0)
			size--;
	}
	for (vector<char>::size_type ix = 0; ix != v1.size(); ix++)
		cout << v1[ix];
	cout << endl;
	for (int ix = 0; ix <= size; ix++)
		cout << ' ';
	for (vector<int>::size_type ix = 0; ix != v2.size(); ix++)
		cout << v2[ix];
	cout << endl;
	for (vector<char>::size_type ix = 0; ix != v1.size(); ix++)
		cout << v1[ix];
	cout << endl;

	return 0;
}
