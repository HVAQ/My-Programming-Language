#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

void get_str (int *);

int main (void)
{
	int str[MAX];

	srand ((unsigned int) time(0));
	for (int i = 0; i < MAX; i++)
		str[i] = rand() % 10 + 1;
	get_str (str);

	return 0;
}

void get_str (int * str)
{
	int x, i;

	for (int m = 0; m < MAX - 1; m++)
		for (int n = m + 1; n < MAX; n++)
			if (str[m] < str[n]){
				x = str[m];
				str[m] = str[n];
				str[n] = x;
			}
	for (i = 0; i < MAX; i++){
		printf ("%6d", str[i]);
		if (i % 10 == 9)
			putchar ('\n');
	}
}
