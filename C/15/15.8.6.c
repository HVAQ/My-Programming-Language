#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAKE 0xFF
#define MAKT 0x7F
// font id   font size
#define MAXFID 255
#define MAXFZE 127
#define MINFONT 0
// hoose size
#define SIZE 6
// Bold  Italic Underline
#define OFF 0
#define ON 1
// Alignment
#define LEFT 0
#define CENTER 1
#define RIGHT 2

struct font_box {
	unsigned int fontid    : 8;
	unsigned int fontsize  : 8;
	unsigned int alignment : 2;
	unsigned int bold      : 1;
	unsigned int italic    : 1;
	unsigned int underline : 1;
};

void eatline (void);
void show_box (const struct font_box *);
void show (const struct font_box *);
void mean (void);
char get_ch (char *);
void set_ch (char);
void get_f (struct font_box *);
void get_s (struct font_box *);
void get_a (struct font_box *);
void get_b (struct font_box *);
void get_i (struct font_box *);
void get_u (struct font_box *);

int main (void)
{
	struct font_box box = {1, 12, LEFT, OFF, OFF, OFF};
	char ch;
	char cose[SIZE] = {'f', 's', 'a', 'b', 'i', 'u'};

	show_box(&box);
	mean();
	while ((ch = get_ch(cose)) != 'q')
	{
		switch(ch)
		{
			case 'f': get_f(&box); break;
			case 's': get_s(&box); break;
			case 'a': get_a(&box); break;
			case 'b': get_b(&box); break;
			case 'i': get_i(&box); break;
			case 'u': get_u(&box); break;
		}
		show_box(&box);
		mean ();
	}
	puts ("Bye!");

	return 0;
}

void get_u (struct font_box * box)
{
	if (box -> underline == OFF)
		box -> underline = ON;
	else
		box -> underline = OFF;
}
void get_i (struct font_box * box)
{
	if (box -> italic == OFF)
		box -> italic = ON;
	else
		box -> italic = OFF;
}
void get_b (struct font_box * box)
{
	if (box -> bold == OFF)
		box -> bold = ON;
	else
		box -> bold = OFF;
}
void get_a (struct font_box * box)
{
	char ch;

	puts ("Select alignment:");
	puts ("l) left  c) center  r) right");
	if ((ch = getchar()) != '\n')
		eatline();
	ch = tolower(ch);
	switch(ch)
	{
		case 'l': box -> alignment = 0; break;
		case 'c': box -> alignment = 1; break;
		case 'r': box -> alignment = 2; break;
		default : puts ("Enter faild");
	} 
}
void get_s (struct font_box * box)
{
	int size;

	printf ("Enter font size (0-127): ");
	while (scanf ("%d", &size) != 1)
	{
		eatline();
		printf ("Enter font size (0-127): ");
	}
	eatline();
	size &= MAKT;
	box -> fontsize = size;
}
void get_f (struct font_box * box)
{
	int num;

	printf ("Enter font number (0-255): ");
	while (scanf ("%d", &num) != 1)
	{
		eatline();
		printf ("Enter the font number (0-255): ");
	}
	eatline();
	num &= MAKE;
	box -> fontid = num;
}
void show (const struct font_box * box)
{
	if (box -> alignment == LEFT)
		printf("");
	else if (box -> alignment == CENTER)
		printf(" ");
	else
		printf("  ");
}
void show_box (const struct font_box * box)
{
	putchar('\n');
	show(box);
	puts ("ID SIZE ALIGNMENT B I U");
	show(box);
	printf ("%3d ", box -> fontid);
	printf ("%3d ", box -> fontsize);
	if (box -> alignment == LEFT)
		printf ("%3s ","left");
	else if (box -> alignment == CENTER)
		printf ("%3s ", "center");
	else
		printf ("%3s ", "right");
	printf ("%3s ", (box -> bold == OFF ? "off" : "on"));
	printf ("%3s ", (box -> italic == OFF ? "off" : "on"));
	printf ("%3s\n", (box -> underline == OFF ? "off" : "on"));
}
char get_ch (char * cose)
{
	int i;
	char ch;

	if ((ch = getchar()) != '\n')
		eatline();
	ch = tolower(ch);
	for (i = 0; i < SIZE; i++)
		if (ch == cose[i])
			break;
	if (i == SIZE)
		ch = 'q';

	return ch;
}
void mean (void)
{
	puts ("f) chang font  s) chang size  a) chang alignment");
	puts ("b) toggle bold  i) toggle italic  u) toggle underline");
	puts ("q) quit");
}
void eatline (void)
{
	while (getchar() != '\n')
		continue;
}
