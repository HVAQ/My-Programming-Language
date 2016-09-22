#include <stdio.h>
#include <stdlib.h>

void get_info (char *, char *);
int tonum (char *);
char * itobs (int, char *);

int main (int argc, char ** argv)
{
	int m, n;
	char bstr[8 * sizeof (int) + 1];

	if (argc != 3)
	{
		printf ("请输入参数如%s [二进制码] [二进制码].\n", argv[0]);
		exit (EXIT_FAILURE);
	}
	get_info (argv[1], argv[2]);
	if (argv[1][0] != '\0' && argv[2][0] != '\0')
	{
		m = tonum(argv[1]);
		n = tonum(argv[2]);
		printf ("%s按位取反后的值为%s.\n", argv[1], itobs(~m, bstr)); 
		printf ("%s按位取反后的值为%s.\n", argv[2], itobs(~n, bstr));
		printf ("%s与%s经位于运算符运算后为%d.\n", argv[1], argv[2], m & n);
		printf ("%s与%s经位或运算符运算后为%d.\n", argv[1], argv[2], m | n);
		printf ("%s与%s经位异或运算符运算后为%d.\n", argv[1], argv[2], m ^ n);
	}

	return 0;
}

char * itobs (int n, char * ps)
{
	int i;
	static int size = 8 * sizeof(int);

	for (i = size - 1; i >= 0; i--, n >>= 1)
		ps[i] = (01 & n) + '0';
	ps[size] = '\0';

	return ps;
}
int tonum (char *argv)
{
	unsigned int val = 0;

	while (*argv != '\0')
		val = 2 * val + (*argv++ - '0');

	return val;
}
void get_info (char * str1, char * str2)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if ((*str1 != '1' && *str1 != '0') || (*str2 != '1' && *str2 != '0'))
		{
			printf ("二进制数只能由0和1组成.\n");
			exit (EXIT_FAILURE);
		}
		else
		{
			str1++;
			str2++;
		}
	}
}
