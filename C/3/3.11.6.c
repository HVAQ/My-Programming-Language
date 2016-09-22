#include <stdio.h>

int main(void)
{
	int kt;
	float fz;

	printf("请输入水的夸脱数:");
	scanf("%d",&kt);

	fz = kt*950/(3.0e-23);

	printf("%d夸脱水包含的水分数为：%.2f.\n",kt,fz);

	return 0;
}
