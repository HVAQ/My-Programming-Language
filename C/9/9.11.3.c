#include<stdio.h>
void pc(char,int,int);

int main(void)
{
	char ch;
	int x,y;
	printf("请输入一个字符\n");
	ch=getchar();
	while(getchar()!='\n')
		continue;
	printf("请输入该字符每行输出个数\n");
	while(scanf("%d",&x)!=1){
		while(getchar()!='\n')
			continue;
		printf("请输入一个整数\n");
	}
	printf("请输入该字符打印行数\n");
	while(scanf("%d",&y)!=1){
		while(getchar()!='\n')
			continue;
		printf("请输入一个整数\n");
	}
	printf("按您要求,打印的字符如下\n");
	pc(ch,x,y);
	return 0;
}

void pc(char ch,int x,int y)
{
	int m,n;
	for(m=0;m<y;++m){
		for(n=0;n<x;++n)
			putchar(ch);
		putchar('\n');
	}
}
