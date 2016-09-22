#include <stdio.h>

#define MAX 20

int FindInt (int [], int, int);

int main (void)
{
	int find, index, yn, num;
	int str[MAX];

	// 初始化数组
	for (index = 0, num = 2; index < MAX; index++)
	{
		num += 3;
		str[index] = num;
	}

	printf ("请输入要查找的数: ");
	while (scanf ("%d", &find) != 1)
	{
		while (getchar() != '\n')
			continue;
		printf ("输入有误.\n请重新输入: ");
	}

	if (FindInt (str, MAX, find) == 1)
		printf ("找到了%d.\n", find);
	else
	{
		printf ("没有找到%d.\n", find);
		printf ("数组成员有: \n");

		for (index = 0; index < MAX; index++)
		{
			printf ("%d\t", str[index]);
			if (index % 5 == 4)
				putchar ('\n');
		}
		if (index % 5 != 0)
			putchar ('\n');
	}

	return 0;
}

int FindInt (int str[], int n, int num)
{
	int average;
	int ret, min, count;
	int max = n - 1;

	ret = min = count = 0;
	if (num < str[min] || num > str[max])
		ret = 0;
	else
	{
		while (1)
		{
			count++;
			average = str[(min + max) / 2];
			if (average == num)
			{
				ret = 1;
				break;
			}
			else if (num == str[min] || num == str[max])
			{
				ret = 1;
				break;
			}
			else if (max - min == 1)
				break;
			else if (average > num)
				max = (min + max) / 2;
			else
				min = (min + max) / 2;
		}
	printf ("经过%d次搜索, ", count);

	return ret;
}
