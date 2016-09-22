#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void showstring (char info);

int main (void)
{
	Stack * pt;
	Node info;

	ToFirst (pt);
	if (IsFull (pt))
	{
		fputs ("Memory is full.", stderr);
		exit (EXIT_FAILURE);
	}
	puts ("请输入一个字符串.");
	while ((info.item = getchar()) != EOF)
		if (!AddToString (info.item, pt))
		{
			puts ("MemoryError");
			exit (EXIT_FAILURE);
		}
	if (IsEmpty (pt))
		fprintf (stderr, "It's empty.");
	else
	{
		puts ("String is: ");
		Tranverse (pt, showstring);
	}
	ToEmpty (pt);

	return 0;
}

void showstring (char info)
{
	printf ("%c", info);
}
