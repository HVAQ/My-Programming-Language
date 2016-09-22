#include<stdio.h>
#define ZGS 64
#define NZL 1E15
int main(void)
{
	int gs=3;
	double zj,zl,bnzl;

	printf(" 格数    增加    总量    比年总量\n");
	zj=8;
	zl=11;
	bnzl=zl/NZL;

	printf("%6d %10.2e %14.2e %18.2e\n",gs-2,1.0,1.0,1.0/NZL);
	printf("%6d %10.2e %14.2e %18.2e\n",gs-1,2.0,3.0,3.0/NZL);
	printf("%6d %10.2e %14.2e %18.2e\n",gs,zj,zl,zl/NZL);

	while(gs<ZGS)
	{
		gs=gs+1;
		zj=zj*2;
		zl=zl+zj;
		bnzl=zl/NZL;

		printf("%6d %10.2e %14.2e %18.2e\n",gs,zj,zl,bnzl);
	}
	printf("结束\n");
	return 0;
}
