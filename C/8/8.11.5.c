#include<stdio.h>
int main(void)
{
	int low=0;
	int high=100;
	int num=(low+high)/2;
	char ch;

	printf("请想象一个1到100内的整数\n");
	printf("是%d吗?\n",num);
	while((ch=getchar())!='y'){
		if(ch=='\n')
			continue;
		if(ch!='h'&&ch!='l')
		{
			printf("请输入y代表猜对了,h代表猜高了,l代表猜低了\n");
			continue;
		}
		if(ch=='h')
			high=num;
		else if(ch=='l')
			low=num;
		num=(low+high)/2;
		printf("是%d吗?\n",num);
	}
	printf("我知道我可以的\n");
	return 0;
}
