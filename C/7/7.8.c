#include<stdio.h>
#define COVERAGE 200 //每罐油漆可喷的平方英尺数
int main(void)
{
	int sq_feet;
	int cans;

	printf("请输入要喷的英尺数\n按q退出\n");
	while((scanf("%d",&sq_feet))==1){
		cans = sq_feet / COVERAGE;
		cans += (sq_feet % COVERAGE == 0) ? 0 : 1;
		printf("你说要购买的油漆为%d %s\n",cans,(cans % COVERAGE)==1 ? "can" :"cans");
		printf("请输入要喷的英尺数\n按q退出\n");
	}
	return 0;
}
