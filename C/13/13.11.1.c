#include <stdio.h>
#include <stdlib.h>
#define SIZE 40

int main (void)
{
	int ch;
	FILE *fp;
	long count = 0;
	char fname[SIZE];

	puts ("请输入您要打印的文件名");
	gets (fname);
	if ((fp = fopen (fname, "r")) == NULL){
		fprintf (stderr, "打开文件 \"%s\" 失败\n", fname);
		exit (EXIT_FAILURE);
	}
	while ((ch = getc (fp)) != EOF)
	{
		putc (ch, stdout);
		count++;
	}
	fclose (fp);
	printf ("文件 \"%s\" 有 %ld 个字符\n", fname, count);

	return 0;
}
