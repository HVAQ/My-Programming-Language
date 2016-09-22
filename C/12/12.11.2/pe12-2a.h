#include <stdio.h>

void set_mode (float mode)
{
	if (mode != 0 && mode != 1)
	{
		if (mode > 1)
		{
			puts ("Invalid mode specified. Mode 1 (US) used.");
			mode = 1;
		}
		else
		{
			puts ("Invalid mode specified. Mode 0 (metric) used.");
			mode = 0;
		}
	}
}
