#include <stdio.h>
#define SIZE 10
char * get_str(char *, int);
int main(void)
{
	char str[SIZE];
	char *ch;

	puts("能读取9个字符\n");
	ch = get_str(str, SIZE - 1);
	if (ch == NULL)
		puts("\n输入错误");
	else
		puts(str);
	puts("Done");

	return 0;
}
char * get_str(char *str, int n)
{
	char ch;
	int i;

	for (i = 0; i < n; i++){
		ch = getchar();
		if (ch != EOF)
			str[i] = ch;
		else
			break;
		}
	if (ch == EOF)
		return NULL;
	else{
		str[i] = '\0';
		return str;
	}
}
