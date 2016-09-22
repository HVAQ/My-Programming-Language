#include <iostream>
#include <vector>

int main ()
{
	using std::vector;
	using std::cin;
	using std::cout;
	using std::endl;

	vector<int> num;
	int num_one, sum;

	cout << "Please enter some int." << endl;
	while (cin >> num_one)
		num.push_back(num_one);
	for (vector<int>::size_type ix = 0; ix != num.size() / 2; ++ix)
	{
		sum = num[ix] + num[num.size() - ix - 1];
		cout << num[ix] << " + " << num[num.size() - ix - 1] << " = " << sum << endl;
	}
	if (num.size() < 2)
		cout << "The int is too little." << endl;
	else if (num.size() % 2 != 0)
		cout << "The int " << num[num.size() / 2] << " doesn't be used." << endl;

	return 0;
}
