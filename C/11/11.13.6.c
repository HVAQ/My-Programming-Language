#include <stdio.h>
#include <string.h>
#define MAX 81
char *str_ncpy(char *,char *,int);
int main(void)
{
	char str1[MAX];
	char str2[MAX];
	int n;

	puts("请输入一个字符串");
	while (*gets(str1)){
		puts("请再输入一个字符串");
		gets(str2);
		puts("请输入要复制的个数");
		while (scanf("%d",&n) != 1)
		{
			while(getchar() != '\n')
				continue;
			puts("请输入一个数字");
		}
		str_ncpy(str1, str2, n);
		puts("复制为");
		puts(str1);
		puts("请重新输入一个字符串");
		getchar();
	}

	return 0;
}
char *str_ncpy(char *s1, char *s2, int n)
{
	int m, i;
	
	m = strlen(s1);
	for (i = 0; i < n; i++)
		s1[m + i] = s2[i];
	s1[m + n] = '\0';

	return s1;
}
