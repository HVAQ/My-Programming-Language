#include <stdio.h>

int main(void)
{
	int age,days;

	printf("请输入您的年龄：");
	scanf("%d",&age);
	days = 365 * age;

	printf("天数为%d.\n",days);

	return 0;
}
