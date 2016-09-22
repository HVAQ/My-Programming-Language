#include <stdio.h>
#include <stdbool.h>

bool unbnum (char *);
int isnum (char *);

int main (void)
{
	char num[8 * sizeof(int) + 1];

	printf ("请输入一个%lu位的二进制数.\n", 8 * sizeof(int));
	while (gets (num) && num[0] != '\0')
	{
		if (!unbnum(num))
			puts ("二进制数是由1和0组成的数字.");
		else
			printf ("%s是%d.\n", num, isnum (num));
		puts ("请输入下一个二进制数.");
	}
	puts ("Done!");

	return 0;
}

int isnum (char * num)
{
	int val = 0;

	while (*num != '\0')
		val = 2 * val + (*num++ - '0');

	return val;
}
bool unbnum (char * num)
{
	bool valid = true;

	while (valid && *num != '\0')
	{
		if (*num != '0' && *num != '1')
			valid = false;
		++num;
	}

	return valid;
}
