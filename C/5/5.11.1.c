#include<stdio.h>
#define FZ 60 //每小时有60分钟
int main(void)
{
	int sr,fz,xs;
	printf("请输入总共的分钟数（>0）\n");
	scanf("%d",&sr);
	while(sr>0){
		xs=sr/FZ;
		fz=sr%FZ;
		printf("%d分钟折合%d小时%d分钟\n",sr,xs,fz);
		scanf("%d",&sr);
	}
	printf("谢谢\n");
	return 0;
}
