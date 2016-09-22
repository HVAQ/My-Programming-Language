#include<stdio.h>
void DY(float n);
int main(void)
{
	float n,a;
	printf("请输入一个浮点数\n");
	scanf("%f",&n);
	DY(n);

	return 0;
}

void DY(float n)
{
	float i;
	i=n*n*n;
	printf("n的立方为%f\n",i);
}
