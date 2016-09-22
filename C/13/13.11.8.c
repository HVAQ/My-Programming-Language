#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40
int get_file (FILE *fp, char);

int main (int argc, char **argv)
{
	int count = 0;
	FILE *fp;
	char name [LEN];
	char ch;

	if (argc < 2)
	{
		fprintf (stderr, "请以 %s 字符 (文件名) 的格式输入.\n", argv[0]);
		exit (EXIT_FAILURE);
	}
	else if (argc == 2)
	{
		ch = argv[1][0];
		puts ("请输入要读取的文件名.");
		while (gets (name) != NULL && name[0] != '\0')
		{
			if ((fp = fopen (name, "r")) == NULL)
			{
				fprintf (stderr, "打开文件 %s 失败, 请重新输入一个文件名.\n", name);
				continue;
			}
			count = get_file (fp, ch);
			printf ("文件 %s 中, 共有 %c %d个\n", name, ch, count);
			count = 0;
			fclose (fp);
			printf ("请输入要读取的文件名.\n");
		}
	}
	else
	{
		ch = argv[1][0];
		for (int i = 2; i < argc; i++)
		{
			if ((fp = fopen (argv[i], "r")) == NULL)
			{
				fprintf (stderr, "打开文件 %s 失败.\n", argv[i]);
				continue;
			}
			count = get_file (fp, ch);
			printf ("文件 %s 中, 共有 %c %d个.\n", argv[i], ch, count);
			count = 0;
			fclose (fp);
		}
	}
	puts ("Done!");

	return 0;
}

int get_file (FILE *fp, char ch_one)
{
	int count = 0;
	int ch;

	while ((ch = getc (fp)) != EOF)
		if (ch_one == ch)
			count++;

	return count;
}
