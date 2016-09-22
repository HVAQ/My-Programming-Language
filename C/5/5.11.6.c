#include<stdio.h>
int main(void)
{
	int count,sum,n;
	count=0;
	sum=0;
	printf("请输入n的值\n");
	scanf("%d",&n);
	while(count++<n){
		sum=sum+count*count;
	}
	printf("%d\n",sum);
	return 0;
}
