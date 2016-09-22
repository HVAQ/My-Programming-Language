#include<stdio.h>
void copy_arr(double ar1[],double ar2[],int);
void copy_prr(double *ar1,double *ar2,int);

int main(void)
{
	double source[5]={1.1,2.2,3.3,4.4,5.5};
	double target1[5];
	double target2[5];
	copy_arr(source,target1,5);
	copy_prr(source,target2,5);
	return 0;
}

void copy_arr(double ar1[],double ar2[],int n)
{
	int i;
	printf("target1[5]={");
	for(i=0;i<n;i++){
		ar2[i]=ar1[i];
		printf("%.1f ",ar2[i]);
	}
	printf("}\n");
}

void copy_prr(double *ar1,double *ar2,int n)
{
	int i;
	printf("target2[5]={");
	for(i=0;i<n;i++){
		ar2[i]=*(ar1++);
		printf("%.1f ",ar2[i]);
	}
	printf("}\n");
}
