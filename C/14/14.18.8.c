#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define NAME 20
#define SIZE 12
#define YES 1
#define NO 0

struct seat {
	int num;
	int assig;
	char fname[NAME];
	char lname[NAME];
};

void mean (void);
void eatline (void);
char next (void);
void set (struct seat *);
void cha (const struct seat *);
void chb (const struct seat *);
void chc (const struct seat *);
void chd (struct seat *);
void che (struct seat *);

int main (void)
{
	struct seat seats[SIZE];
	char ch;
	FILE *fp;
	int count = 0;
	int size = sizeof (struct seat);

	do
	{
		set(seats);
		// 打开、读取文件
		if ((fp = fopen ("seatsinfo", "a+d")) == NULL)
		{
			fputs ("It's  failed to open seatsinfo.", stderr);
			exit (EXIT_FAILURE);
		}
		rewind (fp);
		for (count = 0; count < SIZE; count++)
			fread (&seats[count], size, 1, fp);
		// 显示菜单, 提供选择
		mean();
		ch = next();
		while (ch != 'a' && ch != 'b' && ch != 'c' && ch != 'd' && ch != 'e' && ch != 'f')
		{
			puts ("Your enter is wrong. Please enter the letter of list.");
			ch = next();
		}
		if (ch != 'f')
		{
			switch(ch)
			{
				case 'a': cha(seats); break;
				case 'b': chb(seats); break;
				case 'c': chc(seats); break;
				case 'd': chd(seats); break;
				case 'e': che(seats); break;
			}
			fclose (fp);
			fp = fopen ("seatsinfo", "w+d");
			rewind (fp);
			for (int i = 0; i < SIZE; i++)
				fwrite (&seats[i], size, 1, fp);
			puts ("again or stop (enter f to stop) ?");
			ch = next();
		}
		fclose (fp);
	}while (ch != 'f');
	puts ("Bye!");

	return 0;
}

void che (struct seat * seats)
{
	int num, n;
	char ch;

	for (n = 0; n < SIZE; n++)
		if (seats[n].assig == YES)
		{
			puts ("Please enter the number of the seat that you want to delete.");
			while (scanf ("%d" ,&num) != 1 || (num < 1 || num > SIZE))
			{
				puts ("Can't find the number of the seat what you has been enter.");
				puts ("Please enter the other number again.");
			}
			eatline();
			for (int i = 0; i < SIZE; i++)
				if (i == num - 1 && seats[i].assig == NO)
				{
					puts ("The seat haven't been assigned any customer.");
					break;
				}
				else if (i == num - 1)
				{
					printf ("Dou you want to delete the assignment:\n%d: YES %s %s ? (y / n)\n", num, seats[i].fname, seats[i].lname);
					ch = next();
					if (ch == 'y')
					{
						strcpy (seats[i].fname, "null");
						strcpy (seats[i].lname, "null");
						seats[i].assig = NO;
						puts ("It's OK !");
					}
					else
						puts ("Have been stop.");
				}
				else
					continue;
			break;
		}
	if (n == SIZE)
		puts ("Don't have seat have been assigned.");
}
void chd (struct seat * seats)
{
	int num , i, n;
	char ch;
	char fname[NAME], lname[NAME];

	for (n = 0; n < SIZE; n++)
		if (seats[n].assig == NO)
		{
			puts ("Please enter the number of seat.");
			while (scanf ("%d", &num) != 1 || (num > SIZE || num < 1))
			{
				eatline();
				puts ("Dont't have the number of you enter.");
				puts ("Please enter the number of seat.");
			}
			eatline();
			for (i = 0; i < SIZE; i++)
				if (i == num - 1 && seats[i].assig == YES)
				{
					puts ("The seat has been assigned.");
					puts ("You can't assign a customer to the seat.");
					break;
				}
				else if (i == num - 1)
				{
					puts ("Please enter the first name of customer.");
					gets (fname);
					puts ("Next enter the last name of customer.");
					gets (lname);
					break;
				}
				else
					continue;
			if (i == num - 1 && seats[i].assig == NO)
			{
				printf ("Do you want to assign the seat of %d to %s %s ? (y / n)\n", num, fname, lname);
				ch = next();
				if (ch == 'y')
				{
					strcpy (seats[i].fname, fname);
					strcpy (seats[i].lname, lname);
					seats[i].assig = YES;
					puts ("It's OK!");
				}
				else
					puts ("Have been stop.");
			}
			break;
		}
	if (n == SIZE)
		puts ("All seats have been assigned.");
}
void chc (const struct seat * seats)
{
	char yn[4];

	puts ("The list of seats: ");
	for (int i = 0; i < SIZE; i++)
	{
		if (seats[i].assig == YES)
			strcpy (yn, "YES");
		else
			strcpy (yn, "NO");
		printf ("%2d: %s %s %s.\n", seats[i].num, yn, seats[i].fname, seats[i].lname);
	}
}
void chb (const struct seat * seats)
{
	puts ("The list of empty seats: ");
	for (int i = 0; i < SIZE; i++)
		if (seats[i].assig == NO)
			printf ("%2d: NO %s %s.\n", seats[i].num, seats[i].fname, seats[i].lname);
}
void cha (const struct seat * seats)
{
	puts ("The number of empty seats: ");
	for (int i = 0; i < SIZE; i++)
		if (seats[i].assig == NO)
			printf ("%d. ", seats[i].num);
	putchar ('\n');
}
void set (struct seat * seats)
{
	for (int i = 0; i < SIZE; i++)
	{
		seats[i].num = i + 1;
		seats[i].assig = NO;
		strcpy (seats[i].fname, "null");
		strcpy (seats[i].lname, "null");
	}
}
char next (void)
{
	char ch;
	if ((ch = getchar()) != '\n')
		eatline();
	ch = tolower(ch);

	return ch;
}
void eatline(void)
{
	while (getchar() != '\n')
		continue;
}
void mean (void)
{
	puts ("To choose a function, enter its letter lable:");
	puts ("a) Show number of empty seats");
	puts ("b) Show list of empty seats");
	puts ("c) Show alphabetical list of seats");
	puts ("d) Assign a customer to a seat assignment");
	puts ("e) Delete a seat assignment");
	puts ("f) Quit");
}
