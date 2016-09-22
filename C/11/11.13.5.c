#include <stdio.h>
#include <string.h>
#define MAX 81
int is_within(char, char *);
int main(void)
{
	char ch;
	char str[MAX];

	puts("请输入一个字符");
	while ((ch = getchar()) != EOF){
		while(getchar() != '\n')
			continue;
		puts("请输入一个字符串");
		fgets(str, MAX, stdin);
		if (is_within(ch, str) == 0)
			puts("字符不在字符串中\n");
		else
			puts("字符在字符串中\n");
		puts("请输入一个字符");
	}

	return 0;
}
int is_within(char ch, char *str)
{
	int i, n;

	n = strlen(str);
	for (i = 0; i < n; i++)
		if (ch == str[i])
			break;
	if (i == n)
		return 0;
	else
		return i+1;
}
