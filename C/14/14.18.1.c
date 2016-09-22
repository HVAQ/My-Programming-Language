#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 12

struct month {
	char name[10];
	char sname[4];
	int days;
	int nmonth;
};

int get_month (const struct month *, int);

int main (void)
{
	struct month months[SIZE] = {
		{"January", "jan", 31, 1},
		{"February", "feb", 28, 2},
		{"March", "mar", 31, 3},
		{"April", "apr", 30, 4},
		{"May", "may", 31, 5},
		{"June", "jun", 30, 6},
		{"July", "jul", 31, 7},
		{"August", "aug", 31, 8},
		{"September", "sep", 30, 9},
		{"October", "oct", 31, 10},
		{"November", "nov", 31, 11},
		{"December", "dec", 30, 12}
	};
	char name[10];
	int i, total;

	printf ("请输入月份名.\n");
	while (gets(name) != NULL && name[0] != '\0')
	{ 
		name[0] = toupper(name[0]);
		for (i = 1; name[i] != '\0'; i++)
			name[i] = tolower(name[i]);
		for (i = 0; i < SIZE; i++)
			if (strcmp (name, months[i].name) == 0)
			{
				total = get_month (&months[0], i);
				break;
			}
		if (i < SIZE)
			printf ("一直到 %d 月有 %d 天.\n", months[i].nmonth, total);
		else
			puts ("输入有误.");
		puts ("请重新输入一个月份名.");
	}
	puts ("Done!");

	return 0;
}
int get_month (const struct month * addmon, int n)
{
	int i, total;

	for (i = 0, total = 0; i <= n; i++)
		total += addmon++ -> days;
	
	return total;
}
