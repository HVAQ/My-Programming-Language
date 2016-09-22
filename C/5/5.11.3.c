#include<stdio.h>
#define YZ 7 //一周有7天
int main(void)
{
	int sr,ts,zs;
	printf("请输入天数\n");
	scanf("%d",&sr);
	while(sr>0){
	zs=sr/YZ;
	ts=sr%YZ;
	printf("%d days are %d weeks, %d days.\n",sr,zs,ts);
	scanf("%d",&sr);
	}
	return 0;
}
