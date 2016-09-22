#include <iostream>
#include <vector>

int main ()
{
	using std::vector;
	using std::cin;
	using std::cout;
	using std::endl;

	int num_one, sum;
	vector<int> num;

	cout << "Please enter some int." << endl;
	while (cin >> num_one)
		num.push_back(num_one);
	for (vector<int>::size_type ix = 0; ix + 1 < num.size(); ix += 2)
	{
		sum = num[ix] + num[ix + 1];
		cout << num[ix] << " + " << num[ix + 1] << " = " << sum << endl;
	}
	if (num.size() < 2)
		cout << "The numbers of int is too little" << endl;
	if (num.size() % 2 != 0)
		cout << "The last int "<< num[num.size() - 1] << " doesn't be used." << endl;

	return 0;
}
