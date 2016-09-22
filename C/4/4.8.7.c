#include<stdio.h>
#define A1 3.785
#define B1 1.609
#define B2 100
int main(void)
{
	float a,b,c;

	printf("行驶的英里\n");
	scanf("%f",&a);
	printf("消耗汽油的加仑数\n");
	scanf("%f",&b);
	printf("每加仑汽油可行驶 %.1f 英里\n",a/b);

	c=B2/(a/b*B1)*A1;
	printf("每100公里消耗 %.1f 升\n",c);
	return 0;
}
