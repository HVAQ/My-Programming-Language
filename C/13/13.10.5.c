#include <stdio.h>
#include <stdlib.h>

#define MAX 256
int get_ch (const char [], char ch);

int main (int argc, char **argv)
{
	FILE *fp;
	char words[MAX];
	char ch;

	if (argc != 3){
		fprintf (stderr, "请以 \"%s 字符 文件名\" 的格式输入.\n", argv[0]);
		exit (EXIT_FAILURE);
	}
	ch = argv[1][0];
	if ((fp = fopen (argv[2], "r")) == NULL){
		fprintf (stderr, "打开文件 \"%s\" 失败.\n", argv[2]);
		exit (EXIT_FAILURE);
	}
	while (fgets (words, MAX, fp) != NULL)
	{
		if (get_ch (words, ch))
			fputs (words, stdout);
	}
	if (fclose(fp) != 0)
		fprintf (stderr, "关闭文件 \"%s\" 失败\n", argv[2]);

	return 0;
}

int get_ch (const char words[], char ch)
{
	while (*words)
		if (*words++ == ch)
			return (1);
	return 0;
}
