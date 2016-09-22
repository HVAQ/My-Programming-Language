#include<stdio.h>
#define MONEY 100
#define QC 10
int main(void)
{
	int n;
	double bj;
	float lx=0.08;
	for(bj=MONEY,n=1;bj>0;++n){
		bj=bj*(1+lx)-QC;
	}
	printf("%d年后,Chuckie Lucky将会清空他的账户\n",n);
	return 0;
}
