#include <iostream>
#include <vector>

int main ()
{
	using namespace std;

	vector<int> num;
	vector<int>::iterator ix, iy;
	int num_one, sum;
	vector<int>::size_type size;

	cout << "Please enter some int." << endl;
	while (cin >> num_one)
		num.push_back(num_one);
	size = num.size();
	if (size != 0)
	{
		for (ix = num.begin(), iy = (ix + size - 1); ix < iy; ++ix, --iy)
		{
			sum = *ix + *iy;
			cout << *ix << " + " << *iy << " = " << sum << endl;
		}
	}
	if (size < 2)
		cout << "The int is too little." << endl;
	else if (size % 2 != 0)
		cout << "The int " << *ix << " doesn't be used." << endl;

	return 0;
}
