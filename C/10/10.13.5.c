#include<stdio.h>
#define SIZE 5
double cz(double [],int);

int main(void)
{
	double ar[SIZE]={2.5,1.8,3.7,5.6,6.9};
	printf("数组中最大最小数的差值为%.1f\n",cz(ar,SIZE));
	return 0;
}

double cz(double arr[],int n)
{
	double max,min;
	int i;

	for(i=0,max=arr[i],min=arr[i];i<n;i++){
		max=max>arr[i]?max:arr[i];
		min=min<arr[i]?min:arr[i];
	}
	return max-min;
}
