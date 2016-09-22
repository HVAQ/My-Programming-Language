#include <stdio.h>

int main (void)
{
	int ch;
	int n = 0;

	while ((ch = getchar()) != EOF)
	{
		if (ch != ' ')
			putchar(ch);
		else if(n != ' ')
			putchar(ch);
		n = ch;
	}

	return 0;
}
