#include<stdio.h>
#include<string.h>
#define md 1.045E3
//计算一个人大概的体积，名字占用位数，以及名字字母多少

int main(void)
{
	char mz[40];
	float tj,zl;
	int zy,ds;

	printf("您好，请输入您的名字：");
	scanf("%s",mz);
	printf("好的,%s,请问您有多少千克：",mz);
	scanf("%f",&zl);
	tj=zl/md;
	zy=sizeof mz;
	ds=strlen (mz);
	printf("好的，%s,您的体积大约为：%2.2f立方米.\n",mz,tj);
	printf("您名字占用位数为%d位.\n",zy);
	printf("您的名字包含%d个字母.\n",ds);

	return 0;
}
