#include <stdio.h>
#include <ctype.h>
#include <string.h>

char eatline (void);
void prt_one (char *);
void prt_two (char *);
void (*pf) (char *);

int main (void)
{
	int n;
	char ch;
	char str[50];

	puts ("请输入一个字符串.");
	gets(str);
	puts ("请选择: ");
	puts ("a) 正向打印");
	puts ("b) 逆向打印");
	puts ("c) 退出");
	ch = eatline();
	if (ch != 'a' && ch != 'b' && ch != 'c')
	{
		puts ("请选择列表中的选项.");
		ch = eatline();
	}
	if (ch != 'c')
		switch(ch)
		{
			case 'a': pf = prt_one; 
					  (*pf)(str);
					  break;
			case 'b': pf = prt_two;
					  (*pf)(str);
					  break;
		}
	puts ("Bye!");

	return 0;
}

void prt_two (char * get)
{
	int size = strlen(get) + 1;
	char put[size];

	strcpy (put, get);
	for (int i = size; i >= 0; i--)
		putc(put[i], stdout);
	putchar ('\n');
}
void prt_one (char * get)
{
	puts (get);
}
char eatline (void)
{
	char ch;

	if ((ch = getchar ()) != '\n')
		while (getchar() != '\n')
			continue;
	ch = tolower(ch);

	return ch;
}
