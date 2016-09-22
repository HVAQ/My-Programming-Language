#include <stdio.h>
//测试fgets()函数在用户输入字符超过其最大输入限制时的输出结果
#define MAX 10
int main(void)
{
	char ch[MAX];

	puts("请输入一串字符(9为分界线)观察输出");
	fgets(ch,MAX,stdin);
	fputs(ch,stdout);

	return 0;
}
