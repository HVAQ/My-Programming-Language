#include <stdio.h>
#include <ctype.h>
#define MAX 81
char * getwords(char *);
int main(void)
{
	char str[MAX];

	while (getwords(str) != NULL)
		puts(str);
	puts("Done!");

	return 0;
}
char * getwords(char *str)
{
	char ch;

	while ((ch = getchar()) != EOF && !isspace(ch))
		*str++ = ch;
	*str = '\0';
	if (ch == EOF)
		return NULL;
	else{
		while(ch != '\n')
			ch = getchar();
		return str;
	}
}
