#include<stdio.h>
int main(void)
{
	float a,b;
	char name[40];

	printf("请输入您的身高(cm)和姓名\n");
	scanf("%f%s",&a,name);
	
	b=a/100;
	printf("%s,您的身高是%.3f米\n",name,b);
	return 0;
}
