#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
	int i;
	FILE *fp;
	char ch;

	for (i = 1; i < argc; i++)
	{
		if ((fp = fopen (argv[i], "r")) == NULL){
			fprintf (stderr, "打开文件\"%s\"错误\n", argv[i]);
			exit (EXIT_FAILURE);
		}
		else{
			printf ("\t%s\n", argv[i]);
			while ((ch = fgetc (fp)) != EOF)
				fputc (ch, stdout);
			if (fclose (fp) != 0)
				fprintf (stderr, "关闭文件\"%s\"错误.\n", argv[i]);
		}
		putchar ('\n');
	}

	return 0;
}
