#include <stdio.h>
#include <stdlib.h>
#define LEN 40

int main (void)
{
	FILE *fp;
	long count = 0L;
	char name[LEN];
	char ch;

	puts ("请输入文件名.");
	gets (name);
	if ((fp = fopen (name, "r")) == NULL)
	{
		fprintf (stderr, "打开文件 %s 失败.\n", name);
		exit (EXIT_FAILURE);
	}
	puts ("请输入一个文件位置.");
	while (scanf ("%ld", &count) == 1)
	{
		fseek (fp, 0L, SEEK_END);
		if (count < ftell (fp))
		{
			fseek (fp, count, SEEK_SET);
			ch = getc (fp);
			putc (ch, stdout);
			while (ch != '\n')
			{
				fseek (fp , ++count, SEEK_SET);
				ch = getc (fp);
				putc (ch, stdout);
			}
		}
		else
			puts ("位置超出文件大小.");
		puts ("请重新输入一个文件位置.");
	}
	if (fclose (fp) != 0)
	{
		fprintf (stderr, "关闭文件 %s 失败.\n", name);
		exit (EXIT_FAILURE);
	}
	puts ("Done!");

	return 0;
}
