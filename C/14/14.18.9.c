#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define NAME 20
#define SIZE 12
#define YES 1
#define NO 0
#define ONFNUM 102
#define TWFNUM 311
#define THFNUM 444
#define FOFNUM 519

struct seat {
    int num;
    int assig;
    char fname[NAME];
    char lname[NAME];
};

void mean (int);
void eatline (void);
char next (void);
void set (struct seat *);
void cha (const struct seat *);
void chb (const struct seat *);
void chc (const struct seat *);
void chd (struct seat *);
void che (struct seat *);
int fn (void);

int main (void)
{
    struct seat seats[SIZE];
    char ch = 'f';
    FILE *fp;
    int count = 0;
    int size = sizeof (struct seat);
	int num;
	char chnum[10];
    
    while (1)
    { 
		// 如果用户键入 f 返回顶层菜单
		if (ch == 'f')
		{
			num = fn();
			if (num == ONFNUM)
				strcpy (chnum, "one_num");
			else if (num == TWFNUM)
				strcpy (chnum, "two_num");
			else if (num == THFNUM)
				strcpy (chnum, "three_num");
			else
				strcpy (chnum, "four_num");
		}
        set(seats);
        // 打开、读取文件
        if ((fp = fopen (chnum, "a+d")) == NULL)
         {
            fprintf (stderr, "It's  failed to open %s.", chnum);
            exit (EXIT_FAILURE);
        }
        rewind (fp);
        for (count = 0; count < SIZE; count++)
            fread (&seats[count], size, 1, fp);
        // 显示菜单, 提供选择
        mean(num);
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
            fp = fopen (chnum, "w+d");
            rewind (fp);
            for (int i = 0; i < SIZE; i++)
                fwrite (&seats[i], size, 1, fp);
            printf ("again at the %d or stop (enter f to return top) ?\n", num);
            ch = next();
        }
        fclose (fp);
    }

    return 0;
}

int fn (void)
{
	char ch[15];
	int num;

	printf ("There is flight number: %d %d %d %d.\n", ONFNUM, TWFNUM, THFNUM, FOFNUM);
	puts ("Please enter the flight number of list (q to quite).");
	gets(ch);
	if (ch[0] == 'q' || ch[0] == 'Q')
	{
		puts ("Bye!");
		exit (EXIT_SUCCESS);
	}
	else 
	{
		num = atoi(ch);
		if (num != ONFNUM && num != TWFNUM && num != THFNUM && num != FOFNUM)
		{
			fprintf (stderr, "Don't have the filght number of %d.\n", num);
			exit (EXIT_FAILURE);
		}
	}

	return num;
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
void mean (int num)
{
	printf ("Now The filght number is %d.\n", num);
    puts ("To choose a function, enter its letter lable:");
    puts ("a) Show number of empty seats");
    puts ("b) Show list of empty seats");
    puts ("c) Show alphabetical list of seats");
    puts ("d) Assign a customer to a seat assignment");
    puts ("e) Delete a seat assignment");
    puts ("f) Retuen top");
}
