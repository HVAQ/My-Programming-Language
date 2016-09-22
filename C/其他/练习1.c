#include<stdio.h>
#define DS_A 2
#define DS_B 5
#define DS_C 50
#define DS_D 1764
//得到你的年龄
int main(void)
{
	int xs,nl,nl1,n;

	printf("请在0~9之间选择任意一个数，并输入。\n");
	scanf("%d",&xs);
	while(xs<0){
		printf("请输入0~9之间的数字哦!\n");
		scanf("%d",&xs);
	}
	while(xs>9){
		printf("亲，请输入0~9之间的数字哦!");
		scanf("%d",&xs);
	}

	printf("请用4位数字表示您的出生年份。\n");
	scanf("%d",&n);
	nl1=(xs*DS_A+DS_B)*DS_C+DS_D-n;

	if(nl1>100)
		nl=nl1-100*xs;
	else if(nl1>10)
		nl=nl1-10*xs;
	else
		nl=nl1-xs;

	printf("您的年龄是\n%d岁\n",nl);
	return 0;
}
