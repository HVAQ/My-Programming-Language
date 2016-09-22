#include<stdio.h>
#define SIZE 8
int main(void)
{
	int num[SIZE];
	int i,x;
	for(i=0,x=1;i<SIZE;i++){
		num[i]=x;
		x*=2;
	}
	i=0;
	do{
		printf("%d\t",num[i]);
		++i;
	}while(i<SIZE);
	printf("\n");
	return 0;
}
