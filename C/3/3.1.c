#include <stdio.h>
 int main(void)
{
	float weight,value;
	printf("Are you worth your weight in rhodium?\nLet's check it out.\nPlease enter your weight in pounds:");
	scanf("%f",&weight);
	value = 770 * weight * 14.5833;

	printf("Your weight in rhodium is worth $%.2f.\nYou are easily worth that! If rhodium prices dorp, \neat more to maintain your value.\n",value);

	return 0;
}
