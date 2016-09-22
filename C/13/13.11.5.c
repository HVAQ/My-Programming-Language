#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 1024

void append (FILE *source, FILE *dest);

int main (int argc, char **argv)
{
	FILE *fa, *fs;
	int files = 0;
	
	if (argc < 3)
	{
		fprintf (stderr, "Source: %s [filename] [filename]\n", argv[0]);
		exit (EXIT_FAILURE);
	}
	if ((fa = fopen (argv[1], "a")) == NULL)
	{
		fprintf (stderr, "Can't open %s\n", argv[0]);
		exit (EXIT_FAILURE);
	}
	if (setvbuf (fa, NULL, _IOFBF, BUFSIZE) != 0)
	{
		fputs ("Can't create output buffer\n", stderr);
		exit (EXIT_FAILURE);
	}
	for (int i = 2; i < argc; i++)
	{
		if (argv[i][0] != '\0')
		{
			if (strcmp (argv[i], argv[1]) == 0)
				fputs ("Can't append file to itself\n", stderr);
			else if ((fs = fopen (argv[i], "r")) == NULL)
				fprintf (stderr, "Can't open %s\n", argv[i]);
			else
			{
				if (setvbuf (fs, NULL, _IOFBF, BUFSIZE) != 0)
				{
					fputs ("Can't creat input buffer\n", stderr);
					continue;
				}
				append (fs, fa);
				if (ferror (fs) != 0)
					fprintf (stderr, "Error in reading file %s.\n", argv[i]);
				if (ferror (fa) != 0)
					fprintf (stderr, "Error in writing file %s.\n", argv[1]);
				fclose (fs);
				files++;
				printf ("File %s appended.\n", argv[i]);
			}
		}
		else
			fprintf (stderr, "Can't append file %s to file %s, because file %s have \\0 at start\n", argv[i], argv[1], argv[i]);
	}
	printf ("Done. %d files appended.\n", files);
	fclose (fa);

	return 0;
}

void append (FILE *source, FILE *dest)
{
	size_t bytes;
	static char temp[BUFSIZE];

	while ((bytes = fread (temp, sizeof (char), BUFSIZE, source)) >0 )
		fwrite (temp, sizeof (char), bytes, dest);
}
