#include <stdio.h>
#include <string.h>
#define MAX 81
char * getput(char *, char);

int main(void)
{
	char str[MAX];
	char ch;
	char *rt;

	do{
		puts("请输入一个字符串");
		gets(str);
		puts("请输入一个字符");
		ch = getchar();
		if ((rt = getput(str, ch)) == NULL)
			printf("字符串中没有字符 %c.\n", ch);
		else
			printf("字符串 %s 中第一个 %c 的存储位置为 %p\n", str, ch, rt);
	}while(getchar() == '\n');
	puts("Done!");

	return 0;
}
char * getput(char *str,char ch)
{
	int i;
	int n = strlen(str);

	for (i =0; i < n; i++, str++)
		if (*str == ch)
			break;
	if(i == n)
		return NULL;
	else
		return str;

}
