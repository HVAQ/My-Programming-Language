#include <stdio.h>
#include <ctype.h>
int get_ch(char *, int);
int main(void)
{
	int ch, u, l, p, n, i, s;
	char str[81];

	u = l = p = n = i = 0;
	puts("请输入字符串");
	while ((ch = getchar()) != EOF){
		str[i] = ch;
		i++;
		isupper(ch) ? u++ : u;
		islower(ch) ? l++ : l;
		ispunct(ch) ? p++ : p;
		if (isalnum(ch) && !isalpha(ch))
			n++;
	}
	str[i] = '\0';
	s = get_ch(str, i);
	printf("\n您输入了 %d 个单词 %d 个大些字母 %d 个小写字母 %d 个标点符号 %d 个数学数字\n", s, u, l, p, n);

	return 0;
}
int get_ch(char *str, int i)
{
	int s = 0;
	int m, n;

	for ( m = 0; m < i; m++)
		for (n = m + 1; n < i + 1; n++){
			if (isalnum(str[m]) && !isalnum(str[n]))
				s++;
			break;
		}	

	return s;
}
