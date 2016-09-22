#include<stdio.h>
//关于scanf在while循环语句中使用的一些思考
int main(void)
{
	long num;
	long sum=0L; //将sum初始化为0，L代表long
	printf("请输入一个数字\n");
	while(scanf("%ld",&num)==1){
		sum=sum+num;
		printf("请输入下一个数字（按任意非数字键退出）\n");
	}
	printf("你输入的数字的总和为%ld\n",sum);
	return 0;
}
