#include<stdio.h>
int main(void)
{
	int a,b,c,d,sum,i;
	printf("Enter lower and upper integer limits:");
	scanf("%d%d",&b,&a);
	while(a>b){
		for(sum=0,i=b;i<=a;i++){
			c=i*i;
			sum+=c;
		}
		printf("The sums of the squares from %d to %d is %d\n",b*b,a*a,sum);
		printf("Enter next set of limits:");
		scanf("%d%d",&b,&a);
	}
	printf("Done\n");
	return 0;
}
