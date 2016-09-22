#include<stdio.h>
#define SIZE 4
void sum(int *a,int *b,int *c,int);

int main(void)
{
	int source1[SIZE]={2,4,5,8};
	int source2[SIZE]={1,0,4,6};
	int source3[SIZE];
	sum(source1,source2,source3,SIZE);
	return 0;
}

void sum(int *a,int *b,int *c,int n)
{
	int i;
	
	for(i=0;i<n;++i){
		c[i]=a[i]+b[i];
		printf("source3[%d]=%d\n",i,c[i]);
	}
}
