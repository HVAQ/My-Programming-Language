#include <stdio.h>
#include <stdlib.h>
#define LINE 8

int * make_array (int elem, int val);
void show_array (const int ar[], int n);

int main (void)
{
	int *pa;
	int size;
	int value;

	printf ("Enter the number of elements: ");
	scanf ("%d", &size);
	while (size > 0)
	{
		printf ("Enter the initializat value: ");
		scanf ("%d", &value);
		pa = make_array (size, value);
		if (pa)
		{
			show_array (pa, size);
				free(pa);
		}
		printf ("Enter the number of elements (<1 to quite): ");
		scanf ("%d", &size);
	}
	printf ("Done.\n");

	return 0;
}

int * make_array (int elem, int val)
{
	int * str = (int *) malloc (elem * sizeof (int));

	for (int i = 0; i < elem; i++)
		str[i] = val;

	return str;
}

void show_array (const int ar[], int n)
{
	int i, m;

	i = m = 1;
	for (i = 1; i < n + 1; i++)
	{
		printf ("%6d", ar[i - 1]);
		m = i % LINE;
		if (m == 0)
			putchar ('\n');
	}
	if (m != 0)
		putchar ('\n');
}
