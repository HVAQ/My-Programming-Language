#include<stdio.h>
#include<ctype.h>
int get_first(void);

int main(void)
{
	int ch;

	ch=get_first();
	putchar(ch);
	printf("\n");
	return 0;
}

int get_first(void)
{
	int ch;

	while(isspace(ch=getchar()))
		continue;
	while((getchar())!='\n')
		continue;
	return ch;
}
