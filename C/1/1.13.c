#include<stdio.h>
int main(void)
{
	float a,b;

	printf("英寸：");
	scanf("%f",&a);

	b=2.54*a;
	printf("厘米：%f\n",b);
	return 0;
}
