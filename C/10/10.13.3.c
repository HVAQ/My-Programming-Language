#include<stdio.h>
#define SIZE 5
int max(int [],int);

int main(void)
{
	int ar[SIZE]={18,12,3,10,5};
	printf("数组中最大值为%d\n",max(ar,SIZE));
	return 0;
}

int max(int ar[],int n)
{
	int max,i;

	for(i=0,max=ar[i];i<n;i++)
		max=max>ar[i]?max:ar[i];
	return max;
}
