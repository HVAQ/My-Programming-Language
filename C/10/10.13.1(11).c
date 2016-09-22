#include<stdio.h>
#define MONTHS 12
#define YEARS 5
void qb(int a,int b,float ar[a][b]);
void bf(float ar2[][MONTHS],int a);

int main(void)
{
	float rain[YEARS][MONTHS]={
		{4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
		{8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
		{9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
		{7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
		{7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
	};

	printf(" YEAR  RAINFALL(inches)\n");
	qb(YEARS,MONTHS,rain);
	printf("MONTHLY AVERAGES:\n\n");
	bf(rain,YEARS);
	return 0;
}

void qb(int a,int b,float ar[a][b])
{
	float subtot;
	float total=0;
	int m,n;

	for(m=0;m<a;m++){
		subtot=0;
		for(n=0;n<b;n++)
			subtot+=ar[m][n];
		printf("%5d %15.1f\n",2000+m,subtot);
		total+=subtot;
	}
	printf("\nThe yearly average is %.1f inches.\n\n",total/a);
}

void bf(float ar2[][MONTHS],int a)
{
	float total;
	int m,n;

	printf("Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec\n");

	for(m=0;m<MONTHS;m++){
		for(n=0,total=0;n<a;n++)
			total+=ar2[n][m];
		printf("%.1f ",total/a);
	}
	putchar('\n');
}
