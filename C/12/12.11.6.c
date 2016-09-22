#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000

int main (void)
{
	int a, b, c, d, e, f, g, h, i, j, m;

	a = b = c = d = e = f = g = h = i = j = 0;
	srand ((unsigned int)time(0));
	for (int n = 0; n < MAX; n++)
	{
		m = rand() % 10 + 1;
		if (m == 1)
			++a;
		else if (m == 2)
			++b;
		else if (m == 3)
			++c;
		else if (m == 4)
			++d;
		else if (m == 5)
			++e;
		else if (m == 6)
			++f;
		else if (m == 7)
			++g;
		else if (m == 8)
			++h;
		else if (m == 9)
			++i;
		else
			++j;
	}
	printf ("1出现%d次,2出现%d次,3出现%d次,4出现%d次,5出现%d次\n", a, b, c, d, e);
	printf ("6出现%d次,7出现%d次,8出现%d次,9出现%d次,10出现%d次\n", f, g, h, i, j);

	return 0;
}
