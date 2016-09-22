#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void)
{
	int sum = 0;
	int sets, sides, dice, i;

	srand ((unsigned int)time(0));
	puts ("Enter the number of sets: enter q to stop.");
	while (scanf ("%d", &sets) == 1 && sets > 0)
	{
		puts ("How many sides and how many dice?");
		if(scanf ("%d %d", &sides, &dice) == 2){
			printf ("Here are %d sets of %d %d-sided throws.\n", sets, sides, dice);
			for (i = 1; i< sets + 1; i++){
				for (int m = 0; m < dice; m++)
					sum += rand() % sides + 1;
				printf ("%6d", sum);
				sum = 0;
				if (i % 15 == 0)
					putchar ('\n');
			}
			if (i % 15 != 0)
				putchar ('\n');
			puts ("Enter the number of sets: enter q to stop.");
		}
	}

	return 0;
}
