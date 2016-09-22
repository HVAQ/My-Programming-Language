#include <stdio.h>
#include <stdlib.h>
#define LEN 20
#define ROWS 30
#define SIZE 10

int main (int argc, char **argv)
{
	FILE *fp1, *fp2;
	int num[LEN][ROWS];
	int m, n;
	char ch[SIZE + 1] = " .':~*=$%#";

	if (argc != 3)
	{
		fprintf (stderr, "请以 %s 文件名 文件名 的格式输入.\n", argv[0]);
		exit (EXIT_FAILURE);
	}
	if ((fp1 = fopen (argv[1], "r")) == NULL)
	{
		fprintf (stderr, "无法打开文件 %s.\n", argv[1]);
		exit (EXIT_FAILURE);
	}
	if ((fp2 = fopen (argv[2], "w")) == NULL)
	{
		fprintf (stderr, "无法打开文件 %s.\n", argv[2]);
		exit (EXIT_FAILURE);
	}
	for (m = 0; m < LEN; m++)
		for (n = 0; n < ROWS; n++)
			fscanf (fp1, "%d", &num[m][n]);
	for (m = 0; m < LEN; m++)
	{
		for (n = 0; n < ROWS; n++)
		{
			putc (ch[num[m][n]], fp2);
			putc (ch[num[m][n]], stdout);
		}
		putchar ('\n');
		putc ('\n', fp2);
	}
	fclose (fp1);
	fclose (fp2);

	return 0;
}
