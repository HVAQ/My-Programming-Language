#include<stdio.h>
#include<ctype.h>
int main(void)
{
	char ch;
	printf("请输入一个小写字母\n");
	printf("按＃退出\n");
	while((ch=getchar())!='#')
	{
		if('\n'==ch)
			continue;
		if(islower(ch))
			switch(ch)
			{
				case 'a':
					printf("你输入的是a\n");
					break;
				case 'b':
					printf("你输入的是b\n");
					break;
				default:
					printf("你输入的是其他小写字母\n");
			}
		else
			printf("请输入小写字母\n");
		while(getchar()!='\n')
			continue;
		printf("请继续输入小写字母，按＃退出\n");
	}
	printf("Bye\n");
	return 0;
}
