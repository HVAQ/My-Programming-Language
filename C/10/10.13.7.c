#include<stdio.h>
#define SIZE 7
void ar(int *pr,int);
int main(void)
{
	int source[SIZE]={1,3,5,7,8,10,12};
	ar(&source[2],3);
	return 0;
}

void ar(int *pr,int n)
{
	int i;
	int target[n];
	for(i=0;i<n;i++){
		target[i]=*pr++;
		printf("target[%d]=%d\n",i,target[i]);
	}
}
