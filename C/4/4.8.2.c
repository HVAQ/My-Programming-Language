//a,b,c
#include<stdio.h>
int main(void)
{
	char name[21];
	printf("请输入您的姓名\n");
	scanf("%s",name);
	printf("\"%-20s\"\n",name);
	return 0;
}
