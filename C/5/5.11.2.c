#include<stdio.h>
int main(void)
{
	int i,a;
	printf("请输入一个整数\n");
	scanf("%d",&i);
	a=i+10;
	while(i<=a){
		printf("%d\t",i);
		i++;
	}
	printf("\n");
	return 0;
}
