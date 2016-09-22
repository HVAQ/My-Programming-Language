#include <stdio.h>
int main (int argc, char **argv)
{
	int m;

	for (m = argc - 1; m > 0; m--)
		printf("%s ",argv[m]);
	putchar('\n');

	return 0;
}
