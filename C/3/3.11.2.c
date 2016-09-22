#include <stdio.h>

int main(void)
{
	int i;

	printf("请输入一个数字：");
	scanf("%d",&i);
	printf("%d对应的ascii值为%c\n",i,i);

	return 0;
}
