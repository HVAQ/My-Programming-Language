#include <stdio.h>
#include <ctype.h>

#define SIZE 6
// 初始化值
#define NONE 0x1180
// get_f
#define SIZEID 12  // 步长
#define YID 0xFF  // 掩码
#define YBOX 0xFFF  // box掩码
// get_s
#define SIZESZ 5
#define YBOXT 0xFF01F
#define YSZ 0x7F
// getz_a
#define SIZEAO 3
#define SIZEAT 4
#define YAL 0xFFFE7 // 掩码
#define FCT 0x8 // for center
#define FRT 0x10 // for right
// show show_get
#define TEXT 0x1 // show get_s
#define SHSZ 0x7F
#define SIZEB 2
#define SIZEI 1
// for b i u
#define FB 0x4
#define FI 0x2
#define FU 0x1

void eatline (void);
void show_box (const unsigned long);
void show (const unsigned long);
void mean (void);
char get_ch (char *);
unsigned long get_f (unsigned long);
unsigned long get_s (unsigned long);
unsigned long get_a (unsigned long);

int main (void)
{
	// 初始化设定
	unsigned long box = NONE;
	char ch;
	char cose[SIZE] = {'f', 's', 'a', 'b', 'i', 'u'};

	show_box(box);
	mean();
	while ((ch = get_ch(cose)) != 'q')
	{
		switch(ch)
		{
			case 'f': box = get_f(box); break;
			case 's': box = get_s(box); break;
			case 'a': box = get_a(box); break;
			case 'b': box ^= FB; break;
			case 'i': box ^= FI; break;
			case 'u': box ^= FU; break;
		}
		show_box(box);
		mean();
	}
	puts ("Bye!");

	return 0;
}

unsigned long  get_a (unsigned long box)
{
	char ch;

	puts ("Select alignment:");
	puts ("l) left  c) center  r) right");
	if ((ch = getchar()) != '\n')
		eatline();
	ch = tolower(ch);
	if (ch == 'l' || ch == 'c' || ch == 'r')
	{
		box &= YAL;
		switch(ch)
		{
			case 'l': break;
			case 'c': box |= FCT; break;
			case 'r': box |= FRT; break;
		}
	}

	return box;
}
unsigned long  get_s (unsigned long box)
{
	unsigned long size;

	printf ("Enter font size (0-127): ");
	while (scanf ("%ld", &size) != 1)
	{
		eatline();
		printf ("Enter font size (0-127): ");
	} 
	eatline();
	size &= YSZ;
	size <<= SIZESZ;
	box &= YBOXT;

	return box |= size;
}
unsigned long  get_f (unsigned long box)
{
	unsigned long num;

	printf ("Enter font number (0-255): ");
	while (scanf ("%ld", &num) != 1)
	{
		eatline();
		printf ("Enter the font number (0-255): ");
	}
	eatline();
	num &= YID;
	num <<= SIZEID;
	box &= YBOX;

	return box |= num;
}
void show (unsigned long box)
{
	if (((box >> SIZEAO) & TEXT) == 1)
		printf (" ");
	else if (((box >> SIZEAT)  & TEXT) == 1)
		printf ("  ");
	else
		printf ("");
}
void show_box (unsigned long box)
{
	putchar('\n');
	show(box);
	puts ("ID SIZE ALIGNMENT B I U");
	show(box);
	printf ("%3lu ", (box >> SIZEID));
	printf ("%3lu ", (box >> SIZESZ) & SHSZ);
	// 将box右移3 4位检查是否位1
	if (((box >> SIZEAO) & TEXT) == 1)
		printf ("%s ", "center");
	else if (((box >> SIZEAT) & TEXT) == 1)
		printf ("%s ", "right");
	else
		printf ("%s ", "left");
	printf ("%3s ", ((box >> SIZEB) & TEXT)== 1 ? "on" : "off");
	printf ("%3s ", ((box >> SIZEI) & TEXT)== 1 ? "on" : "off");
	printf ("%3s\n", (box & TEXT) == 1 ? "on" : "off");
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
