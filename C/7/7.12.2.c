#include<stdio.h>
int main(void)
{
	char ch;
	int i;

	i=0;
	printf("请输入,按＃结束\n");
	while((ch=getchar())!='#')
	{
		printf("%c-%d\t",ch,ch);
		i++;
		if(i%8==0)
			printf("\n");
	}
	printf("\n");
	return 0;
}
