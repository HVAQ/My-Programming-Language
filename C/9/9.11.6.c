#include<stdio.h>
#include<ctype.h>
int is_char(char);
void wz(char);

int main(void)
{
	char ch;
	int i,m;

	printf("请输入一个字母\n");
	while((ch=getchar())!=EOF)
	{
		if(ch=='\n')
			continue;
		if(is_char(ch)==-1)
			printf("%c不是一个字母\n",ch);
		else
			printf("%c在字母表的位置是%d\n",ch,is_char(ch));
		printf("请继续输入\n");
	}
	printf("Bye!\n");
	return 0;
}

int is_char(char ch)
{
	if(isalpha(ch)){
		ch=tolower(ch);
		return ch-96;
	}
	else
		return -1;
}
