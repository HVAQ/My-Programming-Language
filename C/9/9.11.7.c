#include<stdio.h>
void power(double,int);

int main(void)
{
	int n;
	double i;

	printf("请输入一个数字\n");
	while(scanf("%lf",&i)!=1){
		while(getchar()!='\n')
			continue;
		printf("请输入任意数字\n");
	}
	printf("要计算%f的几次幂?请输入\n",i);
	while(scanf("%d",&n)!=1){
		while(getchar()!='\n')
			continue;
		printf("请输入一个数字\n");
	}
	power(i,n);
	return 0;
}

void power(double i,int n)
{
	int x,y;
	double pow;

	x=(n<0)?(-n):n;
	
	for(y=1,pow=1;y<=x;++y)
		pow *=i;
	
	if(i==0)
		pow=0;
	if(i!=0&&n==0)
		pow=1;

	printf("%f的%d次幂为%e\n",i,n,n<0?1/pow:pow);
}
