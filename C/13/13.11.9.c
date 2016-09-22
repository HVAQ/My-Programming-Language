#include <stdio.h>
#include <stdlib.h>
#define MAX 40

int main (void)
{
	FILE *fp;
	char words[MAX];
	int i = 1;

	if ((fp = fopen ("words", "a+")) == NULL)
	{
		fprintf (stderr, "Can't open \"words\" file.\n");
		exit (EXIT_FAILURE);
	}
	puts ("Enter words to add to the file: press the Enter");
	puts ("key at the beginning of a line to terminate.");
	while (gets (words) != NULL && words[0] != '\0')
		fprintf (fp, "%s", words);
	puts ("File contents: ");
	rewind (fp);
	while (fscanf (fp, "%s", words) == 1)
	{
		printf ("%d: ", i);
		puts (words);
		i++;
	}
	if (fclose (fp) != 0)
		fprintf (stderr, "Error closing file.\n");

	return 0;
}
