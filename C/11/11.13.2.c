#include <stdio.h>
#include <ctype.h>  //包含isspace()函数;
#define MAX 10
char * get_str(char *, int);
int main(void)
{
	char str[MAX];
	char *ch;
	
	ch = get_str(str, MAX - 1);
	if (ch == NULL)
		puts("\n输入失败");
	else
		puts(str);
	puts("Done");

	return 0;
}
char * get_str(char *str, int n)
{
	int i;
	char ch;

	for (i = 0; i < n; i++){
		ch = getchar();
		if (isspace(ch) || ch == EOF)
			break;
		else
			str[i] = ch;
	}
	if (ch == EOF)
		return NULL;
	else{
		str[i] = '\0';
		return str;
	}
}
