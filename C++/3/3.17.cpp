#include <iostream>
#include <vector>

int main ()
{
	using namespace std;

	int num_one, sum;
	vector<int> num;
	vector<int>::iterator ix;

	cout << "Please enter some int." << endl;
	while (cin >> num_one)
		num.push_back(num_one);
	for (ix = num.begin(); ix + 1 < num.end(); ix += 2)
	{
		sum = *ix + *(ix + 1);
		cout << *ix << " + " << *(ix + 1) << " = " << sum << endl;
	}
	if (num.size() < 2)
		cout << "The number of int is too little." << endl;
	else if (num.size() % 2 != 0)
		cout << "The last int " << *ix << " doesn't be used." << endl;

	return 0;
}
