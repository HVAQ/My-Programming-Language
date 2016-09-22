#include <stdio.h>

int get_info (int, int);

int main (void)
{
	int m, n;

	puts ("请输入一个整数.");
	while (scanf ("%d", &m) != 1)
	{
		while (getchar() != '\n')
			continue;
		puts ("请输入一个整数.");
	}
	puts ("请输入要查询的位.");
	while (scanf ("%d", &n) != 1 || n < 0)
	{
		while (getchar() != '\n')
			continue;
		puts ("请输入一个不小于0的整数值.");
	}
	printf ("%d的位%d为%d.\n", m, n, get_info(m, n));

	return 0;
}

int get_info (int m, int n)
{
	int i;
	int size = 8 * sizeof(int) - 1;

	for (i = size; i > size - n; i--, m >>= 1);

	return (01 & m);
}
