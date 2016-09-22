// 为数组动态分配存储空间
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	double *ptd;
	int max;
	int number;
	int i = 0;

	puts ("What is the maximum number of type double entries?");
	scanf ("%d", &max);
	ptd = (double *) malloc (max * sizeof (double));
	if (ptd == NULL)
	{
		puts ("Memory allocation faild, Goodbye.");
		exit (EXIT_FAILURE);
	}
	// ptd现在指向一个有max元素的数组
	puts ("Enter the values (q to quite): ");
	while (i < max && scanf ("%lf", &ptd[i]) == 1)
		++i;
	printf ("Here are your %d entrices: \n", number = i);
	for (i = 0; i < number; i++)
	{
		printf ("%7.2f ",  ptd[i]);
		if (i % 7 == 6)
			putchar ('\n');
	}
	if (i % 7 != 0)
		putchar ('\n');
	puts ("Done.");
	free (ptd);

	return 0;
}
