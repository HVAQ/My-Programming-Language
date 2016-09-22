#include<stdio.h>
#define MONEY 100
int main(void)
{
	float lo,lt;
	lo=0.1;
	lt=0.05;
	double x,y; 
	int i;
	i=1;
	y=MONEY;
	do
	{
		x=MONEY*lo*i+MONEY;
		y+=y*lt;
		++i;
	}while(y<=x);
	printf("%d年后,Deirdre的投资额超过Daphne\n",i);
	return 0;
}
