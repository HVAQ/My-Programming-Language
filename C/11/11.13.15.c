#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 81

int main (int argc, char *argv[])
{
	char str[SIZE];
	int ch, i, n;

	i = 0;
	if (argc < 2)
		puts("缺少必要参数");
	else if(strcmp (argv[1],"-p") != 0 && strcmp (argv[1], "-u") != 0 && strcmp (argv[1], "-l") != 0)
		puts("参数错误");
	else{
		puts("请输入字符串");
		while ((ch = getchar()) != EOF){
			str[i] = ch;
			i++;
		}
		str[i] = '\0';
		if (strcmp (argv[1], "-p") == 0){
			putchar('\n');
			puts(str);
		}
		else if (strcmp (argv[1], "-u") == 0){
			for(n = 0; n < i; n++)
				str[n] = toupper(str[n]);
			putchar('\n');
			puts(str);
		}
		else {
			for(n = 0; n < i; n++)
				str[n] = tolower(str[n]);
			putchar('\n');
			puts(str);
		}
	}

	return 0;
}
