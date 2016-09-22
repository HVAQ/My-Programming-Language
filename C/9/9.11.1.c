#include<stdio.h>
double min(double x,double y);

int main(void)
{
	double x,y;

	printf("请输入两个数字(按q退出)\n");
	while(scanf("%lf %lf",&x,&y)==2){
		printf("%f和%f中较小的是%f\n",x,y,min(x,y));
		printf("请继续输入两个数字\n");
	}
	printf("Bye\n");
	return 0;
}
double min(double x,double y)
{
	return (x>y)?y:x;
}
