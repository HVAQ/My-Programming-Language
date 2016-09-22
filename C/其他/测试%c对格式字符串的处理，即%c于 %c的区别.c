//测试%c对格式字符串的处理，即%c于 %c的区别
#include<stdio.h>
int main(void)
{
	char ch;
		
	printf("请输入一个字符串:");
	scanf(" %c",&ch);
	printf("输出为%c\n",ch);
	return 0;
}
