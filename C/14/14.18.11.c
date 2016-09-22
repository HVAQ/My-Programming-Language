#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h> // 包含sin()、cos()函数

char mean (void);
int get_info (double *);
double (*str) (double);
void transform (double * source, double * target, int n, double (* str) (double));

int main (void)
{
	char ch;
	int num, m, n;
	double source[num];
	double target[num];

	for (m = 0; m < 4; m++)
	{
		if ((ch = mean()) == 'a')
		{
			num = get_info (source);
			str = sin;
			transform (source, target, num, str);
			for (n = 0; n < num; n++)
				printf ("sin(%.2f) = %.2f\n", source[n], target[n]);
		}
		else
		{
			num = get_info (source);
			str = cos;
			transform (source, target, num, str);
			for (n = 0; n < num; n++)
				printf ("cos(%.2f) = %.2f\n", source[n], target[n]);
		}
	}
	puts ("Bye!");

	return 0;

}

void transform (double * source, double * target, int n, double (* str) (double))
{
	int i;

	for (i = 0; i < n; i++)
		target[i] = (* str)(source[i]);
}
int get_info (double * numbers)
{
	double num;
	int count = 0;

	puts ("请输入弧度.");
	while (scanf("%lf", &num) == 1)
	{
		numbers[count] = num;
		count++;
	}

	return count;
}
char mean (void)
{
	char ch;

	puts ("您要计算正弦值还是余弦值?");
	puts ("a) 正弦值");
	puts ("b) 余弦值");
	puts ("c) 退出");
	ch = getchar();
	while (getchar() != '\n')
		continue;
	ch = tolower(ch);
	while (ch != 'a' && ch != 'b' && ch != 'c')
	{
		puts ("请输入列表中的选项.");
		ch = getchar();
		while (getchar() != '\n')
			continue;
		ch = tolower(ch);
	}
	if (ch == 'c')
	{
		puts ("Bye!");
		exit (EXIT_SUCCESS);
	}

	return ch;
}
