#include<stdio.h>
int main(void)
{
	int num,o_gs,o_zs,j_gs,j_zs;
	char ch;

	o_gs= o_zs= j_gs= j_zs= 0;
	printf("请输入整数，按0退出\n");
	while((scanf("%d",&num))==1)
	{
		if(num==0)
			break;
		if(num%2==0)
			ch='a';
		else
			ch='b';
		switch(ch)
		{
			case 'a':
				o_gs++;
				o_zs=o_zs+num;
				break;
			case 'b':
				j_gs++;
				j_zs=j_zs+num;
				break;
			default:
				break;
		}
	}
	printf("偶数%d个,平均%d\n奇数%d个,平均%d\n",o_gs,o_zs/o_gs,j_gs,j_zs/j_gs);
	return 0;
}
