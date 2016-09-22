#include<stdio.h>
#define ROWS 5
#define LINES 3
void copy_arr(int,int,double [*][*]);
void show_arr(double *a,double *b,int,int);

int main(void)
{
	double source[LINES][ROWS]={
		{1.1,2.2,3.3,4.4,5.5},
		{6.6,7.7,8.8,9.9,1.2},
		{2.3,3.4,4.5,5.6,6.7}
	};
	copy_arr(LINES,ROWS,source);
	return 0;
}

void copy_arr(int m,int n,double arr[m][n])
{
	int x,y;
	double target[m][n];

	for(x=0;x<m;x++)
		for(y=0;y<n;y++){
			target[x][y]=arr[x][y];
			show_arr(&target[x][y],&arr[x][y],x,y);
		}
}

void show_arr(double *a,double *b,int m,int n)
{
	printf("source[%d][%d]=%.1f  target[%d][%d]=%.1f\n",m,n,*a,m,n,*b);
}
