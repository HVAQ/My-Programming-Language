#include <stdio.h>

int main(void)
{
	float lm,yc;

	printf("请输入您的身高(cm):");
	scanf("%f",&lm);

	yc=lm/2.54;

	printf("您的身高为%.2f厘米，即%.2f英寸.\n",lm,yc);

	return 0;
}
