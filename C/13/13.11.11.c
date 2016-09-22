#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 40

int main (int argc, char **argv)
{
	FILE *fp;
	char ch[LEN];

	if (argc != 3)
	{
		fprintf (stderr, "请按 %s 字符串 文件名 的格式输入.", argv[0]);
		exit (EXIT_FAILURE);
	}
	if ((fp = fopen (argv[2], "r")) == NULL)
	{
		fprintf (stderr, "文件 %s 打开失败.\n", argv[2]);
		exit (EXIT_FAILURE);
	}
	while (fgets (ch, LEN-1, fp) != NULL)
		if (strstr (ch, argv[1]) != NULL)
			fputs (ch, stdout);
	if (fclose (fp) != 0)
		fprintf (stderr, "关闭文件 %s 失败\n", argv[1]);

	return 0;
}
