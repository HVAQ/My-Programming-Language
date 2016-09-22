#include<stdio.h>
#define LINES 3
#define ROWS 5
void b(int,int,double ar [*][*]);
double c(int,int,double ar [*][*]);
double d(int,int,double ar [*][*]);
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
	b(LINES,ROWS,source);
	e(c(LINES,ROWS,source),d(LINES,ROWS,source));
	return 0;
}

void b(int m,int n,double ar[m][n])
{
	int x,y;
	double total;

	for(x=0;x<m;++x){
		for(y=0,total=0;y<n;++y)
			total+=ar[x][y];
		printf("total[%d]=%.2f\n",x,total/n);
	}
}

double c(int m,int n,double ar[m][n])
{
	int x,y;
	double total;

	for(x=0,total=0;x<m;++x)
		for(y=0;y<n;++y)
			total+=ar[x][y];
	return total/(m*n);
}

double d(int m,int n,double ar[m][n])
{
	int x,y;
	double max;

	x=y=0;
	max=ar[x][y];
	for(x=0;x<m;++x)
		for(y=0;y<n;++y)
			max=max>ar[x][y]?max:ar[x][y];
	return max;
}

void e(double a,double b)
{
	printf("所有数的平均值为%.2f\n",a);
	printf("数组中最大的数为%.2f\n",b);
}
