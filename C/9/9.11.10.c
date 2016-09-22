#include<stdio.h>
long Fibonacci(int);

int main(void)
{
	int n;

	printf("请输入一个数字\n");
	while(scanf("%d",&n)!=1){
		while(getchar()!='\n')
			continue;
		printf("请输入一个数字\n");
	}
	printf("在斐波那契数列中,第%d位数是%ld\n",n,Fibonacci(n));
	return 0;
}

long Fibonacci(int n)
{
	int i;
	long sum,x,y;

	if(n<2)
		sum=1;
	else
		for(i=0,x=1,y=0;i<n-1;++i){
		sum=x+y;
		y=x;
		x=sum;
	}
	return sum;
}
