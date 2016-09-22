#include<stdio.h>
#define LINES 3
#define ROWS 5
void copy_arr(int [][ROWS],int);
void two_arr(int [][ROWS],int);

int main(void)
{
	int source[LINES][ROWS]={
		{1,5,7,8,10},
		{6,2,4,3,1},
		{9,9,4,6,2}
	};
	copy_arr(source,LINES);
	two_arr(source,LINES);
	return 0;
}

void copy_arr(int ar[][ROWS],int n)
{
	int x,y;
	for(x=0;x<n;++x)
		for(y=0;y<ROWS;++y)
		printf("source[%d][%d]=%d\n",x,y,ar[x][y]);
}

void two_arr(int ar[][ROWS],int n)
{
	int x,y;
	
	for(x=0;x<n;++x)
		for(y=0;y<ROWS;++y)
			printf("two_source[%d][%d]=%d\n",x,y,2*ar[x][y]);
}
