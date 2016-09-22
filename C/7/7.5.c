#include<stdio.h>
#include<stdbool.h>
int main(void)
{
	unsigned long num;//可能要检查的数
	unsigned long div;//可能的约数
	bool isPrime;//素数的标志

	printf("请输入一个数\n输入q退出\n");
	while(scanf("%lu",&num)==1){
		for(div=2,isPrime=true;(div * div)<=num;div++){
			if(num % div==0){
				if(div * div != num)
					printf("%lu的约数为%lu和%lu\n",num,div,num/div);
				else
					printf("%lu的约数为%lu\n",num,div);
				isPrime=false;//不是素数
			}
		}
		if(isPrime)
			printf("%lu是素数\n",num);
		printf("请输入一个数\n输入q退出\n");
	}
	printf("Bye\n");
	return 0;
}
