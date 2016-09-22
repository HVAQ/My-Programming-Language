#include <stdio.h>
#define SIZE 5

struct allname {
	char fname[20];
	char tname;
	char lname[20];
};

struct info {
	long num;
	struct allname name;
};

void eatline (void);
void show_info (struct info *);

int main (void)
{
	struct info all[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		puts ("请输入社会保障号.");
		scanf ("%ld", &all[i].num);
		eatline();
		puts ("请输入名");
		gets (all[i].name.fname);
		puts ("请输入中间名");
		all[i].name.tname = getchar();
		eatline();
		puts ("请输入姓");
		gets (all[i].name.lname);
	}
	show_info (all);

	return 0;
}

void eatline (void)
{
	while (getchar() != '\n')
		continue;
}

void show_info (struct info *all)
{
	for (int i = 0; i < SIZE; i++)
	{
		if (all[i].name.tname != '\n')
			printf ("%s, %s %c. - %ld\n", all[i].name.fname, all[i].name.lname, all[i].name.tname, all[i].num);
		else
			printf ("%s, %s - %ld\n", all[i].name.fname, all[i].name.lname, all[i].num);
	}
}
