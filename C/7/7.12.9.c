#include<stdio.h>
#include<stdbool.h>
int main(void)
{
	long num_o,num_t;//要检查的数
	long div;//可能的约数
	bool isPrime;

	printf("请输入一个大于等于2的整数\n");
	while(scanf("%ld",&num_o)==1){
		if(num_o<2){
			printf("请输入一个大于等于2的整数\n");
			continue;
		}
		printf("您输入的数为%ld，小于等于它的素数有:\n",num_o);
		for(num_t=num_o;num_t>1;num_t--){
			for(div=2,isPrime=true;div<num_t;div++){
				if(num_t%div==0){
					isPrime=false;
					break;
				}
				else
					isPrime=true;
			}
			if(isPrime)
				printf("%ld ",num_t);
		}
		printf("\n");
		printf("请继续输入\n");
	}
	return 0;
}
