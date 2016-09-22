#include<stdio.h>
void to_base_n(unsigned long,int);

int main(void)
{
	unsigned long num;
	int i;

	printf("请输入一个数字\n");
	while(scanf("%lu",&num)!=1){
		while(getchar()!='\n')
			continue;
		printf("请输入一个数字\n");
	}

	printf("要求%lu的几进制?\n",num);
	while(scanf("%d",&i)!=1||(i<2||i>10)){
		while(getchar()!='\n')
			continue;
		printf("请输入2-10内的数字\n");
	}

	printf("%lu的%d进制数为",num,i);
	to_base_n(num,i);
	putchar('\n');

	return 0;
}

void to_base_n(unsigned long x,int y)
{
	int r;
	r=x%y;
	x=x/y;

	if(x>0)
		to_base_n(x,y);
	printf("%d",r);
}
