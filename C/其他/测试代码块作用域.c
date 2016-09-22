#include <stdio.h>
int main (void)
{
	int m = 0;
	int i = 15;

	while (m < 11){
		int p = m;
		m++;
		printf("p = %d\n", p);
	}
	for (int i = 0; i < 11; i++)
		printf("i = %d\n", i);
	printf("now i = %d\n", i);

	return 0;
}
