#include<stdio.h>
void bj(int *,int *);
int main(void)
{
	int a[3]={9,7,5};
	printf("*a[0]=9=%p *a[2]=5=%p\n",&a[0],&a[2]);
	bj(&a[1],&a[2]);
	return 0;
}
void bj(int *ar1,int *ar2)
{
	if(ar1<ar2)
		printf("比较的是指针指向位置的大小\n");
	else
		printf("比较的是指针指向数值的大小\n");
}
