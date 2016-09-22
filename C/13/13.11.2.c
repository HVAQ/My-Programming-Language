#include <stdio.h>
#include <stdlib.h>
#define SIZE 256

int main (int argc, char **argv)
{
	FILE *fp1, *fp2;
	char words[SIZE];

	if (argc != 3){
		fprintf (stderr, "请以 \"%s 文件名 文件名\" 的格式输入.\n", argv[0]);
		exit (EXIT_FAILURE);
	}
	if ((fp1 = fopen (argv[1], "rd")) == NULL){
		fprintf (stderr, "打开文件 \"%s\" 失败.\n", argv[1]);
		exit (EXIT_FAILURE);
	}
	if ((fp2 = fopen (argv[2], "ad")) == NULL){
		fprintf (stderr, "打开文件 \"%s\" 失败.\n", argv[2]);
		exit (EXIT_FAILURE);
	}
	while (fread (words, sizeof(char), 1, fp1) != 0)
		if (fwrite (words, sizeof(char), 1, fp2) == 0)
			fprintf (stderr, "写入文件 \"%s\" 失败.\n", argv[2]);

	if (fclose (fp1) != 0 || fclose (fp2) != 0)
		fprintf (stderr, "文件关闭失败\n");

	return 0;
}
