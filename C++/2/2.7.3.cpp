#include <iostream>
using namespace std;

void cout_one(void);
void cout_two(void);

int main(void)
{
	cout_one();
	cout_one();
	cout_two();
	cout_two();

	return 0;
}

void cout_one(void)
{
	cout << "Three blind mice" << endl;
}

void cout_two(void)
{
	cout << "See how they run" << endl;
}
