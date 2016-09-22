#include<stdio.h>
int main(void)
{
	int num,j_gs,j_zs,o_gs,o_zs;
	
	j_gs= j_zs= o_gs= o_zs=0;
	printf("请输入整数，按0结束\n");
	while(scanf("%d",&num)==1)
	{
		if(num==0)
			break;
		if(num%2==0){
			o_gs++;
			o_zs=o_zs+num;
		}
		else{
			j_gs++;
			j_zs=j_zs+num;
		}
	}
	printf("偶数%d个，平均为%d\n奇数%d个，平均为%d\n",o_gs,o_zs/o_gs,j_gs,j_zs/j_gs);
	return 0;
}
