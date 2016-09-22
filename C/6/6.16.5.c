#include<stdio.h>
int main(void)
{
	int a,b,c,d;
	printf("请输入表的上、下限\n");
	scanf("%d %d",&a,&b);
	while(a<b){
		c=a;
		a=b;
		b=c;
	}
	for(d=b;d*d*d<=a;d++)
		printf("%6d\t%6d\t%6d\n",d,d*d,d*d*d);
	printf("END\n");
	return 0;
}
