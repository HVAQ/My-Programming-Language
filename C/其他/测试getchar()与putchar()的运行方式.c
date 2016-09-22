#include<stdio.h>
//测试getchar()与putchar()函数的运行工作方式
int main(void)
{
	char ch;
	printf("请输入一个字符\n");
	ch=getchar();
	putchar(ch);
	printf("\n");
	return 0;
}
