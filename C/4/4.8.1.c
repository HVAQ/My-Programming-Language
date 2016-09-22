#include<stdio.h>
int main(void)
{
	char name1[20];
	char name2[20];

	printf("请输入您的姓\n");
	scanf("%s",name1);
	printf("请输入您的名\n");
	scanf("%s",name2);
	printf("%s,%s\n",name2,name1);
	return 0;
}
