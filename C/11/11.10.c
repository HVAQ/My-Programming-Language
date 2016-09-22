#include <stdio.h>
void put1(const char *string);

int main(void)
{
	char string[] = "hello world";

	printf("%s\n",string);
	put1(string);

	return 0;
}
void put1(const char *string)
{
	while(*string)
		putchar(*string++);
}
