#include<stdio.h>
#define ROWS 5
#define LINES 3
void arr(double ar[][ROWS],int);
int main(void)
{
	double source[LINES][ROWS]={
		{1.1,2.2,3.3,4.4,5.5},
		{6.6,7.7,8.8,9.9,10.1},
		{10.2,10.3,10.4,10.5,10.6}
	};
	arr(source,LINES);
	return 0;
}

void arr(double ar[][ROWS],int n)
{
	int x,y;
	double ar2[LINES][ROWS];

	for(x=0;x<n;x++)
		for(y=0;y<ROWS;y++){
			ar2[x][y]=ar[x][y];
			printf("ar2[%d][%d]=%.1f\n",x,y,*(*(ar2+x)+y));
		}
}
