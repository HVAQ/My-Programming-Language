#include<stdio.h>
#include<string.h>
int main(void)
{
	char name[20];
	int a,b;

	printf("请输入您的姓名\n");
	scanf("%s",name);
	a=strlen(name);
	b=a+3;
	printf("%*s\n",b,name);
	return 0;
}
