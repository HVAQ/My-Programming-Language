#include<stdio.h>
#define SIZE 8
int main(void){
	double none[SIZE];
	double ntwo[SIZE];
	int i;
	double sum;
	printf("请输入%d个元素\n",SIZE);
	for(i=0;i<SIZE;i++)
		scanf("%le",&none[i]);
	for(i=0,sum=0;i<SIZE;i++){
		sum+=none[i];
		ntwo[i]=sum;
	}
	i=0;
	do
	{
		printf("%le\t%le\n",none[i],ntwo[i]);
		++i;
	}while(i<SIZE);
	return 0;
}
