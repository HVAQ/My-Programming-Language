#include <stdio.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100

struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

void info_one (struct book library[], int);
void info_two (struct book library[], int);

int main (void)
{
	struct book library[MAXBKS];
	int count = 0;
	int index;

	printf ("Please enter the book title.\n");
	printf ("Please (enter) at the start of a line to stop.\n");
	while (count < MAXBKS && gets (library[count].title) != NULL && library[count].title[0] != '\0')
	{ 
		printf ("Now enter the author.\n");
		gets (library[count].author);
		printf ("Now enter the value.\n");
		scanf ("%f", &library[count++].value);
		while (getchar() != '\n')
			continue;
		if (count < MAXBKS)
			printf ("Enter the next title.\n");
	}
	if (count > 0)
	{ 
		info_one(library, count);
		info_two(library, count);
	}
	else
		printf ("No books? Too bad.\n");

	return 0;
}

void info_one (struct book library[], int count)
{
	struct book temp;
	int m, n, k;

	for (m = 0; m < count - 1; m++)
		for (n = m + 1; n < count; n++)
			if (strcmp (library[m].title, library[n].title) > 0)
			{
				temp = library[m];
				library[m] = library[n];
				library[n] = temp;
			}
	for (k = 0; k < count; k++)
		printf ("%d: %s by %s: $%.2f\n", k + 1, library[k].title, library[k].author, library[k].value);
}

void info_two (struct book library[], int count)
{
	struct book temp;
	int m, n, k;

	for (m = 0; m < count - 1; m++)
		for (n = m + 1; n < count; n++)
			if (library[m].value > library[n].value)
			{
				temp = library[m];
				library[m] = library[n];
				library[n] = temp;
			}
	printf ("\tVALUE\n");
	for (k = 0; k < count; k++)
		printf ("%d: %s by %s: $%.2f\n", k + 1, library[k].title, library[k].author, library[k].value);
}
