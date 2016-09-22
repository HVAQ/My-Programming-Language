#include<stdio.h>
#include<string.h>
int main(void)
{
	char name1[20];
	char name2[20];
	int a,b;

	printf("请输入您的名\n");
	scanf("%s",name1);
	printf("请输入您的姓\n");
	scanf("%s",name2);

	a=strlen(name1);
	b=strlen(name2);

	printf("%s\t%s\n",name1,name2);
	printf("%-*d\t%-*d\n",a,a,b,b);
	return 0;
}
