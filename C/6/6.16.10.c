#include<stdio.h>
#define SIZE 8
int main(void)
{
	int num[SIZE];
	int i,x;
	printf("请输入8个整数\n");
	for(i=0;i<=7;i++){
		scanf("%d",&num[i]);
	}
	for(i=7;i>=0;i--){
		printf("%d\t",num[i]);
	}
	printf("\n");
	return 0;
}
