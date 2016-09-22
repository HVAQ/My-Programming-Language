#include<stdio.h>
int main(void)
{
	char ch;
	int i;
	i=0;
	printf("请输入\n");
	while((ch=getchar())!='#')
	{
		if(ch=='.'){
			printf("!");
			i++;
		}
		else if(ch=='!'){
			printf("!!");
			i++;
		}
		else
			putchar(ch);
	}
	printf("总共替换了%d次\n",i);
	return 0;
}
