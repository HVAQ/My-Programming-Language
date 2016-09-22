#include <stdio.h>
#include <string.h>
#define SIZE 81
void get_input(char *);
int main(void)
{
	char str[SIZE];

	puts("请输入一个字符串");
	while(*gets(str)){
		get_input(str);
		puts("请重新输入一个字符串");
	}
	puts("Done!");

	return 0;
}
void get_input(char *s1)
{
	int m;
	int n = strlen(s1) + 1;
	int x;
	char s2[n];

	for (m =0, x = strlen(s1) - 1; m < n; m++, x--)
		s2[m] = s1[x];
	s2[n] = '\0';
	puts(s2);
}
