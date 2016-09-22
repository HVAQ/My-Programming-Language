#include<stdio.h>
float JG(float a,float b);
int main(void)
{
	float a,b,c;
	printf("请输入两个浮点数\n");
	while(scanf("%f%f",&a,&b)==2){
		while(a<b){
			c=a;
			a=b;
			b=c;
		}
		JG(a,b);
		printf("请重新输入两个浮点数\n");
	}
	printf("END\n");
	return 0;
}
float JG(float a,float b)
{
	float d,e;
	d=(a-b)/(a*b);
	e=printf("(%g-%g)/(%g*%g)=%f\n",a,b,a,b,d);
	return e;
}
