#include<stdio.h>
double power(double,int);

int main(void)
{
	double i;
	int n;

	printf("请输入一个数字\n");
	while(scanf("%lf",&i)!=1){
		while(getchar()!='\n')
			continue;
		printf("请输入一个数字\n");
	}
	printf("要计算%f的几次幂?\n",i);
	while(scanf("%d",&n)!=1){
		while(getchar()!='\n')
			continue;
		printf("请输入一个数字\n");
	}
	printf("%f的%d次幂为%e\n",i,n,(n<0?1/power(i,n):power(i,n)));
	return 0;
}

double power(double x,int y)
{
	double pow;
	int n;

	n=y<0?-y:y;

	if(x==0)
		pow=0;
	if(n==0&&x!=0)
		pow=1;

	if(n>0)
		pow=x*power(x,n-1);
	return pow;
}
