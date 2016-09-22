//查看计算机对整数溢出的处理
#include<stdio.h>
#include<limits.h>

int main(void)
{
int a,b;

printf("此系统所能处理的最大、最小整数为%d,%d\n",INT_MAX,INT_MIN);
printf("要查看计算机对整数溢出的处理\n请输入%d所要乘的数:",INT_MAX);
scanf("%d",&a);
printf("请输入%d所要乘的数:",INT_MIN);
scanf("%d",&b);

printf("计算机对整数溢出处理如下:");
printf("%d溢出，处理为%d\n",INT_MAX,INT_MAX*a);
printf("%d溢出，处理为%d\n",INT_MIN,INT_MIN*b);

return 0;
}
