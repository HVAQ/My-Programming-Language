#include <stdio.h>
#include <stdlib.h>
#define LEN 19
#define ROWS 29
#define SIZE 11

int main (int argc, char **argv)
{
	FILE *fp1, *fp2;
	int num[LEN + 1][ROWS + 1];
	int len, rows, c1, c2, c3, c4;
	char ch[SIZE] = " .':~*=$%#";

	if (argc < 3)
	{
		fprintf (stderr, "请以 %s 文件名 文件名 的格式输入.\n", argv[0]);
		exit (EXIT_FAILURE);
	}
	if ((fp1 = fopen (argv[1], "r")) == NULL)
	{
		fprintf (stderr, "打开文件 %s 失败.\n", argv[1]);
		exit (EXIT_FAILURE);
	}
	if ((fp2 = fopen (argv[2], "w")) == NULL)
	{
		fprintf (stderr, "打开文件 %s 失败.\n", argv[2]);
		exit (EXIT_FAILURE);
	}
	for (len = 0; len <= LEN; len++)
		for (rows = 0; rows <= ROWS; rows++)
			fscanf (fp1, "%d", &num[len][rows]);
	for (len = 0; len <= LEN; len++)
		for (rows = 0; rows <= ROWS; rows++)
		{
			if (len == 0 && rows == 0)
			{
				c1 = (num[len][rows] - num[len + 1][rows]);
				c2 = (num[len][rows] - num[len][rows + 1]);
				if ((c1 > 1 || c1 < -1) && (c2 > 1 || c2 < -1))
					num[len][rows] = (num[len][rows + 1] + num[len + 1][rows]) / 2;
			}
			else if (len == LEN && rows == ROWS)
			{
				c1 = (num[len][rows] - num[len - 1][rows]);
				c2 = (num[len][rows] - num[len][rows - 1]);
				if ((c1 > 1 || c1 < -1) && (c2 > 1 || c2 < -1))
					num[len][rows] = (num[len][rows - 1] + num[len - 1][rows]) / 2;
			}
			else if (len == 0 && rows == ROWS)
			{
				c1 = (num[len][rows] - num[len + 1][rows]);
				c2 = (num[len][rows] - num[len][rows - 1]);
				if ((c1 > 1 || c1 < -1) && (c2 > 1 || c2 < -1))
					num[len][rows] = (num[len + 1][rows] + num[len][rows - 1]) / 2;
			}
			else if (len == LEN && rows == 0)
			{
				c1 = (num[len][rows] - num[len - 1][rows]);
				c2 = (num[len][rows] - num[len][rows + 1]);
				if ((c1 > 1 || c1 < -1) && (c2 > 1 || c2 < -1))
					num[len][rows] = (num[len - 1][rows] + num[len][rows + 1]) / 2;
			}
			else if (len == 0)
			{
				c1 = (num[len][rows] - num[len + 1][rows]);
				c2 = (num[len][rows] - num[len][rows - 1]);
				c3 = (num[len][rows] - num[len][rows + 1]);
				if ((c1 > 1 || c1 < -1) && (c2 > 1 || c2 < -1) && (c3 > 1 || c3 < -1))
					num[len][rows] = (num[len + 1][rows] + num[len][rows - 1] + num[len][rows + 1]) / 3;
			}
			else if (rows == 0)
			{
				c1 = (num[len][rows] - num[len + 1][rows]);
				c2 = (num[len][rows] - num[len - 1][rows]);
				c3 = (num[len][rows] - num[len][rows + 1]);
				if ((c1 > 1 || c1 < -1) && (c2 > 1 || c2 < -1) && (c3 > 1 || c3 < -1))
					num[len][rows] = (num[len + 1][rows] + num[len - 1][rows] + num[len][rows + 1]) / 3;
			}
			else if (len == LEN)
			{
				c1 = (num[len][rows] - num[len - 1][rows]);
				c2 = (num[len][rows] - num[len][rows + 1]);
				c3 = (num[len][rows] - num[len][rows - 1]);
				if ((c1 > 1 || c1 < -1) && (c2 > 1 || c2 < -1) && (c3 > 1 && c3 < -1))
					num[len][rows] = (num[len - 1][rows] + num[len][rows + 1] + num[len][rows - 1]) / 3;
			}
			else if (rows == ROWS)
			{
				c1 = (num[len][rows] - num[len - 1][rows]);
				c2 = (num[len][rows] - num[len + 1][rows]);
				c3 = (num[len][rows] - num[len][rows - 1]);
				if ((c1 > 1 || c1 < -1) && (c2 > 1 || c2 < -1) && (c3 > 1 || c3 < -1))
					num[len][rows] = (num[len - 1][rows] + num[len + 1][rows] + num[len][rows - 1]) / 3;
			}
			else
			{
				c1 = (num[len][rows] - num[len - 1][rows]);
				c2 = (num[len][rows] - num[len + 1][rows]);
				c3 = (num[len][rows] - num[len][rows - 1]);
				c4 = (num[len][rows] - num[len][rows + 1]);
				if ((c1 > 1 || c1 < -1) && (c2 > 1 || c2 < -1) && (c3 > 1 || c3 < -1) && (c4 > 1 || c4 < -1))
					num[len][rows] = (num[len - 1][rows] + num[len + 1][rows] + num[len][rows + 1] + num[len][rows - 1]) / 4;
			}
		}
	for (len = 0; len <= LEN; len++)
	{
		for (rows = 0; rows <= ROWS; rows++)
		{
			putc (ch[num[len][rows]], stdout);
			putc (ch[num[len][rows]], fp2);
		}
		putc ('\n', stdout);
		putc ('\n', fp2);
	}
	fclose (fp1);
	fclose (fp2);

	return 0;
}
