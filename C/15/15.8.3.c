#include <stdio.h>

int get_info (int);

int main (void)
{
	int num;
	int open;

	puts ("请输入一个整数.");
	while (scanf ("%d", &num) != 1)
	{
		while (getchar() != '\n')
			continue;
		puts ("请输入一个整数.");
	}
	open = get_info(num);
	printf ("%d中打开的位共有%d位.\n", num, open);

	return 0;
}

int get_info (int num)
{
	int i;
	int count = 0;
	static int size = 8 * sizeof(int);

	for (i = size - 1; i >= 0; i--, num >>= 1)
		if ((01 & num) == 1)
			++count;

	return count;
}
