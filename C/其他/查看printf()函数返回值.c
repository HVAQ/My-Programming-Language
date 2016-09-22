//发现printf()函数的返回值
#include<stdio.h>
int main(void)
{
	int a = 212;
	int b;

	b=printf("%d返回值。\n",a);
	printf("printf()的返回值为%d\n",b);
	return 0;
}
