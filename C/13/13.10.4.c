#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
	int n = 0;
	double num;
	double sum = 0.0;
	FILE *fp;

	if (argc == 1)
		fp = stdin;
	else if (argc == 2){
		if ((fp = fopen (argv[1], "r")) == NULL){
			printf ("打开文件 \"%s\" 失败\n", argv[1]);
			exit (EXIT_FAILURE);
		}
	}
	else{
		fprintf (stderr, "请使用 \"%s 文件名\" 的格式输入\n", argv[0]);
		exit (EXIT_FAILURE);
	}
	while (fscanf (fp, "%lf", &num) == 1)
	{
		sum += num;
		++n;
	}
	if (n > 0)
		printf ("平均值为 %lf\n", sum / n);
	else
		printf ("获取文件内容失败\n");
	if (fclose (fp) != 0)
		printf ("关闭文件 \"%s\" 失败\n", argv[1]);

	return 0;
}
