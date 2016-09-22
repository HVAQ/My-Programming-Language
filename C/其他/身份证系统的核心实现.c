#include <stdio.h>

int main (void)
{
	FILE *fp;
	int num[][10] = {
		{1, 2, 3, 4, 5, 6, 7, 8, 9, 0},
		{1, 2, 3, 4, 5, 6, 7, 8, 9, 0},
		{2, 4, 6, 8, 0},
	};
	float x;
	int y;

	fp = fopen ("num3.txt", "w");
	for (int i = 0; i < 10; i++)
		for (int m = 0; m < 10; m++)
			for (int n = 0; n < 5; n++)
			{
				x = (7 + 36 + 10 + 5 + 16 + 4 + 2 + 9 + 54 + 15 + 81 + 10 + 30 + num[0][i] * 8 + num[1][m] * 4 + num[2][n] * 2) % 11;
				if (x == 0) y = 1;
				else if (x == 1) y = 0;
				else if (x == 2) y = 10;
				else if (x == 3) y = 9;
				else if (x == 4) y = 8;
				else if (x == 5) y = 7;
				else if (x == 6) y = 6;
				else if (x == 7) y = 5;
				else if (x == 8) y = 4;
				else if (x == 9) y = 3;
				else y = 2;
				if (y == 10) continue;
				else
					fprintf (fp, "%d %d %d %d\n", num[0][i], num[1][m], num[2][n], y);
			}
	fclose (fp);

	return 0;
}
