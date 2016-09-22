#include<stdio.h>
double xjz(double,double);

int main(void)
{
	double a,b;

	printf("请输入两个不等于0的数\n");
	while(scanf("%lf %lf",&a,&b)!=2||(a==0||b==0)){
		while(getchar()!='\n')
			continue;
		printf("请输入两个不等于0的数字\n");
	}
	printf("%f和%f的谐均值为%f\n",a,b,xjz(a,b));
	return 0;
}

double xjz(double x,double y)
{
	return (1/(((1/x)+(1/y))/2));
}
