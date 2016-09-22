#include <iostream>
#include <cstddef>

int main ()
{
	using namespace std;
	size_t count = 0, str_size = 81;
	char str[str_size];

	for (count = 0; count != str_size; ++count)
		cin >> str[count];
	str[count - 1] = '\0';
	
	for (count = 0; str[count]; ++count)
		cout << str[count];
	cout << endl;

	return 0;
}
