#include<stdio.h>
#define LINES 3
#define ROWS 5
void b(double ar[][ROWS],int);
double c(double ar[][ROWS],int);
double d(double ar[][ROWS],int);
void e(double,double);

int main(void)
{
	int m,n;
	double source[LINES][ROWS];
	double ys;

	printf("请输入%d个数，组成一个数组\n",LINES*ROWS);
	for(m=0;m<LINES;++m){
		for(n=0;n<ROWS;++n){
			while(scanf("%lf",&ys)!=1){
				while(getchar()!='\n')
					continue;
				printf("请输入数字\n");
			}
			source[m][n]=ys;
		}
	}
	b(source,LINES);
	e(c(source,LINES),d(source,LINES));
	return 0;
}

void b(double ar[][ROWS],int n)
{
	int x,y;
	double total;

	for(x=0;x<n;++x){
		for(y=0,total=0;y<ROWS;++y)
			total+=ar[x][y];
		printf("total[%d]=%.2f\n",x,total/ROWS);
	}
}

double c(double ar[][ROWS],int n)
{
	int x,y;
	double total;

	for(x=0,total=0;x<n;++x)
		for(y=0;y<ROWS;++y)
			total+=ar[x][y];
	return total/(ROWS*n);
}

double d(double ar[][ROWS],int n)
{
	int x,y;
	double max;

	x=y=0;
	max=ar[x][y];
	for(x=0;x<n;++x)
		for(y=0;y<ROWS;++y)
			max=max>ar[x][y]?max:ar[x][y];
	return max;
}

void e(double a,double b)
{
	printf("所有数的平均值为%.2f\n",a);
	printf("数组中最大的数为%.2f\n",b);
}
