#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define LEN 50

int main (void)
{
	FILE *fp1, *fp2;
	char name1[LEN], name2[LEN];
	char ch;

	puts ("请输入输入文件名");
	gets (name1);;
	if ((fp1 = fopen (name1, "r")) == NULL){
		fprintf (stderr, "打开文件\"%s\"失败.\n", name1);
		exit (EXIT_FAILURE);
	}
	puts ("请输入输出文件名");
	gets (name2);
	if ((fp2 = fopen (name2, "a")) == NULL){
		fprintf (stderr, "创建文件\"%s\"失败.\n", name2);
		exit (EXIT_FAILURE);
	}
	while ((ch = getc (fp1)) != EOF)
	{
		ch = toupper (ch);
		fputc (ch, fp2);
	}
	if (fclose (fp1) != 0 || fclose (fp2) != 0)
		fprintf (stderr, "文件关闭失败\n");

	return 0;
}
