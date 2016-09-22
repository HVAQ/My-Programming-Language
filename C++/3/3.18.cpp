#include <iostream>
#include <vector>

int main ()
{
	using namespace std;

	int num (3);
	vector<int> v1 (10, num);

	for (vector<int>::iterator iter = v1.begin(); iter != v1.end(); ++iter)
	{
		*iter = *iter * 2;
		cout << *iter << ' ';
	}
	cout << endl;

	return 0;
}
