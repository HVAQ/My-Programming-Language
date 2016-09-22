#include <stdio.h>
#define CSIZE 4

struct name {
	char fname[10];
	char lname[10];
};

struct student {
	struct name aname;
	float grade[3];
	float arerage;
};

void eatline (void);
void set_arer (struct student *);
void show_info (const struct student *);

int main (void)
{
	struct student info[CSIZE];

	for (int i = 0; i <	CSIZE; i++)
	{
		puts ("请输入学生姓氏.");
		gets (info[i].aname.fname);
		puts ("请输入学生名.");
		gets (info[i].aname.lname);
		puts ("请输入学生成绩.");
		scanf ("%f %f %f", &info[i].grade[0], &info[i].grade[1], &info[i].grade[2]);
		eatline();
	}
	set_arer (info);
	show_info (info);

	return 0;
}

void eatline (void)
{
	while (getchar() != '\n')
		continue;
}

void set_arer (struct student * him)
{
	for (int i = 0; i < CSIZE; i++)
		if (him[i].grade[0] == 0 && him[i].grade[1] == 0 && him[i].grade[2] == 0)
			him[i].arerage = 0;
		else
			him[i].arerage = (him[i].grade[0] + him[i].grade[1] + him[1].grade[2]) / 3;
}

void show_info (const struct student * him)
{
	for (int i = 0; i < CSIZE; i++)
		printf ("%s %s %.2f %.2f %.2f %.2f\n", him[i].aname.fname, him[i].aname.lname, him[i].grade[0], him[i].grade[1], him[i].grade[2], him[i].arerage);
}
