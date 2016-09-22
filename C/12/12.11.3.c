#include <stdio.h>
float set_mode (float);
void get_info (float);

int main (void)
{
	float mode = 0;

	printf ("Enter 0 for metric mode, 1 for US mode: ");
	while ((scanf("%f", &mode) == 1) && mode >= 0)
	{
		mode = set_mode (mode);
		get_info (mode);
		printf ("enter 0 for metric mode, 1 for US mode (-1 to quit): ");
	}
	puts ("Done");

	return 0;
}

float set_mode (float mode)
{
	if (mode != 1 && mode != 0)
		if (mode > 1){
			puts ("Invalid mode specified. Mode 1 (US) used.");
			return 1;
		}	
		else{
			puts ("Invalid mode specified. Mode 0 (metric) used.");
			return 0;
		}
	else
		return mode;
}

void get_info (float mode)
{
	double dist, cons;

	if (mode == 0){
		printf ("Enter distance traveled in kilometers: ");
		scanf ("%lf", &dist);
		printf ("Enter fuel consumed in liters: ");
		scanf ("%lf", &cons);
		printf ("Fuel consumption is %.2f liters per 100 km.\n", 100 * cons / dist);
	}
	else{
		printf ("Enter distancd traveled in miles: ");
		scanf ("%lf", &dist);
		printf ("Enter fule consumed in gallons: ");
		scanf ("%lf", &cons);
		printf ("Fuel consumeption is %.1f miles per gallon.\n", dist / cons);
	}
}
