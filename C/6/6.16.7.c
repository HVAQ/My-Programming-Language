#include<stdio.h>
int main(void)
{
	float a,b,c,d;
	printf("请输入两一个浮点数\n");
	while(scanf("%f%f",&a,&b)==2){
		while(a<b){
			c=a;
			a=b;
			b=c;
		}
		d=(a-b)/(a*b);
		printf("(%g-%g)/(%g*%g)=%f\n",a,b,a,b,d);
		printf("请重新输入两个新的浮点数\n");
	}
		printf("END\n");
		return 0;
}
