// pe12-2b.c
#include <stdio.h>
#include "pe12-2a.h"

static float mode;
static double dist;
static double cons;

void get_info (void);
void show_info (void);

int main (void)
{
	printf ("Enter 0 for metric mode, 1 for US mode: ");
	while ((scanf ("%f", &mode) == 1) && mode >= 0)
	{
		set_mode (mode);
		get_info ();
		show_info ();
		printf ("Enter 0 for metric mode, 1 for US mode");
		printf (" (-1 to quit): ");
	}
	printf ("Done\n");

	return 0;
}

void get_info (void)
{
	if (mode == 0)
	{
		printf ("Enter distance traveled in kilomenters: ");
		scanf ("%lf", &dist);
		printf ("Enter fuel consumed in liters: ");
	}
	else
	{
		printf ("Enter distance traveled in miles: ");
		scanf ("%lf", &dist);
		printf ("Enter fuel consumed in gallons: ");
	}
	scanf ("%lf", &cons);
}

void show_info (void)
{
	if (mode == 0)
		printf ("Fuel consumption is %.2f liters per 100 km.\n", 100 * cons / dist);
	else
		printf ("Fuel consumption is %.1f miles per gallon.\n", dist / cons);
}
