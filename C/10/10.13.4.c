#include<stdio.h>
#define SIZE 5
int sy(double [],int);

int main(void)
{
	double ar[SIZE]={8.3,14.5,8.9,12.8,6.4};
	printf("数组中最大数的索引为%d\n",sy(ar,SIZE));
	return 0;
}

int sy(double ar[],int n)
{
	int x,y;
	double max;

	for(x=0,y=0,max=ar[y];x<n;x++){
		if(max<ar[x]){
			max=ar[x];
			y=x;
		}
	}
	return y;
}
