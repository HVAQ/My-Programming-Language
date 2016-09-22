#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40

int main (void)
{
	FILE *in, *out;
	int ch;
	char name_one[LEN], name_two[LEN];
	int count = 0;

	printf ("请输入要压缩的文件名.\n");
	gets(name_one);
	if ((in = fopen (name_one, "r")) == NULL)
	{
		fprintf (stderr, "无法打开文件%s.\n", name_one);
		exit (EXIT_FAILURE);
	}
	strcpy (name_two, name_one);
	strcat (name_two, ".red");
	if ((out = fopen (name_two, "w")) == NULL)
	{
		fprintf (stderr, "无法打开\\创建文件%s.\n", name_two);
		exit (EXIT_FAILURE);
	}
	while ((ch = getc (in)) != EOF)
		if (count++ % 3 == 0)
			putc (ch, out);
	if (fclose (in) != 0 || fclose (out) != 0)
		fprintf (stderr, "文件关闭失败.\n");

	return 0;
}
